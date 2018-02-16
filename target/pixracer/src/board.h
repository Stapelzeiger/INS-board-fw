/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/*
 * This file has been automatically generated using ChibiStudio board
 * generator plugin. Do not edit manually.
 */

#ifndef BOARD_H
#define BOARD_H

/*
 * Board identifier.
 */
#define BOARD_PIXRACER
#define BOARD_NAME                  "Pixracer"

/*
 * Board oscillators-related settings.
 * NOTE: LSE not fitted.
 */
#if !defined(STM32_LSECLK)
#define STM32_LSECLK                0U
#endif

#define STM32_HSECLK                24000000U

/*
 * Board voltages.
 * Required for performance limits calculation.
 */
#define STM32_VDD                   330U

/*
 * MCU type as defined in the ST header.
 */
#define STM32F427xx

/*
 * IO pins assignments.
 */
#define GPIOA_FMU_USART4_TX         0U
#define GPIOA_FMU_USART4_RX         1U
#define GPIOA_BATT_VOLT_SENS        2U
#define GPIOA_BATT_CURRENT_SENS     3U
#define GPIOA_VDD_5V_SENS           4U // 1/2 * VDD_5V
#define GPIOA_MPU9250_SCK           5U
#define GPIOA_MPU9250_MISO          6U
#define GPIOA_MPU9250_MOSI          7U
#define GPIOA_8266_RTS              8U // GPIOA_USB_SOF
#define GPIOA_VBUS                  9U // GPIOA_USB_VBUS (input, floating)
#define GPIOA_FrSky_INV             10U // GPIOA_USB_ID
#define GPIOA_OTG_FS_DM             11U // GPIOA_USB_DM
#define GPIOA_OTG_FS_DP             12U // GPIOA_USB_DP
#define GPIOA_FMU_SWDIO             13U // GPIOA_JTAG_TMS
#define GPIOA_FMU_SWCLK             14U // GPIOA_JTAG_TCK
#define GPIOA_ALARM                 15U // GPIOA_JTAG_TDI

#define GPIOB_RC_INPUT              0U // GPIO_PPM_IN (AF2, pullup)
#define GPIOB_FMU_LED_GREEN         1U
#define GPIOB_BOOT1                 2U
#define GPIOB_FMU_LED_BLUE          3U
#define GPIOB_8266_GPIO2            4U
#define GPIOB_VDD_BRICK_VALID       5U // 1/2 * VDD_5V_BRICK
#define GPIOB_FMU_USART1_TX         6U
#define GPIOB_FMU_USART1_RX         7U
#define GPIOB_FMU_I2C1_SCL          8U
#define GPIOB_FMU_I2C1_SDA          9U
#define GPIOB_FRAM_SCK              10U
#define GPIOB_FMU_LED_RED           11U
#define GPIOB_CAN2_RX               12U
#define GPIOB_CAN2_TX               13U
#define GPIOB_FRAM_MISO             14U
#define GPIOB_FRAM_MOSI             15U

#define GPIOC_VBUS_VALID            0U // active high
#define GPIOC_RSSI_IN               1U
#define GPIOC_MPU9250_CS            2U
#define GPIOC_LED_SAFETY            3U // active low
#define GPIOC_SAFETY_SWITCH_IN      4U // GPIO_BTN_SAFETY (input pullup)
#define GPIOC_VDD_3V3_PERIPH_EN     5U // GPIO_PERIPH_3V3_EN active high
#define GPIOC_NC                    6U
#define GPIOC_FMU_RC_INPUT          7U
#define GPIOC_SDIO_D0               8U
#define GPIOC_SDIO_D1               9U
#define GPIOC_SDIO_D2               10U
#define GPIOC_SDIO_D3               11U
#define GPIOC_SDIO_CK               12U
#define GPIOC_SBUS_INV              13U
#define GPIOC_20608_DRDY            14U // GPIO_DRDY_ICM_20608_G active low (input, pullup, exti)
#define GPIOC_20608_CS              15U

#define GPIOD_CAN1_RX               0U
#define GPIOD_CAN1_TX               1U
#define GPIOD_SDIO_CMD              2U
#define GPIOD_FMU_USART2_CTS        3U
#define GPIOD_FMU_USART2_RTS        4U
#define GPIOD_FMU_USART2_TX         5U
#define GPIOD_FMU_USART2_RX         6U
#define GPIOD_BARO_CS               7U
#define GPIOD_FMU_USART3_TX         8U
#define GPIOD_FMU_USART3_RX         9U
#define GPIOD_FRAM_CS               10U
#define GPIOD_FMU_USART3_CTS        11U
#define GPIOD_FMU_USART3_RTS        12U
#define GPIOD_FMU_CH5               13U // PWM, GPIO_TIM4_CH2OUT (AF2, pushpull)
#define GPIOD_FMU_CH6               14U // PWM, GPIO_TIM4_CH3OUT (AF2, pushpull)
#define GPIOD_MPU9250_DRDY          15U // GPIO_DRDY_MPU9250 (input, floating, exti)

#define GPIOE_FMU_USART8_RX         0U
#define GPIOE_FMU_USART8_TX         1U
#define GPIOE_8266_GPIO0            2U
#define GPIOE_VDD_3V3_SENSORS_EN    3U // active high
#define GPIOE_SPEKTRUM_POWER        4U // active low
#define GPIOE_8266_PD               5U
#define GPIOE_8266_RST              6U
#define GPIOE_FMU_UART7_RX          7U // DEBUG_UART_RX (AF8)
#define GPIOE_FMU_UART7_TX          8U // DEBUG_UART_TX (AF8)
#define GPIOE_FMU_CH4               9U // PWM, GPIO_TIM1_CH1OUT (AF1, pushpull)
#define GPIOE_8266_CTS              10U
#define GPIOE_FMU_CH3               11U // PWM, GPIO_TIM1_CH2OUT (AF1, pushpull)
#define GPIOE_HMC5983_DRDY          12U // GPIO_DRDY_HMC5983 (input, floating, exti)
#define GPIOE_FMU_CH2               13U // PWM, GPIO_TIM1_CH3OUT (AF1, pushpull)
#define GPIOE_FMU_CH1               14U // PWM, GPIO_TIM1_CH4OUT (AF1, pushpull)
#define GPIOE_HMC5983_CS            15U

#define GPIOH_OSC_IN                0U
#define GPIOH_OSC_OUT               1U

/*
 * IO lines assignments.
 */
