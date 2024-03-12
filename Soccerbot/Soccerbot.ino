#define BT_SERIAL   Serial1

const int inar = 24;
const int inbr = 26;
const int incr = 28;
const int indr = 30;
const int enar = 7;
const int enbr = 6;

char ch = ' ';
const int baudRateBT = 9600;

void setup() {
  Serial.begin(9600);
  for (int i = 22; i <= 32; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  pinMode(enar, OUTPUT);
  pinMode(enbr, OUTPUT);

  BT_SERIAL.begin(baudRateBT);
  Serial.print("BTserial started at ");
  Serial.println(baudRateBT);
  Serial.println(" ");
}

void loop() {
  // Read from the Bluetooth module and send to the Arduino Serial Monitor
  if (BT_SERIAL.available()) {
    ch = BT_SERIAL.read();
    Serial.println(ch);
    if (ch == 'F') {

      digitalWrite(inar, HIGH);
      digitalWrite(inbr, LOW);
      digitalWrite(incr, HIGH);
      digitalWrite(indr, LOW);
    } else if (ch == 'B') {
      digitalWrite(inar, LOW);
      digitalWrite(inbr, HIGH);
      digitalWrite(incr, LOW);
      digitalWrite(indr, HIGH);
    } else if (ch == 'R') {
      digitalWrite(inar, HIGH);
      digitalWrite(inbr, LOW);
      digitalWrite(incr, LOW);
      digitalWrite(indr, HIGH);
    } else if (ch == 'L') {
      digitalWrite(inar, LOW);
      digitalWrite(inbr, HIGH);
      digitalWrite(incr, HIGH);
      digitalWrite(indr, LOW);
    } else if (ch == 'S') {
      digitalWrite(inar, LOW);
      digitalWrite(inbr, LOW);
      digitalWrite(incr, LOW);
      digitalWrite(indr, LOW);
      digitalWrite(enar, LOW);
      digitalWrite(enbr, LOW);
      delay(10000);
    } else if (ch == 'I') {  //FR
      digitalWrite(inar, HIGH);
      digitalWrite(inbr, LOW);
      digitalWrite(incr, LOW);
      digitalWrite(indr, LOW);
    } else if (ch == 'G') {  //FL
      digitalWrite(inar, LOW);
      digitalWrite(inbr, LOW);
      digitalWrite(incr, HIGH);
      digitalWrite(indr, LOW);
    } else if (ch == 'J') {  //BR
      digitalWrite(inar, LOW);
      digitalWrite(inbr, HIGH);
      digitalWrite(incr, LOW);
      digitalWrite(indr, LOW);
    } else if (ch == 'H') {  //BL
      digitalWrite(inar, LOW);
      digitalWrite(inbr, LOW);
      digitalWrite(incr, LOW);
      digitalWrite(indr, HIGH);
    } else if (ch == '0') {
      analogWrite(enar, 0);
      analogWrite(enbr, 0);
    } else if (ch == '1') {
      analogWrite(enar, 25);
      analogWrite(enbr, 25);
    } else if (ch == '2') {
      analogWrite(enar, 50);
      analogWrite(enbr, 50);
    } else if (ch == '3') {
      analogWrite(enar, 75);
      analogWrite(enbr, 75);
    } else if (ch == '4') {
      analogWrite(enar, 100);
      analogWrite(enbr, 100);
    } else if (ch == '5') {
      analogWrite(enar, 125);
      analogWrite(enbr, 125);
    } else if (ch == '6') {
      analogWrite(enar, 150);
      analogWrite(enbr, 150);
    } else if (ch == '7') {
      analogWrite(enar, 175);
      analogWrite(enbr, 175);
    } else if (ch == '8') {
      analogWrite(enar, 200);
      analogWrite(enbr, 200);
    } else if (ch == '9') {
      analogWrite(enar, 226);
      analogWrite(enbr, 226);
    } else if (ch == 'q') {
      analogWrite(enar, 255);
      analogWrite(enbr, 255);
    }
  }


}
