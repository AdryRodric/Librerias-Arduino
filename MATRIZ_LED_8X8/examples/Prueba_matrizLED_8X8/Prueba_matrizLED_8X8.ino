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