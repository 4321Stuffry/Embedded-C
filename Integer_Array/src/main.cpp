#include <Arduino.h>
int a[2][2]={
23,34,
35,75,
};
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);

}
void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      Serial.println(a[i][j]);
      delay(1000);
    }
  }
}

