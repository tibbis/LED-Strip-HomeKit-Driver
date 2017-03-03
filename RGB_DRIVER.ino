#include "nRF24L01.h"
#include "RF24.h"
#include "RF24_config.h"
#include <SPI.h>

/////////////////////////////-RF24-////////////////////////////////////////
RF24 radio(9, 10); //RF24 pins
const uint64_t pipe = 0xF0F0F0F0E1LL; //ID
unsigned long RGB = 0;
/////////////////////////////////////////////////////////////////////////

//////////////////////////////-RGB-/////////////////////////////////////////
#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 3
#define FADESPEED 5     // make this higher to slow down fading
int r, g, b;
int blueMask = 0xFF0000, greenMask = 0xFF00, redMask = 0xFF; //decoding masks
//////////////////////////////////////////////////////////////////////////


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

//fade function you can play with
void fade(void) {
  // fade from blue to violet
  for (r = 0; r < 256; r++) {
    analogWrite(REDPIN, r);
    delay(FADESPEED);

  }
  // fade from violet to red
  for (b = 255; b > 0; b--) {
    analogWrite(BLUEPIN, b);
    delay(FADESPEED);

  }
  // fade from red to yellow
  for (g = 0; g < 256; g++) {
    analogWrite(GREENPIN, g);
    delay(FADESPEED);

  }
  // fade from yellow to green
  for (r = 255; r > 0; r--) {
    analogWrite(REDPIN, r);
    delay(FADESPEED);

  }
  // fade from green to teal
  for (b = 0; b < 256; b++) {
    analogWrite(BLUEPIN, b);
    delay(FADESPEED);

  }
  // fade from teal to blue
  for (g = 255; g > 0; g--) {
    analogWrite(GREENPIN, g);
    delay(FADESPEED);
  }

}


