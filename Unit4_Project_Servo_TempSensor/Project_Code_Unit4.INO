// Unit_4_project
// This code will rotate a servo depending on the temperature reading from a temperature sensor

#include <Servo.h>

// Define global variables
// Define pins
int servoPin = 4;           // Pin for the servo
int tempPin = A0;           // Analog pin A0 for temperature sensor

int bitReading = 0;         // Variable to store sensor bits
int turnCount = 0;          // Tracks open/close state

Servo myServo;

int ServoStopValue = 1450;  // Neutral servo stop position
float bits2volts = 5000.0 / 1023.0;  // Conversion from bits to millivolts
float Temperature = 0;      // Temperature in Celsius

void setup() {
  // Attach servo
  myServo.attach(servoPin);
  myServo.writeMicroseconds(ServoStopValue);  // Initialize servo to neutral

  // Set pin mode for temperature sensor
  pinMode(tempPin, INPUT);

  // Begin serial communication
  Serial.begin(9600);
}

void loop() {
  delay(1000);  // Wait 1 second between reads

  // Read temperature
  bitReading = analogRead(tempPin);
  Temperature = (bits2volts * bitReading) / 10.0 - 50.0;  // LM35 conversion
  Serial.println(Temperature);
  Serial.print(" ");

  // If temperature >= 27°C and has not been opened yet
  if (turnCount == 0) {
    if (Temperature >= 27) {
      openFunction();  // Rotate to open
      turnCount++;
    }
  }

  // If temperature drops to <= 23°C and has already been opened
  if (turnCount >= 1) {
    if (Temperature <= 23) {
      closeFunction();  // Rotate to close
      turnCount++;
    }
  }

  // Reset count after one full cycle
  if (turnCount >= 2) {
    turnCount = 0;
  }
}

// Define function to open
void openFunction() {
  delay(3000);  // Wait before action
  myServo.writeMicroseconds(1510);  // Rotate to open
  delay(700);
  myServo.writeMicroseconds(ServoStopValue);  // Stop servo
}

// Define function to close
void closeFunction() {
  delay(3000);  // Wait before action
  myServo.writeMicroseconds(1410);  // Rotate to close
  delay(700);
  myServo.writeMicroseconds(ServoStopValue);  // Stop servo
}
