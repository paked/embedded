// PWM - by Harrison Shoebridge

const int width = 2;

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(width);
  digitalWrite(13, LOW);
  delay(20 - width);
}
