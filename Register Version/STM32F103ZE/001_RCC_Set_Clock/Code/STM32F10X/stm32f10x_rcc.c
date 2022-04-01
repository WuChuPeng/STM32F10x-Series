#include "cortex_m3.h"
#include "stm32f10xxx.h"
#include "stm32f10x_rcc.h"

#define SYSTEM_CLOCK_72MHZ 1u

void _RCC_SET_SYSTEM_CLOCK(void);
void _RCC_RESET(void);
#if (SYSTEM_CLOCK_72MHZ > 0u)
void _RCC_SET_SYSTEM_CLOCK_72MHZ(void);
#endif
void _RCC_CONFIGURE_AHB_CLOCK(RCC_AHB_Clock_TypeDef clock_source, Function_TypeDef status);
void _RCC_CONFIGURE_APB1_CLOCK(RCC_APB1_Clock_TypeDef clock_source, Function_TypeDef status);
void _RCC_CONFIGURE_APB2_CLOCK(RCC_APB2_Clock_TypeDef clock_source, Function_TypeDef status);

RCC_Object_TypeDef RCC_Object = {
  _RCC_SET_SYSTEM_CLOCK,
  _RCC_CONFIGURE_AHB_CLOCK,
  _RCC_CONFIGURE_APB1_CLOCK,
  _RCC_CONFIGURE_APB2_CLOCK,
};

void _RCC_SET_SYSTEM_CLOCK(void)
{
  /* clean all registers value for debug purpose */
  _RCC_RESET();
  /* enable HSI */
  RCC->CR |= 0x00000001;                       // enable HSI clock
  while((RCC->CR & 0x00000002) != 0x00000002); // wait for HSI clock ready
  /* system clock selection */
  #if (SYSTEM_CLOCK_72MHZ > 0u)
  _RCC_SET_SYSTEM_CLOCK_72MHZ();
  #endif
  /* configure vector table */
  #if FLASH_MODE
  SCB->VTOR = FLASH_BASE | 0x00;
  #endif
  #if SRAM_MODE
  SCB->VTOR = SRAM_BASE | 0x00;  
  #endif
}

void _RCC_RESET(void)
{
  /* clean all registers */
  RCC->CR &= 0x0000FF83;
  RCC->CFGR = 0x00000000;
  RCC->CIR = 0x00000000;
  RCC->APB2RSTR = 0x00000000;
  RCC->APB1RSTR = 0x00000000;
  RCC->AHBENR = 0x00000014;
  RCC->APB2ENR = 0x00000000;
  RCC->APB1ENR = 0x00000000;
}

#if (SYSTEM_CLOCK_72MHZ > 0u)
void _RCC_SET_SYSTEM_CLOCK_72MHZ(void)
{
  /* configure flash */
  FLASH->ACR |= 0x00000010; // prefetch buffer enable
  FLASH->ACR |= 0x00000002; // two wait states
  /* enable HSE */
  RCC->CR |= 0x00010000;                       // enable HSE clock
  while((RCC->CR & 0x00020000) != 0x00020000); // wait for HSE clock ready
  /* configure prescalers */
  RCC->CFGR |= 0x00000000; // AHB prescaler: no divided (72MHz)
  RCC->CFGR |= 0x00000400; // ABP1 prescaler: divided by 2 (36MHz)
  RCC->CFGR |= 0x00000000; // ABP2 prescaler: no divided (72MHz)
  RCC->CFGR |= 0x00008000; // ADC prescaler: divided by 6 (12MHz)
  /* enable PLL */
  RCC->CFGR |= 0x001C0000; // PLL multiplication factor: input clock x 9 (72MHz)
  RCC->CFGR |= 0x00010000; // PLL entry clock source: HSE
  RCC->CFGR |= 0x00000000; // HSE driver for PLL entry: HSE clock no divided
  RCC->CR   |= 0x01000000; // PLL enable
  while((RCC->CR & 0x02000000) == 0x00000000); // wait for PLL locked
  /* select system clock */
  RCC->CFGR |= 0x00000002; // PLL selected as system clock
  while((RCC->CFGR & 0x0000000C) == 0x00000080); // wait for PLL used as system clock
}
#endif

void _RCC_CONFIGURE_AHB_CLOCK(RCC_AHB_Clock_TypeDef clock_source, Function_TypeDef status)
{  
  if (status == ENABLE)
  {
    RCC->AHBENR |= clock_source;
  } else {
    RCC->AHBENR &= ~clock_source;
  }
}

void _RCC_CONFIGURE_APB1_CLOCK(RCC_APB1_Clock_TypeDef clock_source, Function_TypeDef status)
{  
  if (status == ENABLE)
  {
    RCC->APB1ENR |= clock_source;
  } else {
    RCC->APB1ENR &= ~clock_source;
  }
}

void _RCC_CONFIGURE_APB2_CLOCK(RCC_APB2_Clock_TypeDef clock_source, Function_TypeDef status)
{  
  if (status == ENABLE)
  {
    RCC->APB2ENR |= clock_source;
  } else {
    RCC->APB2ENR &= ~clock_source;
  }
}
