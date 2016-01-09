// UART Communication - by Harrison Shoebridge, 2016.

#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  mySerial.begin(9600);
}

void loop() {
  mySerial.println("I came here to drink milk and kick ass... and I've just finished my milk.");
  delay(1000);
}
