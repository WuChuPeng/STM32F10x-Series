#ifndef __STM32F10X_GPIO_H
#define __STM32F10X_GPIO_H

#include "stm32f10xxx.h"

typedef enum
{
  GPIO_Mode_INPUT_ANALOG    = 0x00,
  GPIO_Mode_OUTPUT_PP_10MHZ = 0x01,
  GPIO_Mode_OUTPUT_PP_2MHZ  = 0x02,
  GPIO_Mode_OUTPUT_PP_50MHZ = 0x03,
  GPIO_Mode_INPUT_FLOATING  = 0x04,
  GPIO_Mode_OUTPUT_OD_10MHZ = 0x05,
  GPIO_Mode_OUTPUT_OD_2MHZ  = 0x06,
  GPIO_Mode_OUTPUT_OD_50MHZ = 0x07,
  GPIO_Mode_INPUT_UP_DOWN   = 0x08,
  GPIO_Mode_OUTPUT_AP_10MHZ = 0x09,
  GPIO_Mode_OUTPUT_AP_2MHZ  = 0x0A,
  GPIO_Mode_OUTPUT_AP_50MHZ = 0x0B,
  GPIO_Mode_OUTPUT_AO_10MHZ = 0x0D,
  GPIO_Mode_OUTPUT_AO_2MHZ  = 0x0E,
  GPIO_Mode_OUTPUT_AO_50MHZ = 0x0F,
} GPIO_Mode_TypeDef;

typedef struct
{
  void (*configurePin) (GPIO_TypeDef*, uint8_t, GPIO_Mode_TypeDef);
  void (*setBit) (GPIO_TypeDef*, uint8_t);
  void (*resetBit) (GPIO_TypeDef*, uint8_t);
  void (*toggleBit) (GPIO_TypeDef*, uint8_t);
  Level_TypeDef (*readBit) (GPIO_TypeDef*, uint8_t);
} GPIO_Object_TypeDef;

extern GPIO_Object_TypeDef GPIO_Object;

#define pGPIO_Object ((GPIO_Object_TypeDef*)&GPIO_Object)

#endif
