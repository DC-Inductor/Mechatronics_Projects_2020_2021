//This code will cause a garage door to open and close based on how many times a button is pushed.
//include servo libraries
#include <Servo.h>

//define global variable
//define pins for reading voltage and signaling servo
int servoPin = 11;
int buttonPin = 4;

byte val = 0; //reading at button pin
//create a counter
int counter = 0;

//name servo
Servo myServo;
//define servo stop value
int servoStopValue = 1450;

void setup() {
  // put your setup code here, to run once:
  //attach servo
  myServo.attach(servoPin);
  //make servo stop (servostopvalue)
  myServo.writeMicroseconds(servoStopValue);
  //start reading voltage at button pin
  //set pinmodes
  pinMode(buttonPin, INPUT); //set button pin to read voltage
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //delay
  delay(25);
  //see if button is being pushed
  val = digitalRead(buttonPin); //assigns 1 or 0 to val, based on voltage
  if (val == 1) {
    counter = counter + 1; //adds 1 to counter
    //if button is pushed the first time open the door
    if (counter <= 1) { //if counter is <=1 call openFunction
      openFunction();
    }
    //if the button is pushed a second time close the door
    else if (counter <= 2) { //if counter is <=2 call closeFunction
      closeFunction();
    }

    //reset counter
    if (counter >= 3) { //return counter to 0
      counter = 0;
    }
  }
}

//define openFunction
void openFunction() {
  //servo spin
  myServo.writeMicroseconds(1400);
  //delay
  delay(3000);
  //servo stop value
  myServo.writeMicroseconds(servoStopValue);
}

//define closeFunction
void closeFunction() {
  //servo spin
  myServo.writeMicroseconds(1530);
  //delay
  delay(2050);
  //servo stop value
  myServo.writeMicroseconds(servoStopValue);
}

