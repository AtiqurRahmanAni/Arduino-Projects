#define SPEED_PACKET_SIZE     7     //Speed packet size
#define DIRECTION_PACKET_SIZE 7     //Direction packet size
const int L_PWM1 = 3;
const int R_PWM1 = 9;
const int L_PWM2 = 10;
const int R_PWM2 = 11;
int timeout_counter = 0;
int x = 0, y = 0, diff;
void setup()
{
  TCCR2B = TCCR2B & B11111000 | B00000010;
  TCCR1B = TCCR1B & B11111000 | B00000010;
  pinMode(L_PWM1, OUTPUT);
  pinMode(R_PWM1, OUTPUT);
  pinMode(L_PWM2, OUTPUT);
  pinMode(R_PWM2, OUTPUT);
  digitalWrite(L_PWM1, LOW);
  digitalWrite(R_PWM1, LOW);
  digitalWrite(L_PWM2, LOW);
  digitalWrite(R_PWM2, LOW);
  Serial.begin(9600);
  delay(1000);
}

void loop()
{
  if (Serial.available())
  {
    while (Serial.available())
      handleSerial(Serial.peek());
    timeout_counter = 0;
  }
  else
  {
    if (timeout_counter >= 10)
    {
      analogWrite(L_PWM1, 0);
      analogWrite(R_PWM1, 0);
      analogWrite(L_PWM2, 0);
      analogWrite(R_PWM2, 0);
      x=y=512;
    }
    else
      timeout_counter++;
  }
  delay(25);
}
void handleSerial(char c)
{
  switch (c)
  {
    case 'S':
      {
        if (Serial.available() < SPEED_PACKET_SIZE)
          break;
        y = Serial.parseInt();
        if (Serial.read() == 13)
        {
          if (Serial.read() == 10)
          {
            motorDrive();
          }
          else
            clearSerialBuffer();
        }
        else
          clearSerialBuffer();
      } break;
    case 'D':
      {
        if (Serial.available() < DIRECTION_PACKET_SIZE)
          break;
        x = Serial.parseInt();
        if (Serial.read() == 13)
        {
          if (Serial.read() == 10)
          {
            motorDrive();
          }
          else
            clearSerialBuffer();
        }
        else
          clearSerialBuffer();
      } break;
    default:
      clearSerialBuffer();
      break;
  }
}
void clearSerialBuffer()
{
  while (Serial.available())
    Serial.read();
}
void motorDrive()
{
  if (y == 512)
  {
    if (x == 512)
    {
      analogWrite(L_PWM1, 0);
      analogWrite(R_PWM1, 0);
      analogWrite(L_PWM2, 0);
      analogWrite(R_PWM2, 0);
    }
    else if (x > 512)
    {
      analogWrite(L_PWM1, 0);
      analogWrite(L_PWM2, 0);
      analogWrite(R_PWM2, map(x, 513, 1024, 0, 255));
      analogWrite(R_PWM1, map(x, 513, 1024, 0, 255));
    }
    else if (x < 512)
    {
      analogWrite(R_PWM1, 0);
      analogWrite(R_PWM2, 0);
      analogWrite(L_PWM2, map(x, 511, 0, 0, 255));
      analogWrite(L_PWM1, map(x, 511, 0, 0, 255));
    }
  }
  else if (y > 512) //Forward
  {
    analogWrite(R_PWM1, 0);
    analogWrite(L_PWM2, 0);
    if (x > 512)
    {
      diff = y - x;
      if (diff < 0)
        diff = 0;
      analogWrite(L_PWM1, map(diff, 0, 511, 0, 255));
      analogWrite(R_PWM2, map(y, 513, 1024, 0, 255));
    }
    else if (x < 512)
    {
      diff = y - map(x, 511, 0, 513, 1024);
      if (diff < 0)
        diff = 0;
      analogWrite(L_PWM1, map(y, 513, 1024, 0, 255));
      analogWrite(R_PWM2, map(diff, 0, 511, 0, 255));
    }
    else if (x == 512)
    {
      analogWrite(L_PWM1, map(y, 513, 1024, 0, 255));
      analogWrite(R_PWM2, map(y, 513, 1024, 0, 255));
    }
  }
  else if (y < 512)//Backward
  {
    analogWrite(L_PWM1, 0);
    analogWrite(R_PWM2, 0);
    if (x > 512)
    {
      diff = map(x, 513, 1024, 511, 0) - y;
      if (diff < 0)
        diff = 0;
      analogWrite(R_PWM1, map(diff, 0, 511, 0, 255));
      analogWrite(L_PWM2, map(y, 511, 0, 0, 255));
    }
    else if (x < 512)
    {
      diff = x - y;
      if (diff < 0)
        diff = 0;
      analogWrite(R_PWM1, map(y, 511, 0, 0, 255));
      analogWrite(L_PWM2, map(diff, 0, 511, 0, 255));
    }
    else
    {
      analogWrite(L_PWM2, map(y, 511, 0, 0, 255));
      analogWrite(R_PWM1, map(y, 511, 0, 0, 255));
    }
  }
}
