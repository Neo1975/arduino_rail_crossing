#ifndef Led_h
#define Led_h

#include "Arduino.h"

class Led {
private:  
  int pin;
public:
  Led(int pin);
  void init();
  void on();
  void off();
};

#endif