#define LINE_LED_RED                PAL_LINE(GPIOB, GPIOB_FMU_LED_RED)
#define LINE_LED1                   LINE_LED_RED
#define LINE_LED_GREEN              PAL_LINE(GPIOB, GPIOB_FMU_LED_GREEN)
#define LINE_LED2                   LINE_LED_GREEN
#define LINE_LED_BLUE               PAL_LINE(GPIOB, GPIOB_FMU_LED_BLUE)
#define LINE_LED3                   LINE_LED_BLUE
#define LINE_LED_SAFETY             PAL_LINE(GPIOC, GPIOC_LED_SAFETY)

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the STM32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n)           (0U << ((n) * 2U))
#define PIN_MODE_OUTPUT(n)          (1U << ((n) * 2U))
#define PIN_MODE_ALTERNATE(n)       (2U << ((n) * 2U))
#define PIN_MODE_ANALOG(n)          (3U << ((n) * 2U))
#define PIN_ODR_LOW(n)              (0U << (n))
#define PIN_ODR_HIGH(n)             (1U << (n))
#define PIN_OTYPE_PUSHPULL(n)       (0U << (n))
#define PIN_OTYPE_OPENDRAIN(n)      (1U << (n))
#define PIN_OSPEED_VERYLOW(n)       (0U << ((n) * 2U))
#define PIN_OSPEED_LOW(n)           (1U << ((n) * 2U))
#define PIN_OSPEED_MEDIUM(n)        (2U << ((n) * 2U))
#define PIN_OSPEED_HIGH(n)          (3U << ((n) * 2U))
#define PIN_PUPDR_FLOATING(n)       (0U << ((n) * 2U))
#define PIN_PUPDR_PULLUP(n)         (1U << ((n) * 2U))
#define PIN_PUPDR_PULLDOWN(n)       (2U << ((n) * 2U))
#define PIN_AFIO_AF(n, v)           ((v) << (((n) % 8U) * 4U))

/*
 * GPIOA setup:
 */
#define VAL_GPIOA_MODER             (PIN_MODE_INPUT(GPIOA_FMU_USART4_TX) | \
                                     PIN_MODE_INPUT(GPIOA_FMU_USART4_RX) | \
                                     PIN_MODE_INPUT(GPIOA_BATT_VOLT_SENS) | \
                                     PIN_MODE_INPUT(GPIOA_BATT_CURRENT_SENS) | \
                                     PIN_MODE_ANALOG(GPIOA_VDD_5V_SENS) | \
                                     PIN_MODE_INPUT(GPIOA_MPU9250_SCK) | \
                                     PIN_MODE_INPUT(GPIOA_MPU9250_MISO) | \
                                     PIN_MODE_INPUT(GPIOA_MPU9250_MOSI) | \
                                     PIN_MODE_INPUT(GPIOA_8266_RTS) | \
                                     PIN_MODE_INPUT(GPIOA_VBUS) | \
                                     PIN_MODE_INPUT(GPIOA_FrSky_INV) | \
                                     PIN_MODE_ALTERNATE(GPIOA_OTG_FS_DM) | \
                                     PIN_MODE_ALTERNATE(GPIOA_OTG_FS_DP) | \
                                     PIN_MODE_ALTERNATE(GPIOA_FMU_SWDIO) | \
                                     PIN_MODE_ALTERNATE(GPIOA_FMU_SWCLK) | \
                                     PIN_MODE_OUTPUT(GPIOA_ALARM))
#define VAL_GPIOA_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOA_FMU_USART4_TX) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_FMU_USART4_RX) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_BATT_VOLT_SENS) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_BATT_CURRENT_SENS) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_VDD_5V_SENS) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_MPU9250_SCK) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_MPU9250_MISO) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_MPU9250_MOSI) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_8266_RTS) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_VBUS) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_FrSky_INV) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_OTG_FS_DM) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_OTG_FS_DP) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_FMU_SWDIO) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_FMU_SWCLK) | \
                                     PIN_OTYPE_PUSHPULL(GPIOA_ALARM))
#define VAL_GPIOA_OSPEEDR           (PIN_OSPEED_HIGH(GPIOA_FMU_USART4_TX) | \
                                     PIN_OSPEED_HIGH(GPIOA_FMU_USART4_RX) | \
                                     PIN_OSPEED_HIGH(GPIOA_BATT_VOLT_SENS) | \
                                     PIN_OSPEED_HIGH(GPIOA_BATT_CURRENT_SENS) | \
                                     PIN_OSPEED_HIGH(GPIOA_VDD_5V_SENS) | \
                                     PIN_OSPEED_HIGH(GPIOA_MPU9250_SCK) | \
                                     PIN_OSPEED_HIGH(GPIOA_MPU9250_MISO) | \
                                     PIN_OSPEED_HIGH(GPIOA_MPU9250_MOSI) | \
                                     PIN_OSPEED_HIGH(GPIOA_8266_RTS) | \
                                     PIN_OSPEED_HIGH(GPIOA_VBUS) | \
                                     PIN_OSPEED_HIGH(GPIOA_FrSky_INV) | \
                                     PIN_OSPEED_HIGH(GPIOA_OTG_FS_DM) | \
                                     PIN_OSPEED_HIGH(GPIOA_OTG_FS_DP) | \
                                     PIN_OSPEED_HIGH(GPIOA_FMU_SWDIO) | \
                                     PIN_OSPEED_HIGH(GPIOA_FMU_SWCLK) | \
                                     PIN_OSPEED_HIGH(GPIOA_ALARM))
#define VAL_GPIOA_PUPDR             (PIN_PUPDR_PULLDOWN(GPIOA_FMU_USART4_TX) | \
                                     PIN_PUPDR_PULLDOWN(GPIOA_FMU_USART4_RX) | \
                                     PIN_PUPDR_PULLDOWN(GPIOA_BATT_VOLT_SENS) | \
                                     PIN_PUPDR_PULLDOWN(GPIOA_BATT_CURRENT_SENS) | \
                                     PIN_PUPDR_FLOATING(GPIOA_VDD_5V_SENS) | \
                                     PIN_PUPDR_PULLDOWN(GPIOA_MPU9250_SCK) | \
                                     PIN_PUPDR_PULLDOWN(GPIOA_MPU9250_MISO) | \
                                     PIN_PUPDR_PULLDOWN(GPIOA_MPU9250_MOSI) | \
                                     PIN_PUPDR_PULLDOWN(GPIOA_8266_RTS) | \
                                     PIN_PUPDR_FLOATING(GPIOA_VBUS) | \
                                     PIN_PUPDR_PULLDOWN(GPIOA_FrSky_INV) | \
                                     PIN_PUPDR_FLOATING(GPIOA_OTG_FS_DM) | \
                                     PIN_PUPDR_FLOATING(GPIOA_OTG_FS_DP) | \
                                     PIN_PUPDR_PULLUP(GPIOA_FMU_SWDIO) | \
                                     PIN_PUPDR_PULLDOWN(GPIOA_FMU_SWCLK) | \
                                     PIN_PUPDR_FLOATING(GPIOA_ALARM))
