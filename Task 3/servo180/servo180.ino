#include <Servo.h>
// int photoPin = A0;
Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position
 
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
//  Serial.begin(9600);
}
 
void loop() {
  for (pos = 0; pos < 181; pos++) {
    myservo.write(pos);
    delay(15);
  }
  for (pos = 180; pos > -1; pos--) {
    myservo.write(pos);
    delay(15);
  }
}