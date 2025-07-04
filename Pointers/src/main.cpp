#include <Arduino.h>
long int *p;
long int i=5;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(*p=&i);
}