int fsrPin = 0;
int fsrReading;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  fsrReading = analogRead(fsrPin);

  Serial.print("Analog reading = ");
  Serial.println(fsrReading); // Print the raw anaog reading
  if (fsrReading < 10) {
    Serial.println("-No pressure");
  } else if (fsrReading < 200) {
    Serial.println("-Light touch");
  } else if (fsrReading < 500) {
    Serial.println("-Light squeeze");
  } else if (fsrReading < 800) {
    Serial.println("-Medium squeeze");
  } else {
    Serial.println("-Big squeeze");
  }

  delay(1000);
}
