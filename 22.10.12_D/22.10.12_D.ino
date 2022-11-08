#include <Adafruit_NeoPixel.h>
#define LED_PIN 2
#define LED_COUNT 8
#define BRIGHTNESS 50
#define DELAYVAL 500

Adafruit_NeoPixel pixels(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800); //refresh rate

void setup() {
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif

  pixels.begin(); 
  //pixels.setBrightness(BRIGHTNESS);
}

void loop() {
  pixels.clear();
  pixels.setPixelColor(0, 0, 255, 0);
  pixels.show();
  delay(DELAYVAL);
  pixels.setPixelColor(1, 255, 0, 0);
  pixels.show();
  delay(DELAYVAL);
  pixels.setPixelColor(2, 0, 0, 255);
  pixels.show();
  delay(DELAYVAL);
  pixels.setPixelColor(3, 255, 255, 0);
  pixels.show();
  delay(DELAYVAL);
  pixels.setPixelColor(4, 0, 255, 0);
  pixels.show();
  delay(DELAYVAL);
  pixels.setPixelColor(5, 255, 0, 0);
  pixels.show();
  delay(DELAYVAL);
  pixels.setPixelColor(6, 0, 0, 255);
  pixels.show();
  delay(DELAYVAL);
  pixels.setPixelColor(7, 255, 255, 0);
  pixels.show();
  delay(DELAYVAL);
}
