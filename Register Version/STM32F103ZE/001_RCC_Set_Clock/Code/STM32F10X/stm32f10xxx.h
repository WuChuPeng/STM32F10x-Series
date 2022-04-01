#ifndef __STM32F10XXX_H
#define __STM32F10XXX_H

#define USE_STM32F10X_RCC   1u
#define USE_STM32F10X_FLASH 1u
#define USE_STM32F10X_GPIO  1u

#include <stdint.h>
#include "cortex_m3.h"

/* memory map *************************************************************************/
/* peripheral memory map */
#define FLASH_BASE            ((uint32_t)0x08000000) 
#define SRAM_BASE             ((uint32_t)0x20000000) 
#define PERIPH_BASE           ((uint32_t)0x40000000)

#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x20000)

/* AHB peripheral memory map */
#if (USE_STM32F10X_RCC > 0u)
#define RCC_BASE              (AHBPERIPH_BASE + 0x1000)
#endif
#if (USE_STM32F10X_FLASH > 0u)
#define FLASH_R_BASE          (AHBPERIPH_BASE + 0x2000)
#endif

/* APB2 peripheral memory map */
#if (USE_STM32F10X_GPIO > 0u)
#define GPIOG_BASE          (APB2PERIPH_BASE + 0x2000)
#define GPIOF_BASE          (APB2PERIPH_BASE + 0x1C00)
#define GPIOE_BASE          (APB2PERIPH_BASE + 0x1800)
#define GPIOD_BASE          (APB2PERIPH_BASE + 0x1400)
#define GPIOC_BASE          (APB2PERIPH_BASE + 0x1000)
#define GPIOB_BASE          (APB2PERIPH_BASE + 0x0C00)
#define GPIOA_BASE          (APB2PERIPH_BASE + 0x0800)
#endif

/* structure *************************************************************************/
/* AHB struct typedef */
#if (USE_STM32F10X_RCC > 0u)
typedef struct
{
  __IO uint32_t CR;
  __IO uint32_t CFGR;
  __IO uint32_t CIR;
  __IO uint32_t APB2RSTR;
  __IO uint32_t APB1RSTR;
  __IO uint32_t AHBENR;
  __IO uint32_t APB2ENR;
  __IO uint32_t APB1ENR;
  __IO uint32_t BDCR;
  __IO uint32_t CSR;
} RCC_TypeDef;
#endif
#if (USE_STM32F10X_FLASH > 0u)
typedef struct
{
  __IO uint32_t ACR;
  __IO uint32_t KEYR;
  __IO uint32_t OPTKEYR;
  __IO uint32_t SR;
  __IO uint32_t CR;
  __IO uint32_t AR;
  __IO uint32_t RESERVED;
  __IO uint32_t OBR;
  __IO uint32_t WRPR;
} FLASH_TypeDef;
#endif
#if (USE_STM32F10X_GPIO > 0u)
typedef struct
{
  __IO uint32_t CRL;
  __IO uint32_t CRH;
  __I  uint32_t IDR;
  __IO uint32_t ODR;
  __O  uint32_t BSRR;
  __O  uint32_t BRR;
  __IO uint32_t LCKR;
} GPIO_TypeDef;
#endif
/* instance *************************************************************************/
/* AHB instance */
#if (USE_STM32F10X_RCC > 0u)
#define RCC                 ((RCC_TypeDef *) RCC_BASE)
#endif
#if (USE_STM32F10X_FLASH > 0u)
#define FLASH               ((FLASH_TypeDef *) FLASH_R_BASE)
#endif
/* APB2 instance */
#if (USE_STM32F10X_GPIO > 0u)
#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF               ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG               ((GPIO_TypeDef *) GPIOG_BASE)
#endif

/* bit band *************************************************************************/
#define BIT_BAND(ADDRESS, BIT)    ((ADDRESS & 0xF0000000) + 0x2000000 + ((ADDRESS & 0xFFFFF) << 5) + (BIT << 2 ))
#define INSTANCE_ADDRESS(ADDRESS) (*((volatile unsigned long*)ADDRESS))

#define PAout(n) INSTANCE_ADDRESS(BIT_BAND(GPIOA_BASE + 0x0C, n))
#define PBout(n) INSTANCE_ADDRESS(BIT_BAND(GPIOB_BASE + 0x0C, n))
#define PCout(n) INSTANCE_ADDRESS(BIT_BAND(GPIOC_BASE + 0x0C, n))
#define PDout(n) INSTANCE_ADDRESS(BIT_BAND(GPIOD_BASE + 0x0C, n))
#define PEout(n) INSTANCE_ADDRESS(BIT_BAND(GPIOE_BASE + 0x0C, n))
#define PFout(n) INSTANCE_ADDRESS(BIT_BAND(GPIOF_BASE + 0x0C, n))
#define PGout(n) INSTANCE_ADDRESS(BIT_BAND(GPIOG_BASE + 0x0C, n))

#define PAin(n) INSTANCE_ADDRESS(BIT_BAND(GPIOA_BASE + 0x08, n))
#define PBin(n) INSTANCE_ADDRESS(BIT_BAND(GPIOB_BASE + 0x08, n))
#define PCin(n) INSTANCE_ADDRESS(BIT_BAND(GPIOC_BASE + 0x08, n))
#define PDin(n) INSTANCE_ADDRESS(BIT_BAND(GPIOD_BASE + 0x08, n))
#define PEin(n) INSTANCE_ADDRESS(BIT_BAND(GPIOE_BASE + 0x08, n))
#define PFin(n) INSTANCE_ADDRESS(BIT_BAND(GPIOF_BASE + 0x08, n))
#define PGin(n) INSTANCE_ADDRESS(BIT_BAND(GPIOG_BASE + 0x08, n))

#endif
