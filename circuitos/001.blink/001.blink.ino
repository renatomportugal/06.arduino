#define LED 13

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  // Led ON
  digitalWrite(LED, HIGH);
  // DELAY 1s
  delay(1000);
  // Led OFF
  digitalWrite(LED, LOW);
  // DELAY 1s
  delay(1000);
}
