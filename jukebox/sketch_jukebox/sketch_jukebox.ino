// Projeto Jukebox - Seletor de músicas
#include <avr/pgmspace.h>
#include "notas.h"

const int pinBuzzer = 12;
int compasso_MarioBros = 900;

// HarryPotter song
const int melody_HarryPotter[] PROGMEM = {
  REST, 2, NOTE_D4, 4,
  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
  NOTE_G4, 2, NOTE_D5, 4,
  NOTE_C5, -2, 
  NOTE_A4, -2,
  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
  NOTE_F4, 2, NOTE_GS4, 4,
  NOTE_D4, -1, 
  NOTE_D4, 4,

  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4, //10
  NOTE_G4, 2, NOTE_D5, 4,
  NOTE_F5, 2, NOTE_E5, 4,
  NOTE_DS5, 2, NOTE_B4, 4,
  NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
  NOTE_CS4, 2, NOTE_B4, 4,
  NOTE_G4, -1,
  NOTE_AS4, 4,
     
  NOTE_D5, 2, NOTE_AS4, 4,//18
  NOTE_D5, 2, NOTE_AS4, 4,
  NOTE_DS5, 2, NOTE_D5, 4,
  NOTE_CS5, 2, NOTE_A4, 4,
  NOTE_AS4, -4, NOTE_D5, 8, NOTE_CS5, 4,
  NOTE_CS4, 2, NOTE_D4, 4,
  NOTE_D5, -1, 
  REST,4, NOTE_AS4,4,  

  NOTE_D5, 2, NOTE_AS4, 4,//26
  NOTE_D5, 2, NOTE_AS4, 4,
  NOTE_F5, 2, NOTE_E5, 4,
  NOTE_DS5, 2, NOTE_B4, 4,
  NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
  NOTE_CS4, 2, NOTE_AS4, 4,
  NOTE_G4, -1, 
};
const int notes_HarryPotter = sizeof(melody_HarryPotter) / sizeof(melody_HarryPotter[0]) / 2;
const int tempo_HarryPotter = 144;
const int wholenote_HarryPotter = (60000 * 4) / tempo_HarryPotter;

// StarWars song
const int melody_StarWars[] PROGMEM = {
  NOTE_AS4,8, NOTE_AS4,8, NOTE_AS4,8,//1
  NOTE_F5,2, NOTE_C6,2,
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
  NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,8, NOTE_C5,8, NOTE_C5,8,
  NOTE_F5,2, NOTE_C6,2,
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
  
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4, //8  
  NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,-8, NOTE_C5,16, 
  NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_F5,8, NOTE_G5,8, NOTE_A5,8, NOTE_G5,4, NOTE_D5,8, NOTE_E5,4,NOTE_C5,-8, NOTE_C5,16,
  NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  
  NOTE_C6,-8, NOTE_G5,16, NOTE_G5,2, REST,8, NOTE_C5,8,//13
  NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_F5,8, NOTE_G5,8, NOTE_A5,8, NOTE_G5,4, NOTE_D5,8, NOTE_E5,4,NOTE_C6,-8, NOTE_C6,16,
  NOTE_F6,4, NOTE_DS6,8, NOTE_CS6,4, NOTE_C6,8, NOTE_AS5,4, NOTE_GS5,8, NOTE_G5,4, NOTE_F5,8,
  NOTE_C6,1
};
const int notes_StarWars = sizeof(melody_StarWars) / sizeof(melody_StarWars[0]) / 2;
const int tempo_StarWars = 108;
const int wholenote_StarWars = (60000 * 4) / tempo_StarWars;

// Pink Panter song
const int melody_Pinkpanter[] PROGMEM = {
  REST,2, REST,4, REST,8, NOTE_DS4,8, 
  NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8,
  NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_E4,8, NOTE_G4,-8, NOTE_B4,8,   
  NOTE_AS4,2, NOTE_A4,-16, NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16, 
  NOTE_E4,2, REST,4, REST,8, NOTE_DS4,4,
  NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8,
  NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_G4,8, NOTE_B4,-8, NOTE_E5,8,
  NOTE_DS5,1,   
  NOTE_D5,2, REST,4, REST,8, NOTE_DS4,8, 
  NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8,
  NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_E4,8, NOTE_G4,-8, NOTE_B4,8,   
  NOTE_AS4,2, NOTE_A4,-16, NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16, 
  NOTE_E4,-4, REST,4,
  REST,4, NOTE_E5,-8, NOTE_D5,8, NOTE_B4,-8, NOTE_A4,8, NOTE_G4,-8, NOTE_E4,-8,
  NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8,   
  NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16, NOTE_E4,16, NOTE_E4,16, NOTE_E4,2,
};
const int notes_Pinkpanter = sizeof(melody_Pinkpanter) / sizeof(melody_Pinkpanter[0]) / 2;
const int tempo_Pinkpanter = 120;
const int wholenote_Pinkpanter = (60000 * 4) / tempo_Pinkpanter;

