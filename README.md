## Siri Controlled RGB LED-Strip Project - by Thibault and Ramtin
### DIY RGB LED strip driver that can be connected to a smart home (HomeKit) using Raspberry Pi and Arduino. 

This is a complete DIY guide going through all steps on how to build your own RGB LED Strip Driver that will be able to work together with HomeKit. This will allow you to control the LED-strip wirelessly through the use of Siri. You simply tell Siri to turn on your LED-strip and set the color to e.g. red and through the combined work of the Raspberry Pi, Arduino Uno and a nicely crafted board, the strip will light up in the color of your choice.

![](https://github.com/GitTibbe/LED-Strip-HomeKit-Driver/blob/master/Pictures/demo.gif?raw=true?)

_"Hey Siri! Put my LED Strip to red."_
### Components used for this project
- RGB-LED Strip (5m)
- Raspberry Pi 3 Model B+
- Arduino UNO
- 2x NRF24L01+ Radio Trancievers
- 3x N-Channel MOSFET transistors (IRLB8721, BUZ100 or similar)
- 3x 160 Ohm Resistors
- Circuit Board or breadboard

You may use any type of N-Channel MOSFET as long as it can handle the amount of current that your LED-strip requires.

## Design of the circuit board for the LED-strip
Depending on your resources you can create your PCB as you want as long you follow the following schematic: (rgb-board.sch)
<p align="center">
  <img src=https://raw.githubusercontent.com/GitTibbe/LED-Strip-HomeKit-Driver/master/Pictures/Schematic.png alt="schematic" >
</p>

We will provide an EAGLE file so that it can be milled on a double-sided copper plate using a PCB milling machine, but if you lack the resources, we will also include illustrative pictures of how to do all of this using traditional breadboards.

If you are using a bredboard, this image can be helpful:
<p align="center">
  <img src=https://cdn-learn.adafruit.com/assets/assets/000/002/693/original/led_strips_ledstripbjt.gif?1448059603 alt="breadboard" width=50% height=50% >
</p>

The EAGLE Board file looks like this: (rgb-board.brd)

<p align="center">
  <img src=https://raw.githubusercontent.com/GitTibbe/LED-Strip-HomeKit-Driver/master/Pictures/PCB.png alt="PCB" width=50% height=50%>
</p>

#### Connecting RF24 Tranciever to Arduino

This image shows how to connect the wireless tranceiver to the Arduino pins.
<p align="center">
  <img src=https://raw.githubusercontent.com/GitTibbe/LED-Strip-HomeKit-Driver/master/Pictures/RF24-Arduino.png alt="PCB" width=30% height=30%>
</p>

The following code is then implemented into the Arduino. (RGB_DRIVER.ino). Please note that the library RF24.h needs to be installed from e.g: https://github.com/maniacbug/RF24. The pins corresponds to the same pins as the pictures above and the same ID set to the parameter```const uint64_t pipe``` will be used later on the Raspberry Pi program.

```Arduino
#include "nRF24L01.h"
#include "RF24.h"
#include "RF24_config.h"
#include <SPI.h>
/////////////////////////////-RF24-///////////////////////////////////////
RF24 radio(9, 10); //RF24 pins
const uint64_t pipe = 0xF0F0F0F0E1LL; //ID
unsigned long RGB = 0;
//////////////////////////////-RGB-///////////////////////////////////////
#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 3
#define FADESPEED 5     // make this higher to slow down fading
int r, g, b;
int blueMask = 0xFF0000, greenMask = 0xFF00, redMask = 0xFF; //decoding masks
////////////////////////////////////////////////////////////////////////////
void setup(void) {
  //Radio module setup
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();

  //RGB pin setup
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);

  //serial Setup
  Serial.begin(9600);
  Serial.println("Started Listening...");
}

void loop(void)
{
  if (radio.available()) { //signal recieved
    if ( !radio.read(&RGB, sizeof(unsigned long)) ) {
      Serial.println("ACK not received by client."); 
    }
    //Decode RGB value
    r = (RGB & 0xFF);
    g = ((RGB & 0xFF00) >> 8);
    b = ((RGB & 0xFF0000) >> 16);

    //Serial Print
    Serial.print("Recieved RGB-value: R= "); Serial.print(r); Serial.print(", G= ");
    Serial.print(g); Serial.print(", B= "); Serial.println(b);
  }
  //set RGB pins
  analogWrite(REDPIN, r);
  analogWrite(GREENPIN, g);
  analogWrite(BLUEPIN, b);
}
```

### Design and create your own box
We provide you 3D CAD files for a 3D-printable box that fits an Arduino UNO and our PCB that we used. Depending on your circuit board dimensions you may need to create your own box. It needs 3 openings, one for the Arduino USB and DC inputs, and one RGB-LED strip output port (in our case 4 pins). The box should contain the Arduino, circuit board and RF24 tranciever with all its wires.


### [This document is being updated continuously...]

