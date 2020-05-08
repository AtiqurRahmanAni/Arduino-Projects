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
const int leftbasespeed = 90; //Speed for line follow
const int rightbasespeed = 90; //Speed for line follow
const int maxspeed = 90; //Speed for line follow
const int turnspeedright=70; //Speed for line follow
const int turnspeedleft=70; //Speed for line follow
int lastsensor,num_sensor=8,i,j,threshold=450;
float kp=2.50;
float kd=27;
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
int nr=6,nl=5,ns=0,nfr=1,nfl=0;
int right[10]={0,1,4,5,6,10};
int left[10]={3,7,8,9,11};
int straight[10]={};
int forwardright[10]={2};
int forwardleft[10]={};
int preverror,count=0,count1=0;
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
