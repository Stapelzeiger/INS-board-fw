#include <ch.h>
#include <hal.h>
#include <chprintf.h>

#include <string.h>
#include <usbcfg.h>

#include "shell_cmds.h"
#include "sensors/onboardsensors.h"
#include "serial-datagram/serial_datagram.h"
#include "cmp/cmp.h"
#include "cmp_mem_access.h"

BaseSequentialStream* stdout;
SerialUSBDriver SDU1;


/*
 *  Heartbeat, Error LED thread
 *
 * The Heartbeat-LED double-flashes every second in normal mode and continuously
 *  flashes in safemode. If the error level is above NORMAL, the Heartbeat-LED
 *  is off and the Error-LED indicates the error level.
 * If the error level is WARNING, the Error-LED blinks slowly (once per second)
 * If the error level is CRITICAL, the Error-LED blinks rapidly (10 times per second)
 * If a kernel panic occurs the Error-LED is on and all LEDs are off.
 */
static THD_WORKING_AREA(led_task_wa, 128);
static THD_FUNCTION(led_task, arg)
{
    (void)arg;
    chRegSetThreadName("led_task");
    while (1) {
        int err = error_level_get();
        if (err == ERROR_LEVEL_WARNING) {
            palSetPad(GPIOA, GPIOA_LED_ERROR);
            chThdSleepMilliseconds(500);
            palClearPad(GPIOA, GPIOA_LED_ERROR);
            chThdSleepMilliseconds(500);
        } else if (err == ERROR_LEVEL_CRITICAL) {
            palSetPad(GPIOA, GPIOA_LED_ERROR);
            chThdSleepMilliseconds(50);
            palClearPad(GPIOA, GPIOA_LED_ERROR);
            chThdSleepMilliseconds(50);
        } else {
            palSetPad(GPIOA, GPIOA_LED_HEARTBEAT);
            chThdSleepMilliseconds(80);
            palClearPad(GPIOA, GPIOA_LED_HEARTBEAT);
            chThdSleepMilliseconds(80);
            palSetPad(GPIOA, GPIOA_LED_HEARTBEAT);
            chThdSleepMilliseconds(80);
            palClearPad(GPIOA, GPIOA_LED_HEARTBEAT);
            if (safemode_active()) {
                chThdSleepMilliseconds(80);
            } else {
                chThdSleepMilliseconds(760);
            }
        }
    }
    return 0;
}


static void _stream_imu_values_sndfn(void *arg, const void *p, size_t len)
{
    if (len > 0) {
        chSequentialStreamWrite((BaseSequentialStream*)arg, (const uint8_t*)p, len);
    }
}

// not reentrant!
void stream_imu_values(BaseSequentialStream *out)
{
    static char dtgrm[100];
    static cmp_mem_access_t mem;
    static cmp_ctx_t cmp;
    while (1) {
        chSysLock();
        float gx = mpu_gyro_sample.rate[0];
        float gy = mpu_gyro_sample.rate[1];
        float gz = mpu_gyro_sample.rate[2];
        float ax = mpu_acc_sample.acceleration[0];
        float ay = mpu_acc_sample.acceleration[1];
        float az = mpu_acc_sample.acceleration[2];
        chSysUnlock();
        cmp_mem_access_init(&cmp, &mem, dtgrm, sizeof(dtgrm));
        bool err = false;
        err = err || !cmp_write_map(&cmp, 2);
        const char *gyro_id = "gyro";
        err = err || !cmp_write_str(&cmp, gyro_id, strlen(gyro_id));
        err = err || !cmp_write_array(&cmp, 3);
        err = err || !cmp_write_float(&cmp, gx);
        err = err || !cmp_write_float(&cmp, gy);
        err = err || !cmp_write_float(&cmp, gz);
        const char *acc_id = "acc";
        err = err || !cmp_write_str(&cmp, acc_id, strlen(acc_id));
        err = err || !cmp_write_array(&cmp, 3);
        err = err || !cmp_write_float(&cmp, ax);
        err = err || !cmp_write_float(&cmp, ay);
        err = err || !cmp_write_float(&cmp, az);
        if (!err) {
            serial_datagram_send(dtgrm, cmp_mem_access_get_pos(&mem), _stream_imu_values_sndfn, out);
        }
        chThdSleepMilliseconds(10);
    }
}



#include <ff.h>
static FATFS SDC_FS;
bool fatfs_mounted = false;

void sdcard_mount(void)
{
    if (palReadPad(GPIOC, GPIOC_SDCARD_DETECT)) {
        chprintf(stdout, "no SD card detected\n");
        return;
    }
    board_sdcard_pwr_en(true);
    chprintf(stdout, "SD card detected\n");
    sdcStart(&SDCD1, NULL);
    if (sdcConnect(&SDCD1)) {
        chprintf(stdout, "SD card: failed to connect\n");
        return;
    }
    FRESULT err;
    err = f_mount(&SDC_FS, "", 0);
    if (err != FR_OK) {
        chprintf(stdout, "SD card: mount failed\n");
        sdcDisconnect(&SDCD1);
        return;
    }
    fatfs_mounted = true;
    palSetPad(GPIOB, GPIOB_LED_SDCARD);
    chprintf(stdout, "SD card mounted\n");
}


void file_cat(const char *file_path)
{
    if (!fatfs_mounted) {
        return;
    }
    static FIL f;
    FRESULT res = f_open(&f, file_path, FA_READ);
    if (res) {
        chprintf(stdout, "error opening %s\n", file_path);
        return;
    }
    static char line[80];
    while (f_gets(line, sizeof(line), &f)) {
        chprintf(stdout, line);
    }
    f_close(&f);
}


int main(void)
{
    halInit();
    chSysInit();

    chThdCreateStatic(led_task_wa, sizeof(led_task_wa), LOWPRIO, led_task, NULL);

    sdStart(&UART_CONN1, NULL);
    sdStart(&UART_CONN2, NULL);
    sdStart(&UART_CONN3, NULL);
    sdStart(&UART_CONN4, NULL);

    stdout = (BaseSequentialStream*)&UART_CONN1;

    chprintf(stdout, "boot\n");

    // USB Serial Driver
    sduObjectInit(&SDU1);
    sduStart(&SDU1, &serusbcfg);
    usbDisconnectBus(serusbcfg.usbp);
    chThdSleepMilliseconds(100);
    usbStart(serusbcfg.usbp, &usbcfg);
    usbConnectBus(serusbcfg.usbp);

    onboard_sensors_start();

    sdcard_mount();
    file_cat("/test.txt");

    // stream_imu_values((BaseSequentialStream*)&UART_CONN2);

    shell_run((BaseSequentialStream*)&SDU1);

    while (true) {
        chThdSleepMilliseconds(500);
    }
}
