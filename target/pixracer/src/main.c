#include <ch.h>
#include <hal.h>
#include <chprintf.h>
#include <shell.h>
#include "usbcfg.h"

static THD_WORKING_AREA(heartbeat_thread, 128);
static THD_FUNCTION(heartbeat_main, arg)
{
    (void)arg;
    chRegSetThreadName("heartbeat");
    while (true) {
        palClearPad(GPIOG, GPIOG_LED4_RED);
        chThdSleepMilliseconds(500);
        palSetPad(GPIOG, GPIOG_LED4_RED);
        chThdSleepMilliseconds(500);
    }
}

int main(void)
{
    halInit();
    chSysInit();

    // // Shell manager initialization.
    // shellInit();

    // Initializes a serial-over-USB CDC driver.
    sduObjectInit(&SDU1);
    sduStart(&SDU1, &serusbcfg);

    usbDisconnectBus(serusbcfg.usbp);
    chThdSleepMilliseconds(1000);
    usbStart(serusbcfg.usbp, &usbcfg);
    usbConnectBus(serusbcfg.usbp);

    chThdCreateStatic(heartbeat_thread, sizeof(heartbeat_thread),
                      LOWPRIO, heartbeat_main, NULL);

    while (true) {
        // if (SDU1.config->usbp->state == USB_ACTIVE) {
        //     thread_t *shelltp = chThdCreateFromHeap(NULL, SHELL_WA_SIZE,
        //                                             "shell", NORMALPRIO + 1,
        //                                             shellThread, (void *)&shell_cfg1);
        //     chThdWait(shelltp);
        // }
        chprintf((BaseSequentialStream *)&SDU1, "hello world\n");
        chThdSleepMilliseconds(1000);
    }
}
