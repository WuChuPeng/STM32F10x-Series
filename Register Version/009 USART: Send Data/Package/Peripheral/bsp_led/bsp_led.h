#ifndef __BSP_LED__
#define __BSP_LED__

#include "..\..\user\main.h"

#if (USE_BSP_LED > 0u)

typedef struct {
  uint32_t GPIO_BASE;
  uint8_t GPIO_PIN;
} _BSP_LED_Configuration_Structure;

typedef struct __BSP_LED_Structure
{
  void (*turnOn) (_BSP_LED_Configuration_Structure* instance);
  void (*turnOff) (_BSP_LED_Configuration_Structure* instance);
  void (*turnToggle) (_BSP_LED_Configuration_Structure* instance);
} _BSP_LED_Structure;

extern _BSP_LED_Configuration_Structure LED_Red;
extern _BSP_LED_Configuration_Structure LED_Green;
extern _BSP_LED_Structure bsp_led;
#endif

#endif /* __BSP_LED__ */
