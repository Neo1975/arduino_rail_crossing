#include "led.h"

Led::Led(int pin){
  this->pin = pin;
}

void Led::init() {
  pinMode(pin,OUTPUT);
  digitalWrite(pin,LOW);
}

void Led::on(){
  digitalWrite(this->pin,HIGH);
}

void Led::off(){
  digitalWrite(this->pin,LOW);
}

