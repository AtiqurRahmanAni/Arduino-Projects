int x;
void setup() 
{
   TCCR2B = TCCR2B & B11111000 | B00000010; 
   pinMode(3,OUTPUT);
}

void loop() 
{
   x=analogRead(A1);
   analogWrite(3,map(x,0,1023,0,255));
}
