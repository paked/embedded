// Serial Read - by Harrison Shoebridge, 2016.

const int lightPin = 13;

void setup() {
  Serial.begin(9600);
  
  pinMode(lightPin, HIGH);
}

void loop() {
  if (Serial.available() > 0) {
    int incomingByte = Serial.read();

    if (incomingByte == 97) { // if the character is "a"
      digitalWrite(lightPin, HIGH);
    } else if (incomingByte == 98) { // if the character is "b"
      digitalWrite(lightPin, LOW);
    }
  }
}
