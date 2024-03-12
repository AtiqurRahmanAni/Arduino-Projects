String s;
int oneCnt = 0;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  while (Serial.available())
  {
    char x = Serial.read();
    //Serial.println(x, DEC);
    oneCnt = x == '1' ? oneCnt + 1 : oneCnt; //Ternery operator
    s += x;
    if (s.length() == 4)
    {
      Serial.print("Input: ");
      Serial.println(s);
      Serial.print("Output: ");
      if (oneCnt > 1 || oneCnt == 0)
      {
        Serial.println("Wrong");
      }
      else
      {
        int j = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
          j++;
          if (s[i] == '1')
          {
            if (j - 1 < 2)
            {
              Serial.print(0);
              Serial.print(j - 1, BIN);
            }
            else
            {
              Serial.print(j - 1, BIN);
            }
            Serial.print("(D");
            Serial.print(j - 1);
            Serial.println(")");
          }
        }
      }
      s = "";
      oneCnt = 0;
    }
  }
}
