void remote()
{
  while (digitalRead(12) == LOW)
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
        analogWrite(ena, 255);
        analogWrite(enb, 255);
        digitalWrite(ina, HIGH);
        digitalWrite(inb, HIGH);
        digitalWrite(inc, HIGH);
        digitalWrite(ind, HIGH);
        x = y = 512;
      }
      else
        timeout_counter++;
    }
    delay(25);
  }
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
      analogWrite(ena, 255);
      analogWrite(enb, 255);
      digitalWrite(ina, HIGH);
      digitalWrite(inb, HIGH);
      digitalWrite(inc, HIGH);
      digitalWrite(ind, HIGH);
    }
    else if (x > 512)
    {
      digitalWrite(ina, HIGH);
      digitalWrite(inb, LOW);
      digitalWrite(inc, HIGH);
      digitalWrite(ind, LOW);
      analogWrite(ena, map(x, 513, 1024, 0, 255));
      analogWrite(enb, map(x, 513, 1024, 0, 255));
    }
    else if (x < 512)
    {
      digitalWrite(ina, LOW);
      digitalWrite(inb, HIGH);
      digitalWrite(inc, LOW);
      digitalWrite(ind, HIGH);
      analogWrite(ena, map(x, 511, 0, 0, 255));
      analogWrite(enb, map(x, 511, 0, 0, 255));
    }
  }
  else if (y > 512) //Forward
  {
    digitalWrite(ina, LOW);
    digitalWrite(inb, HIGH);
    digitalWrite(inc, HIGH);
    digitalWrite(ind, LOW);
    if (x > 512)
    {
      diff = y - x;
      if (diff < 0)
        diff = 0;
      analogWrite(ena, map(diff, 0, 511, 0, 255));
      analogWrite(enb, map(y, 513, 1024, 0, 255));
    }
    else if (x < 512)
    {
      diff = y - map(x, 511, 0, 513, 1024);
      if (diff < 0)
        diff = 0;
      analogWrite(ena, map(y, 513, 1024, 0, 255));
      analogWrite(enb, map(diff, 0, 511, 0, 255));
    }
    else if (x == 512)
    {
      analogWrite(ena, map(y, 513, 1024, 0, 255));
      analogWrite(enb, map(y, 513, 1024, 0, 255));
    }
  }
  else if (y < 512)//Backward
  {
    digitalWrite(ina, HIGH);
    digitalWrite(inb, LOW);
    digitalWrite(inc, LOW);
    digitalWrite(ind, HIGH);
    if (x > 512)
    {
      diff = map(x, 513, 1024, 511, 0) - y;
      if (diff < 0)
        diff = 0;
      analogWrite(ena, map(diff, 0, 511, 0, 255));
      analogWrite(enb, map(y, 511, 0, 0, 255));
    }
    else if (x < 512)
    {
      diff = x - y;
      if (diff < 0)
        diff = 0;
      analogWrite(ena, map(y, 511, 0, 0, 255));
      analogWrite(enb, map(diff, 0, 511, 0, 255));
    }
    else
    {
      analogWrite(ena, map(y, 511, 0, 0, 255));
      analogWrite(enb, map(y, 511, 0, 0, 255));
    }
  }
}
