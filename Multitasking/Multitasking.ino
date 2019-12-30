#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
byte led1=2;
byte led2=3;
unsigned long long led2_time=0,led1_time=0,current,lcd_time=0;
bool led1_state=false,led2_state=false;
unsigned long long led1mini,led2mini;
char str[3],s1[3],s2[3];
int x;
void setup() 
{
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(5,OUTPUT);  
  pinMode(A0,INPUT);
  lcd.clear();
  lcd.init();
  lcd.backlight();
  lcd.print("PWM Value:");
  lcd.setCursor(0,1);
  lcd.print("LED:");
  lcd.setCursor(9,1);
  lcd.print("LED:");
}

void loop() {
  current=millis();
  if(current-led1_time>=600)
  {
     if(!led1_state)
     {
       digitalWrite(led1,1);
       sprintf(s1,"%-3s","ON");
       lcd.setCursor(4,1);
       lcd.print(s1);
       led1_state=true;
     }
     else
     {
       digitalWrite(led1,0);
       sprintf(s1,"%-3s","OFF");
       lcd.setCursor(4,1);
       lcd.print(s1);
       led1_state=false;
     }
     led1_time=current;
  }
  if(current-led2_time>=500)
  {
     if(!led2_state)
     {
       digitalWrite(led2,1);
       sprintf(s2,"%-3s","ON");
       lcd.setCursor(13,1);
       lcd.print(s2);
       led2_state=true;
     }
     else
     {
       digitalWrite(led2,0);
       sprintf(s2,"%-3s","OFF");
       lcd.setCursor(13,1);
       lcd.print(s2);
       led2_state=false;
     }
     led2_time=current;
  }
  x=map(analogRead(A0),0,1024,0,255);
  analogWrite(5,x);
  if(current-lcd_time>=300)
  {
    sprintf(str,"%-3d",x);
    lcd.setCursor(10,0);
    lcd.print(str);
    lcd_time=current;
  }
  
}
