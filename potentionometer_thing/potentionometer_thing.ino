void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);

  int redValue = constrain(map(sensorValue, 0, 512, 255, 0), 0, 255);
  int greenValue = constrain(map(sensorValue, 0, 512, 0, 255), 0, 255) -
                   constrain(map(sensorValue, 512, 1023, 0, 255), 0, 255);
  int blueValue = constrain(map(sensorValue, 512, 1023, 0, 255), 0, 255);

  analogWrite(11, redValue);
  analogWrite(10, greenValue);
  analogWrite(9, blueValue);
}
