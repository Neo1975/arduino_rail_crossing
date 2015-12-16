#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button {
private:  
  int pin;
public:
  Button(int pin);
  void init();
  void lightOn();
  void lightOff();
};

#endif

