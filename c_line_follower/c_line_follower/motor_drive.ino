void wheel(int leftspeed,int rightspeed)
{
  Serial.print(leftspeed);
  Serial.print(' ');
  Serial.println(rightspeed); 
  if(leftspeed==0)
  {
    digitalWrite(inc,1);
    digitalWrite(ind,1);
  }
   if(leftspeed>0)
  {
    digitalWrite(inc,1);
    digitalWrite(ind,0);
  }
  else if(leftspeed<0)
  {
     digitalWrite(inc,0);
     digitalWrite(ind,1);
  }

  
  if(rightspeed==0)
  {
    digitalWrite(ina,1);
    digitalWrite(inb,1);
  }
   if(rightspeed>0)
  {
    digitalWrite(ina,1);
    digitalWrite(inb,0);
  }
  else if(rightspeed<0)
  {
     digitalWrite(ina,0);
     digitalWrite(inb,1);
  }
  if(abs(leftspeed)>maxspeed)
     leftspeed=maxspeed;
  if(abs(rightspeed)>maxspeed)
     rightspeed=maxspeed;
     analogWrite(ena,abs(rightspeed));
     analogWrite(enb,abs(leftspeed));
}
