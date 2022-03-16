#include "bsp_led.h"
#include "..\..\user\main.h"

#if (USE_BSP_LED > 0u)

#define USE_FUNCTION 0u

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
  #if (USE_FUNCTION > 0u)
  stm3210x_gpio.resetBit(instance->GPIO_BASE, instance->GPIO_PIN);  
  #else
  BIT_WORD_ADDR(instance->GPIO_BASE + 0x0C, instance->GPIO_PIN) = 0;
  #endif
}

void __LED_TURN_OFF (_BSP_LED_Configuration_Structure* instance)
{
  #if (USE_FUNCTION > 0u)
  stm3210x_gpio.setBit(instance->GPIO_BASE, instance->GPIO_PIN);  
  #else
  BIT_WORD_ADDR(instance->GPIO_BASE + 0x0C, instance->GPIO_PIN) = 1;
  #endif
}

void __LED_TURN_TOGGLE (_BSP_LED_Configuration_Structure* instance)
{
  #if (USE_FUNCTION > 0u)
  stm3210x_gpio.toggleBit(instance->GPIO_BASE, instance->GPIO_PIN); 
  #else
  BIT_WORD_ADDR(instance->GPIO_BASE + 0x0C, instance->GPIO_PIN) = !BIT_WORD_ADDR(instance->GPIO_BASE + 0x0C, instance->GPIO_PIN);
  #endif  
}

#endif
