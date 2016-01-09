// LED Button Interrupt - by Harrison Shoebridge, 2016
// Uses a toggle and an interrupt!

int inputHistory = -1;
bool on;

void setup() {
  pinMode(13, OUTPUT);
  // pinMode(2, INPUT);

  attachInterrupt(0, changeLED, FALLING);
}

void loop() {}

void changeLED() {
  on = !on;

  if (on) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
}
