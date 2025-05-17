// Unit_5_project
// This program will drive a car autonomously using whisker sensors
//Written by: Ricardo Tapia Vargas

#include <Servo.h>

// Declare global variables
// Pins for servos
int LServoPin = 13;
int RServoPin = 12;

// Pins for whiskers
int LWhiskerPin = 7;
int RWhiskerPin = 5;

// Variables to store whisker readings
byte LWhiskerReading = 0;
byte RWhiskerReading = 0;

// Define the servos
Servo LServo;
Servo RServo;

void setup() {
  // Attach servos
  LServo.attach(LServoPin);  // Attach left servo
  RServo.attach(RServoPin);  // Attach right servo

  // Set whisker pins as input
  pinMode(LWhiskerPin, INPUT);
  pinMode(RWhiskerPin, INPUT);

  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Read voltage at whisker pins
  LWhiskerReading = digitalRead(LWhiskerPin);
  RWhiskerReading = digitalRead(RWhiskerPin);

  // Print whisker values
  Serial.print(LWhiskerReading);
  Serial.print(" ");
  Serial.println(RWhiskerReading);

  // If both whiskers are not triggered, go forward
  if (LWhiskerReading >= 1 && RWhiskerReading >= 1) {
    ForwardFunction();
  }

  // If both whiskers are triggered, reverse and turn right
  else if (LWhiskerReading <= 0 && RWhiskerReading <= 0) {
    ReverseFunction();
    RTurnFunction();
  }

  // If only the left whisker is triggered, reverse and turn right
  else if (LWhiskerReading <= 0 && RWhiskerReading >= 1) {
    ReverseFunction();
    RTurnFunction();
  }

  // If only the right whisker is triggered, reverse and turn left
  else if (RWhiskerReading <= 0 && LWhiskerReading >= 1) {
    ReverseFunction();
    LTurnFunction();
  }
}

// Movement Functions

void ForwardFunction() {
  // Move forward
  LServo.writeMicroseconds(1600);
  RServo.writeMicroseconds(1350);
}

void ReverseFunction() {
  // Move backward
  LServo.writeMicroseconds(1300);
  RServo.writeMicroseconds(1650);
  delay(500);
}

void RTurnFunction() {
  // Turn right
  LServo.writeMicroseconds(1600);
  RServo.writeMicroseconds(1650);
  delay(650);
}

void LTurnFunction() {
  // Turn left
  LServo.writeMicroseconds(1300);
  RServo.writeMicroseconds(1350);
  delay(650);
}
