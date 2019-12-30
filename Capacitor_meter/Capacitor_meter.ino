#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
const int OUT_PIN = A2;
const int IN_PIN = A0;
const float IN_STRAY_CAP_TO_GND = 24.48;
const float IN_CAP_TO_GND  = IN_STRAY_CAP_TO_GND;
const float R_PULLUP = 34.8;
const int MAX_ADC_VALUE = 1023;
char value[15];
char value1[15];
double x;
void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.print("Capacitance");
  pinMode(OUT_PIN, OUTPUT);
  pinMode(IN_PIN, OUTPUT);

}

void loop()
{
  pinMode(IN_PIN, INPUT);
  digitalWrite(OUT_PIN, HIGH);
  int val = analogRead(IN_PIN);
  digitalWrite(OUT_PIN, LOW);

  if (val < 1000)
  {
    pinMode(IN_PIN, OUTPUT);

    float capacitance = (float)val * IN_CAP_TO_GND / (float)(MAX_ADC_VALUE - val);
    lcd.setCursor(0, 1);
    dtostrf(capacitance, 6, 3, value);
    sprintf(value1, "%-7spF", value);
    lcd.print(value1);
  }
  else
  {
    pinMode(IN_PIN, OUTPUT);
    delay(1);
    pinMode(OUT_PIN, INPUT_PULLUP);
    unsigned long u1 = micros();
    unsigned long t;
    int digVal;

    do
    {
      digVal = digitalRead(OUT_PIN);
      unsigned long u2 = micros();
      t = u2 > u1 ? u2 - u1 : u1 - u2;
    } while ((digVal < 1) && (t < 400000L));

    pinMode(OUT_PIN, INPUT);
    val = analogRead(OUT_PIN);
    digitalWrite(IN_PIN, HIGH);
    int dischargeTime = (int)(t / 1000L) * 5;
    delay(dischargeTime);
    pinMode(OUT_PIN, OUTPUT);
    digitalWrite(OUT_PIN, LOW);
    digitalWrite(IN_PIN, LOW);

    float capacitance = -(float)t / R_PULLUP
                        / log(1.0 - (float)val / (float)MAX_ADC_VALUE);

    if (capacitance > 1000.0)
    {
      lcd.setCursor(0, 1);
      x = capacitance / 1000.0;
      dtostrf(x, 6, 3, value);
      sprintf(value1, "%-7suF", value);
      lcd.print(value1);

    }
    else
    { 
      lcd.setCursor(0, 1);
      dtostrf(capacitance, 6, 3, value);
      sprintf(value1, "%-7snF", value);
      lcd.print(value1);
    }
  }
  while (millis() % 1000 != 0)
    ;
}
