void lineFollow()
{
  //flag 1 for right
  //flag 2 for left
  //flag 3 for straight
  //flag 4 for forwardright
  //flag 5 for forwardleft
  int error, delspeed;
  error = conditions();
  if (error == 1000)
  {
    digitalWriteFast(led, HIGH);
    count++;
    sprintf(countstring, "%2d", count);
    lcd.setCursor(8, 0);
    lcd.print(countstring);
    flag = 0;
    ////////////////////////////////
    for (i = 0; i < nr; i++)
    {
      if (count == right[i])
      {
        flag = 1;
        break;
      }
    }
    for (i = 0; i < nl; i++)
    {
      if (count == left[i])
      {
        flag = 2;
        break;
      }
    }
    for (i = 0; i < ns; i++)
    {
      if (count == straight[i])
      {
        flag = 3;
        break;
      }
    }
    for (i = 0; i < nfr; i++)
    {
      if (count == forwardright[i])
      {
        flag = 4;
        break;
      }
    }
    for (i = 0; i < nfl; i++)
    {
      if (count == forwardleft[i])
      {
        flag = 5;
        break;
      }
    }
    ///////////////////////////////
    //Check which direction the bot will go
    if (flag == 1)
    {
      turnRight(30, 300);/*First parameter is time to go forward and second is turning duration*/
    }
    else if (flag == 2)
    {
      turnLeft(30, 300); /*First parameter is time to go forward and second is turning duration*/
    }
    else if (flag == 3)
    {
      while (true)
      {
        if (digitalReadFast(button) == LOW)
        {
          stopBot(0);
          break;
        }
        readLine();
        if (sums == 2 || sums == 1)
          break;
        goStraight(0, 230);
      }
    }
    else if (flag == 4)
    {
      goStraight(40, 150);
      wheel(0, 0);
      delay(80);
      forwardRight(150, 150);
    }
    else if (flag == 5)
    {
      goStraight(15, 150);
      wheel(0, 0);
      delay(80);
      forwardLeft(150, 100);
    }
    else if (count > maxcount)
    {
      X:
      stopBot(0);
      dolinefollow = stopflag = false;
      count = 0;
      sprintf(countstring, "%2d", count);
      lcd.setCursor(8, 0);
      lcd.print(countstring);
    }
  }
  else if (error == 420)
  {
    digitalWriteFast(led, HIGH);
    if (stopflag)
    {
      goto X;
    }
  }
  else
  {
    digitalWriteFast(led, LOW);
    if (count == 14)
    {
      stopflag=true;
    }
    delspeed = (kp * error) + (kd * (error - preverror));
    leftspeed = leftbasespeed + delspeed;
    rightspeed = rightbasespeed - delspeed;
    wheel(leftspeed , rightspeed);
    preverror = error;
  }
}