// Greensleeves song
const int melody_Greensleeves[] PROGMEM = {
  NOTE_G4,8,//1
  NOTE_AS4,4, NOTE_C5,8, NOTE_D5,-8, NOTE_DS5,16, NOTE_D5,8,
  NOTE_C5,4, NOTE_A4,8, NOTE_F4,-8, NOTE_G4,16, NOTE_A4,8,
  NOTE_AS4,4, NOTE_G4,8, NOTE_G4,-8, NOTE_FS4,16, NOTE_G4,8,
  NOTE_A4,4, NOTE_FS4,8, NOTE_D4,4, NOTE_G4,8,
  
  NOTE_AS4,4, NOTE_C5,8, NOTE_D5,-8, NOTE_DS5,16, NOTE_D5,8,//6
  NOTE_C5,4, NOTE_A4,8, NOTE_F4,-8, NOTE_G4,16, NOTE_A4,8,
  NOTE_AS4,-8, NOTE_A4,16, NOTE_G4,8, NOTE_FS4,-8, NOTE_E4,16, NOTE_FS4,8, 
  NOTE_G4,-2,
  NOTE_F5,2, NOTE_E5,16, NOTE_D5,8,

  NOTE_C5,4, NOTE_A4,8, NOTE_F4,-8, NOTE_G4,16, NOTE_A4,8,//11
  NOTE_AS4,4, NOTE_G4,8, NOTE_G4,-8, NOTE_FS4,16, NOTE_G4,8,
  NOTE_A4,4, NOTE_FS4,8, NOTE_D4,4,
  NOTE_F5,2, NOTE_E5,16, NOTE_D5,8,
  NOTE_C5,4, NOTE_A4,8, NOTE_F4,-8, NOTE_G4,16, NOTE_A4,8,

  NOTE_AS4,-8, NOTE_A4,16, NOTE_G4,8, NOTE_FS4,-8, NOTE_E4,16, NOTE_FS4,8,//16
  NOTE_G4,-2,

  //repeats from the beginning

  NOTE_G4,8,//1
  NOTE_AS4,4, NOTE_C5,8, NOTE_D5,-8, NOTE_DS5,16, NOTE_D5,8,
  NOTE_C5,4, NOTE_A4,8, NOTE_F4,-8, NOTE_G4,16, NOTE_A4,8,
  NOTE_AS4,4, NOTE_G4,8, NOTE_G4,-8, NOTE_FS4,16, NOTE_G4,8,
  NOTE_A4,4, NOTE_FS4,8, NOTE_D4,4, NOTE_G4,8,
  
  NOTE_AS4,4, NOTE_C5,8, NOTE_D5,-8, NOTE_DS5,16, NOTE_D5,8,//6
  NOTE_C5,4, NOTE_A4,8, NOTE_F4,-8, NOTE_G4,16, NOTE_A4,8,
  NOTE_AS4,-8, NOTE_A4,16, NOTE_G4,8, NOTE_FS4,-8, NOTE_E4,16, NOTE_FS4,8, 
  NOTE_G4,-2,
  NOTE_F5,2, NOTE_E5,16, NOTE_D5,8,

  NOTE_C5,4, NOTE_A4,8, NOTE_F4,-8, NOTE_G4,16, NOTE_A4,8,//11
  NOTE_AS4,4, NOTE_G4,8, NOTE_G4,-8, NOTE_FS4,16, NOTE_G4,8,
  NOTE_A4,4, NOTE_FS4,8, NOTE_D4,04,
  NOTE_F5,2, NOTE_E5,16, NOTE_D5,8,
  NOTE_C5,4, NOTE_A4,8, NOTE_F4,-8, NOTE_G4,16, NOTE_A4,8,

  NOTE_AS4,-8, NOTE_A4,16, NOTE_G4,8, NOTE_FS4,-8, NOTE_E4,16, NOTE_FS4,8,//16
  NOTE_G4,-2
};
const int notes_Greensleeves = sizeof(melody_Greensleeves) / sizeof(melody_Greensleeves[0]) / 2;
const int tempo_Greensleeves = 70;
const int wholenote_Greensleeves = (60000 * 4) / tempo_Greensleeves;

