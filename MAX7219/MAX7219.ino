#include<SPI.h>
#include <Wire.h>
#include <DS3231.h>
RTClib myRTC;

DS3231 cloc;

const int clockpin = 13;
const int datapin = 11;
const int latchpin = 10;
byte i, j;
int tempvar;
byte lookup[10] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09};
byte alldata[16];
void setup()
{
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);

  PORTB |= 0B11111011;
  sendData(0x0f, 0x00, 0x0f, 0x00); // disable test mode;
  sendData(0x0c, 0x01, 0x0c, 0x01); // set shutdown register for normal operation
  sendData(0x09, 0xff, 0x09, 0xff); // set decode mode for all digits
  sendData(0x0a, 0x0f, 0x0a, 0x0f); // set brightness
  sendData(0x0b, 0x07, 0x0b, 0x07); // scan limit
  PORTB |= 0B00000100;

  alldata[2] = 2;
  alldata[3] = 0;
  alldata[14] = 3;
  alldata[15] = 2;

  cloc.setYear(22);
  cloc.setMonth(10);
  cloc.setDate(31);
  //  clock.setDoW(dOW);
  cloc.setHour(4);
  cloc.setMinute(59);
  cloc.setSecond(58);

  //  Serial.begin(9600);

}
void loop()
{
  DateTime now = myRTC.now();
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


  for (i = 8, j = 0; i <= 15; i++, j++)
  {
    sendData(i - 7, lookup[alldata[i]], j + 1, lookup[alldata[j]]);
  }
  delay(1000);
}

void sendData(byte address1, byte data1, byte address2, byte data2)
{
  PORTB &= 0B11111011;
  SPI.transfer(address1);
  SPI.transfer(data1);
  SPI.transfer(address2);
  SPI.transfer(data2);
  PORTB |= 0B00000100;
}
