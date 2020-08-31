int pinLeds[] = {7,6,5};
int pinBotones[] = {8, 9, 10};
int randomLeds[10];
int const NUM_LEDS = 3;

void setup() {
  for (int i = 0; i < 10; i++) {
    int randomindex = random(0, 3);
    randomLeds[i] = pinLeds[randomindex];
  }
  // put your setup code here, to run once:
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(pinLeds[i], OUTPUT);
    pinMode(pinBotones[i], INPUT);
     digitalWrite(pinLeds[i], LOW);
  }
  for (int i = 0; i < 10; i++) {
    blink(randomLeds[i], 200);
  }
}
void blink(int numPin, int retraso) {
  //Si estaba encendido lo apago
  digitalWrite(numPin, LOW);
  //Lo enciendo
  digitalWrite(numPin, HIGH);
  delay(retraso);//retraso
  digitalWrite(numPin, LOW);//lo apago
}
void loop() {
  


  // put your main code here, to run repeatedly:
  int valorLeido = LOW;
  for (int i = 0; i < NUM_LEDS; i++) {
    delay(10);
    valorLeido = digitalRead(pinBotones[i]);
     delay(10);
    while (valorLeido == HIGH) {
      digitalWrite(pinLeds[i], HIGH);
      valorLeido = digitalRead(pinBotones[i]);
    }
    digitalWrite(pinLeds[i], LOW);
  }
  //  if (indiceLectura >= 0)
  //  {
  //    digitalWrite(pinLeds[indiceLectura], HIGH);
  //    delay(10);
  //  }
}





