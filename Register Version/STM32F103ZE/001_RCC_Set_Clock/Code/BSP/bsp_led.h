#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "bsp.h"

#include "stm32f10x_gpio.h"

#if (USE_BSP_LED > 0u)
#define LED_RED_GPIO_SOURCE GPIOB
#define LED_RED_GPIO_PIN    5

#define LED_GREEN_GPIO_SOURCE GPIOE
#define LED_GREEN_GPIO_PIN    5

typedef struct
{
  void (*init) (void);
  void (*on) (GPIO_TypeDef*, uint8_t);
  void (*off) (GPIO_TypeDef*, uint8_t);
  void (*toggle) (GPIO_TypeDef*, uint8_t);
} LED_Object_TypeDef;

extern LED_Object_TypeDef LED_Object;

#define pLED_Object ((LED_Object_TypeDef*)&LED_Object)

#endif

#endif
