#ifndef __STM32F10X_H__
#define __STM32F10X_H__

#include <stdint.h>
#include "..\cortex_m3\cortex_m3.h"

/** 
  * @brief Reset and Clock Control
  */
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

/** 
  * @brief FLASH Registers
  */
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

/** @addtogroup Peripheral_memory_map
  * @{
  */

#define FLASH_BASE      ((uint32_t)0x08000000) /*!< FLASH base address in the alias region      */
#define SRAM_BASE       ((uint32_t)0x20000000) /*!< SRAM base address in the alias region */
#define PERIPH_BASE     ((uint32_t)0x40000000) /*!< Peripheral base address in the alias region */

/*!< Peripheral memory map */
#define AHBPERIPH_BASE  (PERIPH_BASE + 0x20000)    /*!< AHB Peripheral Base Address */

#define RCC_BASE        (AHBPERIPH_BASE + 0x1000)  /*!< RCC Base Address   */

#define FLASH_R_BASE    (AHBPERIPH_BASE + 0x2000) /*!< Flash registers base address */

/** @addtogroup Peripheral_declaration
  * @{
  */  
#define RCC             ((RCC_TypeDef *) RCC_BASE)
#define FLASH           ((FLASH_TypeDef *) FLASH_R_BASE)

#endif /* __STM32F10X_H__ */
