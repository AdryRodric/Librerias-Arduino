#include "MATRIZ_LED_8X8.h"

#define DIN 13
#define CS  12
#define CLK 14

MATRIZ_LED_8X8 matriz_de_leds(DIN, CS, CLK);  // DIN, CS, CLK

void setup() {
  matriz_de_leds.INICIALIZAR();
  matriz_de_leds.SET_BRILLO(8);
}

void loop() {
  for(uint8_t columna = 0; columna <= 8; columna++){
    for(uint8_t fila = 0; fila <= 8; fila ++){
      // matriz.LIMPIAR();
      matriz_de_leds.SET_LED(columna,fila,true); matriz_de_leds.MOSTRAR();
      delay(15);
    }
  }

  for(int8_t columna = 8; columna >= 0; columna --){
    for(int8_t fila = 8; fila >= 0; fila --){
      // matriz.LIMPIAR();
      matriz_de_leds.SET_LED(columna,fila,false); matriz_de_leds.MOSTRAR();
      delay(15);
    }
  }

  matriz_de_leds.ENCENDER_TODOS(); delay(1000);
  matriz_de_leds.APAGAR_TODOS(); delay(500);
  matriz_de_leds.patronX(); delay(1000);
  matriz_de_leds.patronCUAD(); delay(1000);
  matriz_de_leds.patronTRI(); delay(1000);
  matriz_de_leds.patronCIR(); delay(1000);

  matriz_de_leds.APAGAR_TODOS();

  for(uint8_t columna = 0; columna <= 8; columna++){
    for(uint8_t fila = 0; fila <= 8; fila ++){
      matriz_de_leds.LIMPIAR();
      matriz_de_leds.SET_LED(fila,columna,true); matriz_de_leds.MOSTRAR();
      delay(15);
    }
  }

  for(int8_t columna = 7; columna >= 0; columna --){
    for(int8_t fila = 7; fila >= 0; fila --){
      matriz_de_leds.LIMPIAR();
      matriz_de_leds.SET_LED(fila,columna,true); matriz_de_leds.MOSTRAR();
      delay(15);
    }
  }
}
