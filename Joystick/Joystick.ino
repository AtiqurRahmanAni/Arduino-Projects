#include<SoftwareSerial.h>
SoftwareSerial bt(8, 12);
#define SPEED_PACKET_SIZE     7     //Speed packet size
#define DIRECTION_PACKET_SIZE 7     //Direction packet size
const byte ina = 4;
const byte  inb = 5;
const byte  inc = 6;
const byte  ind = 7;
const byte  ena = 3;
const byte  enb = 9;
int timeout_counter = 0;
int x, y , diff;
void setup()
{
  Serial.begin(9600);
  bt.begin(9600);
  pinMode(ina, OUTPUT);
  pinMode(inb, OUTPUT);
  pinMode(inc, OUTPUT);
  pinMode(ind, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(ina, LOW);
  digitalWrite(inb, LOW);
  digitalWrite(inc, LOW);
  digitalWrite(ind, LOW);
  digitalWrite(13, LOW);
  delay(1000);
}

void loop()
{
  if (bt.available())
  {
    while (bt.available())
      handleSerial(bt.peek());
    timeout_counter = 0;
  }
  else
  {
    if (timeout_counter > 20)
    {
      //Serial.println("Yes");
      digitalWrite(ina, LOW);
      digitalWrite(inb, LOW);
      digitalWrite(inc, LOW);
      digitalWrite(ind, LOW);
    }
    else
      timeout_counter++;
  }
  delay(25);
}
void handleSerial(char c)
{
  switch (c)
  {
    case 'S':
      {
        if (bt.available() < SPEED_PACKET_SIZE)
          break;
        y = bt.parseInt();
        if (bt.read() == 13)
        {
          if (bt.read() == 10)
          {
            //Serial.println(y);
            motorDrive(x, y);
          }
          else
            clearSerialBuffer();
        }
        else
          clearSerialBuffer();
      } break;
    case 'D':
      {
        if (bt.available() < SPEED_PACKET_SIZE)
          break;
        x = bt.parseInt();
        if (bt.read() == 13)
        {
          if (bt.read() == 10)
          {
            motorDrive(x, y);
          }
          else
            clearSerialBuffer();
        }
        else
          clearSerialBuffer();
      } break;
    default:
      clearSerialBuffer();
      break;
  }
}
void clearSerialBuffer()
{
  while (bt.available())
    bt.read();
}
void motorDrive(int x, int y)
{
  if (y == 512)
  {
    if (x == 512)
    {
      digitalWrite(ina, LOW);
      digitalWrite(inb, LOW);
      digitalWrite(inc, LOW);
      digitalWrite(ind, LOW);
    }
    else
    {
      if (x > 512)
      {
        digitalWrite(ina, LOW);
        digitalWrite(inb, HIGH);
        digitalWrite(inc, LOW);
        digitalWrite(ind, HIGH);
        analogWrite(ena, map(x, 513, 1024, 0, 255));
        analogWrite(enb, map(x, 513, 1024, 0, 255));
      }
      else if (x < 512)
      {
        digitalWrite(ina, HIGH);
        digitalWrite(inb, LOW);
        digitalWrite(inc, HIGH);
        digitalWrite(ind, LOW);
        analogWrite(ena, map(x, 511, 0, 0, 255));
        analogWrite(enb, map(x, 511, 0, 0, 255));
      }
    }
  }
  else
  {
    if (y > 512)
    {
      digitalWrite(ina, HIGH);
      digitalWrite(inb, LOW);
      digitalWrite(inc, LOW);
      digitalWrite(ind, HIGH);
      //Serial.println(x);
      if (x > 512)
      {
        diff = y - x;
        if (diff < 0)
          diff = 0;
        analogWrite(ena, map(diff, 0, 512, 0, 255));
        analogWrite(enb, map(y, 513, 1024, 0, 255));
      }
      else if (x < 512)
      {
        diff = y - map(x,511,0,513,1024);
        Serial.println(diff);
        if (diff < 0)
          diff = 0;
        analogWrite(ena, map(y, 513, 1024, 0, 255));
        analogWrite(enb, map(diff, 0, 512, 0, 255));
      }
      else
      {
        analogWrite(ena, map(y, 513, 1024, 0, 255));
        analogWrite(enb, map(y, 513, 1024, 0, 255));
      }

    }
    else if (y < 512)
    {
      digitalWrite(ina, LOW);
      digitalWrite(inb, HIGH);
      digitalWrite(inc, HIGH);
      digitalWrite(ind, LOW);
      analogWrite(ena, map(y, 511, 0, 0, 255));
      analogWrite(enb, map(y, 511, 0, 0, 255));
    }
  }
}
