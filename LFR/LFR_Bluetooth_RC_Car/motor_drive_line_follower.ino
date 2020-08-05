void wheel(int leftspeed, int rightspeed)
{
  if (leftspeed == 0)
  {
    analogWrite(enb, 255);
    digitalWrite(inc,HIGH);
    digitalWrite(ind,HIGH); 
  }
  else if (leftspeed > 0)
  {
    digitalWrite(inc,HIGH);
    digitalWrite(ind,LOW);
  }
  else if (leftspeed < 0)
  {
    digitalWrite(inc,LOW);
    digitalWrite(ind,HIGH);
  }
  if (rightspeed == 0)
  {
    analogWrite(ena, 255);
    digitalWrite(ina,HIGH);
    digitalWrite(inb,HIGH);
  }
  else if (rightspeed > 0)
  {
    digitalWrite(ina,LOW);
    digitalWrite(inb,HIGH);
  }
  else if (rightspeed < 0)
  {
    digitalWrite(ina,HIGH);
    digitalWrite(inb,LOW);
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
