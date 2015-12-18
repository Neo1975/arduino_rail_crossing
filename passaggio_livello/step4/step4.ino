#include <Servo.h>

#include <led.h>
//#define DEGUB 1

#define BLINK_TIME 500

bool pushingButton = false;
bool blinking = false;
bool servoMoved = false;

Led ledLeftRed(10);
Led ledRightRed(6);
Servo myServo;

void setup(){
  ledLeftRed.init();
  ledRightRed.init();
  pinMode(13,INPUT);
  pinMode(12,INPUT);
  myServo.attach(5);
#ifdef DEGUB
  Serial.begin(9600);
#endif
  myServo.write(0);
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
      if (!servoMoved){
        myServo.write(82);
        servoMoved = true;
      }
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
      if (servoMoved){
        myServo.write(0);
        servoMoved = false;
      }
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

