#include <Arduino.h>
char a[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
int seg[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};   
void setup() {
  DDRD = 0xFF; // Set PORTD as output
  DDRB = 0x00; // Set PORTC as input
  PORTB = 0xFF; // Enable pull-up resistors on PORTC
  DDRC= 0xff;
 // Serial.begin(9600);
}
void loop() {
  for (int i = 0; i < 4; i++) {
    PORTC &= (~(1 << i)); 
    delay(50); // Debounce delay
    Serial.println(i);
    for (int j = 0; j < 4; j++) {
      if ((PINB & (1 << j )) == 0) {
        // Serial.begin(9600);
        // Serial.println(a[i][j]);
        // Serial.end();
       if( a[i][j] >= '0' && a[i][j] <= '9') {    
      
      Serial.begin(9600);
        Serial.println(a[i][j] - '0');
        Serial.end(); // Convert character to digit and display on 7-segment
       }                                                           
          //    PORT  = seg[a[i][j]]; // Display the digit on the 7-segment display
        delay(100); // Wait for 1 second
    
          }    delay(100);
  
    }
    PORTC = 0xFF;
  }

}
