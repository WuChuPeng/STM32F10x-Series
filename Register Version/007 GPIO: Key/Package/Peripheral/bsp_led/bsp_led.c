#include "..\..\user\main.h"
#include "bsp_led.h"

void __LED_TURN_ON (_BSP_LED_Configuration_Structure* instance);
void __LED_TURN_OFF (_BSP_LED_Configuration_Structure* instance);
void __LED_TURN_TOGGLE (_BSP_LED_Configuration_Structure* instance);

_BSP_LED_Configuration_Structure LED_Red = {
  LED_RED_GPIO_SOURCE,
  LED_RED_GPIO_PIN,
};

_BSP_LED_Configuration_Structure LED_Green = {
  LED_GREEN_GPIO_SOURCE,
  LED_GREEN_GPIO_PIN,
};

_BSP_LED_Structure bsp_led = {
  __LED_TURN_ON,
  __LED_TURN_OFF,
  __LED_TURN_TOGGLE,
};

void __LED_TURN_ON (_BSP_LED_Configuration_Structure* instance)
{
  stm3210x_gpio.resetBit(instance->GPIO_BASE, instance->GPIO_PIN);  
}

void __LED_TURN_OFF (_BSP_LED_Configuration_Structure* instance)
{
  stm3210x_gpio.setBit(instance->GPIO_BASE, instance->GPIO_PIN);  
}

void __LED_TURN_TOGGLE (_BSP_LED_Configuration_Structure* instance)
{
  stm3210x_gpio.toggleBit(instance->GPIO_BASE, instance->GPIO_PIN);  
}
