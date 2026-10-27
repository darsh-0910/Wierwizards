
const int rainfallPin = A0;
const int waterLevelPin = A1;

const int greenLed = 8;
const int redLed = 9;
const int buzzerPin = 10;

void setup() { 
  Serial.begin(9600);

  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int rainfall = analogRead(rainfallPin);
  int waterLevel = analogRead(waterLevelPin);

  bool heavyRain = rainfall > 700;
  bool highWater = waterLevel > 700;

  Serial.print("Rainfall value: ");
  Serial.print(rainfall);
  Serial.print(" | Water level: ");
  Serial.println(waterLevel);

  if (heavyRain && highWater) {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzerPin, 1000);
    Serial.println("ALERT: High Flood Risk!");
  } else if (heavyRain || highWater) {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    noTone(buzzerPin);
    Serial.println("WARNING: Moderate Risk");
  } else {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzerPin);
    Serial.println("Normal Condition");
  }

  delay(1000);
}
