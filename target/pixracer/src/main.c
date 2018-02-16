#include <ch.h>
#include <hal.h>
#include <chprintf.h>
#include <shell.h>
#include "usbcfg.h"

#define HEARTBEAT_THD_PRIO  (LOWPRIO)
#define SHELL_THD_PRIO      (LOWPRIO + 1)

static THD_WORKING_AREA(heartbeat_thread, 128);
static THD_FUNCTION(heartbeat_main, arg)
{
    (void)arg;
    chRegSetThreadName("heartbeat");
    while (true) {
        palClearPad(GPIOB, GPIOB_FMU_LED_GREEN);
        chThdSleepMilliseconds(500);
        palSetPad(GPIOB, GPIOB_FMU_LED_GREEN);
        chThdSleepMilliseconds(500);
    }
}

const ShellCommand commands[] = {
    {NULL, NULL}
};

void shell_spawn(BaseSequentialStream *stream)
{
    static THD_WORKING_AREA(shell_wa, 2048);
    static thread_t *shelltp = NULL;
    static ShellConfig shell_cfg = {
        NULL,
        commands
    };

    if (!shelltp) {
        shell_cfg.sc_channel = stream;
        shelltp = chThdCreateStatic(&shell_wa, sizeof(shell_wa), SHELL_THD_PRIO,
                                    shellThread, (void *)&shell_cfg);
        chRegSetThreadNameX(shelltp, "shell");
    } else if (chThdTerminatedX(shelltp)) {
        chThdRelease(shelltp);    /* Recovers memory of the previous shell.   */
        shelltp = NULL;           /* Triggers spawning of a new shell.        */
    }
}

int main(void)
{
    halInit();
    chSysInit();

    chThdCreateStatic(heartbeat_thread, sizeof(heartbeat_thread),
                      HEARTBEAT_THD_PRIO, heartbeat_main, NULL);


    // Shell manager initialization.
    shellInit();

    // Initializes a serial-over-USB CDC driver.
    sduObjectInit(&SDU1);
    sduStart(&SDU1, &serusbcfg);

    usbDisconnectBus(serusbcfg.usbp);
    chThdSleepMilliseconds(1000);
    usbStart(serusbcfg.usbp, &usbcfg);
    usbConnectBus(serusbcfg.usbp);

    while (true) {
        shell_spawn((BaseSequentialStream *)&SDU1);
        chThdSleepMilliseconds(1000);
    }
}
