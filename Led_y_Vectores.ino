int led1 = 12;
int led2 = 8;
int led3 = 7;
int vectorLed[] = {led1, led2, led3};
int vectorLen = (sizeof(vectorLed)/sizeof(int));
void setup() {
  // put your setup code here, to run once:
  for(int i=0; i < vectorLen ; i++){
    pinMode(vectorLed[i],OUTPUT);  
    }
}

void loop() {
    delay(1000);
  digitalWrite(vectorLed[led1],HIGH);
  delay(1000);
  digitalWrite(vectorLed[led1],LOW);  
  delay(1000);
   for(int i=0; i < vectorLen ; i++){
    digitalWrite(vectorLed[i],HIGH);
    delay(1000);
    digitalWrite(vectorLed[i],LOW);  
    }

    for(int i=vectorLen-1; i >=0 ; i--){
    digitalWrite(vectorLed[i],HIGH);
    delay(1000);
    digitalWrite(vectorLed[i],LOW);  
    }

}
