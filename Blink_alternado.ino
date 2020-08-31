int pinleds [] = {12, 8, 7};
int sizeb = sizeof(pinleds) / sizeof(int);
void setup() {
  for (int i = 0; i < sizeb; i++) {
    pinMode(pinleds[i], OUTPUT);
  }
}
void loop() {
  //digitalWrite (pinleds[12], HIGH);
  //delay(1000);
  //digitalWrite (pinleds[12], LOW);

  for (int i = 0; i < sizeb; i++) {
    digitalWrite (pinleds[i], HIGH);
    delay(1000);
    digitalWrite (pinleds[i], LOW);

  }
  delay(1000);
  for (int i = sizeb - 1; i >= 0; i--) {
    digitalWrite (pinleds[i], HIGH);
    delay(1000);
    digitalWrite (pinleds[i], LOW);
  }
  delay (1000);
}
