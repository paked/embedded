// Blink - by Harrison Shoebridge, 2016.

void setup() {
  Serial.begin(9600);
  Serial.println("Hello, World!");
  pinMode(13, OUTPUT);
}

void loop() {
  Serial.println("HALP");
  digitalWrite(13, HIGH);
  delay(1000);
  Serial.println("NO HALP");
  digitalWrite(13, LOW);
  delay(1000);
}
