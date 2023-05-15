	
/*Introduction to Sensors and Application Class #7 */
 
#include "DHT.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define DHTPIN 8     // what pin we're connected to
//#define DHTTYPE DHT11   // DHT 11 
#define DHTTYPE DHT22   // DHT 22 
#define pwm 9
byte degree[8] =
{
  0b00011,
  0b00011,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  //lcd.begin();
  lcd.init();      // initialize the lcd
  lcd.backlight(); // open the backlight 
  lcd.createChar(1, degree);
  lcd.clear();
  lcd.print("   Fan Speed  ");
  lcd.setCursor(0, 1);
  lcd.print("  Controlling ");
  delay(2000);
  analogWrite(pwm, 255);
  lcd.clear();
  lcd.print("Temp Sensor");
  lcd.setCursor(0, 1);
  lcd.print("Sensor Class");
  delay(2000);
  lcd.clear();
  Serial.begin(9600);
  dht.begin();
}
void loop() {
  // Wait a few seconds between measurements.
  delay(2000);
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
  Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("temp: ");
  lcd.print(t);   // Printing temperature on LCD
  lcd.print(" *C");
  lcd.setCursor(0, 1);
  if (t < 25 )
{
  analogWrite(9, 0);
    lcd.print("Fan OFF            ");
    delay(100);
  }
  else if (t >= 25 && t <= 29)
{
  analogWrite(pwm, 51);
    lcd.print("Fan Speed: 20%   ");
    delay(100);
    digitalWrite(pwm, 51);
  }
  else if (t >= 29 && t <= 30)
{
  analogWrite(pwm, 102);
    lcd.print("Fan Speed: 40%   ");
    digitalWrite(pwm, 102);
    delay(100);
 
  }
  else if (t >= 30 && t <= 31)
{
    analogWrite(pwm, 153);
    lcd.print("Fan Speed: 60%   ");
    digitalWrite(pwm, 153);
    delay(100);
  }
 else if (t >= 31 && t <= 32)
{
    analogWrite(pwm, 204);
    lcd.print("Fan Speed: 80%    ");
    digitalWrite(pwm, 204);
    delay(100);
  }
  else if (t >= 32)
{
    analogWrite(pwm, 255);
    lcd.print("Fan Speed: 100%   ");
    digitalWrite(pwm, 255);
    delay(100);
  }
  delay(2000);
}