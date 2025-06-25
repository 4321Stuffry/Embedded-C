
#include<Arduino.h>


char a[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

void setup() {
  DDRD = 0x0F;
  PORTD = 0xFF;
}

void loop() {
  for (int i = 0; i < 4; i++) {
    PORTD &= (~(1 << i));

    for (int j = 0; j < 4; j++) {
      if ((PIND & (1 << (j + 4))) == 0) {
        Serial.begin(9600);
        Serial.println(a[i][j]);
        Serial.end();
      }
    }

    PORTD = 0xFF;
  }
}