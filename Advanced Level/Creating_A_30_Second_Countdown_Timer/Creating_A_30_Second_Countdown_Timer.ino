#include <Servo.h>

const int servoPin = 9;
const int buttonPin = 2;
int servoPos = 0;
int timerCurValue = 0;
const int timerSetValue = 30;

Servo myservo;

void setup() {
  myservo.attach(servoPin);
  Serial.begin(9600);
  myservo.write(servoPos);
  pinMode(buttonPin, INPUT_PULLUP);
  delay(2000);
}

void loop() {
  if(digitalRead(buttonPin) == LOW) {
	  timerCurValue = 0;
	  Serial.println("*** TIMER RESTARTED ***");
  }
  servoPos = timerSetValue * 3;
  Serial.print("Timer: ");
  Serial.println(timerCurValue);
  Serial.print("Position: ");
  Serial.println(servoPos);
  Serial.println();

  myservo.write(servoPos);

  if(timerCurValue < timerSetValue) {
	  timerCurValue = timerCurValue + 1;
  }

  delay(1000);
}