#define VAL_GPIOA_ODR               (PIN_ODR_LOW(GPIOA_FMU_USART4_TX) | \
                                     PIN_ODR_LOW(GPIOA_FMU_USART4_RX) | \
                                     PIN_ODR_LOW(GPIOA_BATT_VOLT_SENS) | \
                                     PIN_ODR_LOW(GPIOA_BATT_CURRENT_SENS) | \
                                     PIN_ODR_LOW(GPIOA_VDD_5V_SENS) | \
                                     PIN_ODR_LOW(GPIOA_MPU9250_SCK) | \
                                     PIN_ODR_LOW(GPIOA_MPU9250_MISO) | \
                                     PIN_ODR_LOW(GPIOA_MPU9250_MOSI) | \
                                     PIN_ODR_LOW(GPIOA_8266_RTS) | \
                                     PIN_ODR_LOW(GPIOA_VBUS) | \
                                     PIN_ODR_LOW(GPIOA_FrSky_INV) | \
                                     PIN_ODR_LOW(GPIOA_OTG_FS_DM) | \
                                     PIN_ODR_LOW(GPIOA_OTG_FS_DP) | \
                                     PIN_ODR_LOW(GPIOA_FMU_SWDIO) | \
                                     PIN_ODR_LOW(GPIOA_FMU_SWCLK) | \
                                     PIN_ODR_LOW(GPIOA_ALARM))
#define VAL_GPIOA_AFRL              (PIN_AFIO_AF(GPIOA_FMU_USART4_TX, 0U) | \
                                     PIN_AFIO_AF(GPIOA_FMU_USART4_RX, 0U) | \
                                     PIN_AFIO_AF(GPIOA_BATT_VOLT_SENS, 0U) | \
                                     PIN_AFIO_AF(GPIOA_BATT_CURRENT_SENS, 0U) | \
                                     PIN_AFIO_AF(GPIOA_VDD_5V_SENS, 0U) | \
                                     PIN_AFIO_AF(GPIOA_MPU9250_SCK, 0U) | \
                                     PIN_AFIO_AF(GPIOA_MPU9250_MISO, 0U) | \
                                     PIN_AFIO_AF(GPIOA_MPU9250_MOSI, 0U))
#define VAL_GPIOA_AFRH              (PIN_AFIO_AF(GPIOA_8266_RTS, 0U) | \
                                     PIN_AFIO_AF(GPIOA_VBUS, 0U) | \
                                     PIN_AFIO_AF(GPIOA_FrSky_INV, 0U) | \
                                     PIN_AFIO_AF(GPIOA_OTG_FS_DM, 10U) | \
                                     PIN_AFIO_AF(GPIOA_OTG_FS_DP, 10U) | \
                                     PIN_AFIO_AF(GPIOA_FMU_SWDIO, 0U) | \
                                     PIN_AFIO_AF(GPIOA_FMU_SWCLK, 0U) | \
                                     PIN_AFIO_AF(GPIOA_ALARM, 0U))

/*
 * GPIOB setup:
 */
#define VAL_GPIOB_MODER             (PIN_MODE_INPUT(GPIOB_RC_INPUT) | \
                                     PIN_MODE_OUTPUT(GPIOB_FMU_LED_GREEN) | \
                                     PIN_MODE_INPUT(GPIOB_BOOT1) | \
                                     PIN_MODE_OUTPUT(GPIOB_FMU_LED_BLUE) | \
                                     PIN_MODE_INPUT(GPIOB_8266_GPIO2) | \
                                     PIN_MODE_ANALOG(GPIOB_VDD_BRICK_VALID) | \
                                     PIN_MODE_INPUT(GPIOB_FMU_USART1_TX) | \
                                     PIN_MODE_INPUT(GPIOB_FMU_USART1_RX) | \
                                     PIN_MODE_INPUT(GPIOB_FMU_I2C1_SCL) | \
                                     PIN_MODE_INPUT(GPIOB_FMU_I2C1_SDA) | \
                                     PIN_MODE_INPUT(GPIOB_FRAM_SCK) | \
                                     PIN_MODE_OUTPUT(GPIOB_FMU_LED_RED) | \
                                     PIN_MODE_INPUT(GPIOB_CAN2_RX) | \
                                     PIN_MODE_INPUT(GPIOB_CAN2_TX) | \
                                     PIN_MODE_INPUT(GPIOB_FRAM_MISO) | \
                                     PIN_MODE_INPUT(GPIOB_FRAM_MOSI))
#define VAL_GPIOB_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOB_RC_INPUT) | \
                                     PIN_OTYPE_OPENDRAIN(GPIOB_FMU_LED_GREEN) | \
                                     PIN_OTYPE_PUSHPULL(GPIOB_BOOT1) | \
                                     PIN_OTYPE_OPENDRAIN(GPIOB_FMU_LED_BLUE) | \
                                     PIN_OTYPE_PUSHPULL(GPIOB_8266_GPIO2) | \
                                     PIN_OTYPE_PUSHPULL(GPIOB_VDD_BRICK_VALID) | \
                                     PIN_OTYPE_PUSHPULL(GPIOB_FMU_USART1_TX) | \
                                     PIN_OTYPE_PUSHPULL(GPIOB_FMU_USART1_RX) | \
                                     PIN_OTYPE_PUSHPULL(GPIOB_FMU_I2C1_SCL) | \
                                     PIN_OTYPE_PUSHPULL(GPIOB_FMU_I2C1_SDA) | \
                                     PIN_OTYPE_PUSHPULL(GPIOB_FRAM_SCK) | \
                                     PIN_OTYPE_OPENDRAIN(GPIOB_FMU_LED_RED) | \
                                     PIN_OTYPE_PUSHPULL(GPIOB_CAN2_RX) | \
                                     PIN_OTYPE_PUSHPULL(GPIOB_CAN2_TX) | \
                                     PIN_OTYPE_PUSHPULL(GPIOB_FRAM_MISO) | \
                                     PIN_OTYPE_PUSHPULL(GPIOB_FRAM_MOSI))
#define VAL_GPIOB_OSPEEDR           (PIN_OSPEED_HIGH(GPIOB_RC_INPUT) | \
                                     PIN_OSPEED_VERYLOW(GPIOB_FMU_LED_GREEN) | \
                                     PIN_OSPEED_HIGH(GPIOB_BOOT1) | \
                                     PIN_OSPEED_VERYLOW(GPIOB_FMU_LED_BLUE) | \
                                     PIN_OSPEED_HIGH(GPIOB_8266_GPIO2) | \
                                     PIN_OSPEED_HIGH(GPIOB_VDD_BRICK_VALID) | \
                                     PIN_OSPEED_HIGH(GPIOB_FMU_USART1_TX) | \
                                     PIN_OSPEED_HIGH(GPIOB_FMU_USART1_RX) | \
                                     PIN_OSPEED_HIGH(GPIOB_FMU_I2C1_SCL) | \
                                     PIN_OSPEED_HIGH(GPIOB_FMU_I2C1_SDA) | \
                                     PIN_OSPEED_HIGH(GPIOB_FRAM_SCK) | \
                                     PIN_OSPEED_VERYLOW(GPIOB_FMU_LED_RED) | \
                                     PIN_OSPEED_HIGH(GPIOB_CAN2_RX) | \
                                     PIN_OSPEED_HIGH(GPIOB_CAN2_TX) | \
                                     PIN_OSPEED_HIGH(GPIOB_FRAM_MISO) | \
                                     PIN_OSPEED_HIGH(GPIOB_FRAM_MOSI))
