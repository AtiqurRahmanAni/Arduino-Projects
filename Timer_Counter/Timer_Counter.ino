void setup() {

  Serial.begin(9600);

  TCCR1A = 0;
  TCCR1B = 0;

  //  TCCR1B = B00000100;
  //   TCCR1B = (1<<CS12);
  TCCR1B = _BV(CS12) | _BV(WGM12);
  
  TIMSK1 = _BV(OCIE1A);

  OCR1A = 62500;
  

}

void loop() {
  // put your main code here, to run repeatedly:

}

ISR(TIMER1_COMPA_vect)
{
  
  Serial.println("Hello");
}
