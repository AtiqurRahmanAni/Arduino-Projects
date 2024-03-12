int pin = 2;
volatile int x = 0;
unsigned long lastRpmMillis;
void setup() {
  attachInterrupt(digitalPinToInterrupt(pin), change, FALLING);
  Serial.begin(9600);
  lastRpmMillis = millis();
}
void loop() {

  unsigned long elapsedTime = millis() - lastRpmMillis;
  if(elapsedTime >= 1000)
  {
    double rpm = (60 * x) / 2.0;
    Serial.println(rpm);
    x = 0;
    lastRpmMillis = millis();
  }
}
void change()
{
  x++;
}
