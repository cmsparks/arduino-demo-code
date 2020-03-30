void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int read = analogRead(A0);
  read = read / 4;
  analogWrite(5, read);
}