const int melody_Furelise[] PROGMEM = {
  //starts from 1 ending on 9
  NOTE_E5, 16, NOTE_DS5, 16, //1
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,
  NOTE_C5, 8,  REST, 16, NOTE_E4, 16, NOTE_E5, 16,  NOTE_DS5, 16,
  
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,//6
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16, 
  NOTE_B4, -8, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16, 
  NOTE_A4 , 4, REST, 8, //9 - 1st ending

  //repaets from 1 ending on 10
  NOTE_E5, 16, NOTE_DS5, 16, //1
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,
  NOTE_C5, 8,  REST, 16, NOTE_E4, 16, NOTE_E5, 16,  NOTE_DS5, 16,
  
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,//6
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16, 
  NOTE_B4, -8, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16, 
  NOTE_A4, 8, REST, 16, NOTE_B4, 16, NOTE_C5, 16, NOTE_D5, 16, //10 - 2nd ending
  //continues from 11
  NOTE_E5, -8, NOTE_G4, 16, NOTE_F5, 16, NOTE_E5, 16, 
  NOTE_D5, -8, NOTE_F4, 16, NOTE_E5, 16, NOTE_D5, 16, //12
  
  NOTE_C5, -8, NOTE_E4, 16, NOTE_D5, 16, NOTE_C5, 16, //13
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16, REST, 16,
  REST, 16, NOTE_E5, 16, NOTE_E6, 16, REST, 16, REST, 16, NOTE_DS5, 16,
  NOTE_E5, 16, REST, 16, REST, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, 8, REST, 16, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16, //19
  NOTE_C5, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16,  NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, 8, REST, 16, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16,
  NOTE_A4, 8, REST, 16, NOTE_B4, 16, NOTE_C5, 16, NOTE_D5, 16, //24 (1st ending)
  
  //repeats from 11
  NOTE_E5, -8, NOTE_G4, 16, NOTE_F5, 16, NOTE_E5, 16, 
  NOTE_D5, -8, NOTE_F4, 16, NOTE_E5, 16, NOTE_D5, 16, //12
  
  NOTE_C5, -8, NOTE_E4, 16, NOTE_D5, 16, NOTE_C5, 16, //13
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16, REST, 16,
  REST, 16, NOTE_E5, 16, NOTE_E6, 16, REST, 16, REST, 16, NOTE_DS5, 16,
  NOTE_E5, 16, REST, 16, REST, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, 8, REST, 16, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16, //19
  NOTE_C5, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16,  NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, 8, REST, 16, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16,
  NOTE_A4, 8, REST, 16, NOTE_C5, 16, NOTE_C5, 16, NOTE_C5, 16, //25 - 2nd ending

  //continues from 26
  NOTE_C5 , 4, NOTE_F5, -16, NOTE_E5, 32, //26
  NOTE_E5, 8, NOTE_D5, 8, NOTE_AS5, -16, NOTE_A5, 32,
  NOTE_A5, 16, NOTE_G5, 16, NOTE_F5, 16, NOTE_E5, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_AS4, 8, NOTE_A4, 8, NOTE_A4, 32, NOTE_G4, 32, NOTE_A4, 32, NOTE_B4, 32,
  NOTE_C5 , 4, NOTE_D5, 16, NOTE_DS5, 16,
  NOTE_E5, -8, NOTE_E5, 16, NOTE_F5, 16, NOTE_A4, 16,
  NOTE_C5 , 4,  NOTE_D5, -16, NOTE_B4, 32,
  
  
  NOTE_C5, 32, NOTE_G5, 32, NOTE_G4, 32, NOTE_G5, 32, NOTE_A4, 32, NOTE_G5, 32, NOTE_B4, 32, NOTE_G5, 32, NOTE_C5, 32, NOTE_G5, 32, NOTE_D5, 32, NOTE_G5, 32, //33
  NOTE_E5, 32, NOTE_G5, 32, NOTE_C6, 32, NOTE_B5, 32, NOTE_A5, 32, NOTE_G5, 32, NOTE_F5, 32, NOTE_E5, 32, NOTE_D5, 32, NOTE_G5, 32, NOTE_F5, 32, NOTE_D5, 32,
  NOTE_C5, 32, NOTE_G5, 32, NOTE_G4, 32, NOTE_G5, 32, NOTE_A4, 32, NOTE_G5, 32, NOTE_B4, 32, NOTE_G5, 32, NOTE_C5, 32, NOTE_G5, 32, NOTE_D5, 32, NOTE_G5, 32,

  NOTE_E5, 32, NOTE_G5, 32, NOTE_C6, 32, NOTE_B5, 32, NOTE_A5, 32, NOTE_G5, 32, NOTE_F5, 32, NOTE_E5, 32, NOTE_D5, 32, NOTE_G5, 32, NOTE_F5, 32, NOTE_D5, 32, //36
  NOTE_E5, 32, NOTE_F5, 32, NOTE_E5, 32, NOTE_DS5, 32, NOTE_E5, 32, NOTE_B4, 32, NOTE_E5, 32, NOTE_DS5, 32, NOTE_E5, 32, NOTE_B4, 32, NOTE_E5, 32, NOTE_DS5, 32,
  NOTE_E5, -8, NOTE_B4, 16, NOTE_E5, 16, NOTE_DS5, 16,
  NOTE_E5, -8, NOTE_B4, 16, NOTE_E5, 16, REST, 16,

  REST, 16, NOTE_DS5, 16, NOTE_E5, 16, REST, 16, REST, 16, NOTE_DS5, 16, //40
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, 8, REST, 16, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,
  NOTE_C5, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16, NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,

  NOTE_A4, 8, REST, 16, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16, //46
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16,
  NOTE_A4, 8, REST, 16, NOTE_B4, 16, NOTE_C5, 16, NOTE_D5, 16,
  NOTE_E5, -8, NOTE_G4, 16, NOTE_F5, 16, NOTE_E5, 16,
  NOTE_D5, -8, NOTE_F4, 16, NOTE_E5, 16, NOTE_D5, 16,
  NOTE_C5, -8, NOTE_E4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16, REST, 16,
  REST, 16, NOTE_E5, 16, NOTE_E6, 16, REST, 16, REST, 16, NOTE_DS5, 16,

  NOTE_E5, 16, REST, 16, REST, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_D5, 16, //54
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, 8, REST, 16, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,
  NOTE_C5, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16, NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  
  NOTE_A4, 8, REST, 16, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16, //60
  NOTE_B4, 8, REST, 16, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16,
  NOTE_A4, 8, REST, 16, REST, 16, REST, 8, 
  NOTE_CS5 , -4, 
  NOTE_D5 , 4, NOTE_E5, 16, NOTE_F5, 16,
  NOTE_F5 , 4, NOTE_F5, 8, 
  NOTE_E5 , -4,
  NOTE_D5 , 4, NOTE_C5, 16, NOTE_B4, 16,
  NOTE_A4 , 4, NOTE_A4, 8,
  NOTE_A4, 8, NOTE_C5, 8, NOTE_B4, 8,
  NOTE_A4 , -4,
  NOTE_CS5 , -4,

  NOTE_D5 , 4, NOTE_E5, 16, NOTE_F5, 16, //72
  NOTE_F5 , 4, NOTE_F5, 8,
  NOTE_F5 , -4,
  NOTE_DS5 , 4, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_AS4 , 4, NOTE_A4, 8,
  NOTE_GS4 , 4, NOTE_G4, 8,
  NOTE_A4 , -4,
  NOTE_B4 , 4, REST, 8,
  NOTE_A3, -32, NOTE_C4, -32, NOTE_E4, -32, NOTE_A4, -32, NOTE_C5, -32, NOTE_E5, -32, NOTE_D5, -32, NOTE_C5, -32, NOTE_B4, -32,

  NOTE_A4, -32, NOTE_C5, -32, NOTE_E5, -32, NOTE_A5, -32, NOTE_C6, -32, NOTE_E6, -32, NOTE_D6, -32, NOTE_C6, -32, NOTE_B5, -32, //80
  NOTE_A4, -32, NOTE_C5, -32, NOTE_E5, -32, NOTE_A5, -32, NOTE_C6, -32, NOTE_E6, -32, NOTE_D6, -32, NOTE_C6, -32, NOTE_B5, -32,
  NOTE_AS5, -32, NOTE_A5, -32, NOTE_GS5, -32, NOTE_G5, -32, NOTE_FS5, -32, NOTE_F5, -32, NOTE_E5, -32, NOTE_DS5, -32, NOTE_D5, -32,

  NOTE_CS5, -32, NOTE_C5, -32, NOTE_B4, -32, NOTE_AS4, -32, NOTE_A4, -32, NOTE_GS4, -32, NOTE_G4, -32, NOTE_FS4, -32, NOTE_F4, -32, //84
  NOTE_E4, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,

  NOTE_C5, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16, NOTE_DS5, 16, //88
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16, 
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16, 
  NOTE_B4, -8, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16, 
  NOTE_A4, -8, REST, -8,
  REST, -8, NOTE_G4, 16, NOTE_F5, 16, NOTE_E5, 16,
  NOTE_D5 , 4, REST, 8,
  REST, -8, NOTE_E4, 16, NOTE_D5, 16, NOTE_C5, 16,
  
  NOTE_B4, -8, NOTE_E4, 16, NOTE_E5, 8, //96
  NOTE_E5, 8, NOTE_E6, -8, NOTE_DS5, 16,
  NOTE_E5, 16, REST, 16, REST, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,

  NOTE_C5, 8, REST, 16, NOTE_E4, 16, NOTE_E5, 16, NOTE_DS5, 16, //102
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16,
  NOTE_A4 , -4,
};
const int notes_Furelise = sizeof(melody_Furelise) / sizeof(melody_Furelise[0]) / 2;
const int tempo_Furelise = 80;
const int wholenote_Furelise = (60000 * 4) / tempo_Furelise;

