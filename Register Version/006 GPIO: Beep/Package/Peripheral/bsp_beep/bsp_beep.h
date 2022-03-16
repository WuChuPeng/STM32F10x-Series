#ifndef __BSP_BEEP__
#define __BSP_BEEP__

#include <stdint.h>

typedef struct {
  uint32_t GPIO_BASE;
  uint8_t GPIO_PIN;
} _BSP_BEEP_Configuration_Structure;

typedef struct __BSP_BEEP_Structure
{
  void (*turnOn) (_BSP_BEEP_Configuration_Structure* instance);
  void (*turnOff) (_BSP_BEEP_Configuration_Structure* instance);
  void (*turnToggle) (_BSP_BEEP_Configuration_Structure* instance);
} _BSP_BEEP_Structure;

extern _BSP_BEEP_Configuration_Structure BEEP;
extern _BSP_BEEP_Structure bsp_beep;

#endif /* __BSP_BEEP__ */
