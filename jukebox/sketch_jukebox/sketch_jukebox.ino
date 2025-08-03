// Projeto Jukebox - Seletor de músicas

#include "notas.h"

const int pinBuzzer = 9;
int compasso = 900;

// Jingle Bells

int melody[] = {
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
  NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_G5
};

int tempo[] = {
  8, 8, 4,
  8, 8, 4,
  8, 8, 8, 8,
  2,
  8, 8, 8, 8,
  8, 8, 8, 16, 16,
  8, 8, 8, 8,
  4, 4
};

// We wish you a merry Christmas

int wish_melody[] = {
  NOTE_B3, 
  NOTE_F4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4,
  NOTE_D4, NOTE_D4, NOTE_D4,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4,
  NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_D4, NOTE_B3, NOTE_B3,
  NOTE_D4, NOTE_G4, NOTE_E4,
  NOTE_F4
};

int wish_tempo[] = {
  4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 8, 8,
  4, 4, 4,
  2
};

// Santa Claus is coming to town

int santa_melody[] = {
  NOTE_G4,
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, NOTE_C5,
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4,
  NOTE_E4, NOTE_G4, NOTE_C4, NOTE_E4,
  NOTE_D4, NOTE_F4, NOTE_B3,
  NOTE_C4
};

int santa_tempo[] = {
  8,
  8, 8, 4, 4, 4,
  8, 8, 4, 4, 4,
  8, 8, 4, 4, 4,
  8, 8, 4, 2,
  4, 4, 4, 4,
  4, 2, 4,
  1
};

int bot_1 = 0;
int bot_2 = 0;
int bot_3 = 0;

int som = 0;

void setup(void) {
  pinMode(pinBuzzer, OUTPUT); // Buzzer
  pinMode(13, OUTPUT); // Led indicador quando toca a nota
  pinMode(2, INPUT_PULLUP); // push buttom 1
  pinMode(3, INPUT_PULLUP); // push buttom 2
  pinMode(4, INPUT_PULLUP); // push buttom 3

  Serial.begin(9600);
}

void loop() {
  bot_1 = digitalRead(2);
  bot_2 = digitalRead(3);
  bot_3 = digitalRead(4);
  if (bot_1 == 0) {
    sing(1);
  } else if (bot_2 == 0) {
    sing(2);
  } else if (bot_3 == 0) {
    sing(3);
  }
}

void sing(int s) {
  // intera as notas da melodia:
  som = s;
  if (som == 3) {
    Serial.println(" 'We wish you a Merry Christmas'");
    int size = sizeof(wish_melody) / sizeof(int);
    for (int estaNota = 0; estaNota < size; estaNota++) {
    
      // Tomamos 1 segundo divido pelo tipo da nota para calcular a duração
      //ex.  semínima = compasso / 4
      int notaTempo = compasso / wish_tempo[estaNota];

      buzz(pinBuzzer, wish_melody[estaNota], notaTempo);

      // para distinguir melhor as notas, defimos um tempo mínimo entre ela
      int pausaNotas = notaTempo * 1.30;
      delay(pausaNotas);

      // interrompe a melodia:
     buzz(pinBuzzer, 0, notaTempo);
    }

  } else if (som == 2) {
    Serial.println(" 'Santa Claus is coming to town'");
    int size = sizeof(santa_melody) / sizeof(int);
    for (int estaNota = 0; estaNota < size; estaNota++) {
       
      // Tomamos 1 segundo divido pelo tipo da nota para calcular a duração
      //ex.  semínima = compasso / 4
      int notaTempo = compasso / santa_tempo[estaNota];

      buzz(pinBuzzer, santa_melody[estaNota], notaTempo);

      // para distinguir melhor as notas, defimos um tempo mínimo entre ela
      int pausaNotas = notaTempo * 1.30;
      delay(pausaNotas);

      // interrompe a melodia:
      buzz(pinBuzzer, 0, notaTempo);

    }
  } else {

    Serial.println(" 'Jingle Bells'");
    int size = sizeof(melody) / sizeof(int);
    for (int estaNota = 0; estaNota < size; estaNota++) {
      
      // Tomamos 1 segundo divido pelo tipo da nota para calcular a duração
      //ex.  semínima = compasso / 4
      int notaTempo = compasso / tempo[estaNota];

      buzz(pinBuzzer, melody[estaNota],notaTempo);

      // para distinguir melhor as notas, defimos um tempo mínimo entre ela
      int pausaNotas = notaTempo * 1.30;
      delay(pausaNotas);

      // interrompe a melodia:
      buzz(pinBuzzer, 0, notaTempo);
    }
  }
}

void buzz(int pin , int frequencia, float dur) {
  
  digitalWrite(13, HIGH);
   
  int delayValor = 1000000 / frequencia / 2; // calcula o delay entre transições
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle

  int numCiclos = frequencia * dur / 1000; // calcula o número de ciclos adequado
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce

  for (int i = 0; i < numCiclos; i++) { // para definir a duração da nota
    digitalWrite(pin, HIGH); // buzzer em HIGH para emprurrar o diafragama do buzzer
    delayMicroseconds(delayValor); // espera o valor calculado do delay
    digitalWrite(pin, LOW); // buzzer em LOW para puxar o diafragama do buzzer
    delayMicroseconds(delayValor); // espera o valor calculado do delay
    }

  digitalWrite(13, LOW);
} 