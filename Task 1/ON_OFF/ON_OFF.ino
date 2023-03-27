const int LED = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  char* name;
  printf("hello, ");
  scanf("%s", &name);
  printf("hello, %s", name);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  On for 1 seconds and off for .5 seconds
  */
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(500);

}
