#ifndef __STM32F10X_GPIO_H__
#define __STM32F10X_GPIO_H__

#include <stdint.h>

typedef struct
{
  void (*init) (void);
  void (*setBit)(uint32_t gpio_source, uint8_t pin);
  void (*resetBit)(uint32_t gpio_source, uint8_t pin);
  void (*toggleBit)(uint32_t gpio_source, uint8_t pin);
  uint8_t (*readBit)(uint32_t gpio_source, uint8_t pin);
} STM32F10X_GPIO_Structure;

extern STM32F10X_GPIO_Structure stm3210x_gpio;

#endif /* __STM32F10X_GPIO_H__ */
