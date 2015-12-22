#ifndef Led_h
#define Led_h

#include "Arduino.h"

class Led {
private:  
  byte pin;
public:
  void init(byte pin);
  void on();
  void off();
};

#endif

