const int L_PWM1 = 3;
const int R_PWM1 = 9;

const int L_PWM2 = 10;
const int R_PWM2 = 11;

char ch;
int x=100;
void setup() 
{
  pinMode(L_PWM1,OUTPUT);  
  pinMode(R_PWM1,OUTPUT);
   
  pinMode(L_PWM2,OUTPUT);  
  pinMode(R_PWM2,OUTPUT);
  
  digitalWrite(L_PWM1,LOW);
  digitalWrite(R_PWM1,LOW);
  
  digitalWrite(L_PWM2,LOW);
  digitalWrite(R_PWM2,LOW);
  
  Serial.begin(9600);
}

void loop() 
{
  while(Serial.available()>0)
  {
    ch=Serial.read();
    if(ch=='F')
    {
      analogWrite(R_PWM1,0);
      analogWrite(L_PWM2,0);
      analogWrite(L_PWM1,255);
      analogWrite(R_PWM2,255);
    }
    else if(ch=='B')
    {
      analogWrite(L_PWM1,0);
      analogWrite(R_PWM2,0);
      analogWrite(R_PWM1,255);
      analogWrite(L_PWM2,255);
    }
    else if(ch=='R')
    {
      analogWrite(L_PWM1,0);
      analogWrite(L_PWM2,0);
      analogWrite(R_PWM2,255);
      analogWrite(R_PWM1,255);
    }
    else if(ch=='L')
    {
      analogWrite(R_PWM1,0);
      analogWrite(R_PWM2,0);
      analogWrite(L_PWM2,255);
      analogWrite(L_PWM1,255); 
    }
    else if(ch=='I')
    {
      analogWrite(R_PWM1,0);
      analogWrite(L_PWM2,0);
      analogWrite(R_PWM2,255);
      analogWrite(L_PWM1,x);
    }
    else if(ch=='G')
    {
      analogWrite(L_PWM2,0);
      analogWrite(R_PWM1,0);
      analogWrite(R_PWM2,x);
      analogWrite(L_PWM1,255);
    }
    else if(ch=='J')
    {
      analogWrite(L_PWM1,0);
      analogWrite(R_PWM2,0);
      analogWrite(R_PWM1,x);
      analogWrite(L_PWM2,255);
    }
    else if(ch=='H')
    {
      analogWrite(L_PWM1,0);
      analogWrite(R_PWM2,0);
      analogWrite(L_PWM2,x);
      analogWrite(R_PWM1,255);
    }
    else if(ch=='S')
    {
      analogWrite(L_PWM1,0);
      analogWrite(R_PWM1,0);
      analogWrite(L_PWM2,0);
      analogWrite(R_PWM2,0);
    }
  }
}
