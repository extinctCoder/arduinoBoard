#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11); // RX | TX
String SerialData, BTSerialData;
String SerialDataMod, BTSerialDataMod;
void setup()
{
  //For AT Mode
  //pinMode(9, OUTPUT);
  //digitalWrite(9, HIGH);
  Serial.begin(9600);
  Serial.println("Wellcome to string  manupulation script");
  Serial.println("virtual  terminal initialized"); 
  BTSerial.begin(9600);
  Serial.println("bluetooth  terminal initialized");
}

void loop()
{
  if (BTSerial.available()){ 
    SerialData = BTSerial.readString();
    Serial.print("SerialData: "); 
    Serial.print(SerialData);
    SerialDataMod=SerialData.substring(SerialData.length()-3, SerialData.length()-1);
    SerialDataMod+=SerialData.substring(0, SerialData.length()-3);
    SerialDataMod+=SerialData.substring(SerialData.length()-1, SerialData.length());
    Serial.print("\nSerialDataMod: ");
    Serial.print(SerialDataMod);
    Serial.println();
    }
  if (Serial.available()){
    BTSerialData = Serial.readString(); 
    BTSerial.print("BTSerialData: "+BTSerialData);
    BTSerialDataMod=BTSerialData.substring(BTSerialData.length()-5, BTSerialData.length()-3);
    BTSerialDataMod+=BTSerialData.substring(0, BTSerialData.length()-5);
    BTSerialDataMod+=BTSerialData.substring(BTSerialData.length()-3, BTSerialData.length());
    BTSerial.print("BTSerialDataMod: "+BTSerialDataMod);
    }
}
