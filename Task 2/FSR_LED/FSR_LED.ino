const int OUTPUT_LED_PIN = 3;
const int INPUT_FSR_PIN = A0;
const int DELAY = 50;


void setup() {
  // put your setup code here, to run once:
  pinMode(OUTPUT_LED_PIN, OUTPUT);
  pinMode(INPUT_FSR_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Read the force-sensitive resistor value
  int fsrVal = analogRead(INPUT_FSR_PIN);
  // Remap the value for output
  int ledVal = map(fsrVal, 0, 1023, 0, 255);
  // Print the raw sensor value and the converted led value
  Serial.print(fsrVal);
  Serial.print(",");
  Serial.println(ledVal);

  // Write out the LED value
  analogWrite(OUTPUT_LED_PIN, ledVal);
}
