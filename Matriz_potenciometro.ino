#include "MATRIZ_LED_8X8.h"

#define POT 32   // Pin analógico del potenciómetro

#define DIN 13
#define CS 12
#define CLK 14

MATRIZ_LED_8X8 matriz(DIN, CS, CLK);

void mostrarLEDS(uint8_t cantidad) {
  matriz.LIMPIAR();

  uint8_t contador = 0;
  for (uint8_t fila = 0; fila < 8 ; fila++) { // for(uint8_t fila = 7 ; fila < 8; fila--){} de arriba hacia abajo
    for (uint8_t columna = 0; columna < 8; columna++) {
      if (contador < cantidad)
        matriz.SET_LED(columna, fila, true);
      contador++;
    }
  }

  matriz.MOSTRAR();
}

void setup() {
  Serial.begin(115200);
  matriz.INICIALIZAR();
  Serial.println("Iniciando control de LEDs individual con potenciómetro...");
}

void loop() {
  int valorPot = analogRead(POT);              // 0–4095
  uint8_t ledsEncendidos = map(valorPot, 0, 4095, 0, 64);  // Escala 0–64 LEDs
  uint16_t luz = ledsEncendidos * 7;
  
  mostrarLEDS(ledsEncendidos);
  Serial.println(luz);
  delay(80);
}
