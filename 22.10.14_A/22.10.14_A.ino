#define OUTPUT_PIN 11
#include <Servo.h>
const int DELAY_MS = 200;
int inputVal;

Servo myservo;
int pos = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(11);
  pinMode(OUTPUT_PIN, OUTPUT);
}

void loop() {
  // Check to see if there is any incoming serial data
  if (Serial.available() > 0) {
    // read string until the endo of the line
    String rcvdSerialData = Serial.readStringUntil('\n');
    int value = rcvdSerialData.toInt();
    pos = map(value, 0, 1, 0, 180);
    myservo.write(pos);
    //analogWrite(OUTPUT_PIN, rcvdSerialData.toInt());
    delay(DELAY_MS);
  }
}
