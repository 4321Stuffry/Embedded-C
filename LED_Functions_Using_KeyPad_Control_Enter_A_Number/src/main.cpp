#include <Arduino.h>
char a[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

int num1 = -1, num2 = -1;
bool waitingForFirst = false, waitingForSecond = false;

void setup() {
  DDRB = 0x00;
  PORTB = 0xFF;
  DDRC = 0xFF;
  Serial.begin(115200);
}

void loop() {
  for (int i = 0; i < 4; i++) {
    PORTC &= ~(1 << i);
    for (int j = 0; j < 4; j++) {
      if ((PINB & (1 << j)) == 0) {
        char key = a[i][j];
        Serial.print("Pressed Key: ");
        Serial.println(key);

        if (key == '#') {
          Serial.println("Enter 1st number:");
          waitingForFirst = true;
          waitingForSecond = false;
          num1 = -1;
          num2 = -1;
          delay(500);
        } else if (waitingForFirst && key >= '0' && key <= '9') {
          num1 = key - '0';
          Serial.print("First number entered: ");
          Serial.println(num1);
          Serial.println("Enter 2nd number:");
          waitingForFirst = false;
          waitingForSecond = true;
          delay(500);
        } else if (waitingForSecond && key >= '0' && key <= '9') {
          num2 = key - '0';
          Serial.print("Second number entered: ");
          Serial.println(num2);
          Serial.println("Calculating sum...");
          delay(2000);// Simulate some processing time
          Serial.print("Sum: ");
          Serial.println(num1 + num2);
          waitingForSecond = false;
          delay(1000);
        }
        // Debounce: wait until key is released
        while ((PINB & (1 << j)) == 0);
        delay(100);
      }
    }
    PORTC = 0xFF;
  }
}