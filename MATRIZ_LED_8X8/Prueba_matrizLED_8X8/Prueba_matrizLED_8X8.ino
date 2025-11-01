// #define DIN 13
// #define CS  12
// #define CLK 14

// void enviar(uint8_t dir, uint8_t val) {
//   digitalWrite(CS, LOW);
//   shiftOut(DIN, CLK, MSBFIRST, dir);
//   shiftOut(DIN, CLK, MSBFIRST, val);
//   digitalWrite(CS, HIGH);
// }

// void setup() {
//   pinMode(DIN, OUTPUT);
//   pinMode(CS, OUTPUT);
//   pinMode(CLK, OUTPUT);
//   digitalWrite(CS, HIGH);

//   enviar(0x0F, 0x00);
//   enviar(0x0C, 0x01);
//   enviar(0x0B, 0x07);
//   enviar(0x09, 0x00);
//   enviar(0x0A, 0x08);

//   // Encender solo la fila 1
//   enviar(1, B10000001);
//   enviar(2, B01000010);
//   enviar(3, B00100100);
//   enviar(4, B00011000);
//   enviar(5, B00100100);
//   enviar(6, B01000010);
//   enviar(7, B10000001);
//   enviar(8, B00000000);
// }

// void loop() {}

#include "MATRIZ_LED_8X8.h"

#define DIN 13
#define CS  12
#define CLK 14

MATRIZ_LED_8X8 matriz(DIN, CS, CLK);  // DIN, CS, CLK

void setup() {
  matriz.INICIALIZAR();
  matriz.SET_BRILLO(8);
}

void loop() {
  for(uint8_t columna = 0; columna <= 8; columna++){
    for(uint8_t fila = 0; fila <= 8; fila ++){
      // matriz.LIMPIAR();
      matriz.SET_LED(columna,fila,true); matriz.MOSTRAR();
      delay(15);
    }
  }

  for(int8_t columna = 8; columna >= 0; columna --){
    for(int8_t fila = 8; fila >= 0; fila --){
      // matriz.LIMPIAR();
      matriz.SET_LED(columna,fila,false); matriz.MOSTRAR();
      delay(15);
    }
  }

  matriz.ENCENDER_TODOS(); delay(1000);
  matriz.APAGAR_TODOS(); delay(500);
  matriz.patronX(); delay(1000);
  matriz.patronCUAD(); delay(1000);
  matriz.patronTRI(); delay(1000);
  matriz.patronCIR(); delay(1000);

  matriz.APAGAR_TODOS();

  for(uint8_t columna = 0; columna <= 8; columna++){
    for(uint8_t fila = 0; fila <= 8; fila ++){
      matriz.LIMPIAR();
      matriz.SET_LED(fila,columna,true); matriz.MOSTRAR();
      delay(15);
    }
  }

  for(int8_t columna = 7; columna >= 0; columna --){
    for(int8_t fila = 7; fila >= 0; fila --){
      matriz.LIMPIAR();
      matriz.SET_LED(fila,columna,true); matriz.MOSTRAR();
      delay(15);
    }
  }
}