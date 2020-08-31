int pinLeds[] = {5,6,7};
int pinBotones[] = {8, 9, 10};
int randomLeds[10];
int contador=3;
int BA[10];

void setup() {
  for (int i = 0; i < contador; i++) {
    int randomindex = random(0,3);
    randomLeds[i] = pinLeds[randomindex];
  }
  for (int i = 0; i < 3; i++) {
    pinMode(pinLeds[i], OUTPUT);
    pinMode(pinBotones[i], INPUT);
     digitalWrite(pinLeds[i], LOW);
  }
    for (int i = 0; i < contador; i++) {
    blink(randomLeds[i], 500);
  }
}
void blink(int numPin, int retraso) {
  //Si estaba encendido lo apago
  digitalWrite(numPin, LOW);
  digitalWrite(numPin, HIGH);
  delay(retraso);
  digitalWrite(numPin, LOW);
  delay(retraso);
}
void loop() {
  
  for(int j=0;j<10;i++){
  for (int i=0;i<3;i++){
    digitalRead(pinBotones[i]);
  if(digitalRead(pinBotones[i])==HIGH){
   BA[j]=pinBotones[i];
  }
}
}
 if(BA[j]==randomLeds[i]){
    blink(pinLeds[0],1000);
    }else{
    blink(randomLeds[2],1000);
    }
}  
