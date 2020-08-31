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

  int repeArray[3] = { -1, -1, -1};//numero de veces seguida que se puede repetir un numero
  mainRandomSecuence[0] = pinled[random(0, NUMBER_OF_LEDS)];//seteo el primer elemento por propósito de lógica
  int contRepeIndex = 0;
  //Crear la secuenciaRandom
  for (int i = 1; i < RANDOM_SERIE_LENGTH; i++) {
    int newPin = pinled[random(0, NUMBER_OF_LEDS)];
    if (contRepeIndex == 3) {
      contRepeIndex = 0;
      if (repeArray[i - 1] == repeArray[i - 2] == repeArray[i - 3]) {
        while (newPin == repeArray[i - 1]) {
          newPin = pinled[random(0, NUMBER_OF_LEDS)];
        }
      }
    }
    mainRandomSecuence[i] = newPin;
    repeArray[contRepeIndex] = newPin;
    contRepeIndex++;
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

    delay(100);

    for (int i = 0; i < NUMBER_OF_LEDS; i++) {
      digitalWrite(pinled[i], LOW);
    }
    delay(100);
  }
}
void raiseError(int pinIndex) {
  digitalWrite(pinBuzzer[0], HIGH);
  delay(100);
  blink(mainRandomSecuence[pinIndex], 300);
  delay(100);
  blink(mainRandomSecuence[pinIndex], 300);
  delay(100);
  blink(mainRandomSecuence[pinIndex], 300);
  buzz(1300);
}
void buzz(int timedelay) {
  digitalWrite(pinBuzzer[0], HIGH);
  delay(timedelay);
  digitalWrite(pinBuzzer[0], LOW);
}
void readSecuence() {

  int startPosition = LOOPS - 1;

  //menos uno porque incrementa antes de parpadear los leds y luego llama a esta funcion
  int buttonsPushed[LOOPS];
  int pinIndex;
  int auxLoops = 0;
  while (startPosition < LOOPS ) {

    int readIndex = -1;
    for (int i = 0; i < NUMBER_OF_LEDS; i++) {

      buttonsPushed[i] = digitalRead(pinboton[i]);

      if (buttonsPushed[i] == HIGH) {
        readIndex = i;

        while (digitalRead(pinboton[i]) == HIGH)
        {
          digitalWrite(pinled[i], HIGH);
        }
        delay(150);//por latencia
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
        raiseError(mainRandomSecuence[pinIndex]);

        startPosition = LOOPS;//salgo
      }
    }
    auxLoops++;
    delay(10);
    if (auxLoops >= 150) {

      passed = false;
      pinIndex = getLedIndexByPinNumber(mainRandomSecuence[LOOPS - 1]);
      raiseError(mainRandomSecuence[pinIndex]);
      startPosition = LOOPS;//salgo
    }
  }

}

void blink(int pinNumber, int delayTime) {
  digitalWrite(pinNumber, HIGH);
  delay(delayTime);
  digitalWrite(pinNumber, LOW);
}
int FRECUENCY = 200;
void loop() {
  if (passed) {
    blinkAll(2);
    passed = false;
    //    createRandomSequence();
    LOOPS++;
  }

  delay(ADJUST_DELAY);

  int prev = -1;
  for (int i = LOOPS - 1; i < LOOPS; i++) {
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
  ADJUST_DELAY = ADJUST_DELAY - 25;
  if (ADJUST_DELAY <= 0)
  {
    ADJUST_DELAY = 2;
  }
}





