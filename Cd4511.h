#ifndef Cd4511_h
#define Cd4511_h

#include <inttypes.h>


class Cd4511;
typedef void (*cd4511EventHandler)(Cd4511&);

class Cd4511 {
  public:
   Cd4511(uint8_t b0Pin, uint8_t b1Pin, uint8_t b2Pin, uint8_t b3Pin);
   void display(uint8_t digit);
    
  private: 
    uint8_t mB0Pin;
    uint8_t mB1Pin;
    uint8_t mB2Pin;
    uint8_t mB3Pin;
};

#endif
