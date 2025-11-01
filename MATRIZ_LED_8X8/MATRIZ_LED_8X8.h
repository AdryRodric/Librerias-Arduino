#ifndef MATRIZ_LED_8X8_H
#define MATRIZ_LED_8X8_H

#include <Arduino.h>

class MATRIZ_LED_8X8
{
  private:
    uint8_t pinDIN;
    uint8_t pinCS;
    uint8_t pinCLK;
    uint8_t buffer[8]; // Representa las 8 filas de la matriz (1 byte = 8 columnas)

  void ENVIAR_DATOS(uint8_t direccion, uint8_t valor);
  void ENVIAR_BYTE(uint8_t data);

public:
  MATRIZ_LED_8X8(uint8_t pinDIN, uint8_t pinCS, uint8_t pinCLK);
  ~MATRIZ_LED_8X8();
  void INICIALIZAR();
  void LIMPIAR();
  void SET_LED(uint8_t fila, uint8_t columna, bool estado);
  void MOSTRAR();
  void SET_BRILLO(uint8_t nivel);
  void ENCENDER_TODOS();
  void APAGAR_TODOS();

  // Pruebas de funcionamiento (PATRONES)
  void patronX();
  void patronTRI();
  void patronCIR();
  void patronCUAD();
};

#endif