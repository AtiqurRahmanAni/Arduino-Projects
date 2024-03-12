#include <DS3231.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 5

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
RTClib myRTC;

int temp, templastdigit, tempfirstdigit;
const byte data = 6;
const byte latch = 3;
const byte clockpin = 4;
const byte a1 = 8;
const byte a2 = 9;
byte i;
int tempvar;
byte alldata[16];
byte lookup[10] = {0x7E, 0x30, 0x6D, 0x79, 0x33, 0x5B, 0x5F, 0x70, 0x7F, 0x7B};
unsigned int digits[16] = {0x8000, 0x4000, 0x2000, 0x1000, 0x800, 0x400, 0x200, 0x100, 0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1};
void setup()
{
  pinMode(data, OUTPUT);
  pinMode(clockpin, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  sensors.begin();

  Serial.begin(9600);
//  while(true)
//  {
//    digitalWrite(a1, HIGH);
//    delay(1);
//    digitalWrite(a1, LOW);
//    delay(15);
//  }
}
void loop()
{
  DateTime now = myRTC.now();
  //    sensors.requestTemperatures();
  //    temp = abs(sensors.getTempCByIndex(0));
  //  templastdigit = temp % 10;
  //  tempfirstdigit = temp / 10;
  //  Serial.println(tempfirstdigit);
  //  Serial.println(templastdigit);
  //  Serial.println(temp);

  tempvar = now.day();
  alldata[1] = tempvar % 10;
  alldata[0] = tempvar / 10;

  tempvar = now.year();
  alldata[5] = tempvar % 10;
  alldata[4] = (tempvar / 10) % 10;

  tempvar = now.month();
  alldata[7] = tempvar % 10;
  alldata[6] = tempvar / 10;

  tempvar = now.hour();
  tempvar = tempvar == 0 ? 12 : tempvar > 12 ? tempvar - 12 : tempvar;
  alldata[9] = tempvar % 10;
  alldata[8] = tempvar / 10;

  tempvar = now.minute();
  alldata[11] = tempvar % 10;
  alldata[10] = tempvar / 10;

  tempvar = now.second();
  alldata[13] = tempvar % 10;
  alldata[12] = tempvar / 10;

  for (i = 0; i < 16; i++)
  {
    digitalWrite(latch, LOW);
    //    PORTH &= 0B10011111;
    shiftOut(data, clockpin, LSBFIRST, digits[i]);
    shiftOut(data, clockpin, LSBFIRST, (digits[i] >> 8));
    digitalWrite(latch, HIGH);
    delayMicroseconds(1000);
  }
}
