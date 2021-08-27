#include <Servo.h>
/* TODO
 * 1. pwm scale setting
 * 2. relay on, off find
 */

#define RelayOnMotorOn    'a'
#define RelayOnMotorOff   'b'
#define RelayOffMotorOn   'c'
#define RelayOffMotorOff  'd'

#define SERVO_ON             20
#define SERVO_OFF            180

#define PIN_PWM            3
#define PIN_RELAY          2

Servo servo;
char data = RelayOffMotorOff;

void setup() {
  Serial.begin(9600);
  control(data);
  servo.attach(PIN_PWM);
}

void loop() {
  if(Serial.available() > 0){
    data = Serial.read();
    control(data);
  }
  delay(100);
  Serial.write(data);
}

void control(char c){
    switch(c){
    case RelayOnMotorOn:
      digitalWrite(PIN_RELAY, HIGH);
      servo.write(SERVO_ON);
      break;
    case RelayOnMotorOff:
      digitalWrite(PIN_RELAY, HIGH);
      servo.write(SERVO_OFF);
      break;
    case RelayOffMotorOn:
      digitalWrite(PIN_RELAY, LOW);
      servo.write(SERVO_ON);
      break;
    case RelayOffMotorOff:
      digitalWrite(PIN_RELAY, LOW);
      servo.write(SERVO_OFF);
  }
}
