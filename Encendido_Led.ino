int pinLeds[] = {5, 6, 7};
int pinBotones[] = {8, 9, 10};
int sizeb = sizeof(pinLeds) / sizeof(int);

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < sizeb; i++) {
    pinMode(pinLeds[i], OUTPUT);
    pinMode(pinBotones[i], INPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int estado = LOW;
  for (int i = 0; i < sizeb; i++) {
    estado = digitalRead(pinBotones[i]);
    while (estado == HIGH) {
      digitalWrite(pinLeds[i], HIGH);
     estado = digitalRead(pinBotones[i]);
    }
     digitalWrite(pinLeds[i], LOW);   
     
  }
}