const int melody_Takeonme[] PROGMEM = {
  NOTE_FS5,8, NOTE_FS5,8,NOTE_D5,8, NOTE_B4,8, REST,8, NOTE_B4,8, REST,8, NOTE_E5,8, 
  REST,8, NOTE_E5,8, REST,8, NOTE_E5,8, NOTE_GS5,8, NOTE_GS5,8, NOTE_A5,8, NOTE_B5,8,
  NOTE_A5,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, REST,8, NOTE_D5,8, REST,8, NOTE_FS5,8, 
  REST,8, NOTE_FS5,8, REST,8, NOTE_FS5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8,
  NOTE_FS5,8, NOTE_FS5,8,NOTE_D5,8, NOTE_B4,8, REST,8, NOTE_B4,8, REST,8, NOTE_E5,8, 
  
  REST,8, NOTE_E5,8, REST,8, NOTE_E5,8, NOTE_GS5,8, NOTE_GS5,8, NOTE_A5,8, NOTE_B5,8,
  NOTE_A5,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, REST,8, NOTE_D5,8, REST,8, NOTE_FS5,8, 
  REST,8, NOTE_FS5,8, REST,8, NOTE_FS5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8,
  NOTE_FS5,8, NOTE_FS5,8,NOTE_D5,8, NOTE_B4,8, REST,8, NOTE_B4,8, REST,8, NOTE_E5,8, 
  REST,8, NOTE_E5,8, REST,8, NOTE_E5,8, NOTE_GS5,8, NOTE_GS5,8, NOTE_A5,8, NOTE_B5,8,
  
  NOTE_A5,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, REST,8, NOTE_D5,8, REST,8, NOTE_FS5,8, 
  REST,8, NOTE_FS5,8, REST,8, NOTE_FS5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8,
};
const int notes_Takeonme = sizeof(melody_Takeonme) / sizeof(melody_Takeonme[0]) / 2;
const int tempo_Takeonme = 140;
const int wholenote_Takeonme = (60000 * 4) / tempo_Takeonme;

// Super Mario Bros Song
const int melody_MarioBros[] PROGMEM = {
  NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,8, //1
  NOTE_G5,4, REST,4, NOTE_G4,8, REST,4, 
  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // 3
  NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
  REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,
  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // repeats from 3
  NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
  REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,

  
  REST,4, NOTE_G5,8, NOTE_FS5,8, NOTE_F5,8, NOTE_DS5,4, NOTE_E5,8,//7
  REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_C4,8, REST,8, NOTE_A4,8, NOTE_C5,8, NOTE_D5,8,
  REST,4, NOTE_DS5,4, REST,8, NOTE_D5,-4,
  NOTE_C5,2, REST,2,

  REST,4, NOTE_G5,8, NOTE_FS5,8, NOTE_F5,8, NOTE_DS5,4, NOTE_E5,8,//repeats from 7
  REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_C4,8, REST,8, NOTE_A4,8, NOTE_C5,8, NOTE_D5,8,
  REST,4, NOTE_DS5,4, REST,8, NOTE_D5,-4,
  NOTE_C5,2, REST,2,

  NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4,//11
  NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,

  NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,8, NOTE_E5,8,//13
  REST,1, 
  NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4,
  NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,
  NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,4,
  NOTE_G5,4, REST,4, NOTE_G4,4, REST,4, 
  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // 19
  
  NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
  REST,8, NOTE_E5,4, NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,

  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // repeats from 19
  NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
  REST,8, NOTE_E5,4, NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,

  NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,//23
  NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
  NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,
  
  NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //26
  NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
  NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
  NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
  NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,

  NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,//repeats from 23
  NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
  NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,
  
  NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //26
  NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
  NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
  NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
  NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,
  NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,8, NOTE_E5,8,
  REST,1,

  NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4, //33
  NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,
  NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,4,
  NOTE_G5,4, REST,4, NOTE_G4,4, REST,4, 
  NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
  NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
  NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,
  
  NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //40
  NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
  NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
  NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
  NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,
  
  //game over sound
  NOTE_C5,-4, NOTE_G4,-4, NOTE_E4,4, //45
  NOTE_A4,-8, NOTE_B4,-8, NOTE_A4,-8, NOTE_GS4,-8, NOTE_AS4,-8, NOTE_GS4,-8,
  NOTE_G4,8, NOTE_D4,8, NOTE_E4,-2,  
};
const int tempo_MarioBros = 200;
const int notes_MarioBros = sizeof(melody_MarioBros) / sizeof(melody_MarioBros[0]) / 2;
const int wholenote_MarioBros = (60000 * 4) / tempo_MarioBros;

