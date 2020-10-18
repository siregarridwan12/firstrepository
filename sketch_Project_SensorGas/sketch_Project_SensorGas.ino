#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
int MQ7_GAS_SENSOR = 3;
int greenLED = 4;
int redLED = 5;

void setup() {
pinMode (MQ7_GAS_SENSOR, INPUT_PULLUP);
pinMode (greenLED, OUTPUT);
pinMode (redLED, OUTPUT);
lcd.begin(20,4);
lcd.setCursor (0,0);
lcd.print ("RIDWAN SIREGAR");
lcd.setCursor (0,1);
lcd.print ("1903332088");
lcd.setCursor (0,2);
lcd.print ("TELEKOMUNIKASI 3C");
delay(1000);
lcd.clear();
lcd.setCursor (0,0);
lcd.print ("SISTEM PENDETEKSI");
lcd.setCursor (0,1);
lcd.print ("ALKOHOL");
lcd.setCursor (0,2);
lcd.print ("TELEKOMUNIKASI PNJ");
delay(1000);
}

void loop() {
  int GAS_SENSOR = digitalRead (MQ7_GAS_SENSOR);
  if (GAS_SENSOR == LOW)
  {
    lcd.clear();
    lcd.setCursor (0,3);
    lcd.print ("ALKOHOL DETECTED");
    digitalWrite (greenLED, HIGH);
    digitalWrite (redLED, LOW);
    delay(20);
  }
  else
  {
    lcd.clear();
    lcd.setCursor(0,3);
    lcd.print("ALKOHOL NOT DETECTED");
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    delay(20);
  }
}
