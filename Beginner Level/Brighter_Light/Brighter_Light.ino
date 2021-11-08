int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  analogWrite(ledPin, 0);
  delay(300);
  analogWrite(ledPin, 90);
  delay(300);
  analogWrite(ledPin, 130);
  delay(300);
  analogWrite(ledPin, 190);
  delay(300);
  analogWrite(ledPin, 255);
  delay(300);
}
