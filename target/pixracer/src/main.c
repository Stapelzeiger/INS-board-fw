#include <ch.h>
#include <hal.h>
#include <chprintf.h>
#include <shell.h>
#include <shell_cmd.h>
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

static void cmd_threads(BaseSequentialStream *chp, int argc, char *argv[])
{
    static const char *states[] = {CH_STATE_NAMES};
    thread_t *tp;

    (void)argv;
    if (argc > 0) {
        shellUsage(chp, "threads");
        return;
    }
    chprintf(chp,
             "stklimit    stack     addr refs prio     state       time         name\r\n"SHELL_NEWLINE_STR);
    tp = chRegFirstThread();
    do {
#if (CH_DBG_ENABLE_STACK_CHECK == TRUE) || (CH_CFG_USE_DYNAMIC == TRUE)
        uint32_t stklimit = (uint32_t)tp->wabase;
#else
        uint32_t stklimit = 0U;
#endif
        chprintf(chp, "%08lx %08lx %08lx %4lu %4lu %9s %10lu %12s"SHELL_NEWLINE_STR,
                 stklimit, (uint32_t)tp->ctx.sp, (uint32_t)tp,
                 (uint32_t)tp->refs - 1, (uint32_t)tp->prio, states[tp->state],
                 (uint32_t)tp->time, tp->name == NULL ? "" : tp->name);
        tp = chRegNextThread(tp);
    } while (tp != NULL);
    chprintf(chp, "[sytick %d @ %d Hz]\n", chVTGetSystemTime(), CH_CFG_ST_FREQUENCY);
}

const ShellCommand commands[] = {
    {"threads", cmd_threads},
    {NULL, NULL}
};

static THD_WORKING_AREA(shell_wa, 2048);
static thread_t *shelltp = NULL;

#if (SHELL_USE_HISTORY == TRUE)
char sc_histbuf[256];
#endif
#if (SHELL_USE_COMPLETION == TRUE)
// size = # help + # default commands + # custom commands + 1 for NULL termination
#define SC_COMPLETION_SIZE (sizeof(commands) / sizeof(ShellCommand) + 8)
char *sc_completion[SC_COMPLETION_SIZE];
#endif

static ShellConfig shell_cfg = {
    NULL,
    commands,
#if (SHELL_USE_HISTORY == TRUE)
    sc_histbuf,
    sizeof(sc_histbuf),
#endif
#if (SHELL_USE_COMPLETION == TRUE)
    sc_completion
#endif
};

void shell_spawn(BaseSequentialStream *stream)
{
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

#define TELEM1 (BaseSequentialStream *)&SD2

int main(void)
{
    halInit();
    chSysInit();

    chThdCreateStatic(heartbeat_thread, sizeof(heartbeat_thread),
                      HEARTBEAT_THD_PRIO, heartbeat_main, NULL);


    SerialConfig uart_config = {
        SERIAL_DEFAULT_BITRATE, 0,
        USART_CR2_STOP1_BITS, 0
    };
    uart_config.speed = 57600;
    sdStart(&SD7, &uart_config);
    chprintf((BaseSequentialStream *)&SD7, "\nboot\n");

    // Telemetry 1 serial port
    sdStart(&SD2, &uart_config);

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
        chprintf(TELEM1, "hello world\n");
        chprintf((BaseSequentialStream *)&SD7, "hello world\n");
        shell_spawn((BaseSequentialStream *)&SDU1);
        chThdSleepMilliseconds(1000);
    }
}
