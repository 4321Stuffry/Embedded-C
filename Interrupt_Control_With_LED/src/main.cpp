#include <Arduino.h> 
volatile int a = 1;

volatile bool led_state = LOW; // Volatile variable to hold the LED state
void blink() {
  a = a + 2; // Increment the variable a by 2
Serial.println(a); // Print the value of a to the Serial Monitor


}
void setup(){
pinMode(7, OUTPUT); // Set pin 13 as output
Serial.begin(115200); // Initialize Serial communication at 115200 baud rate
pinMode(2, INPUT); // Set pin 12 as output
led_state = LOW; // Initialize the LED state to LOW
attachInterrupt(digitalPinToInterrupt(2),blink, FALLING); // Attach interrupt to pin 2
}
void loop(){
digitalWrite(7, led_state); // Turn on the LED
delay(1000); // Wait for 1 second
digitalWrite(7, LOW); // Turn off the LED   
delay(1000); // Wait for 1 second
// The loop will continue indefinitely, blinking the LED every second
}