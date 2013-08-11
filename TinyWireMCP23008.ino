#include "TinyWireM.h"
#include "TinyWire_MCP23008.h"

// Basic toggle test for i/o expansion. flips pin #0 of a MCP23008 I2C
// pin expander up and down. Public domain

// Connect ATtiny85 pin 4 to GND (common ground)
// Connect ATtiny85 pin 5 to MCP23008 pin 2 (I2C data line)
//                    and to a 4.7 kohms resistor, connected to VCC (pull up resistor)
// Connect ATtiny85 pin 7 to MCP23008 pin 1 (I2C clock line)
//                    and to a 4.7 kohms resistor, connected to VCC (pull up resistor)
// Connect ATtiny85 pin 8 to VCC (power, +5V)
//
//
// Connect MCP23008 pin 1  to ATtiny85 pin 7 (I2C clock line)
// Connect MCP23008 pin 2  to ATtiny85 pin 5 (I2C data line)
// Connect MCP23008 pin 3  to GND (address selection)
// Connect MCP23008 pin 4  to GND (address selection)
// Connect MCP23008 pin 5  to GND (address selection)
// Connect MCP23008 pin 6  to VCC (reset disable, +5V)
// Connect MCP23008 pin 9  to GND (common ground)
// Connect MCP23008 pin 10 to a 330 ohms resistor then LED then GND (output 0)
// Connect MCP23008 pin 18 -> VCC (power, +5V)
//
// You can either see breadboard assembly and schematics in the "imgs" folder.
// Fritzing document for breadboard assembly and schematics is in the "doc" folder.

TinyWire_MCP23008 mcp;

void setup() {
  mcp.begin(); // Default address

  mcp.pinMode(0, OUTPUT);
}

void loop() {
  
  mcp.digitalWrite(0, HIGH);
 
  delay(100);
  
  mcp.digitalWrite(0, LOW);

  delay(100);
}
