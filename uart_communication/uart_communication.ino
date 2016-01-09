// UART Communication - by Harrison Shoebridge, 2016.

#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  mySerial.begin(9600);

  mySerial.write(10);
}

void loop() {
  if (mySerial.available() > 0) {
    int incoming = mySerial.read();
    Serial.println(incoming);

    mySerial.write(incoming + 1);
  }

  delay(100);
}
