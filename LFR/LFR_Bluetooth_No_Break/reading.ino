void readLine()
{
  s[0] = digitalReadFast(sen1);
  s[1] = digitalReadFast(sen2);
  s[6] = digitalReadFast(sen7);
  s[7] = digitalReadFast(sen8);
  for (i = 0; i < 4; i++)
  {
    temp = analogRead(i);
    if (temp < threshold)
      s[i + 2] = true;
    else
      s[i + 2] = false;
    if (sensorpos)
    {
      if (temp > maxi)
        maxi = temp;
      if (temp < mini)
        mini = temp;
    }
  }
  sums = 0;
  j = 0;
  for (i = 0; i < num_sensor; i++)
  {
    if (!linecolorblack)
      s[i] = !s[i];
    sums += s[i];
    if (sensorpos)
    {
      if (s[i] == 1)
      {
        lcd.setCursor(j, 0);
        lcd.print(i + 1);
        lcd.print(" ");
      }
      else
      {
        lcd.setCursor(j, 0);
        lcd.write(0);
        lcd.print(" ");
      }
      j += 2;
    }
    //    Serial.print(s[i]);
    //    Serial.print(" ");
  }
  //  Serial.println("");
  if (sensorpos)
  {
    sprintf(minimum, "%3d", mini);
    sprintf(maximum, "%3d", maxi);
    lcd.setCursor(4, 1);
    lcd.print(minimum);
    lcd.setCursor(12, 1);
    lcd.print(maximum);
  }
}
