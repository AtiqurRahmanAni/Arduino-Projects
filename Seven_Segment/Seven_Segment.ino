#include<SevSeg.h>
SevSeg sevseg;
int i=0;
unsigned long long current=0;
void setup() 
{
  byte numDigits=2;
  byte digitPins[]={2,3};
  byte segmentPins[]={6,7,8,9,10,11,12,13};
  bool resistor=false;
  byte hardwareConfig=COMMON_CATHODE;
  bool updateWithDelays=false;
  bool leadingZeros=false;
  sevseg.begin(hardwareConfig,numDigits,digitPins,segmentPins,resistor,updateWithDelays,leadingZeros);
  sevseg.setBrightness(100);
}

void loop() 
{
   if(millis()-current>=350)
   {
      sevseg.setNumber(i,0);
      i++;
      if(i==100)
        i=0;
      current=millis();
   }
   sevseg.refreshDisplay();
}
