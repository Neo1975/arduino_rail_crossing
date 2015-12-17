#include "Arduino.h"
#include <led.h>

int blinkTime = 500;

Led ledLeftRed(10);
Led ledRightRed(4);

void setup(){
  ledLeftRed.init();
  ledRightRed.init();
}

void loop(){
  ledLeftRed.on();
  delay(blinkTime);
  ledLeftRed.off();
  ledRightRed.on();
  delay(blinkTime);
  ledRightRed.off();
}
