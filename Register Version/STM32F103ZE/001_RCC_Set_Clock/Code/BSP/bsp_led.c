#include "bsp.h"
#include "bsp_led.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"

void _LED_INIT(void);
void _LED_ON(GPIO_TypeDef* self, uint8_t pin);
void _LED_OFF(GPIO_TypeDef* self, uint8_t pin);
void _LED_TOGGLE(GPIO_TypeDef* self, uint8_t pin);

LED_Object_TypeDef LED_Object = {
  _LED_INIT,
  _LED_ON,
  _LED_OFF,
  _LED_TOGGLE,
};

void _LED_INIT(void)
{
  pRCC_Object->configureAPB2Clock(RCC_APB2_GPIOB, ENABLE);
  pRCC_Object->configureAPB2Clock(RCC_APB2_GPIOE, ENABLE);
  
  pGPIO_Object->configurePin(LED_GREEN_GPIO_SOURCE, LED_GREEN_GPIO_PIN, GPIO_Mode_OUTPUT_PP_2MHZ);
  pGPIO_Object->configurePin(LED_RED_GPIO_SOURCE, LED_RED_GPIO_PIN, GPIO_Mode_OUTPUT_PP_2MHZ);
  pLED_Object->off(LED_GREEN_GPIO_SOURCE, LED_GREEN_GPIO_PIN);
  pLED_Object->off(LED_RED_GPIO_SOURCE, LED_RED_GPIO_PIN);
}

void _LED_ON(GPIO_TypeDef* self, uint8_t pin)
{
  pGPIO_Object->resetBit(self, pin);
}

void _LED_OFF(GPIO_TypeDef* self, uint8_t pin)
{
  pGPIO_Object->setBit(self, pin);
}

void _LED_TOGGLE(GPIO_TypeDef* self, uint8_t pin)
{
  pGPIO_Object->toggleBit(self, pin);
}
