#ifndef __MAIN_H__
#define __MAIN_H__

/**
 * System timer clock source defintions
 *
 * define system timer clock source selection
 */
#define SYSTEM_CLOCK_HSE_72MHZ 1u
#define SYSTEM_CLOCK_HSI_64MHZ 0u

/**
 * Clock frequency defintions
 *
 * define clock frequncy
 */
#if (SYSTEM_CLOCK_HSE_72MHZ > 0u)
#define SYSCLK_FREQUENCY 72000000
#define AHB_FREQUENCY    72000000
#define PCLK2_FREQUENCY  72000000
#elif (SYSTEM_CLOCK_HSI_64MHZ > 0u)
#define SYSCLK_FREQUENCY 64000000
#define AHB_FREQUENCY 64000000
#endif
/**
 * Vector Table Relocation
 *
 * configure system vector table relocation
 */
#define VECT_TAB_SRAM  1u
#define VECT_TAB_FLASH 0u


/**
 * System timer clock source defintions
 *
 * define system timer clock source selection
 */
#define USE_PERIPHERAL_USART1      1u
#define USE_PERIPHERAL_USART1_RXIT 0u

#define USE_BSP_LED  1u
#define USE_BSP_BEEP 0u
#define USE_BSP_KEY  0u

/**
 * System timer clock source defintions
 *
 * define system timer clock source selection
 */
#define KEY_UP_GPIO_SOURCE GPIOA_BASE
#define KEY_UP_GPIO_PIN    0

#define LED_RED_GPIO_SOURCE GPIOB_BASE
#define LED_RED_GPIO_PIN    5

#define BEEP_GPIO_SOURCE GPIOB_BASE
#define BEEP_GPIO_PIN    8

#define KEY_LEFT_GPIO_SOURCE GPIOE_BASE
#define KEY_LEFT_GPIO_PIN  2

#define KEY_DOWN_GPIO_SOURCE GPIOE_BASE
#define KEY_DOWN_GPIO_PIN  3

#define KEY_RIGHT_GPIO_SOURCE GPIOE_BASE
#define KEY_RIGHT_GPIO_PIN  4

#define LED_GREEN_GPIO_SOURCE GPIOE_BASE
#define LED_GREEN_GPIO_PIN  5

#include "..\stm32f10x\stm32f10x.h"
#include "..\cortex_m3\cortex_m3.h"

#include "..\cortex_m3\cortex_systick\cortex_systick.h"

#include "..\stm32f10x\stm32f10x_rcc\stm32f10x_rcc.h"
#include "..\stm32f10x\stm32f10x_gpio\stm32f10x_gpio.h"
#include "..\stm32f10x\stm32f10x_usart\stm32f10x_usart.h"

#include "..\peripheral\bsp_led\bsp_led.h"
#include "..\peripheral\bsp_beep\bsp_beep.h"
#include "..\peripheral\bsp_key\bsp_key.h"

#endif /* __MAIN_H__ */
