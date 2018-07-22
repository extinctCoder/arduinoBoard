#include <Wire.h> 
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
SoftwareSerial BTSerial(10, 11); // RX | TX
LiquidCrystal_I2C lcd(0x27, 20, 4);
void setup()
{
  lcd.begin();
  lcd.backlight();
  BTSerial.begin(9600);
}

void loop()
{
  if (BTSerial.available()){ 
    delay(100);
    lcd.clear();
     while (BTSerial.available() > 0) {
       lcd.write(BTSerial.read());
      }
    }
}
