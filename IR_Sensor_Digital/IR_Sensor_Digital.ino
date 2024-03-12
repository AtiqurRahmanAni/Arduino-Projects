#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);     //alebo 0x27 --> I2C adresy sa mozu roznit
float value = 0;
float rev = 0;
long rpm;
long oldtime = 0;
long time;

void isr() {
  rev++;
}

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("-----ZETOR 4011-----");
  attachInterrupt(digitalPinToInterrupt (2), isr, RISING); //interrupt pin
}

void loop() {
  delay(1000);
  detachInterrupt(digitalPinToInterrupt(2));      
  time = millis() - oldtime;    //rozdiel casov
  rpm = (rev / time) * 60000;   //vyrataj otacky/min
  oldtime = millis();           //uloz aktualny cas
  rev = 0;
  lcd.setCursor(0, 1);
  lcd.print(rpm);
  lcd.print(" ot/min");
  attachInterrupt(digitalPinToInterrupt (2), isr, RISING);
}
