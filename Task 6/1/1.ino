#define sensorPin 8
unsigned long lastEvent = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Read sound sensor
  int sensorData = digitalRead(sensorPin);
  if (sensorData == HIGH) {
    Serial.print("Count: ");
    Serial.println(lastEvent);
    Serial.println("");
    lastEvent += 1;
  }
  // Serial.println(sensorData);
  delay(10);
  }
