#ifndef __BSP_KEY__
#define __BSP_KEY__

#include <stdint.h>

typedef enum
{
  KEY_NO_PRESS,
  KEY_UP_PRESS,
  KEY_DOWN_PRESS,
  KEY_LEFT_PRESS,
  KEY_RIGHT_PRESS,
} __BSP_KEY_VALUE;

typedef struct __BSP_KEY_Structure
{
  uint8_t (*scan) (uint8_t mode, uint8_t* value); 
} _BSP_KEY_Structure;

extern _BSP_KEY_Structure bsp_key;

#endif /* __BSP_KEY__ */
