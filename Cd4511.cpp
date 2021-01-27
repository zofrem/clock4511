#include <Arduino.h>
#include "Cd4511.h"


Cd4511::Cd4511(uint8_t b0Pin, uint8_t b1Pin, uint8_t b2Pin, uint8_t b3Pin)
{
  mB0Pin = b0Pin;
  mB1Pin = b1Pin;
  mB2Pin = b2Pin;
  mB3Pin = b3Pin;
  
  pinMode(mB0Pin,OUTPUT);
  pinMode(mB1Pin,OUTPUT);
  pinMode(mB2Pin,OUTPUT);
  pinMode(mB3Pin,OUTPUT);

   digitalWrite(mB0Pin, LOW);
   digitalWrite(mB1Pin, LOW);
   digitalWrite(mB2Pin, LOW);
   digitalWrite(mB3Pin, LOW);
}

void Cd4511::display(uint8_t digit)
{
   digitalWrite(mB0Pin, bitRead((byte)digit,3));
   digitalWrite(mB1Pin, bitRead((byte)digit,2));
   digitalWrite(mB2Pin, bitRead((byte)digit,1));
   digitalWrite(mB3Pin, bitRead((byte)digit,0));   
}
