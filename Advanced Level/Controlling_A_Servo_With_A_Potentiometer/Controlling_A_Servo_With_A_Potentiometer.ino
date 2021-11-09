#include <Servo.h>

const int servoPin = 2;
const int userInputPin = A0;

Servo myservo;
int pos = 0;

void setup() {
  myservo.attach(servoPin);
  pinMode(userInputPin, INPUT);
}

void loop() {
  pos = analogRead(userInputPin);
  pos = map(pos, 0, 1023, 0, 180);
  myservo.write(pos);
  delay(100);
}