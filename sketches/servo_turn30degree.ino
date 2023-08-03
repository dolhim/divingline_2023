#include<Servo.h>
Servo servo;
int value = 0;

void setup() {
  servo.attach(7); // 7번 핀 사용
  Serial.begin(9600); // 시리얼 통신 속도, 초당 9600비트 (baud rate) 
}

void loop() {
  if (Serial.available()) {
    char in_data = Serial.read();
    if (in_data == '1') {
      value += 30;
      if (value == 210) {
        value = 0;
      }
    }
    Serial.println(value);
    servo.write(value);
  }
}