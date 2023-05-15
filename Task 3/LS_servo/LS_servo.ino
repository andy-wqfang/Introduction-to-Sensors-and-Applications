#include <Servo.h>
int photoPin = A0;

Servo myservo;
int pos = 0;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int lightVal = analogRead(photoPin);
  lightVal = map(lightVal, 0, 1023, 0, 255);
  if (lightVal > 100) {
      for (pos = 0; pos < 181; pos++) {
        myservo.write(pos);
        delay(15);
      }
      for (pos = 180; pos > -1; pos--) {
        myservo.write(pos);
        delay(15);
      } 
  } else {
    delay(1000);
  }
  
}
