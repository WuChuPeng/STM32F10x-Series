#ifndef __CORTEX_M3_H__
#define __CORTEX_M3_H__

#include <stdint.h>

/**
 * IO definitions
 *
 * define access restrictions to peripheral registers
 */
#define     __I     volatile const            /*!< defines 'read only' permissions      */
#define     __O     volatile                  /*!< defines 'write only' permissions     */
#define     __IO    volatile                  /*!< defines 'read / write' permissions   */

/** @addtogroup CMSIS_CM3_SysTick CMSIS CM3 SysTick
  memory mapped structure for SysTick
  @{
 */
typedef struct
{
  __IO uint32_t CTRL;                         /*!< Offset: 0x00  SysTick Control and Status Register */
  __IO uint32_t LOAD;                         /*!< Offset: 0x04  SysTick Reload Value Register       */
  __IO uint32_t VAL;                          /*!< Offset: 0x08  SysTick Current Value Register      */
  __I  uint32_t CALIB;                        /*!< Offset: 0x0C  SysTick Calibration Register        */
} SysTick_Type;

/** @addtogroup CMSIS_CM3_SCB CMSIS CM3 SCB
  memory mapped structure for System Control Block (SCB)
  @{
 */
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
} SCB_Type;    

/* Memory mapping of Cortex-M3 Hardware */
#define SCS_BASE            (0xE000E000)                              /*!< System Control Space Base Address */
#define SysTick_BASE        (SCS_BASE +  0x0010)                      /*!< SysTick Base Address              */
#define SCB_BASE            (SCS_BASE +  0x0D00)                      /*!< System Control Block Base Address */

#define SCB                 ((SCB_Type *)           SCB_BASE)         /*!< SCB configuration struct          */
#define SysTick             ((SysTick_Type *)       SysTick_BASE)     /*!< SysTick configuration struct      */

#endif /* __CORTEX_M3_H__ */
