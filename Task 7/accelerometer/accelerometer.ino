int xpin = A0;
int ypin = A1;
int zpin = A2;
int xvalue;
int yvalue;
int zvalue;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  xvalue = analogRead(xpin);
  Serial.print("X: ");
  Serial.print(xvalue);

  yvalue = analogRead(ypin);
  Serial.print(" Y: ");
  Serial.print(yvalue);

  zvalue = analogRead(zpin);
  Serial.print(" Z: ");
  Serial.print(zvalue);
  Serial.println();

  delay(100);
}

