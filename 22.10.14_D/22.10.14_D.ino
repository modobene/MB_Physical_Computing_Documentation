#include <Servo.h>
#define OUTPUT_PIN 11
const int DELAY_MS = 20;
int inputVal; 

Servo myservo;

int value = 0; //starting value servo position

void setup() {
  Serial.begin(9600);
  myservo.attach(11);
}

void loop() {
  // Check to see if there is any incoming serial data
  if (Serial.available() > 0) {
    //read string until the end of the line
    String rcvdSerialData = Serial.readStringUntil('\n');
      value = rcvdSerialData.toInt();
      Serial.print("Data received:" + value);
      myservo.write(value);
      //analogWrite(OUTPUT_PIN, rcvdSerialData.toInt());
      delay(DELAY_MS);
  }
}
