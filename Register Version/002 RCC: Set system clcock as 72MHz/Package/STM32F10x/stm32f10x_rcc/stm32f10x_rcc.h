#ifndef __STM32F10X_RCC_H__
#define __STM32F10X_RCC_H__

#include <stdint.h>

typedef struct
{
  void (*setClock) (void);
} STM32F10X_RCC_Structure;

extern STM32F10X_RCC_Structure stm3210x_rcc;

#endif /* __STM32F10X_RCC_H__ */
