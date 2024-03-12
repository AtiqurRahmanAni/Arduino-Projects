int led = 0;
int led1 = 0;
void setup() {

  pinMode(13, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);

  TCCR1A = 0;
  TCCR1B = 0;

  TCCR1B |= _BV(CS12) | _BV(WGM12);

  TIMSK1 |= _BV(OCIE1A) | _BV(OCIE1B);

  OCR1B = 31250;
  OCR1A = 62500;

}

void loop() {

}

ISR(TIMER1_COMPA_vect)
{
  led ^=1;
  digitalWrite(13, led);
}
ISR(TIMER1_COMPB_vect)
{
  led1 ^=1;
  digitalWrite(5, led1);
}
