int photoPin = A0;
const int LED = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int lightRaw = analogRead(photoPin);
  Serial.println(lightRaw);

  int brightness = map(lightRaw, 0, 1023, 0, 255);
  // if (brightness > 127) {
  //   digitalWrite(LED, HIGH);
  // } else {
  //   digitalWrite(LED, LOW);
  // }
  analogWrite(LED, brightness);
  delay(100);
}
