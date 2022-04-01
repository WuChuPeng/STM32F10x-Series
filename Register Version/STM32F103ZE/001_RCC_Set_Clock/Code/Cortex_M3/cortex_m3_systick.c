#include "cortex_m3.h"
#include "cortex_m3_systick.h"

void _SYSTICK_INIT(void);
void _SYSTICK_DELAY_US(uint32_t us);
void _SYSTICK_DELAY_MS(uint16_t ms);

SysTick_Object_TypeDef SysTick_Object = 
{
  _SYSTICK_INIT,
  _SYSTICK_DELAY_US,
  _SYSTICK_DELAY_MS,
};

void _SYSTICK_INIT(void)
{
  SysTick->CTRL |= 0x00000000; // Clock source selection: AHB / 8
}

void _SYSTICK_DELAY_US(uint32_t us)
{
  /* 2^24 = 16,777,216 */
  uint32_t count_flag;
  
  SysTick->LOAD = 9 * us;
  SysTick->VAL  = 0x00000000;
  SysTick->CTRL |= 0x00000001;
  do {
    count_flag = SysTick->CTRL;
  } while(((count_flag & 0x00010000) == 0x00000000) && 
         ((count_flag & 0x00000001) == 0x00000001));
  SysTick->LOAD = 0x00000000;
  SysTick->VAL  = 0x00000000;
  SysTick->CTRL &= 0xFFFFFFFE;
}

void _SYSTICK_DELAY_MS(uint16_t ms)
{
  /* 2^24 = 16,777 */
  uint32_t count_flag;
  
  SysTick->LOAD = 9000 * ms;
  SysTick->VAL  = 0x00000000;
  SysTick->CTRL |= 0x00000001;
  do {
    count_flag = SysTick->CTRL;
  } while(((count_flag & 0x00010000) == 0x00000000) && 
         ((count_flag & 0x00000001) == 0x00000001));
  SysTick->LOAD = 0x00000000;
  SysTick->VAL  = 0x00000000;
  SysTick->CTRL &= 0xFFFFFFFE;
}
