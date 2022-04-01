#ifndef __CORTEX_M3_SYSTICK_H
#define __CORTEX_M3_SYSTICK_H

#include <stdint.h>

typedef struct
{
  void (*init) (void);
  void (*delay_us) (uint32_t );  
  void (*delay_ms) (uint16_t );  
} SysTick_Object_TypeDef;

extern SysTick_Object_TypeDef SysTick_Object;

#define pSysTick_Object ((SysTick_Object_TypeDef*)&SysTick_Object)

#endif
