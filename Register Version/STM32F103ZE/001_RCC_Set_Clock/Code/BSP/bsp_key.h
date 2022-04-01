#ifndef __BSP_KEY_H
#define __BSP_KEY_H

#include "user.h"
#include "bsp.h"

#if (USE_BSP_KEY > 0u)
typedef enum
{
  KEY_VALUE_NO,
  KEY_VALUE_UP,
  KEY_VALUE_DOWN,
  KEY_VALUE_LEFT,
  KEY_VALUE_RIGHT,
} Key_Value_TypeDef;

typedef struct
{
  void (*init) (void);
  Key_Value_TypeDef (*scan) (Boolean_TypeDef);
  void (*handler) (void);
} Key_Object_TypeDef;

extern Key_Object_TypeDef Key_Object;

#define pKey_Object ((Key_Object_TypeDef*)&Key_Object)

#endif

#endif
