int lowNotePin = A3;
int medNotePin = A2;
int highNotePin = A1;

int highNote = 0;
int medNote = 0;
int lowNote = 0;

int SpeakerPin = 10;

void setup() {
  pinMode(lowNotePin, INPUT);
  pinMode(medNotePin, INPUT);
  pinMode(highNotePin, INPUT);

  pinMode(SpeakerPin, OUTPUT);
}

void loop() {
  highNote = digitalRead(highNotePin);
  medNote = digitalRead(medNotePin);
  lowNote = digitalRead(lowNotePin);

  if(lowNote == HIGH) {
    tone(SpeakerPin, 300);
  }
  else if(medNote == HIGH) {
    tone(SpeakerPin, 700);
  }
  else if(highNote == HIGH) {
    tone(SpeakerPin, 900);
  }
  else {
    noTone(SpeakerPin);
  }
}
