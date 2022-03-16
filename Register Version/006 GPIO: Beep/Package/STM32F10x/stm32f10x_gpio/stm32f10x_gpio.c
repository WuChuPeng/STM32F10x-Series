#include "..\..\user\main.h"
#include "stm32f10x_gpio.h"

/**
 * Reset & clock control instance
 *
 * define RCC instance to invoke variables or methods
 */
void __GPIO_INIT(void);
void __GPIO_SET_BIT(uint32_t gpio_source, uint8_t pin);
void __GPIO_RESET_BIT(uint32_t gpio_source, uint8_t pin);
void __GPIO_TOGGLE_BIT(uint32_t gpio_source, uint8_t pin);

STM32F10X_GPIO_Structure stm3210x_gpio = {
  __GPIO_INIT,  
  __GPIO_SET_BIT,
  __GPIO_RESET_BIT,
  __GPIO_TOGGLE_BIT,
};

/**
 * GPIO peripheral initalization
 *
 * initialize GPIO peripheral configuration
 */
void __GPIO_INIT(void)
{
  /* GPIO port configuration */
  // PB.5 (LED-Red)
  GPIOB->CRL &= 0xFF0FFFFF; // Clean configuration
  GPIOB->CRL |= 0x00200000; // Mode: General-Purpose IO, 2MHz
  // PB.8 (Beep)
  GPIOB->CRH &= 0xFFFFFFF0; // Clean configuration
  GPIOB->CRH |= 0x00000002; // Mode: General-Purpose IO, 2MHz
  // PE.5 (LED-Green)
  GPIOE->CRL &= 0xFF0FFFFF; // Clean configuration
  GPIOE->CRL |= 0x00200000; // Mode: General-Purpose IO, 2MHz
}

/**
 * GPIO port set bit
 *
 * set bit on specific GPIO bit
 */
void __GPIO_SET_BIT(uint32_t gpio_source, uint8_t pin)
{
  /* Set GPIO port */
  ((GPIO_TypeDef*)gpio_source)->BSRR |= 0x01 << pin;
}

/**
 * GPIO port reset bit
 *
 * reset bit on specific GPIO bit
 */
void __GPIO_RESET_BIT(uint32_t gpio_source, uint8_t pin)
{
  /* Reset GPIO port */
  ((GPIO_TypeDef*)gpio_source)->BRR |= 0x01 << pin;
}

/**
 * GPIO port toggle status of bit
 *
 * toggle status of bit on specific GPIO bit
 */
void __GPIO_TOGGLE_BIT(uint32_t gpio_source, uint8_t pin)
{
  /* Reset GPIO port */
  ((GPIO_TypeDef*)gpio_source)->ODR ^= 0x01 << pin;
}
