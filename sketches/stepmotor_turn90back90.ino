#include <Stepper.h>
#define STEPS 2048 // 스텝모터의 스텝 수
Stepper stepper(STEPS, 8, 9, 10, 11); // 스텝모터의 스텝 수, 제어핀을 설정

void setup() {
  stepper.setSpeed(10); // 스텝모터의 회전 속도
}

void loop() {
  int degree = 90;

  int length = 9;
  int x[length] = { 1000, 3000, 7000, 2000, 3000, 17000, 1000, 7000, 7000};
  int y[length] = { 9000, 3000, 5000, 9000, 5000, 5000, 20000, 3000, 5000};

  int value = map(degree, 0, 360, 0, 4096);

  for (int i=0; i<length; i++) {
    stepper.step(value);
    delay(x[i]);
    stepper.step(-value);
    delay(y[i]);
  }
}
