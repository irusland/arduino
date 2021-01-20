void setup(void) {
  pinMode(13, OUTPUT);
}

void loop() {
  for (int i = 100; i > 1; i--){
    digitalWrite(13, LOW);
    delay(100);
    digitalWrite(13, HIGH);
    delay(10 * i);
  }
}
