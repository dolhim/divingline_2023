#include <Stepper.h>
#include <SoftwareSerial.h>
#define LEN 9
#define STEPS 2048 // 스텝모터의 스텝 수
Stepper stepper(STEPS, 8, 9, 10, 11); // 스텝모터의 스텝 수, 제어핀을 설정
SoftwareSerial bluetooth(2, 3);

static int degree = 90;
static int milliseconds1[LEN] = { 1000, 3000, 7000, 2000, 3000, 17000, 1000, 7000, 7000};
static int milliseconds2[LEN] = { 9000, 3000, 5000, 9000, 5000, 5000, 20000, 3000, 5000};

String value = "";

void setup() {
  Serial.begin(9600);
  Serial.println("START");
  stepper.setSpeed(10);
  bluetooth.begin(9600);
}

void loop() {
  while (bluetooth.available()) {

    char c = (char)bluetooth.read(); // 블루투스로 값을 입력 받는다.
    value += c;
    delay(5);
  }

  if (value != "") {
    Serial.println("input value: [" + value + "]");

    if (value.indexOf("on") > -1) { 
      Serial.println("IN");
      int value = map(degree, 0, 360, 0, 4096);

      for (int i=0; i<LEN; i++) {
        stepper.step(value);
        delay(milliseconds1[i]);
        stepper.step(-value);
        delay(milliseconds2[i]);
      }
    }

    if (value.indexOf("off") > -1) {
      Serial.println("IN2");
      value = "";
    }

    Serial.println("OUT");
  }
}
