# 1.Introduction
---
## 1.1 Defintion

**I2C** (Inter-Integrated Circuit) bus interface serves as an interface between the microcontroller and the serial I2C bus.

## 1.2 Function

1. It provides **multimaster** capability.
2. It controls all I2C bus-specific **sequencing, protocol, arbitration, and timing**.
3. It supports the **Standard Mode** (sm, up to 100KHz) and the **Fast Mode** (fm, up to 400KHz).
4. It may be used for a variety of purposes, including** CRC generation and verification**, **SMBus** (system management bus) and **PMBus** (power management bus).
5. Depending on specific implementation **DMA** capability can be available for reduced CPU overload.

# 2. Main features
---

## 2.1 Main features
- **Parallel-bus / I2C protocol converter**
- **Multimaster capability**: the same interface can act as Master or Slave
 - Generation and detection of 7-bit / 10-bit addressing and General Call
 - Supoorts different communication speeds:
  + Standard Speed (up to 100KHz)
  + Fast Speed (up tp 400KHz)
- Analog noise filter

## 2.2 I2C Master features
- Clock generation
- Start and Stop generation

## 2.3 I2C Slave features
- Programmable I2C address detection
- Dual Addressing Capability to acknowledge 2 slave address
- Stop bit detection

## 2.4 Flag
- Status flag
  + Transmitter / Receiver mode flag
  + End of Byte transmission flag
  + I2C busy flag
- Error flag
  + Arbitration lost condition for master mode
  + Acknowledgement failure after address / data transmission


  + 