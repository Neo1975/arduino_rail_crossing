#include "led.h"

Led::Led(int pin){
  this->pin = pin;
}

void Led::init() {
  pinMode(pin,OUTPUT);
  digitalWrite(pin,LOW);
}

void Led::lightOn(){
  digitalWrite(this->pin,HIGH);
}

void Led::lightOff(){
  digitalWrite(this->pin,LOW);
}

