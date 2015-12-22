#include "button.h"

void Button::init(byte pin, void (*pressedHandler)(Button src, Button::EventType eventType)) {
  this->pressedHandler = pressedHandler;
  this->pin = pin;
  pinMode(pin,INPUT);
  currentStatus = false;
  currentStatus = false;
}

byte Button::getPin(){
  return pin;
}

void Button::update(){
  prevStatus = currentStatus;
  currentStatus = digitalRead(pin);
  if (pressedHandler != NULL && currentStatus!=prevStatus){
    pressedHandler(*this, currentStatus?PRESSED:RELEASED);
  }
}

bool Button::isPressed(){
  return currentStatus;
}

