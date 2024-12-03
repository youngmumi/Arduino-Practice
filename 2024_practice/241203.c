//입력된 핀번호 LED 출력

int red = 13;     // 빨간 LED 핀
int yellow = 12;  // 노란 LED 핀
int white = 11;   // 하얀 LED 핀

void setup() {
  Serial.begin(115200);  // 시리얼 통신 시작
  pinMode(red, OUTPUT);   // 빨간 LED 핀을 출력으로 설정
  pinMode(yellow, OUTPUT); // 노란 LED 핀을 출력으로 설정
  pinMode(white, OUTPUT);  // 하얀 LED 핀을 출력으로 설정
}

void loop() {
  char userIn;    // 사용자 입력 (o 또는 f)
  int pinNum;     // 핀 번호

  Serial.print("LED on: o / LED off: f ");  // LED 켜기/끄기 안내
  while (Serial.available() == 0) {
    // 입력 대기
  }

  userIn = Serial.read();  // 사용자 입력을 읽음
  Serial.println(userIn);   // 입력 받은 문자 출력
  
  // 핀 번호 입력 안내
  Serial.print("Enter pin number (11, 12, or 13): ");
  
  while (Serial.available() == 0) {
    // 입력 대기
  }

  pinNum = Serial.parseInt();  // 핀 번호 입력 받기
  Serial.print("Pin number received: ");
  Serial.println(pinNum);      // 입력 받은 핀 번호 출력

  // 입력된 핀 번호에 따라 switch문을 사용해 LED 제어
  switch (pinNum) {
    case 13: // 빨간 LED
    case 12: // 노란 LED
    case 11: // 하얀 LED
      switch (userIn) {
        case 'o':  // LED 켜기
          digitalWrite(pinNum, HIGH);
          Serial.println("LED turned ON.");
          break;
        case 'f':  // LED 끄기
          digitalWrite(pinNum, LOW);
          Serial.println("LED turned OFF.");
          break;
        default:
          Serial.println("Invalid input. Use 'o' for on and 'f' for off.");
          break;
      }
      break;

    default:
      // 잘못된 핀 번호 입력 처리
      Serial.println("Invalid pin number. Use 11, 12, or 13.");
      break;
  }

  delay(100);  // 작은 지연 (과도한 입력을 방지하기 위해)
}
