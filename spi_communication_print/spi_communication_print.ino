// SPI Communication Print - By Harrison Shoebridge, 2016
#include <SPI.h>
byte rx = 0;

const int slave_select_pin = 10;

void setup() {
  SPI.begin();
  SPCR = (1 << SPE);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(slave_select_pin) == LOW) {
    DDRB |= (1 << 4); // Set pin 12 to output
    rx = SPI.transfer(rx + 1); // Send value and retrieve incoming data
    DDRB &= ~(1<<4); // Set pin 12 back to input
    Serial.println(rx);
  }
}
