#include <Arduino.h>
volatile bool led_state = HIGH; // Volatile variable to hold the LED state
void blink() {
  static bool led_state = LOW; // Static variable to hold the LED state
  led_state = !led_state; // Toggle the LED state
  digitalWrite(7, led_state); // Write the new state to pin 13
}
void setup(){
pinMode(7, OUTPUT); // Set pin 13 as output
pinMode(2, INPUT); // Set pin 12 as output
attachInterrupt(digitalPinToInterrupt(2),blink, FALLING); // Attach interrupt to pin 2{

}
void loop(){
digitalWrite(7, led_state); // Turn on the LED
delay(1000); // Wait for 1 second
digitalWrite(7, LOW); // Turn off the LED   
delay(1000); // Wait for 1 second
// The loop will continue indefinitely, blinking the LED every second
}