#define VAL_GPIOB_PUPDR             (PIN_PUPDR_PULLDOWN(GPIOB_RC_INPUT) | \
                                     PIN_PUPDR_FLOATING(GPIOB_FMU_LED_GREEN) | \
                                     PIN_PUPDR_PULLDOWN(GPIOB_BOOT1) | \
                                     PIN_PUPDR_FLOATING(GPIOB_FMU_LED_BLUE) | \
                                     PIN_PUPDR_PULLDOWN(GPIOB_8266_GPIO2) | \
                                     PIN_PUPDR_FLOATING(GPIOB_VDD_BRICK_VALID) | \
                                     PIN_PUPDR_PULLDOWN(GPIOB_FMU_USART1_TX) | \
                                     PIN_PUPDR_PULLDOWN(GPIOB_FMU_USART1_RX) | \
                                     PIN_PUPDR_PULLDOWN(GPIOB_FMU_I2C1_SCL) | \
                                     PIN_PUPDR_PULLDOWN(GPIOB_FMU_I2C1_SDA) | \
                                     PIN_PUPDR_PULLDOWN(GPIOB_FRAM_SCK) | \
                                     PIN_PUPDR_FLOATING(GPIOB_FMU_LED_RED) | \
                                     PIN_PUPDR_PULLDOWN(GPIOB_CAN2_RX) | \
                                     PIN_PUPDR_PULLDOWN(GPIOB_CAN2_TX) | \
                                     PIN_PUPDR_PULLDOWN(GPIOB_FRAM_MISO) | \
                                     PIN_PUPDR_PULLDOWN(GPIOB_FRAM_MOSI))
#define VAL_GPIOB_ODR               (PIN_ODR_LOW(GPIOB_RC_INPUT) | \
                                     PIN_ODR_LOW(GPIOB_FMU_LED_GREEN) | \
                                     PIN_ODR_LOW(GPIOB_BOOT1) | \
                                     PIN_ODR_LOW(GPIOB_FMU_LED_BLUE) | \
                                     PIN_ODR_LOW(GPIOB_8266_GPIO2) | \
                                     PIN_ODR_LOW(GPIOB_VDD_BRICK_VALID) | \
                                     PIN_ODR_LOW(GPIOB_FMU_USART1_TX) | \
                                     PIN_ODR_LOW(GPIOB_FMU_USART1_RX) | \
                                     PIN_ODR_LOW(GPIOB_FMU_I2C1_SCL) | \
                                     PIN_ODR_LOW(GPIOB_FMU_I2C1_SDA) | \
                                     PIN_ODR_LOW(GPIOB_FRAM_SCK) | \
                                     PIN_ODR_LOW(GPIOB_FMU_LED_RED) | \
                                     PIN_ODR_LOW(GPIOB_CAN2_RX) | \
                                     PIN_ODR_LOW(GPIOB_CAN2_TX) | \
                                     PIN_ODR_LOW(GPIOB_FRAM_MISO) | \
                                     PIN_ODR_LOW(GPIOB_FRAM_MOSI))
#define VAL_GPIOB_AFRL              (PIN_AFIO_AF(GPIOB_RC_INPUT, 0U) | \
                                     PIN_AFIO_AF(GPIOB_FMU_LED_GREEN, 0U) | \
                                     PIN_AFIO_AF(GPIOB_BOOT1, 0U) | \
                                     PIN_AFIO_AF(GPIOB_FMU_LED_BLUE, 0U) | \
                                     PIN_AFIO_AF(GPIOB_8266_GPIO2, 0U) | \
                                     PIN_AFIO_AF(GPIOB_VDD_BRICK_VALID, 0U) | \
                                     PIN_AFIO_AF(GPIOB_FMU_USART1_TX, 0U) | \
                                     PIN_AFIO_AF(GPIOB_FMU_USART1_RX, 0U))
#define VAL_GPIOB_AFRH              (PIN_AFIO_AF(GPIOB_FMU_I2C1_SCL, 0U) | \
                                     PIN_AFIO_AF(GPIOB_FMU_I2C1_SDA, 0U) | \
                                     PIN_AFIO_AF(GPIOB_FRAM_SCK, 0U) | \
                                     PIN_AFIO_AF(GPIOB_FMU_LED_RED, 0U) | \
                                     PIN_AFIO_AF(GPIOB_CAN2_RX, 0U) | \
                                     PIN_AFIO_AF(GPIOB_CAN2_TX, 0U) | \
                                     PIN_AFIO_AF(GPIOB_FRAM_MISO, 0U) | \
                                     PIN_AFIO_AF(GPIOB_FRAM_MOSI, 0U))

/*
 * GPIOC setup:
 */
#define VAL_GPIOC_MODER             (PIN_MODE_INPUT(GPIOC_VBUS_VALID) | \
                                     PIN_MODE_INPUT(GPIOC_RSSI_IN) | \
                                     PIN_MODE_INPUT(GPIOC_MPU9250_CS) | \
                                     PIN_MODE_OUTPUT(GPIOC_LED_SAFETY) | \
                                     PIN_MODE_INPUT(GPIOC_SAFETY_SWITCH_IN) | \
                                     PIN_MODE_OUTPUT(GPIOC_VDD_3V3_PERIPH_EN) | \
                                     PIN_MODE_INPUT(GPIOC_NC) | \
                                     PIN_MODE_INPUT(GPIOC_FMU_RC_INPUT) | \
                                     PIN_MODE_INPUT(GPIOC_SDIO_D0) | \
                                     PIN_MODE_INPUT(GPIOC_SDIO_D1) | \
                                     PIN_MODE_INPUT(GPIOC_SDIO_D2) | \
                                     PIN_MODE_INPUT(GPIOC_SDIO_D3) | \
                                     PIN_MODE_INPUT(GPIOC_SDIO_CK) | \
                                     PIN_MODE_INPUT(GPIOC_SBUS_INV) | \
                                     PIN_MODE_INPUT(GPIOC_20608_DRDY) | \
                                     PIN_MODE_INPUT(GPIOC_20608_CS))
