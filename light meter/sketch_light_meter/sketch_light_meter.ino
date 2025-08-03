// PROTÓTIPO: SENSOR DE LUZ (LDR) PARA ACIONAMENTO DE LED
// para ligar e desligar o LED de acordo com a incidencia de luz sobre o fotoresistor (LDR)
int led_Vermelho = 4;                                 // Define o Led Vermelho na porta 4
int led_Verde = 8;                                    // Define o Led Vermelho na porta 8
int led_Azul = 12;                                    // Define o Led Vermelho na porta 12
int led_Branco = 13;                                  // Define o Led Vermelho na porta 13
int sensor = A0;                                      // Define o fotoresistor (LDR) no pino analógico A0
int sensorValue = 0;                                  // Armazena o valor de leitura analógica do fotoresistor (LDR)

void ledVermelho(){
  digitalWrite(led_Vermelho, HIGH);
}

void setup() {
  pinMode(led_Vermelho, OUTPUT);                      // Define o LED Vermelho como uma saída
  pinMode(led_Verde, OUTPUT);                         // Define o LED Vermelho como uma saída
  pinMode(led_Azul, OUTPUT);                          // Define o LED Vermelho como uma saída
  pinMode(led_Branco, OUTPUT);                        // Define o LED Vermelho como uma saída
  pinMode(sensor, INPUT);                             // Define o fotoresistor (LDR) como uma entrada
  Serial.begin(9600);                                 // Inicia a comunicação serial com uma taxa de transmissão de 9600 boud rate
}

void loop(){
  sensorValue = analogRead(sensor);                   // Lê o valor atual do fotoresistor (LDR)
  if (sensorValue < 250) {                            // Condição 1: Muito escuro (os 4 LEDs acendem)
    digitalWrite(led_Vermelho, HIGH);
    digitalWrite(led_Verde, HIGH);
    digitalWrite(led_Azul, HIGH);
    digitalWrite(led_Branco, HIGH);
  }

  else if (sensorValue < 500) {                       // Condição 2: Escuro (3 LEDs acendem)
    digitalWrite(led_Vermelho, HIGH);
    digitalWrite(led_Verde, HIGH);
    digitalWrite(led_Azul, HIGH);
    digitalWrite(led_Branco, LOW);
  }

  else if (sensorValue < 750) {                       // Condição 3: Meia-luz (2 LEDs acendem)
    digitalWrite(led_Vermelho, HIGH);
    digitalWrite(led_Verde, HIGH);
    digitalWrite(led_Azul, LOW);
    digitalWrite(led_Branco, LOW);
  }

  else if (sensorValue < 900) {                       // Condição 4: Pouca luz (apenas o LED vermelho acende)
    digitalWrite(led_Vermelho, HIGH);
    digitalWrite(led_Verde, LOW);
    digitalWrite(led_Azul, LOW);
    digitalWrite(led_Branco, LOW);
  }

  else {                                              // Condição 5: Claro (todos os LEDs apagados)
    digitalWrite(led_Vermelho, LOW);
    digitalWrite(led_Verde, LOW);
    digitalWrite(led_Azul, LOW);
    digitalWrite(led_Branco, LOW);
  }
  
  Serial.print ("Leitura atual do sensor: ");         // Imprime as leituras atuais no monitor serial da IDE do Arduino
  Serial.println(sensorValue);
  delay(130);
}
