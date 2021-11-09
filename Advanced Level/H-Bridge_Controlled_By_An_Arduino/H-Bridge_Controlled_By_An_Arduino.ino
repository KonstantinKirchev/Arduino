void setup() {
	pinMode(9, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);

	digitalWrite(9, HIGH);
}

void loop() {
	digitalWrite(10, HIGH);
	digitalWrite(11, LOW);
	delay(6000);

	digitalWrite(10, LOW);
	digitalWrite(11, LOW);
	delay(2000);

	digitalWrite(10, LOW);
	digitalWrite(11, HIGH);
	delay(6000);

	digitalWrite(10, LOW);
	digitalWrite(11, LOW);
	delay(2000);
}