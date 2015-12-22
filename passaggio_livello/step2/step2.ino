#include <led.h>
//#define DEGUB 1

#define BLINK_TIME 500

bool pushingButton = false;
bool blinking = false;

Led ledLeftRed;
Led ledRightRed;

void setup(){
  ledLeftRed.init(10);
  ledRightRed.init(6);
  pinMode(13,INPUT);
#ifdef DEGUB
  Serial.begin(9600);
#endif
}

void loop(){
  bool v = digitalRead(13);
  delay(1);

  if (v && v != pushingButton){
#ifdef DEGUB
    Serial.println("Button Pushed ");
#endif
    blinking = !blinking;
  }

  if (blinking){
    ledLeftRed.on();
    delay(BLINK_TIME);
    ledLeftRed.off();
    ledRightRed.on();
    delay(BLINK_TIME);
    ledRightRed.off();
  }

  pushingButton = v;

}

