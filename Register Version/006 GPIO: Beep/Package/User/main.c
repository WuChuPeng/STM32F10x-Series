#include "main.h"

int main(void)
{
  cortex_systick.init();
  
  stm3210x_rcc.setClock();
  stm3210x_rcc.init();
  stm3210x_gpio.init();
  
  bsp_led.turnOff(&LED_Green);
  bsp_led.turnOff(&LED_Red);
  bsp_beep.turnOff(&BEEP);
  
  while(1)
  {
    bsp_led.turnToggle(&LED_Green);
    bsp_led.turnToggle(&LED_Red);
    bsp_beep.turnToggle(&BEEP);
    cortex_systick.delay_ms(500);
  }
}
