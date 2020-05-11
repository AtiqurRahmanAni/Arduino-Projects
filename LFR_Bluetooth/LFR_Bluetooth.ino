#include<LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const byte ina = 4;
const byte  inb = 5;
const byte  inc = 6;
const byte  ind = 7;
const byte  ena = 3;
const byte  enb = 9;
const byte button = 2;
const byte eco = 13;
const int leftbasespeed = 95; //Speed for line follow
const int rightbasespeed = 95; //Speed for line follow
const int maxspeed = 95; //Speed for line follow
const int turnspeedright = 70; //Speed for line follow
const int turnspeedleft = 70; //Speed for line follow
long long buttonpressdelay = 0;
int lastsensor, num_sensor = 8, i, j, threshold = 450;
int leftspeed = 0, rightspeed = 0;
float kp = 6; //4
float kd = 60; //33
//For wall follow
const int wallleftbasespeed = 55; //Speed for wall follow
const int wallrightbasespeed = 55; //Speed for wall follow
const int wallmaxspeed = 60; //Speed for wall follow
float wallkp = 8.40;
float wallkd = 29;
int setpoint = 12;
double duration, distance;
int wallpreverror;

bool dolinefollow = false, buttonstate = false;
int flag;
String sx = "", s1 = "", s2 = "", pri = "";
char c;
bool linecolorblack = true;
int s[8];
/*int right[] = {1, 3, 4, 5, 11};
  int left[] = {2, 7, 8, 10, 13, 14};
  int straight[] = {6, 9};
  int forwardright[] = {};
  int forwardleft[] = {12};*/
int right[] = {1, 2, 5, 7, 8, 13};
int left[] = {4, 10, 11, 12, 14};
int straight[] = {6, 9};
int forwardright[] = {3};
int forwardleft[] = {};
int nr=sizeof(right) / sizeof(int);
int nl=sizeof(left) / sizeof(int);
int ns=sizeof(straight) / sizeof(int);
int nfr=sizeof(forwardright) / sizeof(int);
int nfl=sizeof(forwardleft) / sizeof(int);
int preverror, count = 0, countnoline = 0, maxcount = 14;
int del = 4500, sums = 0;
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
  lastsensor = 0;
  preverror = 0;
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(6, 0);
  lcd.print("Line");
  lcd.setCursor(4, 1);
  lcd.print("Follower");
  Serial.begin(9600);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Counter:");
  lcd.print(count);
  lcd.setCursor(0, 1);
  lcd.print("No Line:");
  lcd.print(countnoline);
  /*lcd.setCursor(0, 1);
    lcd.print("kp:");
    lcd.setCursor(8, 1);
    lcd.print("kd:");*/
}
void loop()
{
  if (digitalRead(button) == LOW && buttonstate == false)
  {
    buttonpressdelay++;
    if (buttonpressdelay == 200 && count!=0)
    {
      count--;
      lcd.setCursor(8, 0);
      lcd.print("  ");
      lcd.setCursor(8, 0);
      lcd.print(count);
    }
    if (buttonpressdelay >= 275)
    {
      if (dolinefollow == false)
      {
        dolinefollow = true;
        digitalWrite(13, LOW);
        delay(200);
        digitalWrite(13, HIGH);
        delay(800);
        digitalWrite(13, LOW);
        delay(200);
      }
      else
      {
        dolinefollow = false;
        stopBot(0);
      }
      buttonstate = true;
    }
  }
  if (dolinefollow == false && buttonpressdelay == 10)
  {
    count++;
    lcd.setCursor(8, 0);
    lcd.print(count);
    if (count > maxcount+1)
    {
      lcd.setCursor(8, 0);
      lcd.print("   ");
      count = -1;
    }
  }
  else if (digitalRead(button) == HIGH)
  {
    buttonstate = false;
    buttonpressdelay = 0;
  }
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
        i++;
        for (; i < sx.length(); i++)
          s2 += sx[i];
        kd = s2.toDouble();
        sx = s1 = s2 = "";
        lcd.setCursor(3, 1);
        lcd.print("    ");
        lcd.setCursor(11, 1);
        lcd.print("    ");
        lcd.setCursor(3, 1);
        lcd.print(kp);
        lcd.setCursor(11, 1);
        lcd.print(kd);
        stopBot(3500);
        //Serial.println(del);
      }
    }
    else
      sx += c;
  }
  else
  {
    if (dolinefollow)
    {
      lineFollow();
    }
    //      wallFollow();
    //        readLine();

  }
  delayMicroseconds(del);
}
