#include "..\..\user\main.h"
#include "bsp_key.h"

#define KEY_UP_BIT() (stm3210x_gpio.readBit(KEY_UP_GPIO_SOURCE, KEY_UP_GPIO_PIN))
#define KEY_DOWN_BIT() (stm3210x_gpio.readBit(KEY_DOWN_GPIO_SOURCE, KEY_DOWN_GPIO_PIN))
#define KEY_LEFT_BIT() (stm3210x_gpio.readBit(KEY_LEFT_GPIO_SOURCE, KEY_LEFT_GPIO_PIN))
#define KEY_RIGHT_BIT() (stm3210x_gpio.readBit(KEY_RIGHT_GPIO_SOURCE, KEY_RIGHT_GPIO_PIN))

uint8_t __BSP_KEY_SCAN(uint8_t mode, uint8_t* value);

_BSP_KEY_Structure bsp_key = {
  __BSP_KEY_SCAN,
};

uint8_t __BSP_KEY_SCAN(uint8_t mode, uint8_t* value)
{
  static uint8_t keyStatus = 1;
  if (mode)
  {
    keyStatus = 1;
  }
  if ((keyStatus == 1) && ((KEY_UP_BIT() == 1) || (KEY_DOWN_BIT() == 0) || (KEY_RIGHT_BIT() == 0) || (KEY_LEFT_BIT() == 0)))
  {
    keyStatus = 0;
    if (KEY_UP_BIT() == 1)
    {
      *value = KEY_UP_PRESS;
    } else if (KEY_DOWN_BIT() == 0) {
      *value = KEY_DOWN_PRESS;      
    } else if (KEY_LEFT_BIT() == 0) {
      *value = KEY_LEFT_PRESS;
    } else if (KEY_RIGHT_BIT() == 0) {
      *value = KEY_RIGHT_PRESS;
    } else {
      *value = KEY_NO_PRESS;      
    }
    return 1;
  } else if ((KEY_UP_BIT() == 0) && (KEY_DOWN_BIT() == 1) && (KEY_RIGHT_BIT() == 1) && (KEY_LEFT_BIT() == 1)) {
    keyStatus = 1;
  }
  return 0;
}
