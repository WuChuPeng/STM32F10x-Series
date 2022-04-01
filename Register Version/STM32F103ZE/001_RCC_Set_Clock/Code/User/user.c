#include "user.h"
#include "cortex_m3_systick.h"
#include "stm32f10x_rcc.h"
#include "bsp_led.h"
#include "bsp_key.h"

void SystemInit(void);

int main(void)
{
  SystemInit();
  
  while(1)
  {

  }
}

void SystemInit(void)
{
  /* Cortex-M3 */

  /* STM32 */
  pRCC_Object->setSystemClock();
  
  /* BSP */
  
  /* User */
  
}
