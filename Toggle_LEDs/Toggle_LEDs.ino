const int BLINK = 9;
const int FADE = 10;
int steps = 0; //increases to 255, then decreases
bool increasing = true;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BLINK, OUTPUT);
  pinMode(FADE, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if ((steps / 100) % 2 == 0) {
    digitalWrite(BLINK, HIGH);
  } else {
    digitalWrite(BLINK, LOW);
  }
  
  analogWrite(FADE, steps);
  
  if (increasing) {
    steps += 1;
  } else {
    steps -= 1;
  }

  if (steps <=0 || steps >= 255 ) {
    increasing = !increasing;
  }

  Serial.println(steps);
  
  delay(2);
}
