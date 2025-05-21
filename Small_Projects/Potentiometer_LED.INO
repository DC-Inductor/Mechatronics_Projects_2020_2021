int potentiometerpin = A2;  // analog pin A2 used to connect the potentiometer
int val = 0;                // variable to read the value from the analog pin
int LED = 13;               // assign LED to pin

void setup() {
  // set pin mode
  pinMode(LED, OUTPUT);
}

void loop() {
  val = analogRead(potentiometerpin);              // read value from potentiometer (0 to 1023)
  val = map(val, 0, 1023, 100, 1000);               // scale to use with LED delay

  digitalWrite(LED, HIGH);                          // turn LED on
  delay(val);                                       // wait
  digitalWrite(LED, LOW);                           // turn LED off
  delay(val);                                       // wait
}
