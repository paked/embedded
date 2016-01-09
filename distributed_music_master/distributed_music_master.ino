// Distributed Music Master - by Harrison Shoebridge, 2015
#include <SPI.h>

int frozen_notes[] = {50, 66, 129, 50, 0, 66, 0, 50, 66, 129, 66, 0, 50, 0, 18, 50, 129, 18, 0, 50, 0, 129, 177, 0, 0, 161, 0, 0};
int len = 28;

const int slave_select_pin = 10;
const float semitone = 1.0594630943592952645618252949463417007792043174941856;
byte rx = 0;
byte tx = 0;

char freqs[] = {

};

void setup() {
  Serial.begin(9600);
  SPI.begin();

  pinMode(slave_select_pin, OUTPUT);
  digitalWrite(slave_select_pin, HIGH);
}

void loop() {
  for (int i = 0; i < len; i++) {
    if (frozen_notes[i] == 0) {
      delay(25);
    }

    // play on local buzzer
    // note left shift 4, XOR 
    tone(9, get_frequency(frozen_notes[i]), 100);

    digitalWrite(slave_select_pin, LOW);
    delayMicroseconds(10);

    SPI.transfer(frozen_notes[i] + 4); // send note to buzzer
    digitalWrite(slave_select_pin, HIGH);
    delay(200);
  }

  delay(200);
}

int get_frequency(int code) {
  int note = code >> 4;
  int octave = code & B1111;

  return 440 * pow(2, octave) * pow(semitone, note);
}
