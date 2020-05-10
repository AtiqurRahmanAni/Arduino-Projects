#include<LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
const byte ina = 4;
const byte  inb = 5;
const byte  inc = 6;
const byte  ind = 7;
const byte  ena = 3;
const byte  enb = 9;
const byte trig = 2;
const byte eco = 13;
const int leftbasespeed = 95; //Speed for line follow
const int rightbasespeed = 95; //Speed for line follow
const int maxspeed = 95; //Speed for line follow
const int turnspeedright=70; //Speed for line follow
const int turnspeedleft=70; //Speed for line follow
int lastsensor,num_sensor=8,i,j,threshold=450;
int leftspeed=0,rightspeed=0;
float kp=6;//2.50//3.1
float kd=60;//27//30.2
//For wall follow
const int wallleftbasespeed = 55; //Speed for wall follow
const int wallrightbasespeed = 55; //Speed for wall follow
const int wallmaxspeed = 60; //Speed for wall follow
float wallkp = 8.40;
float wallkd = 29;
int setpoint = 12;
double duration, distance;
int wallpreverror;

int flag;
String sx="",s1="",s2="",pri="";
char c;
bool linecolorblack=true;
int s[8];
int right[]={1,2,5,7,8,13};
int left[]={4,10,11,12,14};
int straight[]={6,9};
int forwardright[]={3};
int forwardleft[]={};
int preverror,count=0,countnoline=0;
int del=4500,sums=0;
void setup() 
{
  pinMode(ina, OUTPUT);
  pinMode(inb, OUTPUT);
  pinMode(inc, OUTPUT);
  pinMode(ind, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(8, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, OUTPUT);
  digitalWrite(ina, LOW);
  digitalWrite(inb, LOW);
  digitalWrite(inc, LOW);
  digitalWrite(ind, LOW);
  digitalWrite(13, LOW);
  digitalWrite(trig, LOW);
  lastsensor = 0;
  preverror = 0;
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(6,0);
  lcd.print("Line");
  lcd.setCursor(4,1);
  lcd.print("Follower");
  Serial.begin(9600);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Counter:");
  lcd.print(count);
  lcd.setCursor(0,1);
  lcd.print("No Line:");
  lcd.print(countnoline);
}
void loop() 
{
  if(Serial.available())
  {
    c=Serial.read();
    if(c=='#')
    {
      if(sx.length()>1)
      {
        for(i=0;i<sx.length();i++)
          s1+=sx[i];
        del=s1.toInt();
        sx=s1="";
        stopBot(3500);
        //Serial.println(del);
      }
    }
    else
      sx+=c;
  }
  else
  {
    lineFollow();
    delayMicroseconds(del);
//      wallFollow();
//        readLine();
      
  }
}
