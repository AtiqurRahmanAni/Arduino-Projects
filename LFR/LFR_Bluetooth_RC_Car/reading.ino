void readLine()
{
  s[0] = !digitalRead(sen1);
  s[7] = !digitalRead(sen8);
  j=1;
  for (i = 0; i < 8; i++)
  {
    if (i == 4 || i == 5)
      continue;
    temp = analogRead(i);
    if (temp < threshold)
      s[j] = true;
    else
      s[j] = false;
    j++;
    if (sensorpos)
    {
      if (temp > maxi)
        maxi = temp;
      if (temp < mini)
        mini = temp;
    }
  }
  sums = decimal = 0;
  j = 0;
  for (i = 0; i < num_sensor; i++)
  {
    if (!linecolorblack)
      s[i] = !s[i];
    sums += s[i];
    decimal += (s[i]*(1<<i));
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
  }
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
