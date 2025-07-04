#include <Arduino.h>
void setup() {
Serial.begin(9600); // Initialize serial communication at 9600 baud rate
DDRB |= (0<<1);
DDRD |= (1<<2); // Set PORTB1 as input and PORTD0 as output
PORTB |= (1<<0); // Set PORTB1 as output and initialize it to high
}
void loop() {
// Check the state of PORTB0 and set PORTD2 accordingly
// If PORTB0 is low, set PORTD2 high; if PORTB0 is high, set PORTD2 low
// This is a simple toggle mechanism based on the state of PORTB0   
   if((PINB & (1<<0))==0){
    PORTD  |=(1<<2);
    // Set PORTB0 high
   delay(1000); // Wait for 1 second
   
   
}
else if((PINB & (1<<0))==1){
    PORTD &= ~(1<<2); // Set PORTB0 low
    delay(1000); // Wait for 1 second
  }
//Serial.println(PIND); // Print the value of PORTD to the serial monitor
  Serial.println(PINB & (1<<0)); // Print the value of PORTB to the serial monitor
  delay(1000); // Wait for 1 second before the next iteration
}
