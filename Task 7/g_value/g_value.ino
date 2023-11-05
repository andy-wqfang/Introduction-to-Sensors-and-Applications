int xpin = A0;                
 int ypin = A1;                
 int zpin = A2; 
 int xvalue;
 int yvalue;
 int zvalue;
 
void setup()
{
   Serial.begin(115200);          // initialize the serial communications:
}
 
 
void loop()
{
  xvalue = analogRead(xpin);                              //reads values from x-pin & measures acceleration in X direction 
  int x = map(xvalue, 400, 600, -10, 10);               //maps the extreme ends analog values from -100 to 100 for our understanding
//; you need to replace the 267 & 400 value with your values from calibration
  int xg = (float)x;                          //converts the mapped value into acceleration in terms of "g"
  //Serial.print("X: ");
  //Serial.print(xvalue);
  Serial.println(xg);                                       //prints value of acceleration in X direction
  //Serial.print(" ,");
//  Serial.print("g   ");                                   //prints "g"
    
 // yvalue = analogRead(ypin);
 // int y = map(yvalue, 400, 400, -100, 100);
 // float yg = (float)y/(-10);
//  Serial.print(" Y: ");
//  Serial.print(yvalue);
  //Serial.print(" ,");
 // Serial.print("\t");
//  Serial.print(yg);
 // Serial.print("g   "); 
  
//   zvalue = analogRead(zpin);
//   int z = map(zvalue,400, 600, -10, 10);
//   int zg = (float)z;
//  // Serial.print("\t"); 
//   //Serial.print(" Z: ");
//   //Serial.print(zvalue);
//  // Serial.println();
//   Serial.println(zg);
//  Serial.println("g   ");
  delay(100);
}