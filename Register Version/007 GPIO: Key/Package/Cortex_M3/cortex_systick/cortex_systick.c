#include "..\..\user\main.h"
#include "cortex_systick.h"

/**
 * System timer clock source defintions
 *
 * define system timer clock source selection
 */
#define SYSTICK_CLOCK_SOURCE_HCLK 0u
#define SYSTICK_CLOCK_SOURCE_HCLK_DIVIDE_8 1u

/**
 * System timer instance
 *
 * define system timer instance to invoke variables or methods
 */
void __SYSTICK_INIT(void);
void __SYSTICK_DELAY_US(uint32_t us);
void __SYSTICK_DELAY_MS(uint16_t ms);

Cortex_Systick_Structure cortex_systick = {
    0x00,
    0x00,
    __SYSTICK_INIT,
    __SYSTICK_DELAY_US,
    __SYSTICK_DELAY_MS,
};

/**
 * System timer clock initalization
 *
 * define system timer clock source
 */
void __SYSTICK_INIT(void)
{
/* clock source selection */
#if (SYSTEM_CLOCK_HSE_72MHZ > 0u)
#if SYSTICK_CLOCK_SOURCE_HCLK == 1u
  SysTick->CTRL |= 0x00000004; // AHB
#elif SYSTICK_CLOCK_SOURCE_HCLK_DIVIDE_8 == 1u
  SysTick->CTRL &= 0xFFFFFFFB;                                // AHB divided by 8
  cortex_systick.us_factor = AHB_FREQUENCY / 8000000;         // systick us factor
  cortex_systick.ms_factor = cortex_systick.us_factor * 1000; // systick ms factor
#endif
#elif (SYSTEM_CLOCK_HSI_64MHZ > 0u)
#if SYSTICK_CLOCK_SOURCE_HCLK == 1u
  SysTick->CTRL |= 0x00000004; // AHB
#elif SYSTICK_CLOCK_SOURCE_HCLK_DIVIDE_8 == 1u
  SysTick->CTRL &= 0xFFFFFFFB;                                // AHB divided by 8 (8MHz)
  cortex_systick.us_factor = AHB_FREQUENCY / 8000000;         // systick us factor
  cortex_systick.ms_factor = cortex_systick.us_factor * 1000; // systick ms factor
#endif
#endif
}

/**
 * System timer delay in mircosecond
 *
 * paramenter us maximum is 1,000,000, nearly 1 second
 */
void __SYSTICK_DELAY_US(uint32_t us)
{
  uint32_t controlRegister;
  /* perpare for system timer count */
  SysTick->LOAD = cortex_systick.us_factor * us; // set relaod value
  SysTick->VAL = 0x00000000;                     // clean current value
  SysTick->CTRL |= 0x00000001;                   // counter enabled
  /* looper wait for count to zero */
  do
  {
    controlRegister = SysTick->CTRL; // get counter flag
    /* if timer counted to 0 since last time COUNTFLAG was read and if timer enable is abnormal */
  } while (((controlRegister & 0x00010000) == 0x00000000) && ((controlRegister & 0x00000001) == 0x00000001));
  SysTick->VAL = 0x00000000;   // clean current value
  SysTick->CTRL &= 0xFFFFFFFE; // counter disabled
}

/**
 * System timer delay in millisecond
 *
 * paramenter us maximum is 1,000, nearly 1 second
 */
void __SYSTICK_DELAY_MS(uint16_t ms)
{
  uint32_t controlRegister;
  /* perpare for system timer count */
  SysTick->LOAD = cortex_systick.ms_factor * ms; // set relaod value
  SysTick->VAL = 0x00000000;                     // clean current value
  SysTick->CTRL |= 0x00000001;                   // counter enabled
  /* looper wait for count to zero */
  do
  {
    controlRegister = SysTick->CTRL; // get counter flag
    /* if timer counted to 0 since last time COUNTFLAG was read and if timer enable is abnormal */
  } while (((controlRegister & 0x00010000) == 0x00000000) && ((controlRegister & 0x00000001) == 0x00000001));
  SysTick->VAL = 0x00000000;   // clean current value
  SysTick->CTRL &= 0xFFFFFFFE; // counter disabled
}
