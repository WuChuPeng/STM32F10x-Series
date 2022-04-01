#include "bsp.h"
#include "bsp_key.h"
#include "bsp_led.h"
#include "cortex_m3_systick.h"
#include "stm32f10xxx.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"

#if (USE_BSP_KEY > 0u)

#define KEY_UP_GPIO_SOURCE    GPIOA
#define KEY_UP_GPIO_PIN       0
#define KEY_LEFT_GPIO_SOURCE  GPIOE
#define KEY_LEFT_GPIO_PIN     2
#define KEY_DOWN_GPIO_SOURCE  GPIOE
#define KEY_DOWN_GPIO_PIN     3
#define KEY_RIGHT_GPIO_SOURCE GPIOE
#define KEY_RIGHT_GPIO_PIN    4

#define KEY_UP    PAin(0)
#define KEY_LEFT  PEin(2)
#define KEY_DOWN  PEin(3)
#define KEY_RIGHT PEin(4)

void _KEY_INIT(void);
Key_Value_TypeDef _KEY_SCAN(Boolean_TypeDef isContinuous);
void _KEY_HANDLER(void);

Key_Object_TypeDef Key_Object = {
  _KEY_INIT,
  _KEY_SCAN,
  _KEY_HANDLER,
};

void _KEY_INIT(void)
{
  pRCC_Object->configureAPB2Clock(RCC_APB2_GPIOA, ENABLE);
  pRCC_Object->configureAPB2Clock(RCC_APB2_GPIOE, ENABLE);
  
  pGPIO_Object->configurePin(KEY_UP_GPIO_SOURCE, KEY_UP_GPIO_PIN, GPIO_Mode_INPUT_UP_DOWN);
  pGPIO_Object->configurePin(KEY_DOWN_GPIO_SOURCE, KEY_DOWN_GPIO_PIN, GPIO_Mode_INPUT_UP_DOWN);
  pGPIO_Object->configurePin(KEY_LEFT_GPIO_SOURCE, KEY_LEFT_GPIO_PIN, GPIO_Mode_INPUT_UP_DOWN);
  pGPIO_Object->configurePin(KEY_RIGHT_GPIO_SOURCE, KEY_RIGHT_GPIO_PIN, GPIO_Mode_INPUT_UP_DOWN);
  
  pGPIO_Object->resetBit(KEY_UP_GPIO_SOURCE, KEY_UP_GPIO_PIN);
  pGPIO_Object->setBit(KEY_DOWN_GPIO_SOURCE, KEY_DOWN_GPIO_PIN);
  pGPIO_Object->setBit(KEY_LEFT_GPIO_SOURCE, KEY_LEFT_GPIO_PIN);
  pGPIO_Object->setBit(KEY_RIGHT_GPIO_SOURCE, KEY_RIGHT_GPIO_PIN);
}

Key_Value_TypeDef _KEY_SCAN(Boolean_TypeDef isContinuous)
{
  static Boolean_TypeDef isPress = False;
  if (isContinuous == True)
  {
    isPress = False;
  }
  if ((isPress == False) && ((KEY_UP == 1) || (KEY_DOWN == 0) || (KEY_LEFT == 0) || (KEY_RIGHT == 0)))
  {
    pSysTick_Object->delay_ms(20);
    isPress = True;
    if (KEY_UP == 1)
    {
      return KEY_VALUE_UP;
    } else if (KEY_DOWN == 0) {
      return KEY_VALUE_DOWN;      
    } else if (KEY_RIGHT == 0) {
      return KEY_VALUE_RIGHT;
    } else if (KEY_LEFT == 0) {
      return KEY_VALUE_LEFT;
    } else {
      return KEY_VALUE_NO;
    }
  } else if ((KEY_UP == 0) && (KEY_DOWN == 1) && (KEY_LEFT == 1) && (KEY_RIGHT == 1)) {
    isPress = False;
  }
  return KEY_VALUE_NO;
}

void _KEY_HANDLER(void)
{
  switch(_KEY_SCAN(False))
  {
    case KEY_VALUE_UP:
      pLED_Object->on(LED_GREEN_GPIO_SOURCE, LED_GREEN_GPIO_PIN);
      pLED_Object->on(LED_RED_GPIO_SOURCE, LED_RED_GPIO_PIN);
      break;
    case KEY_VALUE_DOWN:
      pLED_Object->off(LED_GREEN_GPIO_SOURCE, LED_GREEN_GPIO_PIN);
      pLED_Object->off(LED_RED_GPIO_SOURCE, LED_RED_GPIO_PIN);      
      break;
    case KEY_VALUE_LEFT:
      pLED_Object->toggle(LED_RED_GPIO_SOURCE, LED_RED_GPIO_PIN);
      break;
    case KEY_VALUE_RIGHT:
      pLED_Object->toggle(LED_GREEN_GPIO_SOURCE, LED_GREEN_GPIO_PIN);      
      break;
    default:
      break;
  }
}

#endif 
