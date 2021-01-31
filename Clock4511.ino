#include "Cd4511.h"
#include <RTClock.h>

RTClock rtclock (RTCSEL_LSE); // initialise
tm_t mtt;

Cd4511* digit0 = new Cd4511(PB8,PB7,PB6,PB9); //IDE
Cd4511* digit1 = new Cd4511(PB4,PB3,PA15,PB5);
Cd4511* digit2 = new Cd4511(PB14,PB13,PB12,PB15); //IDE
Cd4511* digit3 = new Cd4511(PA10,PA9,PA8,PA11); //IDE


void setup() 
{
   rtclock.setTime(0);   
}

void loop() 
{
  rtclock.attachSecondsInterrupt(trigerSecond);// Call blink
}

void trigerSecond()
{
  rtclock.getTime(mtt);
  uint32_t second = mtt.second;
  uint32_t sec0 = second % 10;
  uint32_t sec1 = (second / 10) % 10;
  digit3->display(sec0);
  digit0->display(sec1);
  digit2->display(3);
  digit1->display(3);
}
