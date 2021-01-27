#include "Button.h"
#include "Cd4511.h"
#include <RTClock.h>

Button* butt = new Button(13);
RTClock rtclock (RTCSEL_LSE); // initialise
Cd4511* digit0 = new Cd4511(PB8,PB7,PB6,PB9); //7 oposite !!
Cd4511* digit1 = new Cd4511(PB10,PB11,PB12,PB13); 
Cd4511* digit2 = new Cd4511(PB0,PB1,PB2,PB3);
Cd4511* digit3 = new Cd4511(PA0,PA1,PA2,PA3);
uint8_t num = 0;
void setup() {
  rtclock.setTime(0);
  rtclock.attachSecondsInterrupt(secondTrigger);// Call SecondCount
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  uint32_t time = rtclock.getTime();
}

void secondTrigger()
{
  digit0->display(num);
    ++num;
  if(10 == num)
    num = 0;
}
