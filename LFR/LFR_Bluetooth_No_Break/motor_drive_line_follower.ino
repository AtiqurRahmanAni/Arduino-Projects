void wheel(int leftspeed, int rightspeed)
{
  /*Serial.print(leftspeed);
  Serial.print(' ');
  Serial.println(rightspeed);*/
  if (leftspeed == 0)
  {
    analogWrite(enb, 255);
    digitalWriteFast(inc, HIGH);
    digitalWriteFast(ind, HIGH);
  }
  else if (leftspeed > 0)
  {
    digitalWriteFast(inc, LOW);
    digitalWriteFast(ind, HIGH);
  }
  else if (leftspeed < 0)
  {
    digitalWriteFast(inc, HIGH);
    digitalWriteFast(ind, LOW);
  }
  if (rightspeed == 0)
  {
    analogWrite(ena, 255);
    digitalWriteFast(ina, HIGH);
    digitalWriteFast(inb, HIGH);
  }
  else if (rightspeed > 0)
  {
    digitalWriteFast(inb, LOW);
    digitalWriteFast(ina, HIGH);
  }
  else if (rightspeed < 0)
  {
    digitalWriteFast(ina, LOW);
    digitalWriteFast(inb, HIGH);
  }
  if (abs(leftspeed) > maxspeed)
    leftspeed = maxspeed;
  if (abs(rightspeed) > maxspeed)
    rightspeed = maxspeed;
  if(leftspeed==0 && rightspeed==0)
  {
    analogWrite(ena, 255);
    analogWrite(enb, 255);
  }
  else if(leftspeed==0)
  {
    analogWrite(enb, 255);
    analogWrite(ena, abs(rightspeed));
  }
  else if(rightspeed==0)
  {
    analogWrite(ena, 255);
    analogWrite(enb, abs(leftspeed));
  }
  else
  {
    analogWrite(ena, abs(rightspeed));
    analogWrite(enb, abs(leftspeed));
  }
}
