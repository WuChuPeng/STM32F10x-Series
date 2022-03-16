#include "..\..\user\main.h"
#include "stm32f10x_rcc.h"

/**
 * System timer clock source defintions
 *
 * define system timer clock source selection
 */
#define SYSTEM_CLOCK_HSE_72MHZ 1u
#define SYSTEM_CLOCK_HSI_64MHZ 0u

/**
 * Reset & clock control instance
 *
 * define RCC instance to invoke variables or methods
 */
void __RCC_SET_CLOCK(void);
void __RCC_SET_CLOCK_FREQUENCY_72MHZ(void);
void __RCC_SET_CLOCK_FREQUENCY_64MHZ(void);

STM32F10X_RCC_Structure stm3210x_rcc = {
  __RCC_SET_CLOCK,  
};

/**
 * System clock initalization
 *
 * define system clock
 */
void __RCC_SET_CLOCK(void)
{
  /* reset the RCC clcok configuration to the default reset state (for debug purpose) */
  RCC->CR   &= 0x0000FF83; // Reset Control clock register
  RCC->CFGR  = 0x00000000; // Reset clock configuration register
  RCC->CIR   = 0x00000000; // Reset clock interrupt register
  RCC->CR   |= 0x00000001; // Internal high-speed clock enable
  /* Set system clock */
  #if (SYSTEM_CLOCK_HSE_72MHZ > 0u)
  __RCC_SET_CLOCK_FREQUENCY_72MHZ();
  #elif (SYSTEM_CLOCK_HSI_64MHZ > 0u)
  __RCC_SET_CLOCK_FREQUENCY_64MHZ();
  #endif
  #if (VECT_TAB_SRAM > 0u)
  SCB->VTOR = SRAM_BASE | 0x00000000; // Vector table relocation in internal SRAM
  #elif (VECT_TAB_FLASH > 0u)
  SCB->VTOR = FLASH_BASE | 0x00000000; // Vector table relocation in internal Flash
  #endif
}

/**
 * Set system clock 72MHz
 *
 * configure system clock by setting HSE(8MHz) as PLL clock source, and multiply 9 up to 72MHz
 */
void __RCC_SET_CLOCK_FREQUENCY_72MHZ(void)
{
  uint32_t rccControlRegister = 0x00000000;
  uint16_t timeOutCounter = 0x0000;
  /* Configure HSE */
  RCC->CR |= 0x00010000; // HSE clock enable
  /* Wait for hardware set the HSERDY bit that indicate that the HSE oscillator is stable */
  do {
    rccControlRegister = RCC->CR;
    timeOutCounter++;
  } while(((rccControlRegister & 0x00020000) == 0x00000000) && (timeOutCounter != 0x0400));
  /* If HSE enable successfully */
  if ((RCC->CR & 0x00020000) != 0x00000000)
  {
    /* Flash configuration */
    FLASH->ACR  = 0x00000030; // Reset flash access control register
    FLASH->ACR |= 0x00000010; // Flash prefecth buffer enable
    #if (SYSTEM_CLOCK_HSE_72MHZ > 0u)
    FLASH->ACR |= 0x00000002; // Two wait states, if 48MHz <= SYSCLK <= 72MHz
    #endif
    /* AHB, APB1, APB2, ADC clock configuration */
    RCC->CFGR  |= 0x00000000; // AHB prescaler: SYSCLK not divided (72MHz) 
    RCC->CFGR  |= 0x00000400; // APB1 prescaler: SYSCLK divided by 2 (36MHz)
    RCC->CFGR  |= 0x00000000; // APB2 prescaler: SYSCLK not divided (72MHz) 
    RCC->CFGR  |= 0x00008000; // ADC prescaler: PCLK2 divided by 6 (12MHz)
    /* PLL clock configuration */
    RCC->CFGR  |= 0x00010000; // PLL entry clock source: HSE oscillator clock selected as PLL input clock
    RCC->CFGR  |= 0x00000000; // HSE divider by PLL entry: HSE clock no divided
    RCC->CFGR  |= 0x001C0000; // PLL multiplication factor: PLL input clock x 9 = 72MHz    
    RCC->CR    |= 0x01000000; // PLL enable
    // Wait for PLL clock ready
    while((RCC->CR & 0x02000000) == 0x00000000); 
    RCC->CFGR  |= 0x00000002; // System clock swtich: PLL
    // Wait for PLL clock as system clock
    while((RCC->CFGR & 0x00000008) == 0x00000000); 
    /* If HSE enable fail */
  } else {
    
  }
}
