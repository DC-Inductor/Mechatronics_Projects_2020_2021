//Wrtitten By: Ricardo Tapia Vargas


//include libraries for servos
#include <Servo.h>

//global variables
//pin for servo
int servoPin = 8;

//define servo
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(servoPin);
  myServo.write(0); //turn to 0 degrees
  delay(2000); //wait 2 seconds
  myServo.write(30); //turn to 30 degrees
  delay(2000); //wait 2 seconds
  myServo.write(0); //turn to 0 degrees
  delay(2000); //wait 2 seconds
  myServo.write(60); //turn to 60 degrees
  delay(2000); //wait 2 seconds
  myServo.write(0); //turn to 0 degrees
  delay(2000); //wait 2 seconds
  myServo.write(90); //turn to 90 degrees
  delay(2000); //wait 2 seconds
  myServo.write(0); //turn to 0 degrees
  delay(2000); //wait 2 seconds
  myServo.write(180); //turn to 180 degrees
  delay(2000); //wait 2 seconds
  myServo.write(0); //turn to 0 degrees
  delay(2000); //wait 2 seconds
}

void loop() {
  // put your main code here, to run repeatedly:
}
