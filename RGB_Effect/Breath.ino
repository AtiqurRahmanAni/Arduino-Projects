void breath(int x,int y,int z)
{
  analogWrite(Red, x);       
  analogWrite(Green, y);
  analogWrite(Blue, z);
}
