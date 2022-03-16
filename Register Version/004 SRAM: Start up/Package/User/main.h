#ifndef __MAIN_H__
#define __MAIN_H__

#include "..\stm32f10x\stm32f10x.h"
#include "..\cortex_m3\cortex_m3.h"

#include "..\cortex_m3\cortex_systick\cortex_systick.h"

#include "..\stm32f10x\stm32f10x_rcc\stm32f10x_rcc.h"
#include "..\stm32f10x\stm32f10x_gpio\stm32f10x_gpio.h"

#include "..\peripheral\bsp_led\bsp_led.h"

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
#define AHB_FREQUENCY 72000000
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
#define LED_RED_GPIO_SOURCE GPIOB_BASE
#define LED_RED_GPIO_PIN    5

#define LED_GREEN_GPIO_SOURCE GPIOE_BASE
#define LED_GREEN_GPIO_PIN    5

#endif /* __MAIN_H__ */