#define VAL_GPIOC_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOC_VBUS_VALID) | \
                                     PIN_OTYPE_PUSHPULL(GPIOC_RSSI_IN) | \
                                     PIN_OTYPE_PUSHPULL(GPIOC_MPU9250_CS) | \
                                     PIN_OTYPE_PUSHPULL(GPIOC_LED_SAFETY) | \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SAFETY_SWITCH_IN) | \
                                     PIN_OTYPE_PUSHPULL(GPIOC_VDD_3V3_PERIPH_EN) | \
                                     PIN_OTYPE_PUSHPULL(GPIOC_NC) | \
                                     PIN_OTYPE_PUSHPULL(GPIOC_FMU_RC_INPUT) | \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SDIO_D0) | \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SDIO_D1) | \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SDIO_D2) | \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SDIO_D3) | \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SDIO_CK) | \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SBUS_INV) | \
                                     PIN_OTYPE_PUSHPULL(GPIOC_20608_DRDY) | \
                                     PIN_OTYPE_PUSHPULL(GPIOC_20608_CS))
#define VAL_GPIOC_OSPEEDR           (PIN_OSPEED_HIGH(GPIOC_VBUS_VALID) | \
                                     PIN_OSPEED_HIGH(GPIOC_RSSI_IN) | \
                                     PIN_OSPEED_HIGH(GPIOC_MPU9250_CS) | \
                                     PIN_OSPEED_HIGH(GPIOC_LED_SAFETY) | \
                                     PIN_OSPEED_HIGH(GPIOC_SAFETY_SWITCH_IN) | \
                                     PIN_OSPEED_HIGH(GPIOC_VDD_3V3_PERIPH_EN) | \
                                     PIN_OSPEED_HIGH(GPIOC_NC) | \
                                     PIN_OSPEED_HIGH(GPIOC_FMU_RC_INPUT) | \
                                     PIN_OSPEED_HIGH(GPIOC_SDIO_D0) | \
                                     PIN_OSPEED_HIGH(GPIOC_SDIO_D1) | \
                                     PIN_OSPEED_HIGH(GPIOC_SDIO_D2) | \
                                     PIN_OSPEED_HIGH(GPIOC_SDIO_D3) | \
                                     PIN_OSPEED_HIGH(GPIOC_SDIO_CK) | \
                                     PIN_OSPEED_HIGH(GPIOC_SBUS_INV) | \
                                     PIN_OSPEED_HIGH(GPIOC_20608_DRDY) | \
                                     PIN_OSPEED_HIGH(GPIOC_20608_CS))
#define VAL_GPIOC_PUPDR             (PIN_PUPDR_PULLDOWN(GPIOC_VBUS_VALID) | \
                                     PIN_PUPDR_PULLDOWN(GPIOC_RSSI_IN) | \
                                     PIN_PUPDR_PULLDOWN(GPIOC_MPU9250_CS) | \
                                     PIN_PUPDR_FLOATING(GPIOC_LED_SAFETY) | \
                                     PIN_PUPDR_PULLUP(GPIOC_SAFETY_SWITCH_IN) | \
                                     PIN_PUPDR_FLOATING(GPIOC_VDD_3V3_PERIPH_EN) | \
                                     PIN_PUPDR_PULLDOWN(GPIOC_NC) | \
                                     PIN_PUPDR_PULLDOWN(GPIOC_FMU_RC_INPUT) | \
                                     PIN_PUPDR_PULLDOWN(GPIOC_SDIO_D0) | \
                                     PIN_PUPDR_PULLDOWN(GPIOC_SDIO_D1) | \
                                     PIN_PUPDR_PULLDOWN(GPIOC_SDIO_D2) | \
                                     PIN_PUPDR_PULLDOWN(GPIOC_SDIO_D3) | \
                                     PIN_PUPDR_PULLDOWN(GPIOC_SDIO_CK) | \
                                     PIN_PUPDR_PULLDOWN(GPIOC_SBUS_INV) | \
                                     PIN_PUPDR_PULLUP(GPIOC_20608_DRDY) | \
                                     PIN_PUPDR_PULLDOWN(GPIOC_20608_CS))
#define VAL_GPIOC_ODR               (PIN_ODR_LOW(GPIOC_VBUS_VALID) | \
                                     PIN_ODR_LOW(GPIOC_RSSI_IN) | \
                                     PIN_ODR_LOW(GPIOC_MPU9250_CS) | \
                                     PIN_ODR_LOW(GPIOC_LED_SAFETY) | \
                                     PIN_ODR_LOW(GPIOC_SAFETY_SWITCH_IN) | \
                                     PIN_ODR_LOW(GPIOC_VDD_3V3_PERIPH_EN) | \
                                     PIN_ODR_LOW(GPIOC_NC) | \
                                     PIN_ODR_LOW(GPIOC_FMU_RC_INPUT) | \
                                     PIN_ODR_LOW(GPIOC_SDIO_D0) | \
                                     PIN_ODR_LOW(GPIOC_SDIO_D1) | \
                                     PIN_ODR_LOW(GPIOC_SDIO_D2) | \
                                     PIN_ODR_LOW(GPIOC_SDIO_D3) | \
                                     PIN_ODR_LOW(GPIOC_SDIO_CK) | \
                                     PIN_ODR_LOW(GPIOC_SBUS_INV) | \
                                     PIN_ODR_LOW(GPIOC_20608_DRDY) | \
                                     PIN_ODR_LOW(GPIOC_20608_CS))
#define VAL_GPIOC_AFRL              (PIN_AFIO_AF(GPIOC_VBUS_VALID, 0U) | \
                                     PIN_AFIO_AF(GPIOC_RSSI_IN, 0U) | \
                                     PIN_AFIO_AF(GPIOC_MPU9250_CS, 0U) | \
                                     PIN_AFIO_AF(GPIOC_LED_SAFETY, 0U) | \
                                     PIN_AFIO_AF(GPIOC_SAFETY_SWITCH_IN, 0U) | \
                                     PIN_AFIO_AF(GPIOC_VDD_3V3_PERIPH_EN, 0U) | \
                                     PIN_AFIO_AF(GPIOC_NC, 0U) | \
                                     PIN_AFIO_AF(GPIOC_FMU_RC_INPUT, 0U))
#define VAL_GPIOC_AFRH              (PIN_AFIO_AF(GPIOC_SDIO_D0, 0U) | \
                                     PIN_AFIO_AF(GPIOC_SDIO_D1, 0U) | \
                                     PIN_AFIO_AF(GPIOC_SDIO_D2, 0U) | \
                                     PIN_AFIO_AF(GPIOC_SDIO_D3, 0U) | \
                                     PIN_AFIO_AF(GPIOC_SDIO_CK, 0U) | \
                                     PIN_AFIO_AF(GPIOC_SBUS_INV, 0U) | \
                                     PIN_AFIO_AF(GPIOC_20608_DRDY, 0U) | \
                                     PIN_AFIO_AF(GPIOC_20608_CS, 0U))

/*
 * GPIOD setup:
 */
