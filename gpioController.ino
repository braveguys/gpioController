/* TODO
 * 1. pwm scale setting
 * 2. relay on, off find
 */

#define RelayOnMotorOn    'a'
#define RelayOnMotorOff   'b'
#define RelayOffMotorOn   'c'
#define RelayOffMotorOff  'd'

#define PWM_ON             20
#define PWM_OFF            200

#define PIN_PWM            3
#define PIN_RELAY          2

char data = RelayOffMotorOff;

void setup() {
  Serial.begin(9600);
  control(data);
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
      analogWrite(PIN_PWM, PWM_ON);
      break;
    case RelayOnMotorOff:
      digitalWrite(PIN_RELAY, HIGH);
      analogWrite(PIN_PWM, PWM_OFF);
      break;
    case RelayOffMotorOn:
      digitalWrite(PIN_RELAY, LOW);
      analogWrite(PIN_PWM, PWM_ON);
      break;
    case RelayOffMotorOff:
      digitalWrite(PIN_RELAY, LOW);
      analogWrite(PIN_PWM, PWM_OFF);      
  }
}
