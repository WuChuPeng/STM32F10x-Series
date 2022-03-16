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
uint8_t __GPIO_READ_BIT(uint32_t gpio_source, uint8_t pin);

STM32F10X_GPIO_Structure stm3210x_gpio = {
  __GPIO_INIT,  
  __GPIO_SET_BIT,
  __GPIO_RESET_BIT,
  __GPIO_TOGGLE_BIT,
  __GPIO_READ_BIT,
};

/**
 * GPIO peripheral initalization
 *
 * initialize GPIO peripheral configuration
 */
void __GPIO_INIT(void)
{
  /* GPIO port configuration */
  #if (USE_BSP_LED > 0u)
  // PB.5 (LED-Red)
  GPIOB->CRL &= 0xFF0FFFFF; // Clean configuration
  GPIOB->CRL |= 0x00200000; // Mode: General-Purpose IO, 2MHz
  __GPIO_SET_BIT(GPIOB_BASE, 5);
  // PE.5 (LED-Green)
  GPIOE->CRL &= 0xFF0FFFFF; // Clean configuration
  GPIOE->CRL |= 0x00200000; // Mode: General-Purpose IO, 2MHz
  __GPIO_SET_BIT(GPIOE_BASE, 5);
  #endif
  #if (USE_BSP_BEEP > 0u)
  // PB.8 (Beep)
  GPIOB->CRH &= 0xFFFFFFF0; // Clean configuration
  GPIOB->CRH |= 0x00000002; // Mode: General-Purpose IO, 2MHz
  __GPIO_RESET_BIT(GPIOB_BASE, 8);
  #endif
  #if (USE_BSP_KEY > 0u)
  // PA.0 (Key up)
  GPIOA->CRL &= 0xFFFFFFF0; // Clean configuration
  GPIOA->CRL |= 0x00000008; // Mode: Input with pull-up / pull-down
  __GPIO_RESET_BIT(GPIOA_BASE, 0);
  // PE.2 (Key left)
  GPIOE->CRL &= 0xFFFFF0FF; // Clean configuration
  GPIOE->CRL |= 0x00000800; // Mode: Input with pull-up / pull-down
  __GPIO_SET_BIT(GPIOE_BASE, 2);
  // PE.3 (Key down)
  GPIOE->CRL &= 0xFFFF0FFF; // Clean configuration
  GPIOE->CRL |= 0x00008000; // Mode: Input with pull-up / pull-down
  __GPIO_SET_BIT(GPIOE_BASE, 3);
  // PE.4 (Key right)
  GPIOE->CRL &= 0xFFF0FFFF; // Clean configuration
  GPIOE->CRL |= 0x00080000; // Mode: Input with pull-up / pull-down
  __GPIO_SET_BIT(GPIOE_BASE, 4);
  #endif
  #if (USE_PERIPHERAL_USART1 > 0u)
  // PA.9 (USART1 TX)
  GPIOA->CRH &= 0xFFFFFF0F; // Clean configuration
  GPIOA->CRH |= 0x000000BF; // Mode: Alternate function output Pull-Push
  // PA.10 (USART1 RX)
  GPIOA->CRH &= 0xFFFFF0FF; // Clean configuration
  GPIOA->CRH |= 0x00000400; // Mode: Floating input
  #endif
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

/**
 * GPIO port read status of specific bit
 *
 * read status of bit on specific GPIO bit
 */
uint8_t __GPIO_READ_BIT(uint32_t gpio_source, uint8_t pin)
{
  /* Reset GPIO port */
  return (((((GPIO_TypeDef*)gpio_source)->IDR >> pin) & 0x0001) == 0x0000)? 0x00 : 0x01;
}
