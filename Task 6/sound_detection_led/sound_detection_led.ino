int Sensor = 2;
int led = 3;
int clap = 0;
long detection_range_start = 0;
long detection_range = 0;
bool status_lights = false;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Sensor, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int status_sensor = digitalRead(Sensor);
  // digitalWrite(led, HIGH);
  if (status_sensor == 1) {
    Serial.println(status_sensor);
    Serial.println("");
  }
  // Serial.println(status_sensor);
  if (status_sensor == 0) {
    if (clap == 0) {
      detection_range_start = detection_range = millis();
      clap += 1;
      printf("%i", clap);

    }

    else if (clap > 0 && millis() - detection_range >= 50) {
      detection_range = millis();
      clap += 1;
      // printf("%i", clap);

    }
  }

  if (millis() - detection_range_start >= 400) {
    if (clap == 2) {
      if (!status_lights) {
        status_lights = true;
        digitalWrite(led, HIGH);
      }

      else if (status_lights) {
        status_lights = false;
        digitalWrite(led, LOW);
      }
    }
    // clap = 0;
  }
  delay(200);
}
