#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int trig = 3, eco = 4, i;
char s1[8];
char s2[8];
double distance, distance1;
long long duration;
void setup() {

  pinMode(trig, OUTPUT);
  pinMode(eco, INPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, 0);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Distance");
}

void loop()
{
  digitalWrite(trig, 0);
  delayMicroseconds(2);
  digitalWrite(trig, 1);
  delayMicroseconds(10);
  duration = pulseIn(eco, 1);
  distance = ((duration * 0.0332) / 2.0);
  lcd.setCursor(0, 1);
  dtostrf(distance, 6, 2, s1);
  sprintf(s2, "%-7scm", s1);
  lcd.print(s2);
  delay(500);
}
