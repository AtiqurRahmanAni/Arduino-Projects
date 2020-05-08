void readLine()
{
  s[0] = digitalRead(8);
  s[1] = digitalRead(10);
  s[6] = digitalRead(11);
  s[7] = digitalRead(12);
  for (i = 0; i < 4; i++)
  {
    if (linecolorblack)
    {
      if (analogRead(i) < threshold)
        s[i + 2] = 1;
      else
        s[i + 2] = 0;
    }
    else
    {
      if (analogRead(i) > threshold)
        s[i + 2] = 1;
      else
        s[i + 2] = 0;
    }
  }
  sums = 0;
  for (i = 0; i < num_sensor; i++)
  {
    sums += s[i];
//    Serial.print(s[i]);
//    Serial.print(" ");
  }
//  Serial.println("");
}
