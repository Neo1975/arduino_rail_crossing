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
  ledLeftRed.lightOn();
  delay(blinkTime);
  ledLeftRed.lightOff();
  ledRightRed.lightOn();
  delay(blinkTime);
  ledRightRed.lightOff();
}
