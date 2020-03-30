void setup() {
  // put your setup code here, to run once:
  // Clean up Timer/Counter Control Registers
  TCCR1A = 0; //Set Timer/Counter Control Register A value to 0

  TCCR1B = 0; //Set Timer/Counter Control Register B value to 0
  bitSet(TCCR1B, CS12);
  bitSet(TIMSK1, TOIE1);
  pinMode(9, OUTPUT);
}

ISR(TIMER1_OVF_vect) {
  digitalWrite(9, !digitalRead(9));
}

void loop() {
  
}
