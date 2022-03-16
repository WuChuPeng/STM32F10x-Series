#include "main.h"
int main(void)
{  
  static uint8_t counter = 0;
  
  cortex_systick.init();
  
  stm3210x_rcc.setClock();
  stm3210x_rcc.init();
  stm3210x_gpio.init();
  stm3210x_usart1.init(&stm3210x_usart1, 115200);
  
  while(1)
  {
    stm3210x_usart1.transmitFormatStringLine(&stm3210x_usart1, (uint8_t*)"The counter is %d", ++counter);
    bsp_led.turnToggle(&LED_Green);
    cortex_systick.delay_ms(500);
  }
}
