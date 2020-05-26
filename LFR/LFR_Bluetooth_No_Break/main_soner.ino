void wallFollow()
{
  int wallerror,delspeed;
  measureDistance();
  if (distance >= 30) 
  {
    stopBot(15);
    while (true)
    {
      measureDistance();
      if (distance <= 20)
        break;
    }
  }
  else
  {
    wallerror=distance - setpoint;
    delspeed = (wallkp * wallerror) + (wallkd * (wallerror - wallpreverror));
    wheel(wallleftbasespeed + delspeed, wallrightbasespeed - delspeed);
    wallpreverror = wallerror;
  }
  delayMicroseconds(600);
}
