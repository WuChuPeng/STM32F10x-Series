# 1.Introduction

## 1.1 Defintion

**I2C** (Inter-Integrated Circuit) bus interface serves as an interface between the microcontroller and the serial I2C bus.

## 1.2 Function

1. It provides **multimaster** capability.
2. It controls all I2C bus-specific **sequencing, protocol, arbitration, and timing**.
3. It supports the **Standard Mode** (sm, up to 100KHz) and the **Fast Mode** (fm, up to 400KHz).
4. It may be used for a variety of purposes, including **CRC generation and verification**, **SMBus** (system management bus) and **PMBus** (power management bus).
5. Depending on specific implementation **DMA** capability can be available for reduced CPU overload.

# 2. Main features

## 2.1 Main features
- **Parallel-bus / I2C protocol converter**
- **Multimaster capability**: the same interface can act as Master or Slave
- Generation and detection of 7-bit / 10-bit addressing and General Call
- Analog noise filter
- Optional clock stretching 
- 1 byte buffer with DMA capability
- Configurable **PEC** (packet error cheching) generation or varification:
  + PEC value can be transmitted as last byte in Tx mode
  + PEC error checking for last received byte
- SMBus 2.0 Compatibility
  + 25 ms clock low timeout delay
  + 10 ms master cumullative clock low extend time
  + 25 ms slave cumulative clock low extend time
  + Hardware PEC generation / verification with ACK control
  + Address Resolution Protocol (ARP) supported
- PMBus Compatibillity

## 2.2 Master features
- Clock generation
- Start and Stop generation

## 2.3 Slave features
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
  + Detection of misplaced start or stop condition
  + Overrun / Underrun if clock stretching is disabled

## 2.4 Interrupt
- 1 interrupt for successful address / data communication
- 1 interrupt for error condition

 ## 2.5 Communication speeds:
 Supoorts different communication speeds:
- Standard Speed (up to 100KHz)
- Fast Speed (up tp 400KHz)

> Some of above features may not be available in certain products. The user should refer to the product datasheet, to identify the specific features supported by the I2C interface implementation.

# 3. Functional Description

**Serial to Parallel**
In addition to receiving and transmitting data, this interface converts it from **serial to parallel** format and vice versa. 

**Enable or Disabled Interrupt**

The interrupts are enabled or disabled by software.

**Structure**
The interface is connected to the I2C bus by a data pin (**SDA**) and by a clock pin (**SCL**).

## 3.1 

