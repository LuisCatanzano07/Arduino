int pinboton[3] = {10, 9, 8};
int pinled[3] = {7, 6, 5};
int pinBuzzer[1] = {3};
int const RANDOM_SERIE_LENGTH = 100;
int mainRandomSecuence[RANDOM_SERIE_LENGTH];
int ADJUST_DELAY = 800;
int const NUMBER_OF_LEDS = 3;
int LOOPS = 0;
int startSequence = 0;
boolean passed = true;

void setup() {
  // put your setup code here, to run once:

  randomSeed(analogRead(0));
  pinMode(pinBuzzer[0], OUTPUT);
  for (int i = 0; i < RANDOM_SERIE_LENGTH; i++) {
    mainRandomSecuence[i] = pinled[random(0, NUMBER_OF_LEDS)];
  }
  for (int i = 0; i < NUMBER_OF_LEDS; i++) {
    pinMode(pinboton[i], INPUT);
    pinMode(pinled[i], OUTPUT);
    digitalWrite(pinled[i], LOW);
  }
}

int getLedIndexByPinNumber(int pinNumber) {
  for (int i = 0; i < NUMBER_OF_LEDS; i++) {
    if (pinled[i] == pinNumber) {
      return i;
    }
  }
}
void blinkAll(int attempts) {
  for (int i = 0; i < NUMBER_OF_LEDS; i++) {
    digitalWrite(pinled[i], LOW);
  }
  int cont = 0;
  while (cont < attempts) {
    cont++;
    for (int i = 0; i < NUMBER_OF_LEDS; i++) {
      digitalWrite(pinled[i], HIGH);
    }

    delay(200);

    for (int i = 0; i < NUMBER_OF_LEDS; i++) {
      digitalWrite(pinled[i], LOW);
    }
    delay(200);
  }
}
void raiseError() {
  buzz(2000);
}
void buzz(int timedelay) {
  digitalWrite(pinBuzzer[0], HIGH);
  delay(timedelay);
  digitalWrite(pinBuzzer[0], LOW);
}
void readSecuence() {

  int startPosition = 0;

  int sequenceLength = LOOPS  ; //menos uno porque incrementa antes de parpadear los leds y luego llama a esta funcion
  int buttonsPushed[sequenceLength];
  int pinIndex;
  while (startPosition < sequenceLength) {

    int readIndex = -1;
    for (int i = 0; i < NUMBER_OF_LEDS; i++) {

      buttonsPushed[i] = digitalRead(pinboton[i]);

      if (buttonsPushed[i] == HIGH) {
        readIndex = i;

        while (digitalRead(pinboton[i]) == HIGH)
        {
          digitalWrite(pinled[i], HIGH);
        }
        delay(150);
        digitalWrite(pinled[i], LOW);
        break;
      }
    }

    if (readIndex >= 0)
    {
      pinIndex = getLedIndexByPinNumber(mainRandomSecuence[startPosition]);
      if (readIndex == pinIndex) {//es válido
        startPosition++;
        passed = true;
      }
      else
      {
        passed = false;
        raiseError();
        startPosition = sequenceLength;//salgo
      }
    }
  }
}

void blink(int pinNumber, int delayTime) {
  digitalWrite(pinNumber, HIGH);
  delay(delayTime);
  digitalWrite(pinNumber, LOW);
}
int FRECUENCY = 300;
void loop() {
  if (passed) {
    blinkAll(2);
    passed = false;
    //    createRandomSequence();
    LOOPS++;
  }
  delay(ADJUST_DELAY);

  int prev = -1;
  for (int i = 0; i < LOOPS; i++) {
    if (prev == i) {
      delay(FRECUENCY);
    }
    blink(mainRandomSecuence[i], ADJUST_DELAY);
    prev = i;
    if (i + 1 < LOOPS) {
      delay(FRECUENCY);
    }
  }
  
  readSecuence();
  delay(ADJUST_DELAY / 2);
  ADJUST_DELAY = ADJUST_DELAY - 10;
}

