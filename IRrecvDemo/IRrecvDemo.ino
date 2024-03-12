int x;
void setup()
{
   pinMode(A0,INPUT);
   pinMode(10,OUTPUT);  
}

void loop() 
{
    x=analogRead(A0);
    if(x<=350)
    {
      digitalWrite(10,1);
      delay(500);
    }
    else
    {
      digitalWrite(10,0);
    }
}
