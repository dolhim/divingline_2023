#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2, 3);
void setup() 
{
  Serial.begin(9600);
  bluetooth.begin(9600);
  Serial.println("START"); // 시작하면 START를 한번 출력
}

void loop() {
  if (bluetooth.available()) {
    Serial.write(bluetooth.read()); // 블루투스로 전달받은 값을 시리얼 모니터에 출력
  }
  if (Serial.available()) { // 시리얼 모니터로 입력된 값을 블루투스로 전송
    bluetooth.write(Serial.read());
  }
}