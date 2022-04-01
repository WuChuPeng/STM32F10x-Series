#ifndef __STM32F10X_RCC_H
#define __STM32F10X_RCC_H

#include "bsp.h"

typedef enum
{
  RCC_AHB_DMA1   = 0x00000001,
  RCC_AHB_DMA2   = 0x00000002,
  RCC_AHB_SRAM   = 0x00000004,
  RCC_AHB_FLITF  = 0x00000010,
  RCC_AHB_CRCE   = 0x00000040,
  RCC_AHB_FSMC   = 0x00000100,
  RCC_AHB_SDIO   = 0x00000400,
} RCC_AHB_Clock_TypeDef;

typedef enum
{
  RCC_APB2_AFIO   = 0x00000001,
  RCC_APB2_GPIOA  = 0x00000004,
  RCC_APB2_GPIOB  = 0x00000008,
  RCC_APB2_GPIOC  = 0x00000010,
  RCC_APB2_GPIOD  = 0x00000020,
  RCC_APB2_GPIOE  = 0x00000040,
  RCC_APB2_GPIOF  = 0x00000080,
  RCC_APB2_GPIOG  = 0x00000100,
  RCC_APB2_ADC1   = 0x00000200,
  RCC_APB2_ADC2   = 0x00000400,
  RCC_APB2_TIM1   = 0x00000800,
  RCC_APB2_SPI1   = 0x00001000,
  RCC_APB2_TIM8   = 0x00002000,
  RCC_APB2_USART1 = 0x00004000,
  RCC_APB2_ADC3   = 0x00008000,
  RCC_APB2_TIM9   = 0x00080000,
  RCC_APB2_TIM10  = 0x00100000,
  RCC_APB2_TIM11  = 0x00200000,
} RCC_APB2_Clock_TypeDef;

typedef enum
{
  RCC_APB1_TIM2   = 0x00000001,
  RCC_APB1_TIM3   = 0x00000002,
  RCC_APB1_TIM4   = 0x00000004,
  RCC_APB1_TIM5   = 0x00000008,
  RCC_APB1_TIM6   = 0x00000010,
  RCC_APB1_TIM7   = 0x00000020,
  RCC_APB1_TIM12  = 0x00000040,
  RCC_APB1_TIM13  = 0x00000080,
  RCC_APB1_TIM14  = 0x00000100,
  RCC_APB1_WWDG   = 0x00000800,
  RCC_APB1_SPI2   = 0x00004000,
  RCC_APB1_SPI3   = 0x00008000,
  RCC_APB1_USART2 = 0x00020000,
  RCC_APB1_USART3 = 0x00040000,
  RCC_APB1_USART4 = 0x00080000,
  RCC_APB1_USART5 = 0x00100000,
  RCC_APB1_I2C1   = 0x00200000,
  RCC_APB1_I2C2   = 0x00400000,
  RCC_APB1_USB    = 0x00800000,
  RCC_APB1_CAN    = 0x02000000,
  RCC_APB1_BKP    = 0x08000000,
  RCC_APB1_PWR    = 0x10000000,
  RCC_APB1_DAC    = 0x20000000,
} RCC_APB1_Clock_TypeDef;

typedef struct
{
  void (*setSystemClock) (void);
  void (*configureAHBClock) (RCC_AHB_Clock_TypeDef, Function_TypeDef);
  void (*configureAPB1Clock) (RCC_APB1_Clock_TypeDef, Function_TypeDef);
  void (*configureAPB2Clock) (RCC_APB2_Clock_TypeDef, Function_TypeDef);
} RCC_Object_TypeDef;

extern RCC_Object_TypeDef RCC_Object;

#define pRCC_Object ((RCC_Object_TypeDef*)&RCC_Object)

#endif