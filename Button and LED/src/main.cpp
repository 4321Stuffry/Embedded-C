#include <Arduino.h>
void setup(){
DDRD |= (0<<5); // Set PORTD5 as input 
DDRD |= (1<<6); // Set PORTD6 as output
DDRD |= (1<<7); // Set PORTD7 as output
DDRC |= (1<<0); // Set PORTC0 as output
PORTD |= (1<<5); // Set PORTD5 as output and initialize it to high

}
void loop(){
if((PIND & (1<<5))==0){ 
PORTD |= (1<<6);
PORTD |= (1<<7);
PORTC |= (1<<0); 
}
else{
PORTD &= ~(1<<6); // Clear bit 6 of PORTD
PORTD &= ~(1<<7); // Clear bit 7 of PORTD
PORTC &= ~(1<<0); // Clear bit 0 of PORTC
}
}