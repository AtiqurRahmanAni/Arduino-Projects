const int PACKET_SIZE = 8;
float kp, kd, ki;
void setup()
{
  Serial.begin(9600);
  delay(500);
}
void loop()
{
  if (Serial.available())
  {
    while (Serial.available())
      handleSerial(Serial.peek());
  }
}
void handleSerial(char c)
{
  switch (c)
  {
    case 'P':
      {
        if (Serial.available() < PACKET_SIZE)
          break;
        kp = Serial.parseFloat();
        if (Serial.read() == 13)
        {
          if (Serial.read() == 10)
          {
            //Use kp value from here
            Serial.print("KP: ");
            Serial.println(kp);
          }
          else
            clearSerialBuffer();
        }
        else
          clearSerialBuffer();
      } break;
    case 'D':
      {
        if (Serial.available() < PACKET_SIZE)
          break;
        kd = Serial.parseFloat();
        if (Serial.read() == 13)
        {
          if (Serial.read() == 10)
          {
            //Use kd value from here
            Serial.print("KD: ");
            Serial.println(kd);
          }
          else
            clearSerialBuffer();
        }
        else
          clearSerialBuffer();
      } break;
    case 'I':
      {
        if (Serial.available() < PACKET_SIZE)
          break;
        ki = Serial.parseFloat();
        if (Serial.read() == 13)
        {
          if (Serial.read() == 10)
          {
            //Use ki value from here
            Serial.print("KI: ");
            Serial.println(ki);
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
