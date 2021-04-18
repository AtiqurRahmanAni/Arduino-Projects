const int KP_PACKET_SIZE = 8;
const int KD_PACKET_SIZE = 8;
const short inb = 4;
const short ina = 5;
const short ind = 6;
const short inc = 7;
const short ena = 3;
const short enb = 9;
const int leftbasespeed = 65;
const int rightbasespeed = 65;
const int maxspeed = 60;
const short trig = 10;
const short obstacle = 11;
const short eco = 8;
long int duration;
float distance;
float kp = 13;
float kd = 22.7;
float integral;
float preverror;
char c;
int lasterror, setpoint = 12, i;
float error;
int delspeed;
void setup()
{
  pinMode(ina, OUTPUT);
  pinMode(inb, OUTPUT);
  pinMode(inc, OUTPUT);
  pinMode(ind, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(2, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(eco, INPUT);
  digitalWrite(ina, LOW);
  digitalWrite(inb, LOW);
  digitalWrite(inc, LOW);
  digitalWrite(ind, LOW);
  digitalWrite(13, LOW);
  digitalWrite(obstacle, LOW);
  preverror = 0;
  Serial.begin(9600);
  delay(100);
}

void loop() {

  if (Serial.available())
  {
    {
      handleSerial(Serial.peek());
    }
  }
  while (digitalRead(obstacle) == HIGH)
  {
    turn();
  }
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(eco, HIGH);
  distance = (duration / 2.0) * 0.0343;
  //    Serial.print("Distance: ");
  //    Serial.print(distance);
  //    Serial.println(" cm");
  error = distance - setpoint;
  integral += error;
  delspeed = (kp * error) + (kd * (error - preverror));
  wheel(leftbasespeed + delspeed, rightbasespeed - delspeed);
  preverror = error;
  delayMicroseconds(600);
}
void wheel(int leftspeed, int rightspeed)
{
  //    Serial.print(leftspeed);
  //    Serial.print(' ');
  //    Serial.println(rightspeed);
  if (leftspeed == 0)
  {
    digitalWrite(inc, LOW);
    digitalWrite(ind, LOW);
  }
  else if (leftspeed > 0)
  {
    digitalWrite(inc, LOW);
    digitalWrite(ind, HIGH);
  }
  else if (leftspeed < 0)
  {
    digitalWrite(inc, 1);
    digitalWrite(ind, LOW);
  }
  if (rightspeed == 0)
  {
    digitalWrite(ina, LOW);
    digitalWrite(inb, LOW);
  }
  else if (rightspeed > 0)
  {
    digitalWrite(inb, LOW);
    digitalWrite(ina, HIGH);
  }
  else if (rightspeed < 0)
  {
    digitalWrite(ina, LOW);
    digitalWrite(inb, HIGH);
  }
  if (abs(leftspeed) > maxspeed)
    leftspeed = maxspeed;
  if (abs(rightspeed) > maxspeed)
    rightspeed = maxspeed;
  analogWrite(ena, abs(rightspeed));
  analogWrite(enb, abs(leftspeed));
}
void handleSerial(char c)
{
  switch (c)
  {
    case 'P':
      {
        if (Serial.available() < KP_PACKET_SIZE)
          break;
        kp = Serial.parseFloat();
        if (Serial.read() == 13)
        {
          if (Serial.read() == 10)
          {
            Serial.print("KP: ");
            Serial.println(kp);
          }
          else
            clearSerialBuffer();
        }
        else
          clearSerialBuffer();
      } break;
    case 'D':
      {
        if (Serial.available() < KD_PACKET_SIZE)
          break;
        kd = Serial.parseFloat();
        if (Serial.read() == 13)
        {
          if (Serial.read() == 10)
          {
            Serial.print("KD: ");
            Serial.println(kd);
          }
          else
            clearSerialBuffer();
        }
        else
          clearSerialBuffer();
      } break;
    default:
      clearSerialBuffer();
      break;
  }
}
void clearSerialBuffer()
{
  while (Serial.available())
    Serial.read();
}
void turn()
{
  digitalWrite(ind, LOW);
  digitalWrite(inc, HIGH);
  digitalWrite(inb, LOW);
  digitalWrite(ina, HIGH);
  analogWrite(ena, 65);
  analogWrite(enb, 65);
}
