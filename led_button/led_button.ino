// LED Button - by Harrison Shoebridge, 2016
// Uses a toggle!

int inputHistory = -1;
bool on = false;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  int inputStatus = digitalRead(2);

  if (inputStatus == LOW && inputHistory == HIGH) {
    // button was pressed

    on = !on;
  }

  inputHistory = inputStatus;

  if (on) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
}
