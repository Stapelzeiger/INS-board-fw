#include <ch.h>
#include <hal.h>

#define ADC_MAX         4096

#define ADC_NB_CHANNELS 1
#define DMA_BUFFER_SIZE (128)

static int32_t adc_value;

int32_t analog_get(void)
{
    return adc_value / (DMA_BUFFER_SIZE / 2 / 16);
}

static void adc_callback(ADCDriver *adcp, adcsample_t *adc_samples, size_t n)
{
    (void)adcp;
    uint32_t accumulator = 0;

    int i;
    for (i = 0; i < (int)(n); i++) {
        accumulator += adc_samples[i];
    }

    adc_value = accumulator;
}

static void adcerrorcallback(ADCDriver *adcp, adcerror_t err)
{
    (void)adcp;
    if (err == ADC_ERR_DMAFAILURE) {
        chSysHalt("ADC_ERR_DMAFAILURE");
    }
    if (err == ADC_ERR_OVERFLOW) {
        chSysHalt("ADC_ERR_OVERFLOW");
    }
    chSysHalt("ADC error");
}

static THD_FUNCTION(adc_task, arg)
{
    (void)arg;
    chRegSetThreadName("adc read");

    // uart conn 3 rx pin (PA3)
    palSetPadMode(GPIOA, GPIOA_UART2_RX_CONN3, PAL_MODE_INPUT_ANALOG);

    static adcsample_t adc_samples[ADC_NB_CHANNELS * DMA_BUFFER_SIZE];
    static const ADCConversionGroup adcgrpcfg1 = {
        TRUE,                   // circular
        ADC_NB_CHANNELS,        // nb channels
        adc_callback,           // callback fn
        adcerrorcallback,       // error callback fn
        0,                      // CR1
        ADC_CR2_CONT,           // CR2
        0,
        ADC_SMPR2_SMP_AN0(5),   // SMPR2 : sample time 112 ADC cycles
        ADC_SQR1_NUM_CH(1),     // SQR1
        0,                      // SQR2
        ADC_SQR3_SQ1_N(3)       // SQR3
    };

    adcStart(&ADCD1, NULL);

    adcConvert(&ADCD1, &adcgrpcfg1, adc_samples, DMA_BUFFER_SIZE); // should never return

    return 0;
}

void analog_init(void)
{
    static THD_WORKING_AREA(adc_task_wa, 128);
    chThdCreateStatic(adc_task_wa, sizeof(adc_task_wa), HIGHPRIO, adc_task, NULL);
}
