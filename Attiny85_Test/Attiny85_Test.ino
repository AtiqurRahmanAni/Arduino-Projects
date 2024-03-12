#include <SoftwareSerial.h>
#include <TinyWireM.h>

const uint8_t RTC_ADDR = 0x68;
const unsigned long READ_INTERVAL = 1000;    //milliseconds
SoftwareSerial Debug = SoftwareSerial(3, 4);

void setup()
{
  Debug.begin(9600);
}

void loop()
{
  static unsigned long msLast;

  unsigned long ms = millis();
  if (ms - msLast >= READ_INTERVAL) {
    msLast = ms;

    //read seconds, minutes, hours registers from the rtc
    TinyWireM.begin();
    TinyWireM.beginTransmission(RTC_ADDR);
    TinyWireM.send(0x00);
    uint8_t txStatus = TinyWireM.endTransmission();

    TinyWireM.requestFrom(RTC_ADDR, 3);
    uint8_t s = TinyWireM.receive();
    uint8_t m = TinyWireM.receive();
    uint8_t h = TinyWireM.receive();

    //print the i2c status and the time from the rtc
    Debug.print(txStatus, DEC);
    Debug.print(' ');
    Debug.print(h, HEX);
    Debug.print('h');
    Debug.print(m, HEX);
    Debug.print('m');
    Debug.print(s, HEX);
    Debug.println('s');
    Debug.end();
  }
}
