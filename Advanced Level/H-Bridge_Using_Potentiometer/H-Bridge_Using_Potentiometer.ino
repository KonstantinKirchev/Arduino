const int motorEnPin = 9;
const int motorFwdPin = 10;
const int motorBkwdPin = 11;

const int potInputPin = A0;
int inputValue = 0;
int motorSpeed = 0;

void setup() {
	pinMode(motorEnPin, OUTPUT);
	pinMode(motorFwdPin, OUTPUT);
	pinMode(motorBkwdPin, OUTPUT);

	pinMode(potInputPin, INPUT);

	Serial.begin(9600);
}

void loop() {
	inputValue = analogRead(potInputPin);

	if(inputValue >= 0 & inputValue <= 472) {
		Serial.println("Clockwise");
		digitalWrite(motorFwdPin, HIGH);
		digitalWrite(motorBkwdPin, LOW);
		motorSpeed = map(inputValue, 0, 472, 255, 0);
	}
	else if(inputValue >= 552 & inputValue <= 1023) {
        Serial.println("Counterclockwise");
		digitalWrite(motorFwdPin, LOW);
		digitalWrite(motorBkwdPin, HIGH);
		motorSpeed = map(inputValue, 552, 1023, 0, 255);
	}
	else {
		Serial.println("Stop");
		digitalWrite(motorFwdPin, LOW);
		digitalWrite(motorBkwdPin, LOW);
		motorSpeed = 0;
	}

	Serial.print("Input: ");
	Serial.println(inputValue);
	Serial.print("Speed: ");
	Serial.println(motorSpeed);

	analogWrite(motorEnPin, motorSpeed);

	delay(100);
}