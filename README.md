## RGB-LED-Strip-HomeKit-Driver
### RGB LED strip driver that can be connected to a smart home (HomeKit) using Raspberry Pi and Arduino. 

This is a complete guide going through all steps on how to build your own RGB LED Strip Driver that will be able to work together with HomeKit. This will allow you to control the LED-strip wirelessly through the use of Siri. You simply tell Siri to turn on your LED-strip to and set the color to e.g. red color and through the combined work of the Raspberry Pi, Arduino Uno and a nicely crafted board, the strip will light up in the color of your choice. GIF:......

### Components used for this project
- RGB-LED Strip (5m)
- Raspberry Pi 3 Model B+
- Arduino UNO
- 2x NRF24L01+ Radio Tranciever
- 3x N-Channel MOSFET transistors (IRLB8721, BUZ100 or similar)
- 3x 160 Ohm Resistors
- Circuit Board or breadboard

You may use any type of N-Channel MOSFET as long as it can handle the amount of current that your LED-strip requires.

## Design of the circuit board for the LED-strip
Depending on your resources you can create your PCB as you want as long you follow the following schematic:
<img src=https://raw.githubusercontent.com/GitTibbe/LED-Strip-HomeKit-Driver/master/PCB.png alt="alt text" width=500 height=400>

We will provide an EAGLE file so that it can be milled on a double-sided copper plate using a PCB milling machine, but if you lack the resources, we will also include illustrative pictures of how to do all of this using traditional breadboards.
