#include "main.h"

int main(void)
{
  cortex_systick.init();
  *(uint32_t*)0x40010C00 &= 0xFF0FFFFF;
  *(uint32_t*)0x40010C00 |= 0x00200000;
  while(1)
  {
    *(uint32_t*)0x40010C0C ^= 0x00000020; // trigger bit on PB.5
    cortex_systick.delay_ms(10);
  }
}
