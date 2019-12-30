char ch;
int i,x=255,y;
void setup()
{
  for(i=2;i<=13;i++)
  {
    pinMode(i,OUTPUT);
  }
  for(i=2;i<=13;i++)
  {
    digitalWrite(i,0);
  }
  Serial.begin(9600);
} 

void loop()
{
  while(Serial.available()>0)
  {
    ch=Serial.read();
    if(ch=='0')
      x=0;
    else if(ch=='1')
      x=25;
    else if(ch=='2')
      x=51;
    else if(ch=='3')
      x=76;
    else if(ch=='4')
      x=102;
    else if(ch=='5')
      x=127;
    else if(ch=='6')
      x=153;
    else if(ch=='7')
      x=178;
    else if(ch=='8')
      x=204;
    else if(ch=='9')
      x=229;
    else if(ch=='q')
      x=255;
        analogWrite(3,x);
        analogWrite(9,x);
        analogWrite(10,x);
        analogWrite(11,x);
    if(ch=='F')
    {
        digitalWrite(2, 1);
        digitalWrite(4, 0);
        digitalWrite(5, 1);
        digitalWrite(6, 0);
        digitalWrite(7, 1);
        digitalWrite(8, 0);
        digitalWrite(12, 1);
        digitalWrite(13, 0);
    }
    else if(ch=='B')
    {
        digitalWrite(2, 0);
        digitalWrite(4, 1);
        digitalWrite(5, 0);
        digitalWrite(6, 1);
        digitalWrite(7, 0);
        digitalWrite(8, 1);
        digitalWrite(12, 0);
        digitalWrite(13, 1);
    }
    else if(ch=='R')
    {   
        digitalWrite(2, 1);
        digitalWrite(4, 0);
        digitalWrite(5, 1);
        digitalWrite(6, 0);
        digitalWrite(7, 0);
        digitalWrite(8, 1);
        digitalWrite(12, 0);
        digitalWrite(13, 1);
   
    }
    else if(ch=='L')
    {
        digitalWrite(2, 0);
        digitalWrite(4, 1);
        digitalWrite(5, 0);
        digitalWrite(6, 1);
        digitalWrite(7, 1);
        digitalWrite(8, 0);
        digitalWrite(12, 1);
        digitalWrite(13, 0);
    }
    else if(ch=='G')
    {
        digitalWrite(2, 0);
        digitalWrite(4, 0);
        digitalWrite(5, 0);
        digitalWrite(6, 0);
        digitalWrite(7, 1);
        digitalWrite(8, 0);
        digitalWrite(12, 1);
        digitalWrite(13, 0);
    }
    else if(ch=='I')
    {
        digitalWrite(2, 1);
        digitalWrite(4, 0);
        digitalWrite(5, 1);
        digitalWrite(6, 0);
        digitalWrite(7, 0);
        digitalWrite(8, 0);
        digitalWrite(12, 0);
        digitalWrite(13, 0);
    }
    else if(ch=='H')
    {
        digitalWrite(2, 0);
        digitalWrite(4, 1);
        digitalWrite(5, 0);
        digitalWrite(6, 1);
        digitalWrite(7, 0);
        digitalWrite(8, 0);
        digitalWrite(12, 0);
        digitalWrite(13, 0);
    }
    else if(ch=='J')
    {
        digitalWrite(2, 0);
        digitalWrite(4, 0);
        digitalWrite(5, 0);
        digitalWrite(6, 0);
        digitalWrite(7, 0);
        digitalWrite(8, 1);
        digitalWrite(12, 0);
        digitalWrite(13, 1);
    }
    else if(ch=='S')
    {
        digitalWrite(2, 0);
        digitalWrite(4, 0);
        digitalWrite(5, 0);
        digitalWrite(6, 0);
        digitalWrite(7, 0);
        digitalWrite(8, 0);
        digitalWrite(12, 0);
        digitalWrite(13, 0);
    }
  }
}
