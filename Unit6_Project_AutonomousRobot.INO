// Unit_6_project
// This program allows a car to drive autonomously
// It also turns on the car's "headlights" if the room is dark.
//Written by: Ricardo Tapia Vargas

#include <Servo.h>

// Global variables
// Photoresistor system
int lightPin = 5;         // LED headlight pin
int pResPin = 13;         // Photoresistor pin

// IR system
int IR_leftLight_Pin = 3;         // Left IR LED
int IR_leftReceiving_Pin = 4;     // Left IR receiver
int IR_rightLight_Pin = 6;        // Right IR LED
int IR_rightReceiving_Pin = 7;    // Right IR receiver

// Servo pins
int LServoPin = 10;
int RServoPin = 12;

// Define servos
Servo LServo;
Servo RServo;

int roomLight = 0;

void setup() {
  pinMode(pResPin, INPUT);
  pinMode(lightPin, OUTPUT);

  pinMode(IR_leftLight_Pin, OUTPUT);
  pinMode(IR_leftReceiving_Pin, INPUT);
  pinMode(IR_rightLight_Pin, OUTPUT);
  pinMode(IR_rightReceiving_Pin, INPUT);

  LServo.attach(LServoPin);
  RServo.attach(RServoPin);

  Serial.begin(9600);
}

void loop() {
  // Read room light level
  roomLight = digitalRead(pResPin);
  Serial.print(roomLight);
  Serial.println(" ");

  if (roomLight >= 1) {
    digitalWrite(lightPin, LOW); // Lights off
  } else {
    digitalWrite(lightPin, HIGH); // Lights on
  }

  // IR detection
  int irLeft = irDetect(IR_leftLight_Pin, IR_leftReceiving_Pin, 38000);
  int irRight = irDetect(IR_rightLight_Pin, IR_rightReceiving_Pin, 38000);

  Serial.print(irLeft);
  Serial.print(" ");
  Serial.println(irRight);

  delay(100);

  // Decision logic
  if (irLeft >= 1 && irRight >= 1) {
    ForwardFunction();
  }
  else if (irLeft <= 0 && irRight <= 0) {
    ReverseFunction();
    RTurnFunction();
  }
  else if (irRight <= 0 && irLeft >= 1) {
    ReverseFunction();
    LTurnFunction();
  }
  else if (irLeft <= 0 && irRight >= 1) {
    ReverseFunction();
    RTurnFunction();
  }
}

// IR detection function
int irDetect(int irLedPin, int irReceiverPin, long frequency) {
  tone(irLedPin, frequency, 8);
  delay(1);
  int ir = digitalRead(irReceiverPin);
  delay(1);
  return ir;
}

// Movement functions
void ForwardFunction() {
  LServo.writeMicroseconds(1600);
  RServo.writeMicroseconds(1350);
}

void ReverseFunction() {
  LServo.writeMicroseconds(1300);
  RServo.writeMicroseconds(1650);
  delay(500);
}

void RTurnFunction() {
  LServo.writeMicroseconds(1600);
  RServo.writeMicroseconds(1650);
  delay(650);
}

void LTurnFunction() {
  LServo.writeMicroseconds(1300);
  RServo.writeMicroseconds(1350);
  delay(650);
}
