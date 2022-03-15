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

typedef struct
{
  __IO uint32_t CTRL;                         /*!< Offset: 0x00  SysTick Control and Status Register */
  __IO uint32_t LOAD;                         /*!< Offset: 0x04  SysTick Reload Value Register       */
  __IO uint32_t VAL;                          /*!< Offset: 0x08  SysTick Current Value Register      */
  __I  uint32_t CALIB;                        /*!< Offset: 0x0C  SysTick Calibration Register        */
} SysTick_Type;

/* Memory mapping of Cortex-M3 Hardware */
#define SCS_BASE            (0xE000E000)                              /*!< System Control Space Base Address */
#define SysTick_BASE        (SCS_BASE +  0x0010)                      /*!< SysTick Base Address              */

#define SysTick             ((SysTick_Type *)       SysTick_BASE)     /*!< SysTick configuration struct      */

#endif /* __CORTEX_M3_H__ */