#define VAL_GPIOD_MODER             (PIN_MODE_INPUT(GPIOD_CAN1_RX) | \
                                     PIN_MODE_INPUT(GPIOD_CAN1_TX) | \
                                     PIN_MODE_INPUT(GPIOD_SDIO_CMD) | \
                                     PIN_MODE_INPUT(GPIOD_FMU_USART2_CTS) | \
                                     PIN_MODE_INPUT(GPIOD_FMU_USART2_RTS) | \
                                     PIN_MODE_ALTERNATE(GPIOD_FMU_USART2_TX) | \
                                     PIN_MODE_ALTERNATE(GPIOD_FMU_USART2_RX) | \
                                     PIN_MODE_INPUT(GPIOD_BARO_CS) | \
                                     PIN_MODE_INPUT(GPIOD_FMU_USART3_TX) | \
                                     PIN_MODE_INPUT(GPIOD_FMU_USART3_RX) | \
                                     PIN_MODE_INPUT(GPIOD_FRAM_CS) | \
                                     PIN_MODE_INPUT(GPIOD_FMU_USART3_CTS) | \
                                     PIN_MODE_INPUT(GPIOD_FMU_USART3_RTS) | \
                                     PIN_MODE_INPUT(GPIOD_FMU_CH5) | \
                                     PIN_MODE_INPUT(GPIOD_FMU_CH6) | \
                                     PIN_MODE_INPUT(GPIOD_MPU9250_DRDY))
#define VAL_GPIOD_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOD_CAN1_RX) | \
                                     PIN_OTYPE_PUSHPULL(GPIOD_CAN1_TX) | \
                                     PIN_OTYPE_PUSHPULL(GPIOD_SDIO_CMD) | \
                                     PIN_OTYPE_PUSHPULL(GPIOD_FMU_USART2_CTS) | \
                                     PIN_OTYPE_PUSHPULL(GPIOD_FMU_USART2_RTS) | \
                                     PIN_OTYPE_PUSHPULL(GPIOD_FMU_USART2_TX) | \
                                     PIN_OTYPE_PUSHPULL(GPIOD_FMU_USART2_RX) | \
                                     PIN_OTYPE_PUSHPULL(GPIOD_BARO_CS) | \
                                     PIN_OTYPE_PUSHPULL(GPIOD_FMU_USART3_TX) | \
                                     PIN_OTYPE_PUSHPULL(GPIOD_FMU_USART3_RX) | \
                                     PIN_OTYPE_PUSHPULL(GPIOD_FRAM_CS) | \
                                     PIN_OTYPE_PUSHPULL(GPIOD_FMU_USART3_CTS) | \
                                     PIN_OTYPE_PUSHPULL(GPIOD_FMU_USART3_RTS) | \
                                     PIN_OTYPE_PUSHPULL(GPIOD_FMU_CH5) | \
                                     PIN_OTYPE_PUSHPULL(GPIOD_FMU_CH6) | \
                                     PIN_OTYPE_PUSHPULL(GPIOD_MPU9250_DRDY))
#define VAL_GPIOD_OSPEEDR           (PIN_OSPEED_HIGH(GPIOD_CAN1_RX) | \
                                     PIN_OSPEED_HIGH(GPIOD_CAN1_TX) | \
                                     PIN_OSPEED_HIGH(GPIOD_SDIO_CMD) | \
                                     PIN_OSPEED_HIGH(GPIOD_FMU_USART2_CTS) | \
                                     PIN_OSPEED_HIGH(GPIOD_FMU_USART2_RTS) | \
                                     PIN_OSPEED_HIGH(GPIOD_FMU_USART2_TX) | \
                                     PIN_OSPEED_HIGH(GPIOD_FMU_USART2_RX) | \
                                     PIN_OSPEED_HIGH(GPIOD_BARO_CS) | \
                                     PIN_OSPEED_HIGH(GPIOD_FMU_USART3_TX) | \
                                     PIN_OSPEED_HIGH(GPIOD_FMU_USART3_RX) | \
                                     PIN_OSPEED_HIGH(GPIOD_FRAM_CS) | \
                                     PIN_OSPEED_HIGH(GPIOD_FMU_USART3_CTS) | \
                                     PIN_OSPEED_HIGH(GPIOD_FMU_USART3_RTS) | \
                                     PIN_OSPEED_HIGH(GPIOD_FMU_CH5) | \
                                     PIN_OSPEED_HIGH(GPIOD_FMU_CH6) | \
                                     PIN_OSPEED_HIGH(GPIOD_MPU9250_DRDY))
#define VAL_GPIOD_PUPDR             (PIN_PUPDR_PULLDOWN(GPIOD_CAN1_RX) | \
                                     PIN_PUPDR_PULLDOWN(GPIOD_CAN1_TX) | \
                                     PIN_PUPDR_PULLDOWN(GPIOD_SDIO_CMD) | \
                                     PIN_PUPDR_PULLDOWN(GPIOD_FMU_USART2_CTS) | \
                                     PIN_PUPDR_PULLDOWN(GPIOD_FMU_USART2_RTS) | \
                                     PIN_PUPDR_PULLDOWN(GPIOD_FMU_USART2_TX) | \
                                     PIN_PUPDR_PULLDOWN(GPIOD_FMU_USART2_RX) | \
                                     PIN_PUPDR_PULLDOWN(GPIOD_BARO_CS) | \
                                     PIN_PUPDR_PULLDOWN(GPIOD_FMU_USART3_TX) | \
                                     PIN_PUPDR_PULLDOWN(GPIOD_FMU_USART3_RX) | \
                                     PIN_PUPDR_PULLDOWN(GPIOD_FRAM_CS) | \
                                     PIN_PUPDR_PULLDOWN(GPIOD_FMU_USART3_CTS) | \
                                     PIN_PUPDR_PULLDOWN(GPIOD_FMU_USART3_RTS) | \
                                     PIN_PUPDR_PULLDOWN(GPIOD_FMU_CH5) | \
                                     PIN_PUPDR_PULLDOWN(GPIOD_FMU_CH6) | \
                                     PIN_PUPDR_PULLDOWN(GPIOD_MPU9250_DRDY))
#define VAL_GPIOD_ODR               (PIN_ODR_LOW(GPIOD_CAN1_RX) | \
                                     PIN_ODR_LOW(GPIOD_CAN1_TX) | \
                                     PIN_ODR_LOW(GPIOD_SDIO_CMD) | \
                                     PIN_ODR_LOW(GPIOD_FMU_USART2_CTS) | \
                                     PIN_ODR_LOW(GPIOD_FMU_USART2_RTS) | \
                                     PIN_ODR_LOW(GPIOD_FMU_USART2_TX) | \
                                     PIN_ODR_LOW(GPIOD_FMU_USART2_RX) | \
                                     PIN_ODR_LOW(GPIOD_BARO_CS) | \
                                     PIN_ODR_LOW(GPIOD_FMU_USART3_TX) | \
                                     PIN_ODR_LOW(GPIOD_FMU_USART3_RX) | \
                                     PIN_ODR_LOW(GPIOD_FRAM_CS) | \
                                     PIN_ODR_LOW(GPIOD_FMU_USART3_CTS) | \
                                     PIN_ODR_LOW(GPIOD_FMU_USART3_RTS) | \
                                     PIN_ODR_LOW(GPIOD_FMU_CH5) | \
                                     PIN_ODR_LOW(GPIOD_FMU_CH6) | \
                                     PIN_ODR_LOW(GPIOD_MPU9250_DRDY))
