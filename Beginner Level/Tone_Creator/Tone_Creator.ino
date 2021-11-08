int SpeakerPin = 10;

void setup() {
  pinMode(SpeakerPin, OUTPUT);

}

void loop() {
  tone(SpeakerPin, 300);
  delay(1000);

  tone(SpeakerPin, 700);
  delay(1000);

  tone(SpeakerPin, 999);
  delay(1000);

  noTone(SpeakerPin);
  delay(1000);
}
