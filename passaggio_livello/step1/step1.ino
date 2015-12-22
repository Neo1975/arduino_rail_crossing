#include "Arduino.h"
#include <led.h>

int blinkTime = 500;

Led ledLeftRed;
Led ledRightRed;

void setup(){
  ledLeftRed.init(10);
  ledRightRed.init(4);
}

void loop(){
  ledLeftRed.on();
  delay(blinkTime);
  ledLeftRed.off();
  ledRightRed.on();
  delay(blinkTime);
  ledRightRed.off();
}
