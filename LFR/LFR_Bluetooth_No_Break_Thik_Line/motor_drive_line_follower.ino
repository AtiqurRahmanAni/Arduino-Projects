void wheel(int leftspeed, int rightspeed)
{
  /*Serial.print(leftspeed);
  Serial.print(' ');
  Serial.println(rightspeed);*/
  if (leftspeed == 0)
  {
    digitalWrite(enb, HIGH);
    digitalWrite(inc, HIGH);
    digitalWrite(ind, HIGH);
  }
  else if (leftspeed > 0)
  {
    digitalWrite(inc, LOW);
    digitalWrite(ind, HIGH);
  }
  else if (leftspeed < 0)
  {
    digitalWrite(inc, HIGH);
    digitalWrite(ind, LOW);
  }
  if (rightspeed == 0)
  {
    digitalWrite(ena, HIGH);
    digitalWrite(ina, HIGH);
    digitalWrite(inb, HIGH);
  }
  else if (rightspeed > 0)
  {
    digitalWrite(inb, LOW);
    digitalWrite(ina, HIGH);
  }
  else if (rightspeed < 0)
  {
    digitalWrite(ina, LOW);
    digitalWrite(inb, HIGH);
  }
  if (abs(leftspeed) > maxspeed)
    leftspeed = maxspeed;
  if (abs(rightspeed) > maxspeed)
    rightspeed = maxspeed;
  if(leftspeed==0 && rightspeed==0)
  {
    digitalWrite(ena, HIGH);
    digitalWrite(enb, HIGH);
  }
  else if(leftspeed==0)
  {
    analogWrite(ena, abs(rightspeed));
    digitalWrite(enb, HIGH);
  }
  else if(rightspeed==0)
  {
    digitalWrite(ena, HIGH);
    analogWrite(enb, abs(leftspeed));
  }
  else
  {
    analogWrite(ena, abs(rightspeed));
    analogWrite(enb, abs(leftspeed));
  }
}
