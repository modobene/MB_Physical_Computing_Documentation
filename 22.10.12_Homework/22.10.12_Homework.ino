#include <Wire.h>
#include <Adafruit_NeoPixel.h>
#define LED_PIN 2
#define LED_COUNT 8
#define BRIGHTNESS 20
#define BTN_PIN 7
#define sensorPin A0
int lastValue = 0;
int ledState = 0;

Adafruit_NeoPixel pixels(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);
char report[80];

void setup() {
  pixels.begin();
  Serial.begin(9600);
  Wire.begin();
  pinMode(LED_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT_PULLUP);

}

void loop() {
  int sensorValue = analogRead(sensorPin);
  sensorValue = map(sensorValue, 0, 1023, 0, 255);
  sensorValue = constrain(sensorValue, 0, 255);

  pixels.clear();
  int btnState = digitalRead(BTN_PIN);
  if (btnState == 1 && lastValue == 0) {

    if (ledState == 0) {
      pixels.setBrightness(0);
      pixels.show();
    } else if (sensorValue >= 125) {
      pixels.setBrightness(50);
      pixels.setPixelColor(0, 255, 0, 0);
      pixels.setPixelColor(1, 230, 0, 50);
      pixels.setPixelColor(2, 200, 0, 100);
      pixels.setPixelColor(3, 180, 0, 150);
      pixels.setPixelColor(4, 150, 0, 180);
      pixels.setPixelColor(5, 100, 0, 200);
      pixels.setPixelColor(6, 50, 0, 230);
      pixels.setPixelColor(7, 0, 0, 255);
      pixels.show();
    } else {
      pixels.setBrightness(50);
      pixels.setPixelColor(0, 0, 255, 0);
      pixels.setPixelColor(1, 0, 230, 50);
      pixels.setPixelColor(2, 0, 200, 100);
      pixels.setPixelColor(3, 0, 180, 150);
      pixels.setPixelColor(4, 0, 150, 180);
      pixels.setPixelColor(5, 0, 100, 200);
      pixels.setPixelColor(6, 0, 50, 230);
      pixels.setPixelColor(7, 0, 0, 255);
      pixels.show();
    }
  ledState =!ledState;
 }

  lastValue = btnState;
}