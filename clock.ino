#include <Wire.h>
#include <DS3231.h>
#include "SevSeg.h"
DS3231 clock;
RTCDateTime dt;
SevSeg sevseg;
unsigned long timer;
class time_x{
  public:
  setAllInitialPerametter(){
      clock.begin(); 
      //clock.setDateTime(__DATE__, __TIME__);
      byte numDigits = 4;
      byte digitPins[] = {6, 9, 10, 11};
      byte segmentPins[] = {2, 3, 4, 5, 12, 7, 8, 13};
      bool resistorsOnSegments = false;
      byte hardwareConfig = COMMON_ANODE;
      bool updateWithDelays = false;
      bool leadingZeros = false; 
      sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros);
      sevseg.setBrightness(50);
    }
    void updateTime(){
       dt = clock.getDateTime();
       timer = (dt.hour*100) + dt.minute;
      }
  };
time_x t; 
void setup()
{
  t.setAllInitialPerametter();
}

void loop()
{
  t.updateTime();
  sevseg.setNumber(timer, 2);
  sevseg.refreshDisplay();
  }
