/*
  Basic code for using Maxim MAX7219/MAX7221 with Arduino.
  Wire the Arduino and the MAX7219/MAX7221 together as follows:
  | Arduino   | MAX7219/MAX7221 |
  | --------- | --------------- |
  | MOSI (11) | DIN (1)         |
  | SCK (13)  | CLK (13)        |
  | I/O (7)*  | LOAD/CS (12)    |
      - This should match the LOAD_PIN constant defined below.

  For the rest of the wiring follow the wiring diagram found in the datasheet.

  Datasheet: http://datasheets.maximintegrated.com/en/ds/MAX7219-MAX7221.pdf
  Author:  Nicholas Dobie <nick@nickdobie.com>
  Date:    30 December 2013
  License: WTFPL (http://www.wtfpl.net/)
*/
//#include <SPI.h>

// What pin on the Arduino connects to the LOAD/CS pin on the MAX7219/MAX7221
#define LOAD_PIN 50
#define DATA_PIN 52
#define CLOCK_PIN 10


void setup() {

  // Set load pin to output
  pinMode(LOAD_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  digitalWrite(LOAD_PIN, HIGH);

  // Run test
  // All LED segments should light up
  sendData(0x0F, 0x01, 0x0F, 0x01);
  delay(1000);

  sendData(0x0F, 0x00, 0x0F, 0x00);

  // Enable mode B
  sendData(0x09, 0xFF, 0x09, 0xFF);

  // Use lowest intensity
  sendData(0x0A, 0x0F, 0x0A, 0x0F);

  // Only scan one digit
  sendData(0x0B, 0x07, 0x0B, 0x07);

  // Turn on chip
  sendData(0x0C, 0x01, 0x0C, 0x01);

  sendData(0x01, 0x08, 0x01, 0x01);
  sendData(0x02, 0x02, 0x02, 0x02);
  sendData(0x03, 0x03, 0x03, 0x03);
  sendData(0x04, 0x04, 0x04, 0x04);
  sendData(0x05, 0x05, 0x05, 0x05);
  sendData(0x06, 0x06, 0x06, 0x06);
  sendData(0x07, 0x07, 0x07, 0x07);
  sendData(0x08, 0x08, 0x08, 0x08);

}

void loop() {

  // Loop through each code
  //  for (uint8_t i = 1; i < 0x10; ++i)
  //  {
  //    sendData(1, i - 1);
  //    sendData(2, i - 1); 
  //    sendData(3, i - 1);
  //    sendData(4, i - 1);
  //    delay(500);
  //  }

}

void sendData(byte address1, byte data1, byte address2, byte data2)
{
  digitalWrite(LOAD_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, address1);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, data1);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, address2);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, data2);
  digitalWrite(LOAD_PIN, HIGH);
}
