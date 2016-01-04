// Greeting - by Harrison Shoebridge, 2016.

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Hello harrison?");
  Serial.print("How are you today?\n");

  Serial.print("NCSS "); Serial.println("2016");

  delay(1500);
}

void printy() {
  String ncss = "NCSS 2016";

  for (int i = 0; i < ncss.length(); i++) {
    char c = ncss[i];

    Serial.write(int(c));
  }
}
