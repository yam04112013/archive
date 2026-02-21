void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(3, INPUT_PULLUP);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {

  if (digitalRead(3) == 0) {
    digitalWrite(11, 1);
    digitalWrite(5, 1);
    digitalWrite(6, 0);
  } else {
    digitalWrite(12, 1);
    digitalWrite(5, 0);
    digitalWrite(6, 1);
  }
}
delay(1);
