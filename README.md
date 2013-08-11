ArduTemperatureMonitor
======================

TinyWireMCP23008 is a library that ease the use of the MCP23008 I<sup>2</sup>C port expander with an ATtiny85 microcontroller.

* [Project's page](http://goddess-gate.com/projects/en/arduino/tinywiremcp23008)


Sources
-------

TinyWireMCP23008 use multiple libraries:

* TinyWireM.* and USI_TWI_Master.*: comes from [http://playground.arduino.cc/Code/USIi2c](http://playground.arduino.cc/Code/USIi2c), and slighty modified to work on a 8 MHz ATtiny85 and with Fast Mode I<sup>2</sup>C.
* TinyWire_MCP23008.*: comes from [https://github.com/adafruit/Adafruit-MCP23008-library](https://github.com/adafruit/Adafruit-MCP23008-library), and adapted to work with TinyWire instead of Wire library.
* TinyWireMCP23008.ino: simple example to show how to use TinyWireMCP23008.


ATtiny85 frequency and I<sup>2</sup>C bus mode
--------------------------------------------

TinyWireMCP23008 was tested (and works) with a 8 MHz ATtiny85 and I<sup>2</sup>C standard bus mode and I<sup>2</sup>C fast bus mode. 

TinyWireMCP23008 was not tested with ATtiny85 other frequencie, but should work (I can't guarantee that fast bus mode will work with a 1 MHz ATtiny85).

TinyWireMCP23008 should work with other ATtiny microcontrollers.

If your ATtiny does not run at 8 MHz, you have to adapt the following line into USI_TWI_Master.cpp:

`#define F_CPU 8000000UL`

(Example : `#define F_CPU 1000000UL` for a 1 MHz ATtiny85)

If you want to disable I<sup>2</sup>C fast bus mode, you have to comment the following line into USI_TWI_Master.h:

`#define TWI_FAST_MODE`



You can find all the schematics for the provided example into “doc/TinyWireMCP23008.fzz”, to open with [Fritzing](http://fritzing.org/).

The breadboard assembly and schematics
--------------------------------------

![Breadboard assembly](/imgs/tinywiremcp23008_breadboard.png "Breadboard assembly")
![Schematics](/imgs/tinywiremcp23008_schematics.png "Schematics")
