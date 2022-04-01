#include "user.h"
#include "stm32f10xxx.h"
#include "stm32f10x_gpio.h"

#if (USE_STM32F10X_GPIO > 0u)
void _GPIO_CONFIGURE_PIN(GPIO_TypeDef *self, uint8_t pin, GPIO_Mode_TypeDef mode);
void _GPIO_SET_BIT(GPIO_TypeDef *self, uint8_t pin);
void _GPIO_RESET_BIT(GPIO_TypeDef *self, uint8_t pin);
void _GPIO_TOGGLE_BIT(GPIO_TypeDef *self, uint8_t pin);
Level_TypeDef _GPIO_READ_BIT(GPIO_TypeDef *self, uint8_t pin);

GPIO_Object_TypeDef GPIO_Object = {
  _GPIO_CONFIGURE_PIN,
  _GPIO_SET_BIT,
  _GPIO_RESET_BIT,
  _GPIO_TOGGLE_BIT,
  _GPIO_READ_BIT,
};

void _GPIO_CONFIGURE_PIN(GPIO_TypeDef *self, uint8_t pin, GPIO_Mode_TypeDef mode)
{
  if (pin < 8)
  {
    self->CRL &= ~(0x0F << (pin * 4));
    self->CRL |= mode << (pin * 4);
  } else {
    self->CRH &= ~(0x0F << ((pin - 8) * 4));
    self->CRH |= mode << ((pin - 8) * 4);    
  }
}

void _GPIO_SET_BIT(GPIO_TypeDef *self, uint8_t pin)
{
  self->BSRR |= 0x01 << pin;
}

void _GPIO_RESET_BIT(GPIO_TypeDef *self, uint8_t pin)
{
  self->BRR |= 0x01 << pin;
}

void _GPIO_TOGGLE_BIT(GPIO_TypeDef *self, uint8_t pin)
{
  self->ODR ^= 0x01 << pin;
}

Level_TypeDef _GPIO_READ_BIT(GPIO_TypeDef *self, uint8_t pin)
{
  return ((self->IDR & (0x01 << pin)) == 0x00)? LOW : HIGH;
}

#endif
