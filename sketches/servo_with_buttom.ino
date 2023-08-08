#include<Servo.h>
Servo servo;
int value = 0;

void setup() {
  servo.attach(7); // 7번 핀 사용
  pinMode(2, 2);
}

void loop() {
  int pin2 = digitalRead(2);
  if (pin2 == 0) {
    servo.write(120);
    delay(1000);
    servo.write(0);
  } else {
  }
}
