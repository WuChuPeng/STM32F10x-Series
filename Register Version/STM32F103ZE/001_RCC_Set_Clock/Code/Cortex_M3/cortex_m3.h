#ifndef __CORTEX_M3_H
#define __CORTEX_M3_H

#define USE_CORTEX_M3_SCB     1u
#define USE_CORTEX_M3_SYSTICK 1u

#include <stdint.h>
#include "user.h"

/* Cortex M3 memory map */
#define SCS_BASE            ((uint32_t)0xE000E000) 

/* SCS memory map */
#if (USE_CORTEX_M3_SCB > 0u)
#define SCB_BASE            (SCS_BASE +  0x0D00)
#endif
#if (USE_CORTEX_M3_SYSTICK > 0u)
#define SysTick_BASE        (SCS_BASE +  0x0010)
#endif

/* SCS struct tpyedef */
#if (USE_CORTEX_M3_SCB > 0u)
typedef struct
{
  __I  uint32_t CPUID;                        /*!< Offset: 0x00  CPU ID Base Register                                  */
  __IO uint32_t ICSR;                         /*!< Offset: 0x04  Interrupt Control State Register                      */
  __IO uint32_t VTOR;                         /*!< Offset: 0x08  Vector Table Offset Register                          */
  __IO uint32_t AIRCR;                        /*!< Offset: 0x0C  Application Interrupt / Reset Control Register        */
  __IO uint32_t SCR;                          /*!< Offset: 0x10  System Control Register                               */
  __IO uint32_t CCR;                          /*!< Offset: 0x14  Configuration Control Register                        */
  __IO uint8_t  SHP[12];                      /*!< Offset: 0x18  System Handlers Priority Registers (4-7, 8-11, 12-15) */
  __IO uint32_t SHCSR;                        /*!< Offset: 0x24  System Handler Control and State Register             */
  __IO uint32_t CFSR;                         /*!< Offset: 0x28  Configurable Fault Status Register                    */
  __IO uint32_t HFSR;                         /*!< Offset: 0x2C  Hard Fault Status Register                            */
  __IO uint32_t DFSR;                         /*!< Offset: 0x30  Debug Fault Status Register                           */
  __IO uint32_t MMFAR;                        /*!< Offset: 0x34  Mem Manage Address Register                           */
  __IO uint32_t BFAR;                         /*!< Offset: 0x38  Bus Fault Address Register                            */
  __IO uint32_t AFSR;                         /*!< Offset: 0x3C  Auxiliary Fault Status Register                       */
  __I  uint32_t PFR[2];                       /*!< Offset: 0x40  Processor Feature Register                            */
  __I  uint32_t DFR;                          /*!< Offset: 0x48  Debug Feature Register                                */
  __I  uint32_t ADR;                          /*!< Offset: 0x4C  Auxiliary Feature Register                            */
  __I  uint32_t MMFR[4];                      /*!< Offset: 0x50  Memory Model Feature Register                         */
  __I  uint32_t ISAR[5];                      /*!< Offset: 0x60  ISA Feature Register                                  */
} SCB_TypeDef; 
#endif
#if (USE_CORTEX_M3_SYSTICK > 0u)
typedef struct
{
  __IO uint32_t CTRL;                         /*!< Offset: 0x00  SysTick Control and Status Register */
  __IO uint32_t LOAD;                         /*!< Offset: 0x04  SysTick Reload Value Register       */
  __IO uint32_t VAL;                          /*!< Offset: 0x08  SysTick Current Value Register      */
  __I  uint32_t CALIB;                        /*!< Offset: 0x0C  SysTick Calibration Register        */
} SysTick_Type;
#endif
/* Cortex M3 memory map */
#if (USE_CORTEX_M3_SCB > 0u)
#define SCB                 ((SCB_TypeDef *)SCB_BASE)
#endif
#if (USE_CORTEX_M3_SYSTICK > 0u)
#define SysTick             ((SysTick_Type *)       SysTick_BASE)
#endif

#endif
