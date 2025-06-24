#include <Arduino.h>
void setup() {
  DDRC &= ~(1 << 0);
  DDRD |= 0xFC;
  PORTC |= (1 << 0);
}

void loop() {
  if ((PINC & 1) == 0) {
    for (int i = 0; i < 7; i++) {
      delay(50);
      PORTD |= (128 >> i);
    }
    for (int i = 2; i < 9; i++) {
      delay(50);
      PORTD &= (~(1 << i));
    }
  }
}
