#define sensorPin A0
#define LEDPin 13
void setup() {
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  sensorValue = map(sensorValue, 0, 500, 255, 0);
  sensorValue = constrain(sensorValue, 0, 255);
  Serial.println(sensorValue);

  analogWrite(LEDPin, sensorValue);

  delay(50);
}
