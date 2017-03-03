## RGB-LED-Strip-HomeKit-Driver
### An RGB LED strip driver that can be connected to a smart home (HomeKit) using Raspberry Pi and Arduino. 

This is a complete guide going through all steps on how to build your own RGB LED Strip Driver that will be able to work together with HomeKit. For example you will be able to tell Siri to turn on your LED-strip to red color. GIF:......

### Components used for this project
- RGB-LED Strip (5m)
- Raspberry Pi 3
- Arduino UNO
- 2x NRF24L01+ Radio Tranciever
- 3x MOSFETS transistors (IRLB8721)
- 3x 160 Ohm Resistors
- Circuit Board

You can use any type of MOSFET as long as it can take the amount of current of your LED strip.

## Creating circuit board for LED strip
Depending on your resources you can create your PCB as you want as long you follow the following schematic.
![Schematics]({{site.baseurl}}//schematics-image.png)

I will provde an EAGLE file so that it can be printed on copper plate using a PCB milling machine. 