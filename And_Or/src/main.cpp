#include <Arduino.h>
void setup() {
  DDRD = 0xFF; // Set PORTD as output
  PORTD=0X00; // Initialize PORTD to 0
}
void loop(){

PORTD = (1<<3); // Initialize PORTD to 0
delay(1000); // Wait for 1 second
PORTD = ~(1<<3); // Clear bit 3 of PORTD
delay(1000); // Wait for 1 second
PORTD =(1<<4); // Set PORTD to 0x10
delay(1000); // Wait for 1 second
PORTD = ~(1<<4); // Clear bit 4 of PORTD
delay(1000); // Wait for 1 second
}