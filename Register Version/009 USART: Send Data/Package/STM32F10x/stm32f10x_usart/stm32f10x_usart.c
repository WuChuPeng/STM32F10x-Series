#include "..\..\user\main.h"

#include <stdarg.h>
#include <stdio.h>

/**
 * Reset & clock control instance
 *
 * define USART instance to invoke variables or methods
 */
void __USART_INIT(struct _STM32F10X_USART_Structure* instance, uint32_t baud_rate);
void __USART_TRANSMIT_STRING(struct _STM32F10X_USART_Structure* instance, uint8_t *string);
void __USART_TRANSMIT_STRINGLINE(struct _STM32F10X_USART_Structure* instance, uint8_t *string);
void __USART_TRANSMIT_FORMAT_STRING(struct _STM32F10X_USART_Structure* instance, uint8_t *string, ...);
void __USART_TRANSMIT_FORMAT_STRINGLINE(struct _STM32F10X_USART_Structure* instance, uint8_t *string, ...);


STM32F10X_USART_Structure stm3210x_usart1 = {
  USART1_BASE,
  __USART_INIT,
  __USART_TRANSMIT_STRING,
  __USART_TRANSMIT_STRINGLINE,
  __USART_TRANSMIT_FORMAT_STRING,
  __USART_TRANSMIT_FORMAT_STRINGLINE,
};

/**
 * USART clock initalization
 *
 * initialize USART clock configuration
 */
void __USART_INIT(struct _STM32F10X_USART_Structure* instance, uint32_t baud_rate)
{  
  uint16_t USARTDIV;
  uint16_t mantissa, fraction;
  float value;
  
  value = PCLK2_FREQUENCY / (baud_rate << 4);
  mantissa = value;
  fraction = (value - mantissa) * 16;
  USARTDIV = (mantissa << 4) + fraction;
  #if (USE_PERIPHERAL_USART1_RXIT > 0u)
  ((USART_TypeDef*)(instance->USART_BASE))->CR1 |= 0x00000004; // Receiver: enabled
  #endif
  ((USART_TypeDef*)(instance->USART_BASE))->CR1 |= 0x00000008; // Transmitter: enabled
  ((USART_TypeDef*)(instance->USART_BASE))->CR1 |= 0x00000000; // Parity control: disabled
  ((USART_TypeDef*)(instance->USART_BASE))->CR1 |= 0x00000000; // Word length: 1 start bit, 8 data bits, 0 stop bit
  ((USART_TypeDef*)(instance->USART_BASE))->CR2 |= 0x00000000; // STOP bits: 1 stop bit
  ((USART_TypeDef*)(instance->USART_BASE))->BRR = USARTDIV;
  ((USART_TypeDef*)(instance->USART_BASE))->CR1 |= 0x00002000; // USART enable
}

void __USART_TRANSMIT_STRING(struct _STM32F10X_USART_Structure* instance, uint8_t *string)
{
  while(*string != '\0')
  {
    ((USART_TypeDef*)(instance->USART_BASE))->DR = *string;
    while((((USART_TypeDef*)(instance->USART_BASE))->SR & 0x00000040) == 0x00000000);
    string++;
  }
}

void __USART_TRANSMIT_STRINGLINE(struct _STM32F10X_USART_Structure* instance, uint8_t *string)
{
  while(*string != '\0')
  {
    ((USART_TypeDef*)(instance->USART_BASE))->DR = *string;
    while((((USART_TypeDef*)(instance->USART_BASE))->SR & 0x00000040) == 0x00000000);
    string++;
  }
  ((USART_TypeDef*)(instance->USART_BASE))->DR = 0x0D;
  while((((USART_TypeDef*)(instance->USART_BASE))->SR & 0x00000040) == 0x00000000);
  ((USART_TypeDef*)(instance->USART_BASE))->DR = 0x0A;
  while((((USART_TypeDef*)(instance->USART_BASE))->SR & 0x00000040) == 0x00000000);
}

void __USART_TRANSMIT_FORMAT_STRING(struct _STM32F10X_USART_Structure* instance, uint8_t *string, ...)
{
  uint8_t *buffer;
  va_list valist;
  va_start(valist, string);
  vsprintf((char*) buffer, (const char*)string, valist);
  va_end(valist);
  
  while(*buffer != '\0')
  {
    ((USART_TypeDef*)(instance->USART_BASE))->DR = *buffer;
    while((((USART_TypeDef*)(instance->USART_BASE))->SR & 0x00000040) == 0x00000000);
    buffer++;
  }
}

void __USART_TRANSMIT_FORMAT_STRINGLINE(struct _STM32F10X_USART_Structure* instance, uint8_t *string, ...)
{
  uint8_t *buffer;
  va_list valist;
  va_start(valist, string);
  vsprintf((char*) buffer, (const char*)string, valist);
  va_end(valist);
  
  while(*buffer != '\0')
  {
    ((USART_TypeDef*)(instance->USART_BASE))->DR = *buffer;
    while((((USART_TypeDef*)(instance->USART_BASE))->SR & 0x00000040) == 0x00000000);
    buffer++;
  }
  ((USART_TypeDef*)(instance->USART_BASE))->DR = 0x0D;
  while((((USART_TypeDef*)(instance->USART_BASE))->SR & 0x00000040) == 0x00000000);
  ((USART_TypeDef*)(instance->USART_BASE))->DR = 0x0A;
  while((((USART_TypeDef*)(instance->USART_BASE))->SR & 0x00000040) == 0x00000000);
}
