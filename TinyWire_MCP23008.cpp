/*************************************************** 
  This is a library for the MCP23008 i2c port expander

  These displays use I2C to communicate, 2 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
  
  Modified by Arnaud Boudou to use TinyWire.h and work on an ATtiny85
  microcontroller.
 ****************************************************/

#include "Arduino.h"
#include "TinyWireM.h"
#include <avr/pgmspace.h>
#include "TinyWire_MCP23008.h"


////////////////////////////////////////////////////////////////////////////////
// RTC_DS1307 implementation

void TinyWire_MCP23008::begin(uint8_t addr) {
  if (addr > 7) {
    addr = 7;
  }
  i2caddr = addr;

  TinyWireM.begin();

  // set defaults!
  TinyWireM.beginTransmission(MCP23008_ADDRESS | i2caddr);
  TinyWireM.send((byte)MCP23008_IODIR);
  TinyWireM.send((byte)0xFF);  // all inputs
  TinyWireM.send((byte)0x00);
  TinyWireM.send((byte)0x00);
  TinyWireM.send((byte)0x00);
  TinyWireM.send((byte)0x00);
  TinyWireM.send((byte)0x00);
  TinyWireM.send((byte)0x00);
  TinyWireM.send((byte)0x00);
  TinyWireM.send((byte)0x00);	
  TinyWireM.endTransmission();

}

void TinyWire_MCP23008::begin(void) {
  begin(0);
}

void TinyWire_MCP23008::pinMode(uint8_t p, uint8_t d) {
  uint8_t iodir;
  

  // only 8 bits!
  if (p > 7)
    return;
  
  iodir = read8(MCP23008_IODIR);

  // set the pin and direction
  if (d == INPUT) {
    iodir |= 1 << p; 
  } else {
    iodir &= ~(1 << p);
  }

  // write the new IODIR
  write8(MCP23008_IODIR, iodir);
}

uint8_t TinyWire_MCP23008::readGPIO(void) {
  // read the current GPIO input 
  return read8(MCP23008_GPIO);
}

void TinyWire_MCP23008::writeGPIO(uint8_t gpio) {
  write8(MCP23008_GPIO, gpio);
}


void TinyWire_MCP23008::digitalWrite(uint8_t p, uint8_t d) {
  uint8_t gpio;
  
  // only 8 bits!
  if (p > 7)
    return;

  // read the current GPIO output latches
  gpio = readGPIO();

  // set the pin and direction
  if (d == HIGH) {
    gpio |= 1 << p; 
  } else {
    gpio &= ~(1 << p);
  }

  // write the new GPIO
  writeGPIO(gpio);
}

void TinyWire_MCP23008::pullUp(uint8_t p, uint8_t d) {
  uint8_t gppu;
  
  // only 8 bits!
  if (p > 7)
    return;

  gppu = read8(MCP23008_GPPU);
  // set the pin and direction
  if (d == HIGH) {
    gppu |= 1 << p; 
  } else {
    gppu &= ~(1 << p);
  }
  // write the new GPIO
  write8(MCP23008_GPPU, gppu);
}

uint8_t TinyWire_MCP23008::digitalRead(uint8_t p) {
  // only 8 bits!
  if (p > 7)
    return 0;

  // read the current GPIO
  return (readGPIO() >> p) & 0x1;
}

uint8_t TinyWire_MCP23008::read8(uint8_t addr) {
  TinyWireM.beginTransmission(MCP23008_ADDRESS | i2caddr);
  TinyWireM.send((byte)addr);	
  TinyWireM.endTransmission();
  TinyWireM.requestFrom(MCP23008_ADDRESS | i2caddr, 1);

  return TinyWireM.receive();
}


void TinyWire_MCP23008::write8(uint8_t addr, uint8_t data) {
  TinyWireM.beginTransmission(MCP23008_ADDRESS | i2caddr);
  TinyWireM.send((byte)addr);
  TinyWireM.send((byte)data);
  TinyWireM.endTransmission();
}
