void rainbow()
{
  analogWrite(Red, Rvalue);       
  analogWrite(Green, Gvalue);
  analogWrite(Blue, Bvalue);

  Rvalue += Rdirection;   
  Gvalue += Gdirection;
  Bvalue += Bdirection;

  if (Rvalue >= 255 || Rvalue <= 0)
  {
    Rdirection = Rdirection * -1;
  }
  if (Gvalue >= 255 || Gvalue <= 0)
  {
    Gdirection = Rdirection * -1;
  }
  if (Bvalue >= 255 || Bvalue <= 0)
  {
    Bdirection = Bdirection * -1;
  }
  delay(15);
}
