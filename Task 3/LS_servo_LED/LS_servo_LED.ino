#include <Servo.h>
int photoPin1 = A0;
int photoPin2 = A8;
 
 
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position
 
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
 Serial.begin(9600);
}
 
void loop() {
 int lightValue1 = analogRead(A0);
 int lightRaw1 = analogRead(photoPin1);
 int lightValue2 = analogRead(A8);
 int lightRaw2 = analogRead(photoPin2);
 
 
 lightValue1 = map(lightValue1,0,1023,0,180);
 lightValue2 = map(lightValue2,0,1023,0,180);
 
 Serial.print(lightValue1); Serial.print(',');Serial.println(lightValue2);
 myservo.write(lightValue1);
  
if(lightValue1<10){
 for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  }
 if(lightValue2<10){ 
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  }
}
