int bulbPin = 10;
int brightness = 0;
int fadeAmount = 5;

void setup() {
  pinMode(bulbPin, OUTPUT);
}

void loop(){
  analogWrite(bulbPin, brightness);
  brightness = brightness + fadeAmount;
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  delay(30);
}