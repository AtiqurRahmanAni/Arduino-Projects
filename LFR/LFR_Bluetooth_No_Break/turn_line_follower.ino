void turnRight(int del1, int del2)
{
  wheel(turnspeedleft,turnspeedright);
  delay(del1);
  wheel(0, 0);
  delay(150);
  readLine();
  wheel(turnspeedleft, -turnspeedright);
  delay(del2);
}
void turnLeft(int del1, int del2)
{
  wheel(turnspeedleft,turnspeedright);
  delay(del1);
  wheel(0, 0);
  delay(150);
  wheel(-turnspeedleft, turnspeedright);
  delay(del2);
}
void goStraight(int del1,int wheelspeed)
{
  wheel(wheelspeed,wheelspeed);
  delay(del1);
}
void forwardRight(int diff, int del)
{
  wheel(turnspeedleft, turnspeedright - diff);
  delay(del);
}
void forwardLeft(int diff, int del)
{
  wheel(turnspeedleft-diff, turnspeedright);
  delay(del);
}
void stopBot(int del)
{
  //digitalWrite(13, HIGH);
  wheel(0, 0);
  delay(del);
}
