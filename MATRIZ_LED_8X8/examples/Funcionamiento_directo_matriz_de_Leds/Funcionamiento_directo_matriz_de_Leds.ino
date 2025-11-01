// Prueba de funcionamiento directo del driver de la  Matriz de leds
#define DIN 13
#define CS  12
#define CLK 14

void enviar(uint8_t dir, uint8_t val) {
  digitalWrite(CS, LOW);
  shiftOut(DIN, CLK, MSBFIRST, dir);
  shiftOut(DIN, CLK, MSBFIRST, val);
  digitalWrite(CS, HIGH);
}

void setup() {
  pinMode(DIN, OUTPUT);
  pinMode(CS, OUTPUT);
  pinMode(CLK, OUTPUT);
  digitalWrite(CS, HIGH);

  enviar(0x0F, 0x00);
  enviar(0x0C, 0x01);
  enviar(0x0B, 0x07);
  enviar(0x09, 0x00);
  enviar(0x0A, 0x08);

  // Encender solo la fila 1
  enviar(1, B10000001);
  enviar(2, B01000010);
  enviar(3, B00100100);
  enviar(4, B00011000);
  enviar(5, B00100100);
  enviar(6, B01000010);
  enviar(7, B10000001);
  enviar(8, B00000000);
}

void loop() {}