//This project will synch the lights to the song Jingle Bell Rock when both are stared at the same time

void setup() {
  // assign lights to pins
  int green1 = 13;
  int green2 = 6;
  int yellow = 9;
  int red = 11;

  // set pins as output
  pinMode(green1, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);

  // start music
  // intro music - green on, then red and yellow, then bell pattern
  for (int i = 0; i < 2; i++) {
    digitalWrite(green1, HIGH);
    digitalWrite(green2, HIGH);
    delay(500);
    digitalWrite(green1, LOW);
    digitalWrite(green2, LOW);
    delay(500);
    digitalWrite(red, HIGH);
    digitalWrite(yellow, HIGH);
    delay(500);
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    delay(500);
  }

  // bell sound
  for (int i = 0; i < 4; i++) {
    digitalWrite(yellow, HIGH);
    delay(500);
    digitalWrite(yellow, LOW);
    delay(500);
  }

  // full song pattern with functions
  for (int i = 0; i < 1; i++) JBJBJBRFunction();
  for (int i = 0; i < 2; i++) mainmusicFunction();
  for (int i = 0; i < 3; i++) GuitarFunction();
  for (int i = 0; i < 2; i++) mainmusicFunction();
  delay(100);
  for (int i = 0; i < 5; i++) GuitarFunction();
  for (int i = 0; i < 2; i++) mainmusicFunction();
  delay(100);
  for (int i = 0; i < 1; i++) JBJBJBRFunction();
  for (int i = 0; i < 2; i++) mainmusicFunction();
  for (int i = 0; i < 2; i++) GuitarFunction();
  for (int i = 0; i < 9; i++) mainmusicFunction();
  delay(600);
  for (int i = 0; i < 6; i++) {
    digitalWrite(yellow, HIGH);
    delay(500);
    digitalWrite(yellow, LOW);
    delay(500);
  }
  for (int i = 0; i < 2; i++) GuitarFunction();
  for (int i = 0; i < 3; i++) {
    digitalWrite(yellow, HIGH);
    delay(500);
    digitalWrite(yellow, LOW);
    delay(500);
  }

  // LED build-up then all off
  digitalWrite(green2, HIGH);
  delay(200);
  digitalWrite(yellow, HIGH);
  delay(200);
  digitalWrite(red, HIGH);
  delay(200);
  digitalWrite(green1, HIGH);
  delay(200);
  digitalWrite(green2, LOW);
  delay(200);
  digitalWrite(yellow, LOW);
  delay(200);
  digitalWrite(red, LOW);
  delay(200);
  digitalWrite(green1, LOW);
  delay(200);

  for (int i = 0; i < 3; i++) mainmusicFunction();

  // Ending
  digitalWrite(green1, HIGH);
  digitalWrite(green2, HIGH);
  delay(500);
  digitalWrite(red, HIGH);
  digitalWrite(yellow, HIGH);
  delay(500);
  digitalWrite(green2, LOW);
  delay(250);
  digitalWrite(yellow, LOW);
  delay(250);
  digitalWrite(red, LOW);
  delay(250);
  digitalWrite(green1, LOW);
  delay(250);
}

void loop() {
  // Repeat the full song pattern
  setup();  // Not recommended to call setup again; instead, refactor the main sequence into its own function
}

// Guitar Function
void GuitarFunction() {
  int yellow = 9;
  for (int i = 0; i < 1; i++) {
    digitalWrite(yellow, HIGH);
    delay(100);
    digitalWrite(yellow, LOW);
    delay(50);
  }
  return;
}

// JBJBJBR Function
void JBJBJBRFunction() {
  int red = 11;
  int green1 = 6;
  int green2 = 13;
  int yellow = 9;

  for (int i = 0; i < 1; i++) {
    digitalWrite(green1, HIGH);
    digitalWrite(green2, HIGH);
    delay(750);
    digitalWrite(green1, LOW);
    digitalWrite(green2, LOW);
    delay(200);
    digitalWrite(red, HIGH);
    delay(750);
    digitalWrite(red, LOW);
    delay(200);
    digitalWrite(green1, HIGH);
    digitalWrite(green2, HIGH);
    delay(750);
    digitalWrite(green1, LOW);
    digitalWrite(green2, LOW);
    delay(200);
    digitalWrite(yellow, HIGH);
    delay(500);
    digitalWrite(yellow, LOW);
    delay(500);
  }
  return;
}

// Main Music Function
void mainmusicFunction() {
  int red = 11;
  int green1 = 6;
  int green2 = 13;

  for (int i = 0; i < 1; i++) {
    digitalWrite(green1, HIGH);
    digitalWrite(green2, HIGH);
    delay(700);
    digitalWrite(green1, LOW);
    digitalWrite(green2, LOW);
    delay(200);
    digitalWrite(red, HIGH);
    delay(700);
    digitalWrite(red, LOW);
    delay(200);
  }
  return;
}
