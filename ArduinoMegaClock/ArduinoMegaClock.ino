#include<Wire.h>
#define CLOCK_ADDRESS 0x68
#define LOAD_PIN 50
#define DATA_PIN 52
#define CLOCK_PIN 10

int read_DS3231[7];
int i, k;
uint8_t j;
int alldata[16];                                   //date, year, month, hour, minutes, seconds, temp
bool isIntensityHigh;

//----------------Pin configuration----------------//
// PB1 -> Data Pin 6 (Attiny85 physical pin)       //
// PB4 -> Clock Pin 3 (Attiny85 physical pin)      //
// PB3 -> Latch Pin 2 (Attiny85 physical pin)      //
//-------------------------------------------------//

void setup()
{

  pinMode(LOAD_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  digitalWrite(LOAD_PIN, HIGH);

  Wire.begin();
  Serial.begin(9600);
  delay(200);

  sendData(0x0F, 0x01, 0x0F, 0x01);   // Test mode on
  delay(3000);

  updateTime();

  sendData(0x0F, 0x00, 0x0F, 0x00);   // disable test mode
  sendData(0x09, 0xFF, 0x09, 0xFF);   // set decode mode for all digits
  sendData(0x0C, 0x01, 0x0C, 0x01);   // set shutdown register for normal operation
  sendData(0x0B, 0x07, 0x0B, 0x07);   // scan limit
  if (read_DS3231[2] >= 5 && read_DS3231[2] <= 23)
  {
    sendData(0x0A, 0x0F, 0x0A, 0x0F);  //set full brightness when it is 5 AM
    isIntensityHigh = true;
  }
  else if (read_DS3231[2] >= 0 && read_DS3231[2] < 5)
  {
    sendData(0x0A, 0x07, 0x0A, 0x07);  //set half brightness when it is 12 AM
    isIntensityHigh = false;
  }

  alldata[2] = 2;
  alldata[3] = 0;

  //  set(0x00, 55);        //sec
  //  set(0x01, 59);        //min
  //  set(0x02, 4);         //hour is 24H format
  //  set(0x04, 31);        //date
  //  set(0x05, 12);        //month
  //  set(0x06, 22);        //year

    delay(1000);
}

void loop()
{
  updateTime();
  //  for (i = 0; i < 16; i++)
  //  {
  //    Serial.print(alldata[i]);
  //  }
  //  Serial.println();
  for (i = 8, k = 0; i < 16; i++, k++)
  {
    sendData(i - 7, alldata[i], k + 1, alldata[k]);
  }
  delay(500);
}

void sendData(byte address1, byte data1, byte address2, byte data2)
{
  digitalWrite(LOAD_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, address1);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, data1);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, address2);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, data2);
  digitalWrite(LOAD_PIN, HIGH);
}

void updateTime()
{
  //--write to set pointer register to seconds--//
  Wire.beginTransmission(CLOCK_ADDRESS);
  Wire.write(0x00);                        //point to Seconds register
  Wire.endTransmission();

  //----------read time----------//
  Wire.requestFrom(CLOCK_ADDRESS, 3);
  if (Wire.available())
  {
    read_DS3231[0] = Wire.read();       //read seconds
    read_DS3231[1] = Wire.read();       //read minutes
    read_DS3231[2] = bcdToDec(Wire.read()); //read hours

    alldata[12] = read_DS3231[0] >> 4;          //seconds
    alldata[13] = read_DS3231[0] & 0x0F;        //seconds

    alldata[10] = read_DS3231[1] >> 4;          //minutes
    alldata[11] = read_DS3231[1] & 0x0F;        //minutes

    setBrightness(read_DS3231[2]);               //set brightness of leds

    read_DS3231[2] = read_DS3231[2] == 0 ? 12 : read_DS3231[2];
    read_DS3231[2] = read_DS3231[2] > 12 ? read_DS3231[2] - 12 : read_DS3231[2]; //convert 24H format to 12H

    alldata[9] = read_DS3231[2] % 10;           //hour
    alldata[8] = read_DS3231[2] / 10;           //hour
  }

  //---write to set pointer register to date---//
  Wire.beginTransmission(CLOCK_ADDRESS);
  Wire.write(0x04);                             //point to Date register
  Wire.endTransmission();

  //----------read date----------//
  Wire.requestFrom(CLOCK_ADDRESS, 3);
  if (Wire.available())
  {
    read_DS3231[3] = Wire.read();               //read day
    read_DS3231[4] = Wire.read() & 0x7F;        //read month
    read_DS3231[5] = Wire.read();               //read year

    alldata[0] = read_DS3231[3] >> 4;           //day
    alldata[1] = read_DS3231[3] & 0x0F;         //day

    alldata[6] = read_DS3231[4] >> 4;           //month
    alldata[7] = read_DS3231[4] & 0x0F;         //month

    alldata[4] = read_DS3231[5] >> 4;           //year
    alldata[5] = read_DS3231[5] & 0x0F;         //year
  }

  //--------------------------------------
  //write to set pointer register to temp
  //--------------------------------------
  Wire.beginTransmission(CLOCK_ADDRESS);
  Wire.write(0x11);                         //point to Temp register
  Wire.endTransmission();

  //----------read temp----------//
  Wire.requestFrom(CLOCK_ADDRESS, 1);
  if (Wire.available())
  {
    read_DS3231[6] = Wire.read();       //read integer part of temp
    alldata[15] = read_DS3231[6] % 10;          //temp
    alldata[14] = read_DS3231[6] / 10;          //temp
  }
  else
  {
    alldata[14] = alldata[15] = 0x0A; //For temp error show --. See datasheet of MAX7219, Page 8.
  }
}

void setBrightness(int val)
{
  if (!isIntensityHigh && val >= 5 && val <= 23)
  {
    sendData(0x0A, 0x0F, 0x0A, 0x0F);         //set full brightness when it is 5 AM
    isIntensityHigh = true;
  }
  else if (isIntensityHigh && val >= 0 && val < 5)
  {
    sendData(0x0A, 0x07, 0x0A, 0x07);         //set half brightness when it is 12 AM
    isIntensityHigh = false;
  }
}

byte decToBcd(byte val)
{
  return ( (val / 10 * 16) + (val % 10) );
}

byte bcdToDec(byte val)
{
  return ((val >> 4) * 10) + (val & 0x0F);
}

void set(byte add, byte data)
{
  Wire.beginTransmission(CLOCK_ADDRESS); //sec
  Wire.write(add);
  Wire.write(decToBcd(data));
  Wire.endTransmission();
}