const int melody_Tetris[] PROGMEM = {
  NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
  NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST,4,

  REST,8, NOTE_D5, 4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
  NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,

  NOTE_E5,2, NOTE_C5,2,
  NOTE_D5,2, NOTE_B4,2,
  NOTE_C5,2, NOTE_A4,2,
  NOTE_B4,1,

  NOTE_E5,2, NOTE_C5,2,
  NOTE_D5,2, NOTE_B4,2,
  NOTE_C5,4, NOTE_E5,4, NOTE_A5,2,
  NOTE_GS5,1,

  NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
  NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST,4,

  REST,8, NOTE_D5, 4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
  REST,8, NOTE_E5, 4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  REST,8, NOTE_B4, 4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  REST,8, NOTE_C5, 4,  NOTE_A4,8,  NOTE_A4,4, REST, 4,
};
const int notes_Tetris = sizeof(melody_Tetris) / sizeof(melody_Tetris[0])/2;
const int tempo_Tetris = 144;
const int wholenote_Tetris = (60000 * 4) / tempo_Tetris;

const int divider = 0, noteDuration = 0;

// Funcao para tocar a musica do HarryPotter
void tocarHarryPotter(){
  Serial.println("HarryPotter");
  for (int thisNote = 0; thisNote < notes_HarryPotter * 2; thisNote = thisNote + 2) {
    int divider = pgm_read_word_near(melody_HarryPotter + thisNote + 1);
    int noteDuration;
    if (divider > 0) {
      noteDuration = (wholenote_HarryPotter) / divider;
    }
    else if (divider < 0) {
      noteDuration = (wholenote_HarryPotter) / abs(divider);
      noteDuration *= 1.5;
    }
    int note = pgm_read_word_near(melody_HarryPotter + thisNote);
    tone(pinBuzzer, note, noteDuration * 0.9);
    delay(noteDuration);
    noTone(pinBuzzer);
  }
}

// Funcao para tocar a musica do StarWars
void tocarStarWars(){
  Serial.println("StarWars");
  for (int thisNote = 0; thisNote < notes_StarWars * 2; thisNote = thisNote + 2) {
    int divider = pgm_read_word_near(melody_StarWars + thisNote + 1);
    int noteDuration;
    if (divider > 0) {
      noteDuration = (wholenote_StarWars) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote_StarWars) / abs(divider);
      noteDuration *= 1.5;
    }
    int note = pgm_read_word_near(melody_StarWars + thisNote);
    tone(pinBuzzer, note, noteDuration*0.9);
    delay(noteDuration);
    noTone(pinBuzzer);
  }
}

// Funcao para tocar a musica da pantera cor de rosa
void tocarPinkpanther(){
  Serial.println("PinkPanter");
  for (int thisNote = 0; thisNote < notes_Pinkpanter * 2; thisNote = thisNote + 2) {
    int divider = pgm_read_word_near(melody_Pinkpanter + thisNote + 1);
    int noteDuration;
    if (divider > 0) {
      noteDuration = (wholenote_Pinkpanter) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote_Pinkpanter) / abs(divider);
      noteDuration *= 1.5;
    }
    int note = pgm_read_word_near(melody_Pinkpanter + thisNote);
    if (note > 0) {
      digitalWrite(13, HIGH);
      tone(pinBuzzer, note, noteDuration * 0.9);
    } else {
      digitalWrite(13, LOW);
      noTone(pinBuzzer);
    }
    delay(noteDuration);
    digitalWrite(13, LOW);
  }
}

// Funcao para tocar a musica Greensleeves
void tocarGreensleeves() {
  Serial.println("Greensleeves");
  for (int thisNote = 0; thisNote < notes_Greensleeves * 2; thisNote += 2) {
    int divider = pgm_read_word_near(melody_Greensleeves + thisNote + 1);
    int noteDuration = (divider > 0)
      ? wholenote_Greensleeves / divider
      : (wholenote_Greensleeves / abs(divider)) * 1.5;

    int note = pgm_read_word_near(melody_Greensleeves + thisNote);
    if (note > 0) {
      digitalWrite(13, HIGH);
      tone(pinBuzzer, note, noteDuration * 0.9);
    } else {
      digitalWrite(13, LOW);
      noTone(pinBuzzer);
    }
    delay(noteDuration);
    digitalWrite(13, LOW);
  }
}

// Funcao para tocar a musica Fur Elise
void tocarFurelise(){
  Serial.println("Greensleeves");
  for (int thisNote = 0; thisNote < notes_Furelise * 2; thisNote = thisNote + 2) {
    int divider = pgm_read_word_near(melody_Furelise +thisNote + 1);
    int noteDuration;
    if (divider > 0) {
      noteDuration = (wholenote_Furelise) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote_Furelise) / abs(divider);
      noteDuration *= 1.5;
    }
    int note = pgm_read_word_near(melody_Furelise + thisNote);
    if (note > 0) {
      digitalWrite(13, HIGH);
      tone(pinBuzzer, note, noteDuration * 0.9);
    } else {
      digitalWrite(13, LOW);
      noTone(pinBuzzer);
    }
    delay(noteDuration);
    digitalWrite(13, LOW);
  }
}

// Funcao para tocar a musica Take on Me
void tocarTakeonme(){
  Serial.println("Take on Me");
  for (int thisNote = 0; thisNote < notes_Takeonme * 2; thisNote = thisNote + 2) {
    int divider = pgm_read_word_near(melody_Takeonme + thisNote + 1);
    int noteDuration;
    if (divider > 0) {
      noteDuration = (wholenote_Takeonme) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote_Takeonme) / abs(divider);
      noteDuration *= 1.5;
    }
    int note = pgm_read_word_near(melody_Takeonme + thisNote);
    if (note > 0) {
      digitalWrite(13, HIGH);
      tone(pinBuzzer, note, noteDuration * 0.9);
    } else {
      digitalWrite(13, LOW);
      noTone(pinBuzzer);
    }
    delay(noteDuration);
    digitalWrite(13, LOW);
  }
}

