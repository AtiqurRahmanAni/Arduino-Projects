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
    digitalWrite(13, HIGH);
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
      turnRight(45, 200);/*First parameter is time to go forward and second is turning duration*/
      while (true)
      {
        if (digitalRead(button) == LOW)
        {
          stopBot(0);
          break;
        }
        readLine();
        if (s[3] == 1 || s[4] == 1)
        {
          wheel(-turnspeedleft, turnspeedright);
          delay(80);
          stopBot(80);
          break;
        }
        wheel(turnspeedleft, -turnspeedright);
      }
    }
    else if (flag == 2)
    {
      turnLeft(45, 200); /*First parameter is time to go forward and second is turning duration*/
      while (true)
      {
        if (digitalRead(button) == LOW)
        {
          stopBot(0);
          break;
        }
        readLine();
        if (s[3] == 1 || s[4] == 1)
        {
          wheel(turnspeedleft, -turnspeedright);
          delay(80);
          stopBot(80);
          break;
        }
        wheel(-turnspeedleft, turnspeedright);
      }
    }
    else if (flag == 3)
    {
      while (true)
      {
        if (digitalRead(button) == LOW)
        {
          stopBot(0);
          break;
        }
        readLine();
        if (sums == 2 || sums == 1)
          break;
        goStraight(0,120);
      }
    }
    else if (flag == 4)
    {
      goStraight(30,100);
      wheel(0, 0);
      delay(80);
      while (true)
      {
        if (digitalRead(button) == LOW)
        {
          stopBot(0);
          break;
        }
        readLine();
        if (s[3] == 1 && (s[5]+s[6]+s[7]+s[0]+s[1]+s[2]) == 0)
          break;
        forwardRight(90, 0); //First parameter is speed difference and second is delay time
      }
    }
    else if (flag == 5)
    {
      wheel(0, 0);
      delay(80);
      while (true)
      {
        if (digitalRead(button) == LOW)
        {
          stopBot(0);
          break;
        }
        readLine();
        if (s[4] == 1 && (s[5]+s[6]+s[7]+s[0]+s[1]+s[2]) == 0)
          break;
        forwardLeft(70, 0); //First parameter is speed difference and second is delay time
      }
    }
    else if (count > maxcount)
    {
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
    digitalWrite(13, HIGH);
    if (lastsensor == 1)
    {
      while (true)
      {
        if (digitalRead(button) == LOW)
        {
          stopBot(0);
          break;
        }
        readLine();
        if (sums != 0)
          break;
        wheel(-turnspeedleft, turnspeedright);
      }
    }
    else if (lastsensor == 2)
    {
      while (true)
      {
        if (digitalRead(button) == LOW)
        {
          stopBot(0);
          break;
        }
        readLine();
        if (sums != 0)
          break;
        wheel(turnspeedleft, -turnspeedright);
      }
    }
    else if (lastsensor == 3)
    {
      while (true)
      {
        if (digitalRead(button) == LOW)
        {
          stopBot(0);
          break;
        }
        readLine();
        if (sums != 0)
          break;
        goStraight(0,120);
      }
    }
  }
  else
  {
    digitalWrite(13, LOW);
    delspeed = (kp * error) + (kd * (error - preverror));
    leftspeed = leftbasespeed + delspeed;
    rightspeed = rightbasespeed - delspeed;
    wheel(leftspeed , rightspeed);
    preverror = error;
  }
}
