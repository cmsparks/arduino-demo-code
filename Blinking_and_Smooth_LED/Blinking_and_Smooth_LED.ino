void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);
  for(int i = 0; i < 255; i++) {
    analogWrite(5, i);
    delay(10);
  }
  digitalWrite(13, LOW);
  for(int i = 255; i > 0; i--) {
    analogWrite(5, i);
    delay(10);
  }
}
