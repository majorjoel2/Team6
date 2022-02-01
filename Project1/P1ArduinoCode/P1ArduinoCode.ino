#include <Encoder.h>

union FLOATUNION_t {
  float number;
  uint8_t bytes[4];
};

FLOATUNION_t sendValue;

void setup() {
  // put your setup code here, to run once:
  sendValue.number = 0;
  Serial.begin(9600);
}

Encoder EncA(2, 3);

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.write(sendValue.bytes, 4);
  Serial.println(sendValue.number);
  delay(500);
  sendValue.number = EncA.read();;
  delay(500);
}
