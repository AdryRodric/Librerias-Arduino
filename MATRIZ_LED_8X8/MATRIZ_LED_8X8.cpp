#include "MATRIZ_LED_8X8.h"

MATRIZ_LED_8X8::MATRIZ_LED_8X8(uint8_t pinDIN, uint8_t pinCS, uint8_t pinCLK)
: pinDIN(pinDIN), pinCS(pinCS), pinCLK(pinCLK)
{
  memset(buffer, 0, sizeof(buffer));
}

MATRIZ_LED_8X8::~MATRIZ_LED_8X8() {}

void MATRIZ_LED_8X8::ENVIAR_DATOS(uint8_t direccion, uint8_t valor)
{
  digitalWrite(pinCS, LOW);
  ENVIAR_BYTE(direccion);
  ENVIAR_BYTE(valor);
  digitalWrite(pinCS, HIGH);
}

void MATRIZ_LED_8X8::ENVIAR_BYTE(uint8_t data)
{
  // Se envían primero los bits más significativos (MSB)
  for (int8_t i = 7; i >= 0; i--) {
    digitalWrite(pinCLK, LOW);
    digitalWrite(pinDIN, (data >> i) & 0x01);
    digitalWrite(pinCLK, HIGH);
  }
}

void MATRIZ_LED_8X8::INICIALIZAR()
{
  pinMode(pinDIN, OUTPUT);
  pinMode(pinCLK, OUTPUT);
  pinMode(pinCS, OUTPUT);
  digitalWrite(pinCS, HIGH);

  ENVIAR_DATOS(0x0F, 0x00); // Test display OFF
  ENVIAR_DATOS(0x0C, 0x01); // Shutdown OFF (activar)
  ENVIAR_DATOS(0x0B, 0x07); // Escanear las 8 filas
  ENVIAR_DATOS(0x09, 0x00); // Modo sin decodificación
  ENVIAR_DATOS(0x0A, 0x08); // Brillo medio
  LIMPIAR();
}

void MATRIZ_LED_8X8::LIMPIAR()
{
  memset(buffer, 0, sizeof(buffer));
  MOSTRAR();
}

void MATRIZ_LED_8X8::SET_LED(uint8_t fila, uint8_t columna, bool estado)
{
  if (fila > 7 || columna > 7) return;

  // El bit 7 representa la columna izquierda del MAX7219
  uint8_t mask = 1 << (7 - columna);

  if (estado)
    buffer[fila] |= mask;
  else
    buffer[fila] &= ~mask;
}

void MATRIZ_LED_8X8::MOSTRAR() {
  for (uint8_t i = 0; i < 8; i++) {
    ENVIAR_DATOS(i + 1, buffer[i]);
  }
}

void MATRIZ_LED_8X8::SET_BRILLO(uint8_t nivel) {
  if (nivel > 15) nivel = 15;
  ENVIAR_DATOS(0x0A, nivel);
}

void MATRIZ_LED_8X8::ENCENDER_TODOS() {
  for (uint8_t i = 0; i < 8; i++) {
    buffer[i] = 0xFF; // 11111111 → todos los LEDs encendidos en esa fila
  }
  MOSTRAR();
}

void MATRIZ_LED_8X8::APAGAR_TODOS(){
  memset(buffer, 0, sizeof(buffer)); // limpia todas las filas
  MOSTRAR();
}

void MATRIZ_LED_8X8::patronX(){
  LIMPIAR();
  for(uint8_t i = 0 ; i < 8; i++){
    SET_LED(i,i,true); MOSTRAR();
  }
  for(int8_t columna = 0, fila = 7; columna <= 8, fila >= 0; fila--, columna++){
     SET_LED(columna,fila,true); MOSTRAR();
  }
}

void MATRIZ_LED_8X8::patronTRI(){
  LIMPIAR();
  for(int8_t columna = 0; columna < 8; columna ++){
    SET_LED(columna,0,true); MOSTRAR();
  }
  const uint8_t coordenadas[][2] = {
    {0,1}, {1,2}, {1,3}, {2,4}, {2,5},
    {3,6}, {3,7}, {4,7}, {4,6}, {5,5},
    {5,4}, {6,3}, {6,2}, {7,1}
  };
  for (uint8_t i = 0; i < sizeof(coordenadas)/2; i++) {
    SET_LED(coordenadas[i][0], coordenadas[i][1], true);
  }
  MOSTRAR();
}

void MATRIZ_LED_8X8::patronCIR(){
  LIMPIAR();
  const uint8_t coordenadas[][2] = {
    {0,2}, {0,3}, {0,4}, {0,5},
    {1,6}, 
    {2,7}, {3,7}, {4,7}, {5,7},
    {6,6},
    {7,5}, {7,4}, {7,3}, {7,2},
    {6,1},
    {5,0}, {4,0}, {3,0}, {2,0},
    {1,1}
  };
  for (int8_t i = 0; i < 20; i++){
    SET_LED(coordenadas[i][0], coordenadas[i][1], true);
  }
  MOSTRAR();
}

void MATRIZ_LED_8X8::patronCUAD(){
  LIMPIAR();
  for(int8_t columna = 0, fila = 7; columna <= 7, fila >= 0; columna ++, fila--){
    SET_LED(columna,0,true);
    SET_LED(0,columna,true);
    SET_LED(fila,7,true);
    SET_LED(7,fila,true);
  }
  MOSTRAR();
}