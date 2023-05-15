#define sensorPin A0
#define ledPin 6

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Analog output: ");
  Serial.println(readSensor());
  delay(500);
}

int readSensor() {
  unsigned int sensorValue = analogRead(sensorPin);
  unsigned int outputValue = map(sensorValue, 0, 1023, 0, 255);

  if (outputValue > 65) {
    analogWrite(ledPin, outputValue);
  } else {
    digitalWrite(ledPin, HIGH);
  }

  return outputValue;
}