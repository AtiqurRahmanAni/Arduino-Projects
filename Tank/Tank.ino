const int L_EN1 = 4;
const int R_EN1 = 5;
const int L_PWM1 = 3;
const int R_PWM1 = 9;
const int L_EN2 = 6;
const int R_EN2 = 7;
const int L_PWM2 = 10;
const int R_PWM2 = 11;
char ch;
int x=100;
void setup() 
{
  TCCR2B = TCCR2B & B11111000 | B00000010;
  TCCR1B = TCCR1B & B11111000 | B00000010;
  pinMode(L_EN1,OUTPUT);  
  pinMode(R_EN1,OUTPUT);  
  pinMode(L_PWM1,OUTPUT);  
  pinMode(R_PWM1,OUTPUT);
  pinMode(L_EN2,OUTPUT);  
  pinMode(R_EN2,OUTPUT);  
  pinMode(L_PWM2,OUTPUT);  
  pinMode(R_PWM2,OUTPUT);
  digitalWrite(L_EN1,LOW);
  digitalWrite(R_EN1,LOW);
  digitalWrite(L_PWM1,LOW);
  digitalWrite(R_PWM1,LOW);
  digitalWrite(L_EN2,LOW);
  digitalWrite(R_EN2,LOW);
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
      digitalWrite(L_EN1,HIGH);
      digitalWrite(R_EN1,HIGH);
      digitalWrite(L_EN2,HIGH);
      digitalWrite(R_EN2,HIGH);
      analogWrite(R_PWM1,0);
      analogWrite(L_PWM2,0);
      analogWrite(L_PWM1,255);
      analogWrite(R_PWM2,255);
    }
    else if(ch=='B')
    {
      digitalWrite(L_EN1,HIGH);
      digitalWrite(R_EN1,HIGH);
      digitalWrite(L_EN2,HIGH);
      digitalWrite(R_EN2,HIGH);
      analogWrite(L_PWM1,0);
      analogWrite(R_PWM2,0);
      analogWrite(R_PWM1,255);
      analogWrite(L_PWM2,255);
    }
    else if(ch=='R')
    {
      digitalWrite(L_EN1,HIGH);
      digitalWrite(R_EN1,HIGH);
      digitalWrite(L_EN2,HIGH);
      digitalWrite(R_EN2,HIGH);
      analogWrite(L_PWM1,0);
      analogWrite(L_PWM2,0);
      analogWrite(R_PWM2,255);
      analogWrite(R_PWM1,255);
    }
    else if(ch=='L')
    {
      digitalWrite(L_EN1,HIGH);
      digitalWrite(R_EN1,HIGH);
      digitalWrite(L_EN2,HIGH);
      digitalWrite(R_EN2,HIGH);
      analogWrite(R_PWM1,0);
      analogWrite(R_PWM2,0);
      analogWrite(L_PWM2,255);
      analogWrite(L_PWM1,255); 
    }
    else if(ch=='I')
    {
      digitalWrite(L_EN1,HIGH);
      digitalWrite(R_EN1,HIGH);
      digitalWrite(L_EN2,HIGH);
      digitalWrite(R_EN2,HIGH);
      analogWrite(R_PWM1,0);
      analogWrite(L_PWM2,0);
      analogWrite(R_PWM2,255);
      analogWrite(L_PWM1,x);
    }
    else if(ch=='G')
    {
      digitalWrite(L_EN1,HIGH);
      digitalWrite(R_EN1,HIGH);
      digitalWrite(L_EN2,HIGH);
      digitalWrite(R_EN2,HIGH);
      analogWrite(L_PWM2,0);
      analogWrite(R_PWM1,0);
      analogWrite(R_PWM2,x);
      analogWrite(L_PWM1,255);
    }
    else if(ch=='J')
    {
      digitalWrite(L_EN1,HIGH);
      digitalWrite(R_EN1,HIGH);
      digitalWrite(L_EN2,HIGH);
      digitalWrite(R_EN2,HIGH);
      analogWrite(L_PWM1,0);
      analogWrite(R_PWM2,0);
      analogWrite(R_PWM1,x);
      analogWrite(L_PWM2,255);
    }
    else if(ch=='H')
    {
      digitalWrite(L_EN1,HIGH);
      digitalWrite(R_EN1,HIGH);
      digitalWrite(L_EN2,HIGH);
      digitalWrite(R_EN2,HIGH);
      analogWrite(L_PWM1,0);
      analogWrite(R_PWM2,0);
      analogWrite(L_PWM2,x);
      analogWrite(R_PWM1,255);
    }
    else if(ch=='S')
    {
      digitalWrite(L_EN1,HIGH);
      digitalWrite(R_EN1,HIGH);
      digitalWrite(L_EN2,HIGH);
      digitalWrite(R_EN2,HIGH);
      analogWrite(L_PWM1,0);
      analogWrite(R_PWM1,0);
      analogWrite(L_PWM2,0);
      analogWrite(R_PWM2,0);
    }
  }
}
