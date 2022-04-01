#ifndef __USER_H
#define __USER_H

/* Data types */
#define __I  const volatile 
#define __O  volatile
#define __IO volatile
  
/* enum */
typedef enum
{
  DISABLE,
  ENABLE,
} Function_TypeDef;

typedef enum
{
  False,
  True,
} Boolean_TypeDef;

typedef enum
{
  LOW,
  HIGH,
} Level_TypeDef;

#endif
