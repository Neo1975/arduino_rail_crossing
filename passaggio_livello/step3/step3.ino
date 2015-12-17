#include <led.h>
//#define DEGUB 1

#define BLINK_TIME 500

bool pushingButton = false;
bool blinking = false;

Led ledLeftRed(10);
Led ledRightRed(6);

void setup(){
  ledLeftRed.init();
  ledRightRed.init();
  pinMode(13,INPUT);
  pinMode(12,INPUT);
#ifdef DEGUB
  Serial.begin(9600);
#endif
}

void loop(){
  bool v = false;
  if (!blinking){
#ifdef DEGUB
        Serial.println("Not Blinking ");
#endif

    v = digitalRead(13);
    delay(1);

    if (v && v != pushingButton){
#ifdef DEGUB
      Serial.println("Left Button Pushed ");
#endif
      blinking = true;
    }
  } else{
#ifdef DEGUB
        Serial.println("Blinking ");
#endif

      v = digitalRead(12);
      delay(1);

      if (v && v != pushingButton){
#ifdef DEGUB
        Serial.println("Right Button Pushed ");
#endif
        blinking = false;
      }
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

