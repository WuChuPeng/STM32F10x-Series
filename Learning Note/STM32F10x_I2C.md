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
- Configurable **PEC** (packet error checking) generation or varification:
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

1. In addition to receiving and transmitting data, this interface converts it from **serial to parallel** format and vice versa. 
2. The interrupts are enabled or disabled by software.
3. The interface is connected to the I2C bus by a data pin (**SDA**) and by a clock pin (**SCL**).
4. It can be connected with a standard (up to 100KHz) or fast (up to 400KHz) I2C bus

## 3.1 Mode selection

The interface can operate in one of the four following modes:
- **Slave transmitter**
- **Slave receiver**
- **Master transmitter**
- **Master receiver**

By default, it operates in **Slave Mode**. The interface automatically switches from **slave to master**, after generates a **STRAT** condition and from master to slave. If an arbitration loss or a Stop generation occurs, allowing multimaster capability.

## 3.2 Communication flow

### 3.2.1 Master Mode 
In Master Mode, the I2C interface initates a data transfer and generates the clock signal. A serial data transfer always begins with **a start condition** and ends with **a stop condition**. Both satrt and stop condition are generated in master mode by software.

### 3.2.2 Slave Mode
In Slave Mode, the interface is capable of recognizing its **own addresses** (7 or 10-bit), and the **General Call address**. The General Call address detection may be enabled or disabled by software.

### 3.2.3 Data and Addresses Transmission
Data and addresses are transferred as 8-bit bytes, **MSB** (Mos Significant Bit) first. The first byte(s) following the **start condition** contain the **address** (one in 7-bit mode, two in 10-bit mode). The address is always transmitted in-Master mode.

A 9th clock pulse follows the 8 clock cycles of a byte transfer, during which the receiver must send an acknowledge bit to the transmitter.

![图片](https://user-images.githubusercontent.com/101664225/159149711-d8bb9161-1808-49ca-83d5-868ca562b4a1.png)

Acknowledge may be enabled or disabled by software. The I2C interface address (dual addressing 7-bit / 10-bit and/or general call address) can be selected by software.

## 3.3 I2C block diagram

![图片](https://user-images.githubusercontent.com/101664225/159149761-e301a90b-9d7a-4bf2-9d78-294e253aa804.png)

## 3.4 I2C Slave Mode

By default the I2C interface operates in Slave mode. To switch from default Slave mode to Master mode a Start Condition generation is needed.

The peripheral input clock must be programmed in the *I2C_CR2* register in order to generate correct timings. The peripheral input clock frequency must be at least:
- 2MHz in SM mode
- 4MHZ in FM mode

As soon as a start condition is detect:
1. The address is received from the **SDA** line and sent to the **shift register**.
2. The it is compared with the address of the interface (OAR1) and with OAR2 (if ENDUANL = 1) or the General Call address (if ENGC = 1).

> In 10-bit addressing mode, the comparison includes the header sequence (11110xx0), where xx denotes the **two most significant bits** of the address.

**Header or address not matched**: the interface ignores it and waits for another Start condition.

**Header matched** (10-bit mode only): the interface generates an acknowledge pulse if the ACK bit is set and waits for the 8-bit slave address.

**Address matched**: the interface generates in sequence:
- An acknowledge pulse if the **ACK** bit is set.
- The **ADDR** bit is set by hardware and an interrupt is generated if the **ITEVFEN** bit is set.
- If **ENDUAL** = 1, the software has to read the **DULF** bit to check with slave address has been acknowledged.

In 10-bit mode, after receiving the address requence the slave is always in Receiver mode. It will enter Transmitter mode on receiving **a repeated Start condition** followed by the header sequence with matching address bits and the least significant bit set (11110xx1).

The TRA bit indicates whether the slave is in Receiver or Transmitter mode.

## Slave transmitter

**Procession**

1, Following the address reception and after clearing **ADDR**, the slave sneds bytes from the **DR** register to the SDA line via the internal shift register.
2. The slave stretch SCL low until ADDR is cleared and DR filled with the data to be sent
3. When acknowledge pulse is received, The **TxE** bit is set by hardware with a interrupt if the **ITEVFEN** and **ITBUFEN** bits are set.
4. If TxE is set and some data were not written in the *I2C_DR* register before the end of the next data transmission, the BTF bit is set and the interface waits until BTF is cleared by a read to *I2C_SR1* followed by a write to the *I2C_DR* register, stretching SCL low.

![图片](https://user-images.githubusercontent.com/101664225/159150729-56248c8f-b97a-4621-97a8-cffab57f6c06.png)

