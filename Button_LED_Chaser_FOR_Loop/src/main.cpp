#include <Arduino.h>  

void setup() {
  DDRC &= ~(1 << 0);
  DDRD |= 0xFC;
  PORTC |= (1 << 0);
}

void loop() {
  if ((PIND & (1 << 3)) == 0) {
    PORTD |= 0b10000000;
    PORTD &= 0b10001111;
    for (int i = 1; i < 7; i++) {
      delay(50);
      PORTD |= (1 << i);
      PORTD &= ~(1 << (i - 1));
    }
    PORTD &= 0x00;
    delay(500);
  } else {
    PORTD &= 0x00;
  }
}
