#include "led.h"


void Led::init(byte pin) {
  this->pin = pin;
  pinMode(pin,OUTPUT);
  digitalWrite(pin,LOW);
}

void Led::on(){
  digitalWrite(this->pin,HIGH);
}

void Led::off(){
  digitalWrite(this->pin,LOW);
}

