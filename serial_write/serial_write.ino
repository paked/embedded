// Serial Write - by Harrison Shoebridge, 2016.

void setup() {
  Serial.begin(9600);
}

void loop() {
  printy();
  delay(1000);
}

void printy() {
  String ncss = "NCSS 2016\n";

  for (int i = 0; i < ncss.length(); i++) {
    char c = ncss[i];

    Serial.write(int(c));
  }
}
