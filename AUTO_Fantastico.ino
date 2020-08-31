void setup() {
  // put your setup code here, to run once:
  for(int i=11;i < 14;i++){    
    pinMode(i,OUTPUT);
  }
}

void loop() {
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  for(int i = 13; i >=11; i--){
    
    digitalWrite(i,HIGH);
    delay(1000);
    digitalWrite(i,LOW);
    }
  for(int i = 12; i <= 13; i++){
    digitalWrite(i,HIGH);
    delay(1000);
    digitalWrite(i,LOW);
    }

}




  // put your main code here, to run repeatedly:


