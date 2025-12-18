/*
   PROGRAMA: Termostato Otimizado (1 Leitura/segundo + Display 15 FPS)
   Placa: Arduino Uno / Nano
   Display: U8g2 SSD1306
*/

#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

// --- CONFIGURAÇÃO DO DISPLAY ---
// Mantido o driver SSD1306 e o buffer "_2_" que você já estava usando [cite: 1]
U8G2_SSD1306_128X64_NONAME_2_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

// --- PINOS ---
#define pino_POT_AMBIENTE A0
#define pino_POT_AJUSTE   A1
#define pino_BUZZER       8

// --- VARIÁVEIS DO SISTEMA ---
int temperatura_exibida = 0;
int temperatura_limite = 20;

// --- VARIÁVEIS DE AMOSTRAGEM ---
unsigned long ultimaLeitura = 0;
long acumuladorLeituras = 0;         
int contadorSegundos = 0;
bool sistemaPronto = false;          

// --- VARIÁVEIS DE CONTROLE DE FPS (NOVO) ---
unsigned long ultimoFrame = 0; // Variável para controlar o FPS do display

// --- VARIÁVEIS DO BUZZER ---
unsigned long tempoAnteriorBuzzer = 0;
bool estadoBuzzer = false;
const long tempoBipLigado = 100;
const long tempoBipDesligado = 1000;

// --- FUNÇÃO DE DESENHO (Mantida idêntica à original) ---
void draw()
{
  // 1. CABEÇALHO
  u8g2.setFont(u8g2_font_8x13B_tr); 
  u8g2.setDrawColor(1);
  u8g2.drawRBox(0, 0, 127, 16, 2);
  u8g2.setDrawColor(0);

  if (sistemaPronto) {
    u8g2.drawStr(21, 13, "TEMPERATURA");
  } else {
    u8g2.setCursor(10, 13);
    u8g2.print("CALIBRANDO ");
    u8g2.print(contadorSegundos);
    u8g2.print("s");
  }
  u8g2.setDrawColor(1);

  // 2. CORPO DO DISPLAY
  if (!sistemaPronto) {
    u8g2.drawFrame(10, 35, 108, 14);
    int larguraBarra = map(contadorSegundos, 0, 60, 0, 104);
    u8g2.drawBox(12, 37, larguraBarra, 10); // Barra de progresso [cite: 11]
    
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawStr(25, 60, "Amostrando 1/s...");
  } 
  else 
  {
    u8g2.drawRFrame(0, 17, 84, 46, 2);
    u8g2.setFont(u8g2_font_fur20_tf); 
    u8g2.setCursor(13, 50);
    u8g2.print(temperatura_exibida);
    u8g2.drawCircle(51, 33, 3);
    u8g2.drawStr(56, 50, "C");

    if (temperatura_limite <= temperatura_exibida)
    {
      // Alarme Visual
      u8g2.setDrawColor(1);
      u8g2.drawRBox(86, 17, 42, 46, 2); 
      u8g2.setDrawColor(0);
      u8g2.setFont(u8g2_font_8x13B_tr);
      u8g2.drawStr(96, 33, "MAX");
      u8g2.setCursor(100, 55);
      u8g2.print(temperatura_limite);
      if (estadoBuzzer) u8g2.drawDisc(122, 22, 2); // Ícone de som [cite: 14]
    }
    else
    {
      // Normal
      u8g2.setDrawColor(1);
      u8g2.drawRFrame(86, 17, 42, 46, 2);
      u8g2.setFont(u8g2_font_8x13B_tr);
      u8g2.drawStr(96, 33, "MAX");
      u8g2.setCursor(100, 55);
      u8g2.print(temperatura_limite);
    }
  }
  u8g2.setDrawColor(1);
}

void gerenciarAlarme() {
  if (!sistemaPronto) {
    noTone(pino_BUZZER);
    return;
  }
  
  unsigned long tempoAtual = millis();
  if (temperatura_exibida >= temperatura_limite) {
    if (estadoBuzzer) {
      if (tempoAtual - tempoAnteriorBuzzer >= tempoBipLigado) {
        estadoBuzzer = false;
        noTone(pino_BUZZER);
        tempoAnteriorBuzzer = tempoAtual;
      }
    } else {
      if (tempoAtual - tempoAnteriorBuzzer >= tempoBipDesligado) {
        estadoBuzzer = true;
        tone(pino_BUZZER, 2000);
        tempoAnteriorBuzzer = tempoAtual;
      }
    }
  } else {
    estadoBuzzer = false;
    noTone(pino_BUZZER);
  }
}

void setup(void)
{
  u8g2.begin();
  u8g2.setBusClock(400000); // Mantém o I2C rápido [cite: 21]
  pinMode(pino_BUZZER, OUTPUT);
  ultimaLeitura = millis();
}

void loop(void)
{
  // --- 1. LÓGICA DE SENSORES (Prioridade Alta) ---
  
  // Amostragem de 1 segundo para o sensor ambiente
  if (millis() - ultimaLeitura >= 1000) 
  {
    ultimaLeitura = millis();
    int leituraInstantanea = analogRead(pino_POT_AMBIENTE);
    acumuladorLeituras += leituraInstantanea;
    contadorSegundos++;
    
    if (contadorSegundos >= 60) 
    {
      long media = acumuladorLeituras / 60;
      temperatura_exibida = map(media, 0, 1023, 0, 50);
      acumuladorLeituras = 0;
      contadorSegundos = 0;
      sistemaPronto = true;
    }
  }

  // Leitura do Ajuste (Sempre instantânea para boa UX)
  int leituraAjuste = analogRead(pino_POT_AJUSTE); 
  temperatura_limite = map(leituraAjuste, 0, 1023, 0, 50);

  // Gerenciamento do Buzzer (Precisa rodar livre para não atrasar o beep)
  gerenciarAlarme();

  // --- 2. ATUALIZAÇÃO DO DISPLAY (Limitada a 15 FPS) ---
  // Apenas desenha se tiver passado 66ms desde o último desenho
  if (millis() - ultimoFrame >= 66) 
  {
    ultimoFrame = millis(); // Reseta o timer do frame
    
    u8g2.firstPage();
    do {
      draw();
    } while ( u8g2.nextPage() );
  }
}
