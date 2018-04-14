#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DS3231.h>
#include <Servo.h>
#define trigPin 3
#define echoPin 2
DS3231 clock;
RTCDateTime dt;
LiquidCrystal_I2C lcd(0x3F, 16, 2);
int pos = 0;
Servo myservo;
void setup()
{
  lcd.begin();
  lcd.backlight();
  lcd.print("wellcome...");
  clock.begin();
  myservo.attach(9);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // Set sketch compiling time
  //clock.setDateTime(__DATE__, __TIME__);
}

void loop()
{
    for (pos = 0; pos <= 180; pos += 20) {
    myservo.write(pos);        
    doIt();
    delay(500);                 
  }
  for (pos = 180; pos >= 0; pos -= 20) {
    myservo.write(pos);
    doIt();
    delay(500);                       
  }

}

void doIt(){
  lcd.clear();
  dt = clock.getDateTime();
  lcd.print("D:");
  lcd.print(dt.day);  lcd.print("/");
  lcd.print(dt.month);
  lcd.setCursor(6, 0);
  lcd.print("C:");
  lcd.print(dt.hour);   lcd.print(".");
  lcd.print(dt.minute); lcd.print(".");
  lcd.print(dt.second);
  lcd.setCursor(0, 1);
  lcd.print("T:");
  clock.forceConversion();
  lcd.print(clock.readTemperature());
  lcd.setCursor(7, 1);
  lcd.print("L:");
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
 
  if (distance >= 200 || distance <= 0){
    lcd.println("OFR");
  }
  else {
    lcd.print(distance);
  }
  }
