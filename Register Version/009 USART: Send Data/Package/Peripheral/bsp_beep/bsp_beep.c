#include "bsp_beep.h"

#if (USE_BSP_BEEP > 0u)
void __BEEP_TURN_ON (_BSP_BEEP_Configuration_Structure* instance);
void __BEEP_TURN_OFF (_BSP_BEEP_Configuration_Structure* instance);
void __BEEP_TURN_TOGGLE (_BSP_BEEP_Configuration_Structure* instance);

_BSP_BEEP_Configuration_Structure BEEP = {
  BEEP_GPIO_SOURCE,
  BEEP_GPIO_PIN,
};

_BSP_BEEP_Structure bsp_beep = {
  __BEEP_TURN_ON,
  __BEEP_TURN_OFF,
  __BEEP_TURN_TOGGLE,
};

void __BEEP_TURN_ON (_BSP_BEEP_Configuration_Structure* instance)
{
  stm3210x_gpio.setBit(instance->GPIO_BASE, instance->GPIO_PIN);  
}

void __BEEP_TURN_OFF (_BSP_BEEP_Configuration_Structure* instance)
{
  stm3210x_gpio.resetBit(instance->GPIO_BASE, instance->GPIO_PIN);  
}

void __BEEP_TURN_TOGGLE (_BSP_BEEP_Configuration_Structure* instance)
{
  stm3210x_gpio.toggleBit(instance->GPIO_BASE, instance->GPIO_PIN);  
}

#endif
