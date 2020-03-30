int curr_press;
int last_press = LOW;
unsigned long last_toggle = 0;
unsigned long delay_time = 50;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int in = digitalRead(2);
  Serial.print("Non-debounced: ");
  Serial.println(in);

  if (in != last_press) {
    last_toggle = millis();
    Serial.println("Timer"); 
    Serial.println(last_toggle);
  }
  if((millis() - last_toggle) > delay_time) {
      if (in != curr_press) {
        curr_press = in;
      }
  }
  Serial.print("Debounced: ");
  Serial.println(curr_press);
  last_press = in;
}
