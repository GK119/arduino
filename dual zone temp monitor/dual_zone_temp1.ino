const int tempSensorPins[2] = {A0, A1};
const int fanPins[2] = {2, 3};
const float thresholdTemp = 30.0;

void setup() {
  for (int i = 0; i < 2; i++) {
    pinMode(fanPins[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 2; i++) {
    int sensorValue = analogRead(tempSensorPins[i]);
    float voltage = sensorValue * (5.0 / 1023.0);
    float temperatureC = (voltage - 0.5) * 100;

    Serial.print("Zone ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(temperatureC);
    Serial.println(" °C");

    if (temperatureC > thresholdTemp) {
      digitalWrite(fanPins[i], HIGH);
    } else {
      digitalWrite(fanPins[i], LOW);
    }
  }
  delay(1000);
}
