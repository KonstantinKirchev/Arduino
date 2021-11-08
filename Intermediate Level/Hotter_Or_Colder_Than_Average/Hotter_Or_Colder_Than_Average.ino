const int ledBluePin = 10;
const int ledRedPin = 11;

const int sensorPin = A0;
int rawSensorValue = 0;
float sensorVoltage = 0.0;

float sensorTemperature = 0.0;

int outputRed = 0;
int outputBlue = 0;

float sensorMinValue = 1024.0;
float sensorMaxValue = -1024.0;
float halfTemp = 0;

void setup() {
  pinMode(ledRedPin, OUTPUT);
  pinMode(ledBluePin, OUTPUT);
  
  pinMode(sensorPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  rawSensorValue = analogRead(sensorPin);
  sensorVoltage = (rawSensorValue / 1024.0) * 5.0;
  sensorTemperature = (sensorVoltage - 0.5) * 100;

  Serial.print("Temperature: ");
  Serial.println(sensorTemperature);

  if(sensorTemperature < sensorMinValue) {
    sensorMinValue = sensorTemperature;
  }

  if(sensorTemperature > sensorMaxValue) {
    sensorMaxValue = sensorTemperature;
  }

  halfTemp = (sensorMaxValue - sensorMinValue) / 2;
  halfTemp = sensorMinValue + halfTemp;

  outputBlue = map(sensorTemperature, sensorMinValue, halfTemp + 1, 255, 0);
  outputRed = map(sensorTemperature, halfTemp - 1, sensorMaxValue, 1, 255);

  outputRed = constrain(outputRed, 0, 255);
  outputBlue = constrain(outputBlue, 0, 255);

  analogWrite(ledRedPin, outputRed);
  analogWrite(ledBluePin, outputBlue);

  Serial.print("Half Temp: ");
  Serial.println(halfTemp);
  Serial.print("Min Temp: ");
  Serial.println(sensorMinValue);
  Serial.print("Max Temp: ");
  Serial.println(sensorMaxValue);
  Serial.print("Blue Output: ");
  Serial.println(outputBlue);
  Serial.print("Red Output: ");
  Serial.println(outputRed);

  delay(2000);
}
