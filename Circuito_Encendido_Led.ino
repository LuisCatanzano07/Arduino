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
  for(int i = 12; i >=11; i--){
    
    digitalWrite(i,HIGH);
    delay(1000);
    digitalWrite(i,LOW);
    }
  digitalWrite(12,HIGH);
  delay(1000);
  digitalWrite(12,LOW);
}
