#define MQ2pin 0
#define Threshold 500
#define 
float sensorValue; // variable to store sensor value

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("MQ2 warming up!");
  delay(20000); // Allow the MQ2 sensor to warm up
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(MQ2pin); // Read ananog input from pin0

  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  if (sensorValue > Threshold) {
    Serial.print("| Smoke detected!");
  }

  Serial.println("");
  delay(2000); // Wait 2s for next reading
}
