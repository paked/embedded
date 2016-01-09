// Temperature Read - by Harrison Shoebridge, 2016.

const int temperaturePin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float value = analogRead(temperaturePin);

  float VA0 = value / 1023.0 * 5.0;
  float V0 = 5.0;
  float resistance = ((V0 * 470) / VA0) - 470;

  float temperature = 25;
  float temperatureDifference = (resistance - 470) / 1.9;
  
  temperature += temperatureDifference;

  Serial.print("My temperature is: "); Serial.print(temperature); Serial.println(" C");

  delay(1000);
}
