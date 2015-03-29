#include <ch.h>
#include <string.h>
#include <memstreams.h>
#include <chprintf.h>
#include <ff.h>
#include "main.h"
#include "sensors/onboardsensors.h"
#include "sumd_input.h"
#include "analog.h"
#include "git_revision.h"

#include "sdlog.h"

#define EVENT_MASK_MPU6000      (1<<0)
#define EVENT_MASK_HMC5883L     (1<<1)
#define EVENT_MASK_H3LIS331DL   (1<<2)
#define EVENT_MASK_MS5611       (1<<3)
#define EVENT_MASK_RC_IN        (1<<4)


static THD_WORKING_AREA(sdlog_wa, 512);
static THD_FUNCTION(sdlog, arg)
{
    (void)arg;
    chRegSetThreadName("sdlog");

    // event setup
    static event_listener_t mpu6000_listener;
    chEvtRegisterMaskWithFlags(&sensor_events, &mpu6000_listener,
                               (eventmask_t)EVENT_MASK_MPU6000,
                               (eventflags_t)SENSOR_EVENT_MPU6000);
    static event_listener_t h3lis331dl_listener;
    chEvtRegisterMaskWithFlags(&sensor_events, &h3lis331dl_listener,
                               (eventmask_t)EVENT_MASK_H3LIS331DL,
                               (eventflags_t)SENSOR_EVENT_H3LIS331DL);
    static event_listener_t hmc5883l_listener;
    chEvtRegisterMaskWithFlags(&sensor_events, &hmc5883l_listener,
                               (eventmask_t)EVENT_MASK_HMC5883L,
                               (eventflags_t)SENSOR_EVENT_HMC5883L);
    static event_listener_t ms5611_listener;
    chEvtRegisterMaskWithFlags(&sensor_events, &ms5611_listener,
                               (eventmask_t)EVENT_MASK_MS5611,
                               (eventflags_t)SENSOR_EVENT_MS5611);
    static event_listener_t rc_in_listener;
    chEvtRegisterMaskWithFlags(&sensor_events, &rc_in_listener,
                               (eventmask_t)EVENT_MASK_RC_IN,
                               (eventflags_t)RC_INPUT_EVENT);


    static uint8_t writebuf[200];
    static MemoryStream writebuf_stream;
    bool error = false;
    UINT _bytes_written;

    FRESULT res;

    static FIL version_fd;
    res = f_open(&version_fd, "/log/version", FA_WRITE | FA_CREATE_ALWAYS);
    if (res) {
        chprintf(stdout, "error %d opening %s\n", res, "/log/version");
        return -1;
    }
    msObjectInit(&writebuf_stream, writebuf, sizeof(writebuf), 0);
            chprintf((BaseSequentialStream*)&writebuf_stream,
                      "git version: %s (%s)\n"
                      "compiler:    %s\n"
                      "built:       %s\n",
                      build_git_version, build_git_branch,
                      PORT_COMPILER_NAME,
                      build_date);
    error = error || f_write(&version_fd, writebuf, writebuf_stream.eos, &_bytes_written);
    f_close(&version_fd);

    static FIL mpu6000_fd;
    res = f_open(&mpu6000_fd, "/log/mpu6000.csv", FA_WRITE | FA_CREATE_ALWAYS);
    if (res) {
        chprintf(stdout, "error %d opening %s\n", res, "/log/mpu6000.csv");
        return -1;
    }
    const char *mpu_descr = "time,gyro_x,gyro_y,gyro_z,acc_x,acc_y,acc_z,temp\n";
    error |= error || f_write(&mpu6000_fd, mpu_descr, strlen(mpu_descr), &_bytes_written);

    static FIL rc_fd;
    res = f_open(&rc_fd, "/log/rc.csv", FA_WRITE | FA_CREATE_ALWAYS);
    if (res) {
        chprintf(stdout, "error %d opening %s\n", res, "/log/rc.csv");
        return -1;
    }
    const char *rc_descr = "time,signal,ch1,ch2,ch3,ch4,ch5\n";
    error |= error || f_write(&rc_fd, rc_descr, strlen(rc_descr), &_bytes_written);

    static FIL hmc5883l_fd;
    res = f_open(&hmc5883l_fd, "/log/hmc5883l.csv", FA_WRITE | FA_CREATE_ALWAYS);
    if (res) {
        chprintf(stdout, "error %d opening %s\n", res, "/log/hmc5883l.csv");
        return -1;
    }
    const char *hmc5883l_descr = "time,mx,my,mz\n";
    error |= error || f_write(&hmc5883l_fd, hmc5883l_descr, strlen(hmc5883l_descr), &_bytes_written);

    static FIL h3lis331dl_fd;
    res = f_open(&h3lis331dl_fd, "/log/h3lis331dl.csv", FA_WRITE | FA_CREATE_ALWAYS);
    if (res) {
        chprintf(stdout, "error %d opening %s\n", res, "/log/h3lis331dl.csv");
        return -1;
    }
    const char *h3lis331dl_descr = "time,acc_x,acc_y,acc_z\n";
    error |= error || f_write(&h3lis331dl_fd, h3lis331dl_descr, strlen(h3lis331dl_descr), &_bytes_written);

    static FIL ms5611_fd;
    res = f_open(&ms5611_fd, "/log/ms5611.csv", FA_WRITE | FA_CREATE_ALWAYS);
    if (res) {
        chprintf(stdout, "error %d opening %s\n", res, "/log/ms5611.csv");
        return -1;
    }
    const char *ms5611_descr = "time,static_pressure,air_temp\n";
    error |= error || f_write(&ms5611_fd, ms5611_descr, strlen(ms5611_descr), &_bytes_written);

    static FIL analog_fd;
    res = f_open(&analog_fd, "/log/analog.csv", FA_WRITE | FA_CREATE_ALWAYS);
    if (res) {
        chprintf(stdout, "error %d opening %s\n", res, "/log/analog.csv");
        return -1;
    }
    const char *analog_descr = "time,pitot_pressure\n";
    error |= error || f_write(&analog_fd, analog_descr, strlen(analog_descr), &_bytes_written);

    while (!error) {
        eventmask_t events = chEvtWaitAny(EVENT_MASK_MPU6000 | EVENT_MASK_HMC5883L | EVENT_MASK_H3LIS331DL | EVENT_MASK_MS5611 | EVENT_MASK_RC_IN);
        float t = (float)chVTGetSystemTimeX() / CH_CFG_ST_FREQUENCY;

        if (events & EVENT_MASK_MPU6000) {
            chSysLock();
            float gx = mpu_gyro_sample.rate[0];
            float gy = mpu_gyro_sample.rate[1];
            float gz = mpu_gyro_sample.rate[2];
            float ax = mpu_acc_sample.acceleration[0];
            float ay = mpu_acc_sample.acceleration[1];
            float az = mpu_acc_sample.acceleration[2];
            float temp = mpu_temp;
            chSysUnlock();
            msObjectInit(&writebuf_stream, writebuf, sizeof(writebuf), 0);
            chprintf((BaseSequentialStream*)&writebuf_stream,
                      "%f,%f,%f,%f,%f,%f,%f,%f\n", t, gx, gy, gz, ax, ay, az, temp);
            UINT _bytes_written;
            int ret = f_write(&mpu6000_fd, writebuf, writebuf_stream.eos, &_bytes_written);
            // if (ret == 9) {
            //     f_open(&mpu6000_fd, "/log/mpu6000.csv", FA_WRITE);
            //     f_lseek(&mpu6000_fd, f_size(&mpu6000_fd));
            // }
            static int sync_needed = 0;
            sync_needed++;
            if (sync_needed == 100) {
                f_sync(&mpu6000_fd);
                sync_needed = 0;
            }
        }

        if (events & EVENT_MASK_HMC5883L) {
            chSysLock();
            float mx = magnetic_field[0];
            float my = magnetic_field[1];
            float mz = magnetic_field[2];
            chSysUnlock();
            msObjectInit(&writebuf_stream, writebuf, sizeof(writebuf), 0);
            chprintf((BaseSequentialStream*)&writebuf_stream, "%f,%f,%f,%f\n", t, mx, my, mz);
            UINT _bytes_written;
            int ret = f_write(&hmc5883l_fd, writebuf, writebuf_stream.eos, &_bytes_written);
            static int sync_needed = 0;
            sync_needed++;
            if (sync_needed == 100) {
                f_sync(&hmc5883l_fd);
                sync_needed = 0;
            }
        }

        if (events & EVENT_MASK_H3LIS331DL) {
            chSysLock();
            float ax = h3lis331dl_acc_sample.acceleration[0];
            float ay = h3lis331dl_acc_sample.acceleration[1];
            float az = h3lis331dl_acc_sample.acceleration[2];
            chSysUnlock();
            msObjectInit(&writebuf_stream, writebuf, sizeof(writebuf), 0);
            chprintf((BaseSequentialStream*)&writebuf_stream, "%f,%f,%f,%f\n", t, ax, ay, az);
            UINT _bytes_written;
            int ret = f_write(&h3lis331dl_fd, writebuf, writebuf_stream.eos, &_bytes_written);
            static int sync_needed = 0;
            sync_needed++;
            if (sync_needed == 100) {
                f_sync(&h3lis331dl_fd);
                sync_needed = 0;
            }
        }

        if (events & EVENT_MASK_MS5611) {
            chSysLock();
            float baro = static_pressure;
            float temp = air_temp;
            chSysUnlock();
            msObjectInit(&writebuf_stream, writebuf, sizeof(writebuf), 0);
            chprintf((BaseSequentialStream*)&writebuf_stream, "%f,%f,%f\n", t, baro, temp);
            UINT _bytes_written;
            int ret = f_write(&ms5611_fd, writebuf, writebuf_stream.eos, &_bytes_written);
            static int sync_needed = 0;
            sync_needed++;
            if (sync_needed == 100) {
                f_sync(&ms5611_fd);
                sync_needed = 0;
            }
        }

        if (events & EVENT_MASK_RC_IN) {
            static struct rc_input_s rc_in;
            sumd_input_get(&rc_in);
            msObjectInit(&writebuf_stream, writebuf, sizeof(writebuf), 0);
            chprintf((BaseSequentialStream*)&writebuf_stream,
                      "%f,%d,%f,%f,%f,%f,%f\n", t, !rc_in.no_signal, rc_in.channel[0], rc_in.channel[1], rc_in.channel[2], rc_in.channel[3], rc_in.channel[4]);
            UINT _bytes_written;
            int ret = f_write(&rc_fd, writebuf, writebuf_stream.eos, &_bytes_written);
            if (ret != 0) {
                chprintf(stdout, "write failed %d\n", ret);
            }
            static int sync_needed = 0;
            sync_needed++;
            if (sync_needed == 100) {
                f_sync(&rc_fd);
                sync_needed = 0;
            }
        }

        if (events & EVENT_MASK_MPU6000) { // todo
            int32_t adc = analog_get();
            float press = (float)(adc - (1<<15))/(1<<15) * 6000; // [Pa] fs: +- 60mbar
            msObjectInit(&writebuf_stream, writebuf, sizeof(writebuf), 0);
            chprintf((BaseSequentialStream*)&writebuf_stream, "%f,%f\n", t, press);
            UINT _bytes_written;
            int ret = f_write(&analog_fd, writebuf, writebuf_stream.eos, &_bytes_written);
            static int sync_needed = 0;
            sync_needed++;
            if (sync_needed == 100) {
                f_sync(&analog_fd);
                sync_needed = 0;
            }
        }
    }
    return -1;
}

void sdlog_start(void)
{
    chThdCreateStatic(sdlog_wa, sizeof(sdlog_wa), LOWPRIO, sdlog, NULL);
}