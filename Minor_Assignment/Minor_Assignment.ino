#include <Wire.h>

#define trigPin 3
#define echoPin 2

#define pause 100

#define MOTOR_PIN_A 7
#define MOTOR_PIN_B 8
#define MOTOR_PIN_C 9
#define MOTOR_PIN_D 10
#define SPEED_PIN1 5
#define SPEED_PIN2 6
#define birnenpin 11

int lastBrightness;
int currentBrightness;

int brightnessLeft;
int brightnessRight;

void setup() {
  delay(10000);
  pinMode(MOTOR_PIN_A, OUTPUT);
  pinMode(MOTOR_PIN_B, OUTPUT);
  pinMode(MOTOR_PIN_C, OUTPUT);
  pinMode(MOTOR_PIN_D, OUTPUT);
  pinMode(SPEED_PIN1, OUTPUT);
  pinMode(SPEED_PIN2, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(birnenpin, OUTPUT);

  Serial.begin(9600);
  /*
  lastBrightness = analogRead(A0);
  currentBrightness = analogRead(A0);
  */
  brightnessLeft = analogRead(A0);
  brightnessRight = analogRead(A1);
}

void loop() {
  //One direction
  /*
  if(measureDistance() > 30){
    
    currentBrightness = analogRead(A0);
    if(currentBrightness < lastBrightness){
      driveForward();
      lastBrightness = currentBrightness;
    }
    currentBrightness = analogRead(A0);
    if(currentBrightness > lastBrightness){
      turnLeft();
      if(analogRead(A0) < lastBrightness){
        driveForward();
      }else{
        turnRight();
      }
     }
  }*/

 
  
  brightnessLeft = analogRead(A0);
  brightnessRight = analogRead(A1);

  int brightnessBirne = (brightnessLeft + brightnessRight) / 2;
  map(brightnessBirne, 0, 1023, 255, 0);

  analogWrite(birnenpin, brightnessBirne);

  Serial.println(brightnessLeft);
  Serial.println(brightnessRight);
  
  if(measureDistance() > 30){
    if(brightnessLeft == brightnessRight){
      driveForward();
    }
    
    if(brightnessLeft < brightnessRight){
      turnRight();
    }

    if(brightnessLeft > brightnessRight){
      turnLeft();
    }
    
  }else{
    turnLeft();
  }
  
  

  /*
  if(measureDistance() > 30){
    driveForward();
  }else{
    turnLeft();
  }*/
  //driveForward();
  //delay(5000);
 
  //The other direction
  //driveBackward();
  //delay(5000);
}

void driveForward(){
  digitalWrite(SPEED_PIN1, HIGH);
  digitalWrite(SPEED_PIN2, HIGH);
  digitalWrite(MOTOR_PIN_A, HIGH);
  digitalWrite(MOTOR_PIN_B, LOW);
  digitalWrite(MOTOR_PIN_C, LOW);
  digitalWrite(MOTOR_PIN_D, HIGH);
  delay(100);
}

void driveBackward(){
  digitalWrite(SPEED_PIN1, HIGH);
  digitalWrite(SPEED_PIN2, HIGH);
  digitalWrite(MOTOR_PIN_A, LOW);
  digitalWrite(MOTOR_PIN_B, HIGH);
  digitalWrite(MOTOR_PIN_C, HIGH);
  digitalWrite(MOTOR_PIN_D, LOW);
  delay(100);
}

void stopDriving(){
  digitalWrite(SPEED_PIN1, LOW);
  digitalWrite(SPEED_PIN2, LOW);
}

void turnLeft(){
  digitalWrite(SPEED_PIN1, HIGH);
  analogWrite(SPEED_PIN2, LOW);
  digitalWrite(MOTOR_PIN_A, HIGH);
  digitalWrite(MOTOR_PIN_B, LOW);
  digitalWrite(MOTOR_PIN_C, HIGH);
  digitalWrite(MOTOR_PIN_D, LOW);
  delay(100);
}

void turnRight(){
  digitalWrite(SPEED_PIN1, LOW);
  digitalWrite(SPEED_PIN2, HIGH);
  digitalWrite(MOTOR_PIN_A, HIGH);
  digitalWrite(MOTOR_PIN_B, LOW);
  digitalWrite(MOTOR_PIN_C, LOW);
  digitalWrite(MOTOR_PIN_D, HIGH);
  delay(100);
}

int measureDistance(){
  long duration, distance;

  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
      
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
       
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
      
      
  delay(pause);
  //Serial.print("Sensor:");
      //Serial.println(sensorNumber);
  if(distance < 400){
      return(distance);     
  }
      
  return(400);
}
