const int inputPin = A0;
int userInputValue = 0;

void setup() {
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  userInputValue = analogRead(inputPin);
  Serial.print("User input: ");
  Serial.println(userInputValue);
  delay(1000);
}
