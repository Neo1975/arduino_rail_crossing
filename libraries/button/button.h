#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button {
public:
  enum EventType { 
    PRESSED = 1, 
    RELEASED = 0
  } ;
  void init(byte pin, void (*handler)(Button src, Button::EventType eventType));
  void update();
  byte getPin();
  bool isPressed();
private:  
  byte pin;
  bool currentStatus;
  bool prevStatus;
  void (*pressedHandler)(Button src, Button::EventType eventType);
};

#endif

