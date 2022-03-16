#ifndef __CORTEX_SYSTICK_H__
#define __CORTEX_SYSTICK_H__

#include <stdint.h>

typedef struct
{
  // member variable
  uint8_t us_factor;
  uint16_t ms_factor;
  // member method
  void (*init)     (void);  
 void (*delay_us) (uint32_t us);  
 void (*delay_ms) (uint16_t ms);  
}Cortex_Systick_Structure;

extern Cortex_Systick_Structure cortex_systick;

#endif /* __CORTEX_SYSTICK_H__ */
