//This program will rotate the solar panel based on the readings from it.
//this is an example of a closed loop

//include libraries
#include <Servo.h>

//define global variables
int servoPin = 8;
int solarPin = 14;

int voltReading = 0;
int lastVoltage = 0;

int rangeSize = 10;
int lowRange = 0;

int turnCount = 0; //number of times we make small turns

//define servo
Servo myServo;
int servoStopValue = 1450;

void setup() {
  // put your setup code here, to run once:
  //set pinmodes
  pinMode(solarPin, INPUT);
  //attach and stop servo
  myServo.attach(servoPin);
  myServo.writeMicroseconds(servoStopValue);

  //set baseline for light (calibrate)
  for (int i = 0; i < 3; i++) {
    delay(1000);
    lastVoltage = voltReading; //sets LV to previous voltage
    lowRange = lastVoltage - rangeSize; //value which will initiate motion
    voltReading = analogRead(solarPin); //Assigns bytes to voltreading
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //read voltage
  delay(1000);
  lastVoltage = voltReading; //sets LV to previous voltage
  lowRange = lastVoltage - rangeSize; //voltage value which will initiate motion
  voltReading = analogRead(solarPin); //Assigns bytes to voltreading

  //if voltage drops
  if (voltReading < lowRange) {
    SmallTurnFunction(); //turn the servo
    turnCount++;
  }

  if (turnCount >= 5) {
    ResetPositionFunction(); // if end of day
    turnCount = 0;
  }

  //return to original position
}

//define turn servo a little
void SmallTurnFunction() {
  myServo.writeMicroseconds(1510);
  delay(250);
  myServo.writeMicroseconds(servoStopValue);
  delay(500);
}

//define return servo to original position
void ResetPositionFunction() {
  myServo.writeMicroseconds(1375);
  delay(650);
  myServo.writeMicroseconds(servoStopValue);
  delay(1000);
}
