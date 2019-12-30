#include<LiquidCrystal_I2C.h>
#include<wire.h>
LiquidCrystal_I2C lcd(0x27,16,4);
int h=1,m=31,s=55,d=30,mon=12,y=2019,flag=1;
char hour[3],minute[3],second[3];
char str[3]="PM";
void setup() 
{
  pinMode(13,OUTPUT);
  digitalWrite(13,0);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.print("Time-");
  lcd.setCursor(6,0);
  sprintf(hour,"%02d",h);
  lcd.print(hour);
  lcd.setCursor(8,0);
  lcd.print(':');
  lcd.setCursor(9,0);
  sprintf(minute,"%02d",m);
  lcd.print(minute);
  lcd.setCursor(11,0);
  lcd.print(':');
  sprintf(second,"%02d",s);
  lcd.setCursor(12,0);
  lcd.print(second);
  lcd.setCursor(0,1);
  lcd.print("Date-");
  lcd.setCursor(14,0);
  lcd.print(str);
  lcd.setCursor(6,1);
  lcd.print(d);
  lcd.print('/');
  lcd.print(mon);
  lcd.print('/');
  lcd.print(y);
  Serial.begin(9600);
  
}

void loop() 
{
    if(s==60)
    {
      s=0;
      m++;
      if(m==60)
      {
        m=0;
        h++;
        if(h==13)
        {
          h=1;
          if(flag==0)
            flag=1;
          else if(flag==1)
            flag=0;
          if(flag==0)
          {
             lcd.setCursor(14,0);
             lcd.print("AM");
          }
          else if(flag==1)
          {
             lcd.setCursor(14,0);
             lcd.print("PM");
          }
          
        }
        lcd.setCursor(6,0);
        sprintf(hour,"%02d",h);
        lcd.print(hour);
      }
      lcd.setCursor(9,0);
      sprintf(minute,"%02d",m);
      lcd.print(minute);
    }
    sprintf(second,"%02d",s);
    lcd.setCursor(12,0);
    lcd.print(second);
    s++;
    delay(1000);
   

}
