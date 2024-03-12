#include <Wire.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;
byte echo = 12;
byte trig = 13;
byte irEnb = 4;
byte ina = 8;
byte inb = 7;
byte inc = 6;
byte ind = 5;
byte ena = 9;
byte enb = 3;
int duration;
float distance;
void setup()
{
  servo.attach(8);
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}
void loop()
{
  float temp = ((analogRead(A11) / 1023.0) * 5000) / 10;
  lcd.clear();
  lcd.print(temp, 2);
  Serial.println(temp, 2);
  delay(600);
}
