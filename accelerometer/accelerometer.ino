// Accelerometer - by Harrison Shoebridge, 2016.

float offsetX;
float offsetY;
float offsetZ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  offsetX = getGs(analogRead(A0));
  offsetY = getGs(analogRead(A1));
  offsetZ = getGs(analogRead(A2)) - 1;
}

void loop() {
  float x = getGs(analogRead(A0)) - offsetX;
  float y = getGs(analogRead(A1)) - offsetY;
  float z = getGs(analogRead(A2)) - offsetZ;

  Serial.print("My X is "); Serial.print(x); Serial.print(", my Y is "); Serial.print(y); Serial.print(" and my Z is  "); Serial.println(z);
  delay(100);
}

float getGs(int value) {
  return (1.5 * ((map(value, 0, 675, 0, 3300) / 1000.0) / 0.8));
}
