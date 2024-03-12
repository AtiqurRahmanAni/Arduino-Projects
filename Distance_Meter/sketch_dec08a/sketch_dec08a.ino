#include<Wire.h>
#include<LiquidCrystal_I2C.h>
int i = 0, flag = 1;
long x;
char str[5], ch;
String num;
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{
  TCCR2B = TCCR2B & B11111000 | B00000001;
  TCCR1B = TCCR1B & B11111000 | B00000001;
  pinMode(3, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, 0);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  Serial.begin(115200);
  lcd.print("PWM value:");
}

void loop()
{
  if (Serial.available() > 0) {
    while (Serial.available() > 0)
    {
      ch = Serial.read();
      num += ch;

    }
    x = num.toInt();
  }
  else
  {
    num="";
    if (x >= 0 && x <= 255)
    {
      analogWrite(3, x);
      sprintf(str, "%-3d", x);
      lcd.setCursor(10, 0);
      lcd.print(str);
    }
  }


}
