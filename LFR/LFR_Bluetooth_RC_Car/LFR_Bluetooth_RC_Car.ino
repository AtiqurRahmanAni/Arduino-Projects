#include<LiquidCrystal_I2C.h>
#include<Wire.h>
#include<OneButton.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
OneButton btn = OneButton(2, true);
#define SPEED_PACKET_SIZE     7
#define DIRECTION_PACKET_SIZE 7
const byte ina = 4;
const byte  inb = 5;
const byte  inc = 6;
const byte  ind = 7;
const byte sen1 = 10;
const byte sen8 = 11;
const byte led = 13;
const byte button = 2;
const byte  ena = 3;
const byte  enb = 9;
const int leftbasespeed = 230; //Speed for line follow 150
const int rightbasespeed = 230; //Speed for line follow 150
const int maxspeed = 255; //Speed for line follow 170
const int turnspeedright = 150; //Speed for line follow 100
const int turnspeedleft = 150; //Speed for line follow 100
int lastsensor, num_sensor = 8, i, j, threshold = 450;
int leftspeed = 0, rightspeed = 0;
float kp = 9.25;
float kd = 80;
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
bool s[8];
/*byte right[] = {1, 3, 4, 5, 11};
  byte left[] = {2, 7, 8, 10, 13, 14};
  byte straight[] = {6, 9};
  byte forwardright[] = {};
  byte forwardleft[] = {12};*/
int cond[] = {7, 11, 13, 14, 15, 19, 21, 22, 23, 25, 26, 27, 28, 29, 30, 31, 35, 37, 38, 39, 41, 42, 43, 44, 45, 46, 47, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 67, 69, 70, 71, 73, 74, 75, 76, 77, 78, 79, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 131, 133, 134, 135, 137, 138, 139, 140, 141, 142, 143, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255};
byte right[] = {1,2,4,6,7,11};
byte left[] = {3,5,8,9,10,12};
byte straight[] = {};
byte forwardright[] = {};
byte forwardleft[] = {};
int condsize = sizeof(cond) / sizeof(int);
byte nr = sizeof(right) / sizeof(byte);
byte nl = sizeof(left) / sizeof(byte);
byte ns = sizeof(straight) / sizeof(byte);
byte nfr = sizeof(forwardright) / sizeof(byte);
byte nfl = sizeof(forwardleft) / sizeof(byte);
int preverror, count , maxcount = 12;
int del = 4500, sums , decimal;
char minimum[4], maximum[4], countstring[3];
int mini = 10000, maxi, temp;
int timeout_counter, x, y, diff;
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
void remote();
void setup()
{
  pinMode(ina, OUTPUT);
  pinMode(inb, OUTPUT);
  pinMode(inc, OUTPUT);
  pinMode(ind, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(sen1, INPUT);
  pinMode(sen8, INPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(12, INPUT);
  digitalWrite(ina, LOW);
  digitalWrite(inb, LOW);
  digitalWrite(inc, LOW);
  digitalWrite(ind, LOW);
  digitalWrite(ena, LOW);
  digitalWrite(enb, LOW);
  btn.attachDoubleClick(doubleclick);
  btn.attachClick(singleclick);
  btn.attachLongPressStop(longclick);
  btn.setDebounceTicks(1);
  btn.setClickTicks(250);
  btn.setPressTicks(500);
  lastsensor = preverror = 0;
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
  if (digitalRead(12) == LOW)
  {
    remote();
  }
  if (digitalRead(button) == LOW && dolinefollow)
  {
    dolinefollow = false;
    stopBot(0);
  }
  btn.tick();
  if (Serial.available() > 0)
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
  }
  digitalWrite(led, LOW);
  delay(200);
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  delay(300);
}
