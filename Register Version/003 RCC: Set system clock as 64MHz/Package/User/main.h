#ifndef __MAIN_H__
#define __MAIN_H__

#include "..\stm32f10x\stm32f10x.h"
#include "..\cortex_m3\cortex_m3.h"

#include "..\cortex_m3\cortex_systick\cortex_systick.h"

#include "..\stm32f10x\stm32f10x_rcc\stm32f10x_rcc.h"

/**
 * System timer clock source defintions
 *
 * define system timer clock source selection
 */
#define SYSTEM_CLOCK_HSE_72MHZ 0u
#define SYSTEM_CLOCK_HSI_64MHZ 1u

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
#define VECT_TAB_SRAM 0u
#define VECT_TAB_FLASH 1u

#endif /* __MAIN_H__ */
