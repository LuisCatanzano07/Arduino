int pinLeds[] = {5, 6, 7};/*Vector para almacenar los pines de los leds*/
int pinBotones[] = {8, 9, 10}; /*vector para almacenar los pines de los botones*/
int randomSeq[10]; /*vector para almacenar la secuencia de indices de leds randoms*/
int CONT_SEED = 1;/*Auxiliar para mejorar la secuencia pseudo-aleatoria*/
int CURRENT_LEVEL = 1;/*Auxiliar para saber la cantidad de secuencias que se va a ejecutar*/
int const MAX_LEVEL = 10; /*cantidad máxima de niveles o secuencias*/
int const NUM_LIGHTS = 3; /*El número de luces que tiene el juego*/

void setup() {
  
  for (int i = 0; i < NUM_LIGHTS; i++) {/*inicializo los botones y leds*/
    pinMode(pinBotones[i], INPUT);
    pinMode(pinLeds[i], OUTPUT);
    digitalWrite(pinBotones[i], LOW);/*pone en LOW la entrada del botón*/
  }
  generateRandomSequence();/*Llamo al método para generar la secuencia aleatoria*/
}

void loop() {
  startStage();/*Método para indicar el comienzo del nivel*/
  delay(500);
  showSequence(CURRENT_LEVEL);/*Muestra la secuencia de este nivel*/
  if (assertTest(CURRENT_LEVEL)) {
                                       /*Invoca al método assertTest
                                        que espera a el ingreso
                                        del jugador, si éste ingresó la secuencia correcta,
                                        se incrementa CURRENT_LEVEL para pasar al siguiente nivel*/
    CURRENT_LEVEL ++;
  }
  delay(500);
  if (CURRENT_LEVEL > MAX_LEVEL) {/*Si ya alcanzó el máximo nivel, vuelve al nivel 1*/
    CURRENT_LEVEL = 1;
    generateRandomSequence();/*genero una nueva secuencia*/
  }
}

/*Genera una secuencia aleatoria de valore en el vector randomSeq*/
void generateRandomSequence() {
  /*Genero la secuencia random*/
  randomSeed(analogRead(0) + CONT_SEED);
  int  seq2, seq1;/*Variables auxiliares para almacenar dos pines anteriores*/
  seq2 = -2; seq1 = -1; /*Las inicializo con valores distintos a los que pued generar la secuencia random*/
  for (int i = 0; i < MAX_LEVEL; i++) {
    randomSeq[i] = random(0, NUM_LIGHTS);
    while (seq2 == seq1 && randomSeq[i] == seq2 )/*Para evitar que se repita más de dos veces el mismo pin*/
    {
      randomSeq[i] = random(0, NUM_LIGHTS);
    }
    seq1 = seq2 ;/*intercambio los índices usando LIFO*/
    seq2 = randomSeq[i];
    CONT_SEED++;
  }
}
/*Método que enciende un led en el pin indicado durante el tiempo indicado en milisegundos*/
void blink(int pinLed, int timedelay) {
  digitalWrite(pinLed, HIGH);
  delay(timedelay);
  digitalWrite(pinLed, LOW);
}
/*Método para indicar el comienzo de cada nivel, parpadea todos los leds NUM_LIGHTS veces*/
void startStage() {
  for (int sec = 0; sec < NUM_LIGHTS; sec++) {
    for (int i = 0; i < NUM_LIGHTS; i++) {
      digitalWrite(pinLeds[i], HIGH);
    }
    delay(300);
    for (int i = 0; i < NUM_LIGHTS; i++) {
      digitalWrite(pinLeds[i], LOW);
    }
    delay(300);
  }
}

/*Método que se invoca cuando se
  ha generado la secuencia incorrecta,
  se le pasa como argumento el índice del led*/
void wrongSequence(int indexLed) {
  for (int i = 0; i < NUM_LIGHTS; i++) {/*Apago todos los leds*/
    digitalWrite(pinLeds[i], LOW);
  }
  for (int i = 0; i < NUM_LIGHTS; i++) {/*parpadea NUM_LIGHTS veces*/
    blink(pinLeds[indexLed], 350);
    delay(250);
  }
}
/*Método que se invoca para la prueba de la secuencia
  recibi por parámetro el número de secuencias*/
boolean assertTest(int sequenceLenght) {
  int randomIndex = 0;//voy contando las cantidades de aciertos
  while (randomIndex < sequenceLenght) {
    for (int i = 0 ; i < NUM_LIGHTS; i++) {/*recorro permanentemente los NUM_LIGHTS botones hasta interceptar 
                                    el primero que esté presionado*/
      int buttonPressed = LOW;
      buttonPressed = digitalRead(pinBotones[i]);/*Lee si el botón está presionado*/
      
      if (buttonPressed == HIGH) {/*Si está presionado*/
        digitalWrite(pinLeds[i], HIGH);/*Enciendo el led correspondiente*/
        delay(200);/*Le doy un pequeño retraso para que quede encendido*/
        while (buttonPressed == HIGH) { /*se queda en el loop hasta que suelte el botón*/
          buttonPressed = digitalRead(pinBotones[i]);
         
        }
        digitalWrite(pinLeds[i], LOW);/*Apago el led*/
        if (i == randomSeq[randomIndex]) {
          /*Si el índice "i" del botón presionado
                                              corresponde al índice de la secuencia random
                                              incremento al próximo índice del random*/
          randomIndex++;
        }
        else {/*Si el índice "i" no coincide con el de la secuencia random*/
          delay(500);
          wrongSequence(randomSeq[randomIndex]);/*Invoco al método que se ejecuta cuando la
                                                  secuencia es errónea, pasándole el número de
                                                  pin del led correcto para que le muestre al
                                                  jugador*/
          delay(500);
          return false;/*salgo del método cortocicuitando y retornando falso*/
        }
        delay(5);/*pequeña latencia*/
      }/*Fin del If*/
    }/*Fin del For*/
  }/*Fin del While*/
  return true;/*Si llegó hasta aqui, quiere decir que todo está bien, salgo por true*/
}
/*Muestra la secuenca random desde el comienzo hasta el número indicado por parámetro*/
void showSequence(int sequenceLenght) {
  for (int i = 0; i < sequenceLenght; i++) {
    blink(pinLeds[randomSeq[i]], 500);
    delay(250);
  }
}
