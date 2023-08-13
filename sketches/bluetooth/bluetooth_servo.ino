#include <Servo.h>
#include <SoftwareSerial.h>

Servo motor;
SoftwareSerial bluetooth(2, 3);

String value = "";

void setup() 
{
  motor.attach(7);
  motor.write(0);

  Serial.begin(9600);
  bluetooth.begin(9600);
  Serial.println("START");
}
void loop() {
  while (bluetooth.available()) {
    char c = (char)bluetooth.read(); // 블루투스로 값을 입력 받는다.
    value += c;
    delay(5);
  }

  if (value != "") {
    Serial.println("input value: [" + value + "]");

    // 입력값이 on이면, 서보모터가 110도, 3초 정지, 0도, 0.8초 정지한다.
    // 블루투스로 다른 값을 전달하기 전까지 반복된다.
    if (value == "on") { 
      Serial.println("IN");
      motor.write(110);
      delay(3000);
      motor.write(0);
      delay(800);
    }

    // 입력값이 off면 서보모터를 0도로 설정한다.
    if (value == "off") {
      Serial.println("IN2");
      motor.write(0);
      value = "";
    }

    // TODO: 일정 시간이 지나거나, 모터가 움직인 횟수가 일정 수에 도달하면 입력값을 초기화한다.

    Serial.println("OUT");
  }
}