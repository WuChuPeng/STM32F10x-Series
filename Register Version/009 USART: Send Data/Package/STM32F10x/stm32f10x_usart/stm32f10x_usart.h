#ifndef __STM32F10X_USART_H__
#define __STM32F10X_USART_H__

#include "..\..\user\main.h"

typedef struct _STM32F10X_USART_Structure
{
  uint32_t USART_BASE;
  void (*init) (struct _STM32F10X_USART_Structure* instance, uint32_t baud_rate);
  void (*transmitString) (struct _STM32F10X_USART_Structure* instance, uint8_t* string);
  void (*transmitStringLine) (struct _STM32F10X_USART_Structure* instance, uint8_t* string);
  void (*transmitFormatString) (struct _STM32F10X_USART_Structure* instance, uint8_t* string, ...);
  void (*transmitFormatStringLine) (struct _STM32F10X_USART_Structure* instance, uint8_t* string, ...);
} STM32F10X_USART_Structure;

extern STM32F10X_USART_Structure stm3210x_usart1;

#endif /* __STM32F10X_USART_H__ */
