#include <Wire.h>
#include <LSM6.h>
#include <Adafruit_NeoPixel.h>
#define LED_PIN 2
#define LED_COUNT 8
#define BRIGHTNESS 20
#define potentioPin A0
Adafruit_NeoPixel pixels(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);
LSM6 imu;
char report[80];

void setup()
{
  pixels.begin();
  pixels.clear();
  pixels.setBrightness(BRIGHTNESS);
  Serial.begin(9600);
  Wire.begin();
  if (!imu.init())
  {
    Serial.println("Failed to detect and initialize IMU!");
    while (1);
  }
  imu.enableDefault();
}

void loop()
{
  pixels.clear();
  imu.read();
  int sensorValue = analogRead(sensorPin);

  snprintf(report, sizeof(report), "A: %6d %6d %6d    G: %6d %6d %6d",
    imu.a.x, imu.a.y, imu.a.z,
    imu.g.x, imu.g.y, imu.g.z);
  Serial.println(report);
  delay(100);

  if(imu.g.y >= 200) {
    pixels.clear();
    pixels.setPixelColor(0, 0, 255, 0);
    pixels.setPixelColor(1, 255, 0, 0);
    pixels.setPixelColor(2, 0, 0, 255);
    pixels.setPixelColor(3, 255, 255, 0);
    pixels.setPixelColor(4, 0, 255, 0);
    pixels.setPixelColor(5, 255, 0, 0);
    pixels.setPixelColor(6, 0, 0, 255);
    pixels.setPixelColor(7, 255, 255, 0);
    pixels.show();
  } else {
    pixels.clear();
    pixels.setPixelColor(0, 255, 255, 255);
    pixels.setPixelColor(1, 255, 255, 255);
    pixels.setPixelColor(2, 255, 255, 255);
    pixels.setPixelColor(3, 255, 255, 255);
    pixels.setPixelColor(4, 255, 255, 255);
    pixels.setPixelColor(5, 255, 255, 255);
    pixels.setPixelColor(6, 255, 255, 255);
    pixels.setPixelColor(7, 255, 255, 255);
    pixels.show();
  }
  delay(50);
}