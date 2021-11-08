const int ledRedPin = 11;
const int ledGreenPin = 10;
const int ledBluePin = 9;

const int sensorRedPin = A2;
const int sensorGreenPin = A1;
const int sensorBluePin = A0;

int sensorRedValue = 0;
int sensorGreenValue = 0;
int sensorBlueValue = 0;

int outputRed = 0;
int outputGreen = 0;
int outputBlue = 0;

void setup() {
  pinMode(ledRedPin, OUTPUT);
  pinMode(ledGreenPin, OUTPUT);
  pinMode(ledBluePin, OUTPUT);

  pinMode(sensorRedPin, INPUT);
  pinMode(sensorGreenPin, INPUT);
  pinMode(sensorBluePin, INPUT);

  Serial.begin(9600);
}

void loop() {
  sensorRedValue = analogRead(sensorRedPin);
  sensorGreenValue = analogRead(sensorGreenPin);
  sensorBlueValue = analogRead(sensorBluePin);

  outputRed = map(sensorRedValue, 0, 1023, 0, 255);
  outputGreen = map(sensorGreenValue, 0, 1023, 0, 255);
  outputBlue = map(sensorBlueValue, 0, 1023, 0, 255);

  analogWrite(ledRedPin, outputRed);
  analogWrite(ledGreenPin, outputGreen);
  analogWrite(ledBluePin, outputBlue);

  Serial.print("Output - R:");
  Serial.print(outputRed);
  Serial.print(" G:");
  Serial.print(outputGreen);
  Serial.print(" B:");
  Serial.println(outputBlue);
  delay(2000);
}
