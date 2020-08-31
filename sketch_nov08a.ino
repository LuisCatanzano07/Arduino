int pinLeds[] = {5,6,7};
int pinBotones[] = {8, 9, 10};
int randomLeds[10];
int contador=5;
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
  delay(retraso);//retraso
}
void loop() {
int auxiliarcontador=0;
while(auxiliarcontador< contador){
for(int i=0;i<3;i++){
  if(digitalRead(pinBotones[i])==HIGH){
BA[i]=pinBotones[auxiliarcontador];
  } 
  }    
auxiliarcontador ++;
}
int sinerror=contador;
while (sinerror==contador){
for(int i=0;i<contador;i++){
  if(BA[i]=randomLeds[i]){
    sinerror--;
  }
  }
}
if(sinerror==contador){
  blink (pinLeds[2],1000);}
}


//  sin error
//  for(int i=0;i<contador;i++){
//    if(BA[i]==randomLeds[i]){
//      blink(pinLeds[2],1000);
//     sinerror++;
//    }
//    }
  //if(sinerror==0){
//blink(pinLeds[2],1000);
 // } else {blink(pinLeds[0],1000);}
//}