// Funcao para tocar a musica Despacito
void tocarDespacito(){
  Serial.println("Despacito");
  tone(pinBuzzer, 587, 709.720327982);
  delay(788.578142202);
  digitalWrite(13, HIGH);
  delay(10.3082110092);
  tone(pinBuzzer, 554, 709.720327982);
  delay(788.578142202);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 369, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 369, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 369, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, HIGH);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 440, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 391, 412.843850917);
  delay(458.715389908);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 554, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 440, 412.843850917);
  delay(458.715389908);
  delay(5.15410550459);
  tone(pinBuzzer, 440, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 440, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 440, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 440, 41.7482545872);
  delay(46.3869495413);
  delay(36.0787385321);
  tone(pinBuzzer, 440, 37.109559633);
  delay(41.2328440367);
  digitalWrite(13, HIGH);
  delay(30.9246330275);
  tone(pinBuzzer, 440, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 587, 46.3869495413);
  delay(51.5410550459);
  delay(30.9246330275);
  tone(pinBuzzer, 587, 46.3869495413);
  delay(51.5410550459);
  delay(20.6164220183);
  tone(pinBuzzer, 587, 273.683002294);
  delay(304.092224771);
  digitalWrite(13, HIGH);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 554, 691.165548165);
  delay(767.961720183);
  delay(314.40043578);
  tone(pinBuzzer, 587, 552.004699541);
  delay(613.338555046);
  delay(5.15410550459);
  tone(pinBuzzer, 554, 552.004699541);
  delay(613.338555046);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 369, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 369, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 46.3869495413);
  delay(51.5410550459);
  digitalWrite(13, LOW);
  delay(30.9246330275);
  tone(pinBuzzer, 493, 46.3869495413);
  delay(51.5410550459);
  delay(20.6164220183);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, HIGH);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 440, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, HIGH);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 391, 273.683002294);
  delay(304.092224771);
  delay(159.777270642);
  tone(pinBuzzer, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 391, 41.7482545872);
  delay(46.3869495413);
  delay(30.9246330275);
  tone(pinBuzzer, 391, 37.109559633);
  delay(41.2328440367);
  digitalWrite(13, HIGH);
  delay(36.0787385321);
  tone(pinBuzzer, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 391, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, HIGH);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 554, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 440, 412.843850917);
  delay(458.715389908);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 440, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 440, 64.9417293578);
  delay(72.1574770642);
  delay(5.15410550459);
  tone(pinBuzzer, 440, 64.9417293578);
  delay(72.1574770642);
  delay(5.15410550459);
  tone(pinBuzzer, 440, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 440, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 440, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, HIGH);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 51.0256444954);
  delay(56.6951605505);
  delay(30.9246330275);
  tone(pinBuzzer, 587, 51.0256444954);
  delay(56.6951605505);
  delay(10.3082110092);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 659, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 554, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 880, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 880, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 880, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 880, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 880, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 880, 134.52215367);
  delay(149.469059633);
  delay(314.40043578);
  tone(pinBuzzer, 880, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 880, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 880, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 880, 412.843850917);
  delay(458.715389908);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 739, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 739, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, HIGH);
  delay(5.15410550459);
  tone(pinBuzzer, 739, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 739, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 739, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 739, 273.683002294);
  delay(304.092224771);
  digitalWrite(13, HIGH);
  delay(5.15410550459);
  tone(pinBuzzer, 783, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 783, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 412.843850917);
  delay(458.715389908);
  digitalWrite(13, LOW);
  delay(469.023600917);
  tone(pinBuzzer, 783, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 783, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 783, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, HIGH);
  delay(5.15410550459);
  tone(pinBuzzer, 783, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 783, 125.244763761);
  delay(139.160848624);
  delay(36.0787385321);
  digitalWrite(13, LOW);
  delay(134.006743119);
  tone(pinBuzzer, 783, 4.63869495413);
  delay(5.15410550459);
  tone(pinBuzzer, 880, 129.883458716);
  delay(144.314954128);
  delay(5.15410550459);
  tone(pinBuzzer, 880, 273.683002294);
  delay(304.092224771);
  digitalWrite(13, HIGH);
  delay(5.15410550459);
  tone(pinBuzzer, 739, 111.328678899);
  delay(123.69853211);
  delay(958.663623853);
  tone(pinBuzzer, 739, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 739, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 739, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 739, 134.52215367);
  delay(149.469059633);
  delay(159.777270642);
  tone(pinBuzzer, 880, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 783, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 739, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, HIGH);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 554, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 739, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 739, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 739, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 739, 273.683002294);
  delay(304.092224771);
  delay(185.547798165);
  tone(pinBuzzer, 659, 199.463883028);
  delay(221.626536697);
  delay(25.7705275229);
  digitalWrite(13, HIGH);
  delay(206.164220183);
  tone(pinBuzzer, 739, 4.63869495413);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 171.631713303);
  delay(190.70190367);
  tone(pinBuzzer, 739, 190.186493119);
  delay(211.318325688);
  delay(41.2328440367);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 783, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 783, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 412.843850917);
  delay(458.715389908);
  delay(314.40043578);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 783, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 783, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 783, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 783, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 783, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 880, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 783, 273.683002294);
  delay(304.092224771);
  digitalWrite(13, HIGH);
  delay(5.15410550459);
  tone(pinBuzzer, 739, 552.004699541);
  delay(613.338555046);
  delay(469.023600917);
  tone(pinBuzzer, 739, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 739, 41.7482545872);
  delay(46.3869495413);
  delay(30.9246330275);
  tone(pinBuzzer, 739, 37.109559633);
  delay(41.2328440367);
  delay(36.0787385321);
  tone(pinBuzzer, 739, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, HIGH);
  delay(5.15410550459);
  tone(pinBuzzer, 739, 134.52215367);
  delay(149.469059633);
  delay(190.70190367);
  tone(pinBuzzer, 880, 78.8578142202);
  delay(87.619793578);
  delay(36.0787385321);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 880, 78.8578142202);
  delay(87.619793578);
  delay(30.9246330275);
  tone(pinBuzzer, 783, 190.186493119);
  delay(211.318325688);
  digitalWrite(13, HIGH);
  delay(25.7705275229);
  tone(pinBuzzer, 739, 190.186493119);
  delay(211.318325688);
  delay(36.0787385321);
  tone(pinBuzzer, 659, 807.132922018);
  delay(896.814357798);
  digitalWrite(13, LOW);
  delay(201.010114679);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, HIGH);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 32.4708646789);
  delay(36.0787385321);
  delay(41.2328440367);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 587, 32.4708646789);
  delay(36.0787385321);
  delay(41.2328440367);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, HIGH);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 64.9417293578);
  delay(72.1574770642);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 64.9417293578);
  delay(72.1574770642);
  digitalWrite(13, LOW);
  delay(159.777270642);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 554, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 587, 46.3869495413);
  delay(51.5410550459);
  delay(30.9246330275);
  tone(pinBuzzer, 587, 46.3869495413);
  delay(51.5410550459);
  digitalWrite(13, LOW);
  delay(20.6164220183);
  tone(pinBuzzer, 554, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 64.9417293578);
  delay(72.1574770642);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 64.9417293578);
  delay(72.1574770642);
  delay(159.777270642);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 554, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 554, 27.8321697248);
  delay(30.9246330275);
  delay(41.2328440367);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 554, 27.8321697248);
  delay(30.9246330275);
  delay(51.5410550459);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 493, 64.9417293578);
  delay(72.1574770642);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 64.9417293578);
  delay(72.1574770642);
  delay(159.777270642);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 587, 41.7482545872);
  delay(46.3869495413);
  delay(30.9246330275);
  tone(pinBuzzer, 587, 41.7482545872);
  delay(46.3869495413);
  delay(30.9246330275);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 587, 51.0256444954);
  delay(56.6951605505);
  delay(30.9246330275);
  tone(pinBuzzer, 587, 51.0256444954);
  delay(56.6951605505);
  delay(10.3082110092);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 51.0256444954);
  delay(56.6951605505);
  delay(25.7705275229);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 493, 46.3869495413);
  delay(51.5410550459);
  delay(20.6164220183);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 64.9417293578);
  delay(72.1574770642);
  digitalWrite(13, HIGH);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 64.9417293578);
  delay(72.1574770642);
  delay(314.40043578);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 739, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 659, 46.3869495413);
  delay(51.5410550459);
  delay(30.9246330275);
  tone(pinBuzzer, 659, 46.3869495413);
  delay(51.5410550459);
  delay(20.6164220183);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 273.683002294);
  delay(304.092224771);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(159.777270642);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 659, 60.3030344037);
  delay(67.0033715596);
  delay(20.6164220183);
  tone(pinBuzzer, 659, 60.3030344037);
  delay(67.0033715596);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 51.0256444954);
  delay(56.6951605505);
  digitalWrite(13, HIGH);
  delay(25.7705275229);
  tone(pinBuzzer, 659, 51.0256444954);
  delay(56.6951605505);
  delay(15.4623165138);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 739, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, HIGH);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 273.683002294);
  delay(304.092224771);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 440, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, HIGH);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 659, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(159.777270642);
  tone(pinBuzzer, 587, 64.9417293578);
  delay(72.1574770642);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 587, 64.9417293578);
  delay(72.1574770642);
  delay(82.4656880734);
  tone(pinBuzzer, 587, 64.9417293578);
  delay(72.1574770642);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 64.9417293578);
  delay(72.1574770642);
  delay(82.4656880734);
  tone(pinBuzzer, 587, 64.9417293578);
  delay(72.1574770642);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 587, 64.9417293578);
  delay(72.1574770642);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 659, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(159.777270642);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 739, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, HIGH);
  delay(5.15410550459);
  tone(pinBuzzer, 739, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 739, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 739, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 880, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 880, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 273.683002294);
  delay(304.092224771);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(159.777270642);
  tone(pinBuzzer, 739, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 739, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, HIGH);
  delay(5.15410550459);
  tone(pinBuzzer, 739, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 739, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 166.993018349);
  delay(185.547798165);
  digitalWrite(13, LOW);
  delay(77.3115825688);
  tone(pinBuzzer, 659, 125.244763761);
  delay(139.160848624);
  delay(72.1574770642);
  tone(pinBuzzer, 659, 129.883458716);
  delay(144.314954128);
  delay(92.7738990826);
  tone(pinBuzzer, 659, 143.799543578);
  delay(159.777270642);
  delay(97.9280045872);
  tone(pinBuzzer, 587, 148.438238532);
  delay(164.931376147);
  delay(82.4656880734);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 659, 259.766917431);
  delay(288.629908257);
  delay(15.4623165138);
  tone(pinBuzzer, 587, 148.438238532);
  delay(164.931376147);
  delay(15.4623165138);
  tone(pinBuzzer, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 51.0256444954);
  delay(56.6951605505);
  delay(20.6164220183);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 587, 51.0256444954);
  delay(56.6951605505);
  delay(20.6164220183);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(159.777270642);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(159.777270642);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 106.689983945);
  delay(118.544426606);
  delay(36.0787385321);
  tone(pinBuzzer, 587, 106.689983945);
  delay(118.544426606);
  delay(36.0787385321);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 369, 83.4965091743);
  delay(92.7738990826);
  delay(61.849266055);
  tone(pinBuzzer, 369, 83.4965091743);
  delay(92.7738990826);
  delay(61.849266055);
  tone(pinBuzzer, 587, 273.683002294);
  delay(304.092224771);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 46.3869495413);
  delay(51.5410550459);
  delay(20.6164220183);
  tone(pinBuzzer, 587, 46.3869495413);
  delay(51.5410550459);
  digitalWrite(13, HIGH);
  delay(30.9246330275);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(159.777270642);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 273.683002294);
  delay(304.092224771);
  digitalWrite(13, HIGH);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(159.777270642);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 659, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(159.777270642);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 587, 46.3869495413);
  delay(51.5410550459);
  delay(20.6164220183);
  tone(pinBuzzer, 587, 46.3869495413);
  delay(51.5410550459);
  delay(30.9246330275);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(30.9246330275);
  tone(pinBuzzer, 554, 125.244763761);
  delay(139.160848624);
  delay(56.6951605505);
  tone(pinBuzzer, 554, 111.328678899);
  delay(123.69853211);
  delay(51.5410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 554, 115.967373853);
  delay(128.852637615);
  delay(61.849266055);
  tone(pinBuzzer, 554, 125.244763761);
  delay(139.160848624);
  delay(87.619793578);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 554, 106.689983945);
  delay(118.544426606);
  delay(87.619793578);
  tone(pinBuzzer, 493, 153.076933486);
  delay(170.085481651);
  delay(46.3869495413);
  tone(pinBuzzer, 587, 273.683002294);
  delay(304.092224771);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, HIGH);
  delay(159.777270642);
  tone(pinBuzzer, 587, 41.7482545872);
  delay(46.3869495413);
  delay(30.9246330275);
  tone(pinBuzzer, 587, 41.7482545872);
  delay(46.3869495413);
  delay(30.9246330275);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(159.777270642);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 273.683002294);
  delay(304.092224771);
  digitalWrite(13, HIGH);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(159.777270642);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 273.683002294);
  delay(304.092224771);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 587, 32.4708646789);
  delay(36.0787385321);
  delay(36.0787385321);
  tone(pinBuzzer, 587, 32.4708646789);
  delay(36.0787385321);
  delay(46.3869495413);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  delay(159.777270642);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 659, 55.6643394495);
  delay(61.849266055);
  delay(25.7705275229);
  tone(pinBuzzer, 659, 51.0256444954);
  delay(56.6951605505);
  delay(10.3082110092);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 659, 46.3869495413);
  delay(51.5410550459);
  delay(25.7705275229);
  tone(pinBuzzer, 659, 41.7482545872);
  delay(46.3869495413);
  delay(30.9246330275);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 273.683002294);
  delay(304.092224771);
  digitalWrite(13, HIGH);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 51.0256444954);
  delay(56.6951605505);
  delay(20.6164220183);
  digitalWrite(13, LOW);
  tone(pinBuzzer, 587, 51.0256444954);
  delay(56.6951605505);
  delay(20.6164220183);
  tone(pinBuzzer, 659, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(13, HIGH);
  tone(pinBuzzer, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 659, 273.683002294);
  delay(304.092224771);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(159.777270642);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, HIGH);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 554, 264.405612385);
  delay(293.784013761);
  digitalWrite(13, LOW);
  delay(15.4623165138);
  tone(pinBuzzer, 554, 51.0256444954);
  delay(56.6951605505);
  delay(20.6164220183);
  tone(pinBuzzer, 554, 51.0256444954);
  delay(56.6951605505);
  delay(20.6164220183);
  tone(pinBuzzer, 554, 273.683002294);
  delay(304.092224771);
  digitalWrite(13, HIGH);
  delay(5.15410550459);
  tone(pinBuzzer, 554, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 554, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(pinBuzzer, 493, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, LOW);
  delay(5.15410550459);
  tone(pinBuzzer, 587, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 554, 129.883458716);
  delay(144.314954128);
  delay(10.3082110092);
  tone(pinBuzzer, 369, 134.52215367);
  delay(149.469059633);
  digitalWrite(13, HIGH);
  delay(5.15410550459);
  tone(pinBuzzer, 369, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(pinBuzzer, 369, 273.683002294);
  delay(304.092224771);
  digitalWrite(13, LOW);
}

// Funcao para tocar a musica do Mario Bros
void tocarMarioBros() {
  Serial.println("Super Mario Bros");
  for (int thisNote = 0; thisNote < notes_MarioBros * 2; thisNote = thisNote + 2) {
    int divider = pgm_read_word_near(melody_MarioBros + thisNote + 1);
    int noteDuration;
    if (divider > 0) {
      noteDuration = (wholenote_MarioBros) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote_MarioBros) / abs(divider);
      noteDuration *= 1.5;
    }
    int note = pgm_read_word_near(melody_MarioBros + thisNote);
    if (note > 0) {
      digitalWrite(13, HIGH);
      tone(pinBuzzer, note, noteDuration * 0.9);
    } else {
      digitalWrite(13, LOW);
      noTone(pinBuzzer);
    }
    delay(noteDuration);
    digitalWrite(13, LOW);
  }
}

