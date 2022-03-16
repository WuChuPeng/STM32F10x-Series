#include "main.h"

int main(void)
{
  uint8_t value;
  
  cortex_systick.init();
  
  stm3210x_rcc.setClock();
  stm3210x_rcc.init();
  stm3210x_gpio.init();
  
  while(1)
  {
    if (bsp_key.scan(0, &value))
    {
      switch(value)
      {
        case KEY_UP_PRESS:
          bsp_led.turnOn(&LED_Green);
          bsp_led.turnOn(&LED_Red);
          break;
        case KEY_DOWN_PRESS:
          bsp_led.turnOff(&LED_Green);
          bsp_led.turnOff(&LED_Red);
          break;
        case KEY_LEFT_PRESS:
          bsp_led.turnToggle(&LED_Green);
          break;
        case KEY_RIGHT_PRESS:
          bsp_led.turnToggle(&LED_Red);
          break;
      }
    }
    cortex_systick.delay_ms(10);
  }
}
