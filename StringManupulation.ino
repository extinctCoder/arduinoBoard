#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);
/*
  arduino 5v - module vcc
  arduino gnd - module gnd
  arduino 10 - module TX
  arduino 11 - module RX
  arduino 9 - module EN
*/

String SerialData, BTSerialData;
String SerialDataMod, BTSerialDataMod;
int SerialDataLen, BTSerialDataLen;

void setup()
{
  //pinMode(9, OUTPUT);
  //digitalWrite(9, HIGH);                              // uncomment this line to talk in AT mode
  Serial.begin(9600);
  Serial.println("Wellcome to string  manupulation script");
  Serial.println("virtual  terminal initialized"); 
  BTSerial.begin(9600);                                 // this is module baud rate configue it
  Serial.println("bluetooth  terminal initialized");
  Serial.println("waiting for the data ...");
}

void loop()
{
  if (BTSerial.available()){ 
    SerialData = BTSerial.readString();
    Serial.print("SerialData: "); 
    Serial.println(SerialData);
    SerialDataLen = SerialData.length();
    Serial.print("Count of number is : ");
    Serial.println(SerialDataLen);
    if(SerialDataLen==12){
        Serial.println("proceding to string manupulation,"); 
        SerialDataMod=SerialData.substring(11,12);
        SerialDataMod+=SerialData.substring(8,10);
        SerialDataMod+="-";
        SerialDataMod+=SerialData.substring(10,11);
        Serial.print("SerialDataMod: ");
        Serial.println(SerialDataMod);
      }
    else{
        Serial.println("string length mis-matched.");
      }
    }
}
