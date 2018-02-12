#include <Wire.h>
#include <LCD.h>
#include <DS3231.h>

#include <BigCrystal.h>
#include <LiquidCrystal_I2C.h>

#define BACKLIGHT_PIN 3
DS3231 clock;
RTCDateTime dt;
LiquidCrystal_I2C  lcd(0x3f,2,1,0,4,5,6,7);
BigCrystal bigCrystal(&lcd);

int year = 0;
int month = 0;
int day = 0;
int hour = 0;
int minute = 0;
int second = 0;
double temperature = 0;

void clockInit();
void lcdInit();
void serialInit();

void clockUpdate();
void lcdUpdate();
void serialUpdate();

void setup()
{
  clockInit();
  lcdInit();
  serialInit();
  delay(1000);
}

void loop()
{
  clockUpdate();
  lcdUpdate();
  serialUpdate();
  delay(1000);
}
void printInt(int tempNumber, int positionX, int positionY){
  if(tempNumber>9){
    printInt(tempNumber/10,positionX++,positionY);
    printInt(tempNumber%10,positionX,positionY);
    }
  else{
    char printChar = 0x30+tempNumber;
    bigCrystal.writeBig(printChar, positionX*3+1, positionY);
    }
  }
void serialInit(){
  Serial.begin(9600);
  Serial.println("Initializing system ...");
  Serial.println("by shourov");
  }
void lcdInit(){
  lcd.begin (20,4);
  bigCrystal.begin(20, 4);
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.clear();
  lcd.home();
  lcd.print("clock init ...");
  lcd.setCursor (0,3);
  lcd.print("by shourov");
  }
void clockInit(){
  clock.begin();
  //clock.setDateTime(__DATE__, __TIME__);
  }
void clockUpdate(){
  dt = clock.getDateTime();
  year = dt.year;
  month = dt.month;
  day = dt.day;
  hour = dt.hour;
  minute = dt.minute;
  second = dt.second;
  
  clock.forceConversion();
  temperature = clock.readTemperature();
  }
void lcdUpdate(){
  lcd.clear();
  lcd.home();
  lcd.print(day);   
  lcd.print("/");
  lcd.print(month);  
  lcd.print("/");
  lcd.print(year);    
  lcd.print("");
  printInt(hour,0,1);
  printInt(minute,2,1);
  printInt(second,4,1);
  lcd.setCursor(14, 3);
  lcd.print(temperature);
  lcd.print("c");
  }
void serialUpdate(){
  Serial.print("Date : ");
  Serial.print(year);   Serial.print("-");
  Serial.print(month);  Serial.print("-");
  Serial.print(day);    Serial.print(" ");
  Serial.print(hour);   Serial.print(":");
  Serial.print(minute); Serial.print(":");
  Serial.print(second); Serial.print(" ");
  
  Serial.print("Temperature: ");
  Serial.println(temperature);
  }
