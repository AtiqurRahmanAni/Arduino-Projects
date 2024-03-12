int ara[6];
void setup() 
{
  pinMode(4,OUTPUT);
  digitalWrite(4,1);
  Serial.begin(9600);
}

void loop() 
{
    ara[0]=analogRead(A0);
    ara[1]=analogRead(A1);
    ara[2]=analogRead(A2);
    ara[3]=analogRead(A3);
    ara[4]=analogRead(A4);
    ara[5]=analogRead(A5);
    for(int i=0;i<=5;i++)
    {
      if(ara[i]<=450)
        ara[i]=0;
      else
        ara[i]=1;
      Serial.print(ara[i]);
      Serial.print(' ');
    }
    Serial.println("");
    delay(50);
}
