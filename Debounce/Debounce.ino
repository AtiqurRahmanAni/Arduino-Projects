int pin = 2;
short x;
void setup() {
  pinMode(pin, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  digitalWrite(13, 0);
}

void loop() {
  x = digitalRead(pin);
//  Serial.println(digitalRead(pin));
  if(x == 1)
  {
    digitalWrite(13, HIGH);
  }
  else
  {
    digitalWrite(13, LOW);
  }
}
