// 4 Bit Binary Counter - by Harrison Shoebridge

const int START_PIN = 10;

int buttonCount = 0;
bool triggered = false;

byte data = 0;

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 8; i ++) {
    int pin = START_PIN + i;
    pinMode(pin, OUTPUT);
  }

  attachInterrupt(0, incrementButton, FALLING);
}

void loop() {
  if (triggered) {

    buttonCount++;
    render();

    triggered = false;
    Serial.println(buttonCount);
  }
}

void incrementButton() {
  triggered = true;
}

void render() {
  for (int i = 0; i < 4; i++) {
    int stat = (1 << i) & buttonCount;

    if (stat) {
      digitalWrite(i + START_PIN, HIGH);
    } else {
      digitalWrite(i + START_PIN, LOW);
    }
  }
}
