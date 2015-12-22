#include <Servo.h>

#include <button.h>
#include <led.h>
//#define DEBUG 1

#define BLINK_TIME 500
#define PIN_LEFT_LED 10
#define PIN_RIGHT_LED 6
#define PIN_LEFT_BUTTON 12
#define PIN_RIGHT_BUTTON 13
#define PIN_SERVO 5

#define SERVO_START_ANGLE 0
#define SERVO_END_ANGLE 82

bool blinking = false;

Led ledLeftRed;
Led ledRightRed;
Button btnLeft;
Button btnRight;
byte btnSrcAction;
Servo myServo;

long pressTime = 0;

void onPressed(Button src, Button::EventType eventType) {
#ifdef DEBUG
    Serial.println("onPressed");
#endif

  if (btnSrcAction==0 || btnSrcAction != src.getPin()){
    if(eventType == Button::RELEASED){
      blinking = !blinking;
      myServo.write(blinking ? SERVO_END_ANGLE : SERVO_START_ANGLE);
      pressTime = millis();
      btnSrcAction = (btnSrcAction==0 ? src.getPin() : 0);
    }
  }
}

void setup(){
  btnLeft.init(PIN_LEFT_BUTTON, onPressed);
  btnRight.init(PIN_RIGHT_BUTTON, onPressed);

  ledLeftRed.init(PIN_LEFT_LED);
  ledRightRed.init(PIN_RIGHT_LED);

  myServo.attach(PIN_SERVO);
  myServo.write(SERVO_START_ANGLE);
  
  btnSrcAction = 0;

#ifdef DEBUG
  Serial.begin(9600);
#endif
}

void loop(){
  btnLeft.update();
  btnRight.update();
  
  ledLeftRed.off();
  ledRightRed.off();
  
  if (blinking){
    if (((millis()-pressTime)/BLINK_TIME)%2 < 1){
      ledLeftRed.on();
    } else{
      ledRightRed.on();
    }
  }
}


