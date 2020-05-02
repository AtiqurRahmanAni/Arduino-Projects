void readLine()
{
  s[0] = digitalRead(10);
  s[7] = digitalRead(11);
  for (i = 0; i < 6; i++)
  {
    if (linecolorblack)
    {
      if (analogRead(i) < threshold)
        s[i + 1] = 1;
      else
        s[i + 1] = 0;
    }
    else
    {
      if (analogRead(i) > threshold)
        s[i + 1] = 1;
      else
        s[i + 1] = 0;
    }
  }
  sums = 0;
  for (i = 0; i < num_sensor; i++)
  {
    sums += s[i];
    //Serial.print(s[i]);
    //Serial.print(" ");
  }
}
