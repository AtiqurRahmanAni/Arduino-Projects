#include<LiquidCrystal_I2C.h>
#include<OneButton.h>
#include<time.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
OneButton btn = OneButton(4, true, true);
int Rvalue = 254, Gvalue = 1, Bvalue = 127;
int Rdirection = -1, Gdirection = 1, Bdirection = -1;
int mode = 0;
const int Red = 9, Green = 10, Blue = 11;
int red = 0, green = 0, blue = 0;
bool isSelected = false, state = false, isLongPressed = false;
int flag = 1, flag1 = 1;
void rainbow();
void RANDOM();
void setup()
{
  TCCR2B = TCCR2B & B11111000 | B00000001;
  TCCR1B = TCCR1B & B11111000 | B00000001;
  btn.attachDoubleClick(doubleclick);
  btn.attachClick(singleclick);
  btn.attachLongPressStop(longclick);
  btn.setDebounceTicks(50);
  btn.setClickTicks(400);
  btn.setPressTicks(650);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.print("   RGB Effect");
  delay(1000);
  lcd.clear();
  lcd.print("Select Mode");
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Serial.begin(9600);
  srand(time(NULL));
}
void loop()
{
  btn.tick();
  //Serial.println("YES");
  if (mode == 1 && isLongPressed)
  {
    RANDOM();
  }
  else if (mode == 2 && isLongPressed)
  {
    rainbow();
  }
  else if (mode == 3 && isLongPressed)
  {
    if (flag == 1) //Red
    {
      blue=green=0;
      if (flag1 == 1)
      {
        red++;
        if (red == 256)
        { 
          red=255;
          flag1 = 2;
        }
      }
      if (flag1 == 2)
      {
        red--;
        if (red == -1)
        {
          red = 0;
          flag1 = 1;
          flag = 2;
        }
      }
    }
    else if (flag == 2) //Green
    {
      red=blue=0;
      if (flag1 == 1)
      {
        green++;
        if (green == 256)
        {
          green=255;
          flag1 = 2;
        }
      }
      if (flag1 == 2)
      {
        green--;
        if (green == -1)
        {
          green = 0;
          flag = 3;
          flag1=1;
        }
      }
    }
    else if (flag == 3) //Blue
    {
      red=green=0;
      if (flag1 == 1)
      {
        blue++;
        if (blue == 256)
        {
          blue=255;
          flag1 = 2;
        }
      }
      if (flag1 == 2)
      {
        blue--;
        if (blue == -1)
        {
          blue=0;
          flag1 = 1;
          flag = 1;
        }
      }
    }
    //Serial.println(red);
    breath(red, green, blue);
    delay(5);
  }

}
void singleclick()
{
  //Serial.println("Single clicked");
  if (!isSelected)
  {

    isLongPressed = false;
    if (!state)
    {
      mode++;
    }
    else
    {
      state = false;
      lcd.clear();
      lcd.print("Select Mode");
    }
    if (mode == 4)
    {
      mode = 1;
    }
    if (mode == 1)
    {
      lcd.setCursor(0, 1);
      lcd.print("Random     ");
    }
    else if (mode == 2)
    {
      lcd.setCursor(0, 1);
      lcd.print("Color Cycle");
    }
    else if (mode == 3)
    {
      lcd.setCursor(0, 1);
      lcd.print("Breath     ");
    }
  }
}
void doubleclick()
{
  //Serial.println("Double clicked");
  isSelected = false;
  state = true;
  digitalWrite(Red, LOW);
  digitalWrite(Green, LOW);
  digitalWrite(Blue, LOW);
  singleclick();

}
void longclick()
{
  //Serial.println("Long pressed");
  isLongPressed = true;
  lcd.clear();
  isSelected = true;
  if (mode == 1)
  {
    lcd.print("Random mode");
    lcd.setCursor(0, 1);
    lcd.print("Selected");
  }
  else if (mode == 2)
  {
    Rvalue = 254;
    Gvalue = 1;
    Bvalue = 127;
    lcd.print("Color Cycle");
    lcd.setCursor(0, 1);
    lcd.print("Selected");
  }
  else if (mode == 3)
  {
    flag = flag1 = 1;
    red = green = blue = 0;
    lcd.print("Breath mode");
    lcd.setCursor(0, 1);
    lcd.print("Selected");
  }
}
