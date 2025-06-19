#include <Arduino.h>
void setup(){
DDRD=0xFF;





}
void loop(){
for(int i=0;i<8;i++){
PORTD=1<<i;
delay(50);



}
for(int i=7  ;i>=0;i--){
PORTD=1<<i;
delay(50);


}

}