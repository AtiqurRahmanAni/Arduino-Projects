#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);  //sometimes the adress is not 0x3f. Change to 0x27 if it dosn't work.

//13 is the input to the circuit (connects to 150ohm resistor), 11 is the comparator/op-amp output.
double pulse, frequency, capacitance, inductance;
char str[8],str1[6];
void setup(){

  pinMode(11, INPUT);
  pinMode(13, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.print("Inductance:");
}
void loop(){
  digitalWrite(13, HIGH);
  delay(5);//give some time to charge inductor.
  digitalWrite(13,LOW);
  delayMicroseconds(100); //make sure resination is measured
  pulse = pulseIn(11,HIGH,5000);//returns 0 if timeout
  lcd.setCursor(0,1);
  if(pulse > 0.1){ //if a timeout did not occur and it took a reading:
    
    
  capacitance = 2.E-6; // - insert value here
  
  
  frequency = 1.E6/(2*pulse);
  inductance = 1./(capacitance*frequency*frequency*4.*3.14159*3.14159);//one of my profs told me just do squares like this
  inductance *= 1E6; //note that this is the same as saying inductance = inductance*1E6

  lcd.setCursor(0,1);
  dtostrf(inductance,6,2,str1);  
  sprintf(str,"%-7suH",str1);
  lcd.print(str);        
  delay(300);
  }
  else
  {
    lcd.setCursor(0,1);
    sprintf(str,"%-7suH","0");
    lcd.print(str);  
  }
}
