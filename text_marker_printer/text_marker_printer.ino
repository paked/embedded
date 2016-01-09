// Text Marker Printer - by Harrison Shoebridge, 2015.

const int pinMin = 5;
const int pinMax = 13;

const int charBottomLED = 6;
const int charBottomLeftLED = 5;
const int charBottomRightLED = 7;

const int charMiddleLED = 12;

const int charTopLED = 10;
const int charTopLeftLED = 11;
const int charTopRightLED = 9;

const int dotLED = 8;

int current = pinMin;

int characters[][8] = {
  // A
  {
    1, 1, 1,
       1,
    1, 0, 1, 0
  },
  // C
  {
    1, 1, 1,
       0,
    1, 1, 1, 0
  }
};

int characterMap[] = {
  charTopLeftLED, charTopLED, charTopRightLED,
                  charMiddleLED,
  charBottomRightLED, charBottomLED, charBottomRightLED, dotLED
};

void setup() {
  Serial.begin(9600);
  for (int i = pinMin; i <= pinMax; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop() {
  int charToPrint = 0; // A

  int character[8] = characters[charToPrint];

  for (int i = 0; i < sizeof(character)/sizeof(int) - 1; i++) {
    if (character[i]) {
      digitalWrite(characterMap, HIGH);
    }
  }
}
