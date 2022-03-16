#include "main.h"

int main(void)
{
  cortex_systick.init();
  
  stm3210x_rcc.setClock();
  stm3210x_rcc.init();
  stm3210x_gpio.init();
  
  bsp_led.turnOn(&LED_Green);
  bsp_led.turnOff(&LED_Red);

  while(1)
  {
    bsp_led.turnToggle(&LED_Green);
    bsp_led.turnToggle(&LED_Red);
    cortex_systick.delay_ms(500);
  }
}
