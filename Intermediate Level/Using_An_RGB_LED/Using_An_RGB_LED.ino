const int ledGreen = 9;
const int ledBlue = 10;
const int ledRed = 11;

void setup() {
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(ledRed, OUTPUT);
}

void loop() {
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledBlue, LOW);
  digitalWrite(ledRed, LOW);
  delay(1000);

  digitalWrite(ledGreen, LOW);
  digitalWrite(ledBlue, HIGH);
  digitalWrite(ledRed, LOW);
  delay(1000);

  digitalWrite(ledGreen, LOW);
  digitalWrite(ledBlue, LOW);
  digitalWrite(ledRed, HIGH);
  delay(1000);
}
