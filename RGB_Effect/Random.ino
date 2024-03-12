void RANDOM()
{
  Rvalue=rand()%256;
  Gvalue=rand()%256;
  Bvalue=rand()%256;
  analogWrite(Red, Rvalue);       
  analogWrite(Green, Gvalue);
  analogWrite(Blue, Bvalue);
  delay(100);
}