// Funcao para tocar a musica do Tetris
void tocarTetris(){
  Serial.println("Tetris");
  for (int thisNote = 0; thisNote < notes_Tetris * 2; thisNote = thisNote + 2) {
    int divider = pgm_read_word_near(melody_Tetris + thisNote + 1);
    int noteDuration;
    if (divider > 0) {
      noteDuration = (wholenote_Tetris) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote_Tetris) / abs(divider);
      noteDuration *= 1.5;
    }
    int note = pgm_read_word_near(melody_Tetris + thisNote);
    if (note > 0) {
      digitalWrite(13, HIGH);
      tone(pinBuzzer, note, noteDuration * 0.9);
    } else {
      digitalWrite(13, LOW);
      noTone(pinBuzzer);
    }
    delay(noteDuration);
    digitalWrite(13, LOW);
  }
}

// Funcao do buzzer
void buzz(int pin, int frequencia, float dur) {
  if (frequencia == 0) {
    delay(dur);
    return;
  }
  int delayValor = 1000000 / frequencia / 2;
  int numCiclos = frequencia * dur / 1000;
  for (int i = 0; i < numCiclos; i++) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(delayValor);
    digitalWrite(pin, LOW);
    delayMicroseconds(delayValor);
  }
}

// Setup e loop
void setup() {
  pinMode(pinBuzzer, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if (!digitalRead(2)) tocarHarryPotter();
  if (!digitalRead(3)) tocarMarioBros();
  if (!digitalRead(4)) tocarGreensleeves();
  if (!digitalRead(5)) tocarStarWars();
  if (!digitalRead(6)) tocarTetris();
  if (!digitalRead(7)) tocarFurelise();
  if (!digitalRead(8)) tocarTakeonme();
  if (!digitalRead(9)) tocarDespacito();
  if (!digitalRead(10)) tocarPinkpanther();
}