#define VAL_GPIOD_AFRL              (PIN_AFIO_AF(GPIOD_CAN1_RX, 0U) | \
                                     PIN_AFIO_AF(GPIOD_CAN1_TX, 0U) | \
                                     PIN_AFIO_AF(GPIOD_SDIO_CMD, 0U) | \
                                     PIN_AFIO_AF(GPIOD_FMU_USART2_CTS, 0U) | \
                                     PIN_AFIO_AF(GPIOD_FMU_USART2_RTS, 0U) | \
                                     PIN_AFIO_AF(GPIOD_FMU_USART2_TX, 7U) | \
                                     PIN_AFIO_AF(GPIOD_FMU_USART2_RX, 7U) | \
                                     PIN_AFIO_AF(GPIOD_BARO_CS, 0U))
#define VAL_GPIOD_AFRH              (PIN_AFIO_AF(GPIOD_FMU_USART3_TX, 0U) | \
                                     PIN_AFIO_AF(GPIOD_FMU_USART3_RX, 0U) | \
                                     PIN_AFIO_AF(GPIOD_FRAM_CS, 0U) | \
                                     PIN_AFIO_AF(GPIOD_FMU_USART3_CTS, 0U) | \
                                     PIN_AFIO_AF(GPIOD_FMU_USART3_RTS, 0U) | \
                                     PIN_AFIO_AF(GPIOD_FMU_CH5, 0U) | \
                                     PIN_AFIO_AF(GPIOD_FMU_CH6, 0U) | \
                                     PIN_AFIO_AF(GPIOD_MPU9250_DRDY, 0U))

/*
 * GPIOE setup:
 */
#define VAL_GPIOE_MODER             (PIN_MODE_INPUT(GPIOE_FMU_USART8_RX) | \
                                     PIN_MODE_INPUT(GPIOE_FMU_USART8_TX) | \
                                     PIN_MODE_INPUT(GPIOE_8266_GPIO0) | \
                                     PIN_MODE_OUTPUT(GPIOE_VDD_3V3_SENSORS_EN) | \
                                     PIN_MODE_OUTPUT(GPIOE_SPEKTRUM_POWER) | \
                                     PIN_MODE_INPUT(GPIOE_8266_PD) | \
                                     PIN_MODE_INPUT(GPIOE_8266_RST) | \
                                     PIN_MODE_ALTERNATE(GPIOE_FMU_UART7_RX) | \
                                     PIN_MODE_ALTERNATE(GPIOE_FMU_UART7_TX) | \
                                     PIN_MODE_INPUT(GPIOE_FMU_CH4) | \
                                     PIN_MODE_INPUT(GPIOE_8266_CTS) | \
                                     PIN_MODE_INPUT(GPIOE_FMU_CH3) | \
                                     PIN_MODE_INPUT(GPIOE_HMC5983_DRDY) | \
                                     PIN_MODE_INPUT(GPIOE_FMU_CH2) | \
                                     PIN_MODE_INPUT(GPIOE_FMU_CH1) | \
                                     PIN_MODE_INPUT(GPIOE_HMC5983_CS))
#define VAL_GPIOE_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOE_FMU_USART8_RX) | \
                                     PIN_OTYPE_PUSHPULL(GPIOE_FMU_USART8_TX) | \
                                     PIN_OTYPE_PUSHPULL(GPIOE_8266_GPIO0) | \
                                     PIN_OTYPE_PUSHPULL(GPIOE_VDD_3V3_SENSORS_EN) | \
                                     PIN_OTYPE_PUSHPULL(GPIOE_SPEKTRUM_POWER) | \
                                     PIN_OTYPE_PUSHPULL(GPIOE_8266_PD) | \
                                     PIN_OTYPE_PUSHPULL(GPIOE_8266_RST) | \
                                     PIN_OTYPE_PUSHPULL(GPIOE_FMU_UART7_RX) | \
                                     PIN_OTYPE_PUSHPULL(GPIOE_FMU_UART7_TX) | \
                                     PIN_OTYPE_PUSHPULL(GPIOE_FMU_CH4) | \
                                     PIN_OTYPE_PUSHPULL(GPIOE_8266_CTS) | \
                                     PIN_OTYPE_PUSHPULL(GPIOE_FMU_CH3) | \
                                     PIN_OTYPE_PUSHPULL(GPIOE_HMC5983_DRDY) | \
                                     PIN_OTYPE_PUSHPULL(GPIOE_FMU_CH2) | \
                                     PIN_OTYPE_PUSHPULL(GPIOE_FMU_CH1) | \
                                     PIN_OTYPE_PUSHPULL(GPIOE_HMC5983_CS))
#define VAL_GPIOE_OSPEEDR           (PIN_OSPEED_HIGH(GPIOE_FMU_USART8_RX) | \
                                     PIN_OSPEED_HIGH(GPIOE_FMU_USART8_TX) | \
                                     PIN_OSPEED_HIGH(GPIOE_8266_GPIO0) | \
                                     PIN_OSPEED_HIGH(GPIOE_VDD_3V3_SENSORS_EN) | \
                                     PIN_OSPEED_HIGH(GPIOE_SPEKTRUM_POWER) | \
                                     PIN_OSPEED_HIGH(GPIOE_8266_PD) | \
                                     PIN_OSPEED_HIGH(GPIOE_8266_RST) | \
                                     PIN_OSPEED_HIGH(GPIOE_FMU_UART7_RX) | \
                                     PIN_OSPEED_HIGH(GPIOE_FMU_UART7_TX) | \
                                     PIN_OSPEED_HIGH(GPIOE_FMU_CH4) | \
                                     PIN_OSPEED_HIGH(GPIOE_8266_CTS) | \
                                     PIN_OSPEED_HIGH(GPIOE_FMU_CH3) | \
                                     PIN_OSPEED_HIGH(GPIOE_HMC5983_DRDY) | \
                                     PIN_OSPEED_HIGH(GPIOE_FMU_CH2) | \
                                     PIN_OSPEED_HIGH(GPIOE_FMU_CH1) | \
                                     PIN_OSPEED_HIGH(GPIOE_HMC5983_CS))
