#include <Arduino.h>
void setup(){
DDRD |= (0<<5); // Set PORTD5 as input 
DDRD |= (1<<6); // Set PORTD6 as output
DDRD |= (1<<7); // Set PORTD7 as output
DDRC |= (1<<0); // Set PORTC0 as output
DDRD |= (1<<3); // Set PORTD3 as output
DDRD |= (1<<4); // Set PORTD4 as output
DDRC |= (1<<1); // Set PORTC1 as output
PORTD |= (1<<5); // Set PORTD5 as output and initialize it to high

}
void loop(){
if((PIND & (1<<5))==0){ 
PORTC |= (1<<1); // Set bit 1 of PORTC
PORTD |= (1<<6);
delay(50); // Wait for 50 milliseconds
PORTD |= (1<<3);
delay(50); // Wait for 50 milliseconds
PORTD |= (1<<7); 
delay(50); // Wait for 50 milliseconds
PORTD |= (1<<4); 
delay(50); // Wait for 50 milliseconds
PORTC |= (1<<0); 
delay(50); // Wait for 50 milliseconds
PORTC &= ~(1<<0); // Clear bit 0 of PORTC
delay(50); // Wait for 50 milliseconds
PORTD &= ~(1<<4); // Clear bit 4 of PORTD
delay(50); // Wait for 50 milliseconds
PORTD &= ~(1<<7); // Clear bit 7 of PORTD
delay(50); // Wait for 50 milliseconds
PORTD &= ~(1<<3); // Clear bit 3 of PORTD
delay(50); // Wait for 50 milliseconds
PORTD &= ~(1<<6); // Clear bit 6 of PORTD
delay(50); // Wait for 50 milliseconds
PORTC &= ~(1<<1); // Clear bit 1 of PORTC
delay(50); // Wait for 50 milliseconds


}
else if((PIND & (1<<5))==1){
}
else{
PORTC &= ~(1<<1); // Clear bit 1 of PORTC
PORTD &= ~(1<<6); // Clear bit 6 of PORTD
PORTD &= ~(1<<7); // Clear bit 7 of PORTD
PORTC &= ~(1<<0); // Clear bit 0 of PORTC
PORTD &= ~(1<<3); // Clear bit 3 of PORTD
PORTD &= ~(1<<4); // Clear bit 4 of PORTD
}
} 