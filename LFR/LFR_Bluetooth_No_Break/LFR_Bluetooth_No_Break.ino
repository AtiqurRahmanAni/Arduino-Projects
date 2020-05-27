#include<LiquidCrystal_I2C.h>
#include<Wire.h>
#include<OneButton.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
OneButton btn = OneButton(2, true);
const byte ina = 4;
const byte  inb = 5;
const byte  inc = 6;
const byte  ind = 7;
const byte  ena = 3;
const byte  enb = 9;
const byte button = 2;
const byte eco = 13;
const int leftbasespeed = 150; //Speed for line follow
const int rightbasespeed = 150; //Speed for line follow
const int maxspeed = 170; //Speed for line follow
const int turnspeedright = 100; //Speed for line follow
const int turnspeedleft = 100; //Speed for line follow
long long buttonpressdelay = 0;
int lastsensor, num_sensor = 8, i, j, threshold = 450;
int leftspeed = 0, rightspeed = 0;
float kp = 6.20; //4
float kd = 90; //33
//For wall follow
const int wallleftbasespeed = 55; //Speed for wall follow
const int wallrightbasespeed = 55; //Speed for wall follow
const int wallmaxspeed = 60; //Speed for wall follow
float wallkp = 8.40;
float wallkd = 29;
int setpoint = 12;
double duration, distance;
int wallpreverror;

bool dolinefollow = false, botStop = true, doubleclk = false, singleclk = false, sensorpos = false, tune = false, stopflag = false;
int flag;
String sx = "", s1 = "";
char c;
bool linecolorblack = true;
int s[8];
/*int right[] = {1, 3, 4, 5, 11};
  int left[] = {2, 7, 8, 10, 13, 14};
  int straight[] = {6, 9};
  int forwardright[] = {};
  int forwardleft[] = {12};*/
int right[] = {1, 2, 5, 6, 7, 11};
int left[] = {4, 8, 9, 10, 12};
int straight[] = {};
int forwardright[] = {3};
int forwardleft[] = {};
int nr = sizeof(right) / sizeof(int);
int nl = sizeof(left) / sizeof(int);
int ns = sizeof(straight) / sizeof(int);
int nfr = sizeof(forwardright) / sizeof(int);
int nfl = sizeof(forwardleft) / sizeof(int);
int preverror, count = 0, maxcount = 12;
int del = 4500, sums = 0;
char minimum[4], maximum[4], countstring[3];
int mini = 10000, maxi, temp;
byte customChar[] = {
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F
};
int conditions();
void lineFollow();
void wallFollow();
void wheel(int leftspeed, int rightspeed);
void readLine();
void measureDistance();
void turnRight(int del1, int del2);
void turnLeft(int del1, int del2);
void goStraight(int del1);
void forwardRight(int diff, int del);
void forwardLeft(int diff, int del);
void stopBot(int del);
void setup()
{
  pinMode(ina, OUTPUT);
  pinMode(inb, OUTPUT);
  pinMode(inc, OUTPUT);
  pinMode(ind, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(8, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  digitalWrite(button, INPUT_PULLUP);
  digitalWrite(ina, LOW);
  digitalWrite(inb, LOW);
  digitalWrite(inc, LOW);
  digitalWrite(ind, LOW);
  digitalWrite(13, LOW);
  btn.attachDoubleClick(doubleclick);
  btn.attachClick(singleclick);
  btn.attachLongPressStop(longclick);
  btn.setDebounceTicks(1);
  btn.setClickTicks(250);
  btn.setPressTicks(500);
  lastsensor = 0;
  preverror = 0;
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(6, 0);
  lcd.print("Line");
  lcd.setCursor(4, 1);
  lcd.print("Follower");
  delay(750);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Counter:");
  sprintf(countstring, "%2d", count);
  lcd.print(countstring);
  lcd.createChar(0, customChar);
  Serial.begin(9600);
}
void loop()
{
  if (digitalRead(button) == LOW && dolinefollow)
  {
    dolinefollow = false;
    stopBot(0);
  }
  btn.tick();
  if (Serial.available())
  {
    c = Serial.read();
    if (c == '#')
    {
      if (sx.length() > 0)
      {
        for (i = 0; sx[i] != '@'; i++)
          s1 += sx[i];
        kp = s1.toDouble();
        s1 = "";
        i++;
        for (; i < sx.length(); i++)
          s1 += sx[i];
        kd = s1.toDouble();
        sx = s1 = "";
        lcd.clear();
        lcd.print("kp:");
        lcd.setCursor(3, 0);
        lcd.print("     ");
        lcd.setCursor(3, 0);
        lcd.print(kp);
        lcd.setCursor(0, 1);
        lcd.print("kd:");
        lcd.setCursor(3, 1);
        lcd.print("     ");
        lcd.setCursor(3, 1);
        lcd.print(kd);
        stopBot(0);
        tune = true;
        dolinefollow = false;
        //Serial.println(del);
      }
    }
    else
      sx += c;
  }
  else
  {
    if (dolinefollow)
      lineFollow();
    else if (sensorpos)
    {
      mini = 10000;
      maxi = 0;
      readLine();
    }
  }
  delayMicroseconds(del);
}
void doubleclick()
{
  if (!dolinefollow)
  {
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Min:");
    lcd.setCursor(8, 1);
    lcd.print("Max:");
    doubleclk = true;
    sensorpos = true;
    singleclk = false;
  }
}
void singleclick()
{
  singleclk = true;
  stopBot(0);
  if (doubleclk)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Counter:");
    sprintf(countstring, "%2d", count);
    lcd.print(countstring);
    doubleclk = sensorpos = false;
  }
  else
  {
    count++;
    if (count > maxcount + 1)
    {
      count = 0;
      sprintf(countstring, "%2d", count);
      lcd.setCursor(8, 0);
      lcd.print(countstring);
    }
    sprintf(countstring, "%2d", count);
    lcd.setCursor(8, 0);
    lcd.print(countstring);
  }
}
void longclick()
{
  if (!dolinefollow)
  {
    dolinefollow = true;
    if (doubleclk || tune)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Counter:");
      sprintf(countstring, "%2d", count);
      lcd.print(countstring);
      doubleclk = singleclk = sensorpos = false;
    }
    digitalWrite(13, LOW);
    delay(200);
    digitalWrite(13, HIGH);
    delay(400);
    digitalWrite(13, LOW);
    delay(200);
  }
}