#define VAL_GPIOE_PUPDR             (PIN_PUPDR_PULLDOWN(GPIOE_FMU_USART8_RX) | \
                                     PIN_PUPDR_PULLDOWN(GPIOE_FMU_USART8_TX) | \
                                     PIN_PUPDR_PULLDOWN(GPIOE_8266_GPIO0) | \
                                     PIN_PUPDR_FLOATING(GPIOE_VDD_3V3_SENSORS_EN) | \
                                     PIN_PUPDR_FLOATING(GPIOE_SPEKTRUM_POWER) | \
                                     PIN_PUPDR_PULLDOWN(GPIOE_8266_PD) | \
                                     PIN_PUPDR_PULLDOWN(GPIOE_8266_RST) | \
                                     PIN_PUPDR_PULLUP(GPIOE_FMU_UART7_RX) | \
                                     PIN_PUPDR_FLOATING(GPIOE_FMU_UART7_TX) | \
                                     PIN_PUPDR_PULLDOWN(GPIOE_FMU_CH4) | \
                                     PIN_PUPDR_PULLDOWN(GPIOE_8266_CTS) | \
                                     PIN_PUPDR_PULLDOWN(GPIOE_FMU_CH3) | \
                                     PIN_PUPDR_FLOATING(GPIOE_HMC5983_DRDY) | \
                                     PIN_PUPDR_PULLDOWN(GPIOE_FMU_CH2) | \
                                     PIN_PUPDR_PULLDOWN(GPIOE_FMU_CH1) | \
                                     PIN_PUPDR_PULLDOWN(GPIOE_HMC5983_CS))
#define VAL_GPIOE_ODR               (PIN_ODR_LOW(GPIOE_FMU_USART8_RX) | \
                                     PIN_ODR_LOW(GPIOE_FMU_USART8_TX) | \
                                     PIN_ODR_LOW(GPIOE_8266_GPIO0) | \
                                     PIN_ODR_LOW(GPIOE_VDD_3V3_SENSORS_EN) | \
                                     PIN_ODR_HIGH(GPIOE_SPEKTRUM_POWER) | \
                                     PIN_ODR_LOW(GPIOE_8266_PD) | \
                                     PIN_ODR_LOW(GPIOE_8266_RST) | \
                                     PIN_ODR_LOW(GPIOE_FMU_UART7_RX) | \
                                     PIN_ODR_LOW(GPIOE_FMU_UART7_TX) | \
                                     PIN_ODR_LOW(GPIOE_FMU_CH4) | \
                                     PIN_ODR_LOW(GPIOE_8266_CTS) | \
                                     PIN_ODR_LOW(GPIOE_FMU_CH3) | \
                                     PIN_ODR_LOW(GPIOE_HMC5983_DRDY) | \
                                     PIN_ODR_LOW(GPIOE_FMU_CH2) | \
                                     PIN_ODR_LOW(GPIOE_FMU_CH1) | \
                                     PIN_ODR_LOW(GPIOE_HMC5983_CS))
#define VAL_GPIOE_AFRL              (PIN_AFIO_AF(GPIOE_FMU_USART8_RX, 0U) | \
                                     PIN_AFIO_AF(GPIOE_FMU_USART8_TX, 0U) | \
                                     PIN_AFIO_AF(GPIOE_8266_GPIO0, 0U) | \
                                     PIN_AFIO_AF(GPIOE_VDD_3V3_SENSORS_EN, 0U) | \
                                     PIN_AFIO_AF(GPIOE_SPEKTRUM_POWER, 0U) | \
                                     PIN_AFIO_AF(GPIOE_8266_PD, 0U) | \
                                     PIN_AFIO_AF(GPIOE_8266_RST, 0U) | \
                                     PIN_AFIO_AF(GPIOE_FMU_UART7_RX, 8U))
#define VAL_GPIOE_AFRH              (PIN_AFIO_AF(GPIOE_FMU_UART7_TX, 8U) | \
                                     PIN_AFIO_AF(GPIOE_FMU_CH4, 0U) | \
                                     PIN_AFIO_AF(GPIOE_8266_CTS, 0U) | \
                                     PIN_AFIO_AF(GPIOE_FMU_CH3, 0U) | \
                                     PIN_AFIO_AF(GPIOE_HMC5983_DRDY, 0U) | \
                                     PIN_AFIO_AF(GPIOE_FMU_CH2, 0U) | \
                                     PIN_AFIO_AF(GPIOE_FMU_CH1, 0U) | \
                                     PIN_AFIO_AF(GPIOE_HMC5983_CS, 0U))

/*
 * GPIOF setup:
 */
#define VAL_GPIOF_MODER             (0)
#define VAL_GPIOF_OTYPER            (0)
#define VAL_GPIOF_OSPEEDR           (0)
#define VAL_GPIOF_PUPDR             (0)
#define VAL_GPIOF_ODR               (0)
#define VAL_GPIOF_AFRL              (0)
#define VAL_GPIOF_AFRH              (0)

/*
 * GPIOG setup:
 */
#define VAL_GPIOG_MODER             (0)
#define VAL_GPIOG_OTYPER            (0)
#define VAL_GPIOG_OSPEEDR           (0)
#define VAL_GPIOG_PUPDR             (0)
#define VAL_GPIOG_ODR               (0)
#define VAL_GPIOG_AFRL              (0)
#define VAL_GPIOG_AFRH              (0)

/*
 * GPIOH setup:
 *
 * PH0  - OSC_IN                    (input floating).
 * PH1  - OSC_OUT                   (input floating).
 */
#define VAL_GPIOH_MODER             (PIN_MODE_INPUT(GPIOH_OSC_IN) | \
                                     PIN_MODE_INPUT(GPIOH_OSC_OUT))
#define VAL_GPIOH_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOH_OSC_IN) | \
                                     PIN_OTYPE_PUSHPULL(GPIOH_OSC_OUT))
#define VAL_GPIOH_OSPEEDR           (PIN_OSPEED_HIGH(GPIOH_OSC_IN) | \
                                     PIN_OSPEED_HIGH(GPIOH_OSC_OUT))
#define VAL_GPIOH_PUPDR             (PIN_PUPDR_FLOATING(GPIOH_OSC_IN) | \
                                     PIN_PUPDR_FLOATING(GPIOH_OSC_OUT))
#define VAL_GPIOH_ODR               (PIN_ODR_HIGH(GPIOH_OSC_IN) | \
                                     PIN_ODR_HIGH(GPIOH_OSC_OUT))
#define VAL_GPIOH_AFRL              (PIN_AFIO_AF(GPIOH_OSC_IN, 0U) | \
                                     PIN_AFIO_AF(GPIOH_OSC_OUT, 0U))
#define VAL_GPIOH_AFRH              (0)

/*
 * GPIOI setup:
 */
#define VAL_GPIOI_MODER             (0)
#define VAL_GPIOI_OTYPER            (0)
#define VAL_GPIOI_OSPEEDR           (0)
#define VAL_GPIOI_PUPDR             (0)
#define VAL_GPIOI_ODR               (0)
#define VAL_GPIOI_AFRL              (0)
#define VAL_GPIOI_AFRH              (0)

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* BOARD_H */
