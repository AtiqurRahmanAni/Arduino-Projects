const int PACKET_SIZE = 6;
int r, g, b;
byte rp = 9, gp = 10, bp = 11;
void setup()
{
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Serial.begin(9600);
  TCCR2B = TCCR2B & B11111000 | B00000001;
  TCCR1B = TCCR1B & B11111000 | B00000001;
}

void loop()
{
  if (Serial.available())
  {
    handleSerial(Serial.peek());
  }
}
void handleSerial(char c)
{
  switch (c)
  {
    case 'R':
      {
        if (Serial.available() < PACKET_SIZE)
          break;
        r = Serial.parseInt();
        if (Serial.read() == 13)
        {
          if (Serial.read() == 10)
          {
            //            Serial.print("R:");
            //            Serial.println(r);
            analogWrite(rp, r);
          }
          else
            clearSerialBuffer();
        }
        else
          clearSerialBuffer();
      } break;
    case 'G':
      {
        if (Serial.available() < PACKET_SIZE)
          break;
        g = Serial.parseInt();
        if (Serial.read() == 13)
        {
          if (Serial.read() == 10)
          {
            //            Serial.print("G:");
            //            Serial.println(g);
            analogWrite(gp, g);
          }
          else
            clearSerialBuffer();
        }
        else
          clearSerialBuffer();
      } break;
    case 'B':
      {
        if (Serial.available() < PACKET_SIZE)
          break;
        b = Serial.parseInt();
        if (Serial.read() == 13)
        {
          if (Serial.read() == 10)
          {
            //            Serial.print("B:");
            //            Serial.println(b);
            analogWrite(bp, b);
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
