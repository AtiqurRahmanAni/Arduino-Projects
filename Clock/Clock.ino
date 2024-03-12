#include <DS3231.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
DS3231  rtc(SDA, SCL);
String s,s1;
void setup()
{
  Serial.begin(115200);
  rtc.begin();
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  rtc.setDOW(TUESDAY);     // Set Day-of-Week to SUNDAY
  rtc.setTime(18,42,0);     // Set the time to 12:00:00 (24hr format)
  rtc.setDate(5, 3, 2024);   // Set the date to January 1st, 2014
}

void loop()
{
  s=rtc.getTimeStr();
  s1=rtc.getDOWStr();
  Serial.println(s);
  if((s[0]=='1' && (s[1]=='2'||s[1]=='3'||s[1]=='4'||s[1]=='5'||s[1]=='6'||s[1]=='7'||s[1]=='8'||s[1]=='9')))
  {
    lcd.setCursor(8,0);
    lcd.print("PM");
    if(s[1]=='3')
    {
      s[0]='0';
      s[1]='1';
    }
    else if(s[1]=='4')
    {
      s[0]='0';
      s[1]='2';
    }
    else if(s[1]=='5')
    {
      s[0]='0';
      s[1]='3';
    }
    else if(s[1]=='6')
    {
      s[0]='0';
      s[1]='4';
    }
    else if(s[1]=='7')
    {
      s[0]='0';
      s[1]='5';
    }
    else if(s[1]=='8')
    {
      s[0]='0';
      s[1]='6';
    }
    else if(s[1]=='9')
    {
      s[0]='0';
      s[1]='7';
    }
  }
  else if((s[0]=='2' && (s[1]=='0'||s[1]=='1'||s[1]=='2'||s[1]=='3'||s[1]=='4')))
  {
    if(s[1]=='0')
    {
      s[0]='0';
      s[1]='8';
    }
    else if(s[1]=='1')
    {
      s[0]='0';
      s[1]='9';
    }
    else if(s[1]=='2')
    {
      s[0]='1';
      s[1]='0';
    }
    else if(s[1]=='3')
    {
      s[0]='1';
      s[1]='1';
    }
    lcd.setCursor(8,0);
    lcd.print("PM");
  }
  else
  {
    lcd.setCursor(8,0);
    lcd.print("AM");
  }
  if(s[0]=='0'&&s[1]=='0')
  {
    s[0]='1';
    s[1]='2';
  }
  lcd.setCursor(0,0);
  lcd.print(s);
  lcd.setCursor(0,1);
  lcd.print(rtc.getDateStr());
  lcd.setCursor(11,0);
  lcd.print(rtc.getTemp());
  lcd.setCursor(12,1);
  lcd.print(s1[0]);
  lcd.print(s1[1]);
  lcd.print(s1[2]);
}
