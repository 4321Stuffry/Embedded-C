#include <Arduino.h>
char a[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
int sum(int,int);
int mull(int,int);
int divi(int,int);    
int sub(int,int);
void setup() {
  Serial.begin(9600);
  DDRD = 0xFF; // Set PORTD as output
  PORTD = 0x00; // Initialize PORTD to 0
}
void loop() {
  int res,res1,res2,res3;
  int a=10,b=6;
  res1 = mull(a,b);
  Serial.print("Multiplication of "); 
  Serial.println(res1);
  res2 = divi(a,b);
  Serial.print("Division of ");
  Serial.println(res2);
  res3 = sub(a,b);
  Serial.print("Subtraction of ");
  Serial.println(res3);
  // Call the sum function
  // and print the result
  res = sum(a,b);
  Serial.print("Sum of ");
  Serial.println(res);
  if()

  delay(1000);
  if(res%2==0){
    PORTD |= (1 << 7); // Set bit 7 of PORTD
    Serial.println("Result is even, LED ON");
  } else {
    PORTD |= (1 << 6);   // Set bit 6 of PORTD
Serial.println("Result is odd, OTHERLED ON");

  }
if(res1%2==0){
    PORTD |= (1 << 5); // Set bit 5 of PORTD
    delay(1000); // Wait for 1 second
    PORTD &= ~(1 << 5); // Clear bit 5 of PORTD
    delay(1000); // Wait for 1 second
    Serial.println("Multiplication result is even, LED ON");
  } else {
    PORTD |= (1 << 4);   // Set bit 4 of PORTD
Serial.println("Multiplication result is odd, OTHERLED ON");  
  }
if(res2%2==0){
    PORTD |= (1 << 3); // Set bit 3 of PORTD
    Serial.println("Division result is even, LED ON");
  } else {
    PORTD |= (1 << 2);   // Set bit 2 of PORTD  
    Serial.println("Division result is odd, OTHERLED ON");
  }
if(res3%2==0){
    PORTD |= (1 << 1); // Set bit 1 of PORTD
    Serial.println("Subtraction result is even, LED ON");
  } else {
    PORTD |=(1 << 0);   // Set bit 0 of PORTD
    Serial.println("Subtraction result is odd, OTHERLED ON");
  }
  delay(100);
  PORTD = 0x00; // Reset PORTD to 0
}

int sum (int a, int b) {
int c;  
c= a + b;
return c;}
int mull (int a, int b) {
  int c;
  c = a * b;
  return c;
}
int divi (int a, int b) {
  int c;
  c = a / b;
  return c;
}
int sub (int a, int b) {
  int c;
  c = a - b;
  return c;
}
