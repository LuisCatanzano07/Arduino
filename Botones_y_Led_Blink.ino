int pinLeds[] = {5,6,7};
int pinBotones[] = {8, 9, 10};
int randomLeds[5];
int const sizeb = sizeof(pinLeds) / sizeof(int);


void setup() {
  for (int i = 0; i < 10; i++) {
    int randomindex = random(0, 3);
    randomLeds[i] = pinLeds[randomindex];
  }
  // put your setup code here, to run once:
  for (int i = 0; i < sizeb; i++) {
    pinMode(pinLeds[i], OUTPUT);
    pinMode(pinBotones[i], INPUT);
     digitalWrite(pinLeds[i], LOW);
  }
  for (int i = 0; i < 10; i++) {
    blink(randomLeds[i], 500);
  }
}
void blink(int numPin, int retraso) {
  //Si estaba encendido lo apago
  digitalWrite(numPin, LOW);
  //Lo enciendo
  digitalWrite(numPin, HIGH);
  delay(retraso);//retraso
  digitalWrite(numPin, LOW);//lo apago
  delay(retraso);//retraso
}
void loop() {
  int valorLeido = LOW;
  for (int i = 0; i < sizeb; i++) {
    valorLeido = digitalRead(pinBotones[i]);
    while (valorLeido == HIGH) {
      digitalWrite(pinLeds[i], HIGH);
      valorLeido = digitalRead(pinBotones[i]);
    }
    digitalWrite(pinLeds[i], LOW);
  }
}




