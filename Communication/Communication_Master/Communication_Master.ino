#include <SPI.h>
const int potPin = A0;
unsigned int potVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(potPin, INPUT);
  potVal = 0;
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  digitalWrite(SS, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  byte toSend = (short)(potVal/4);
  digitalWrite(SS, LOW);
  Serial.println(toSend); 
  SPI.transfer(toSend);
 
  delay(100);
}
