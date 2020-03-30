#include <SPI.h>
const int LEDPin = 3;
volatile boolean received;
volatile byte Slavereceived,Slavesend;
unsigned short currentVal = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);   
  pinMode(LEDPin, OUTPUT);
  SPCR |= _BV(SPE);    //Turn on SPI in Slave Mode
  received = false;
  SPI.attachInterrupt();  //Interuupt ON is set for SPI commnucation
}

ISR (SPI_STC_vect)       //Inerrrput routine function 
{
  Slavereceived = SPDR;  // Value received from master if store in variable slavereceived
  received = true;       //Sets received as True 
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(Slavereceived);
  if(received) {
    currentVal = Slavereceived; 
  }
  analogWrite(LEDPin, currentVal);
  delay(100);
}
