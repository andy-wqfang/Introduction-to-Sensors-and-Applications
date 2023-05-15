#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x3F or 0x27 for a 16 chars and 2 line display

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("hello world");
  lcd.setCursor(1, 1);
  lcd.print("Sensor Class");
}

void loop() {
  // put your main code here, to run repeatedly:

}
