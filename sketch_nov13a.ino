int pinLeds[] = {5,6,7};
int pinBotones[] = {8, 9, 10};
int randomLeds[10];
int contador=10;
int BA[10];
int BO []={0,1,2};
int posicionrandom[10] ;
          int estado=LOW;
int error=0;
int ban2=0;
int ban=0;


void setup() {
  for (int i = 0; i < contador; i++) {
    int randomindex = random(0,3);
    randomLeds[i] = pinLeds[randomindex];
    posicionrandom[i]=randomindex ;
  }
  for (int i = 0; i < 3; i++) {
    pinMode(pinLeds[i], OUTPUT);
    pinMode(pinBotones[i], INPUT);
     digitalWrite(pinLeds[i], LOW);
  }

}
void blink(int numPin, int retraso) {
  digitalWrite(numPin, LOW);
  digitalWrite(numPin, HIGH);
  delay(retraso);
  digitalWrite(numPin, LOW);
  delay(retraso);
}
void loop () {
  int contadorauxiliar=0;
  int contadorauxiliar2=0;
  int contadorauxiliar3=0;
  for (int n=0; n<contador;n++){
        for (int j = 0; j <= contadorauxiliar3; j++) {
    blink(randomLeds[j], 500);
    }

       while (contadorauxiliar<contador){
         for(int i=0;i<3;i++){ 
         estado= digitalRead(pinBotones[i]);  
          if(estado==HIGH){
          blink(pinLeds[i],100);
              if(i==posicionrandom[contadorauxiliar]){
              contadorauxiliar++;
              BA[i]=i;
              }else {
                (contadorauxiliar=contador);
                  error=i;   
        }
      }
    }
   }
    
   for (int t=0; t<=contador;t++){
      if (BA[t]==posicionrandom[t]){
         contadorauxiliar2++;
    }
  }
    if(contadorauxiliar2==contador){
    contadorauxiliar3 ++; 
    } 
  }
}



