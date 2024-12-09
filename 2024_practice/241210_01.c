int button1 = 11;
int button2 = 12;
int button3 = 13;

int LED1 = 7;
int LED2 = 6;
int LED3 = 5;
int LED4 = 4;
int LED5 = 3;

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
}

void loop()
{
  int Flag1 = digitalRead(button1);
  int Flag2 = digitalRead(button2);
  int Flag3 = digitalRead(button3);

  // Button1: LED 5개 동시 점등 / 소등
  if (Flag1) {
    for (int i = LED1; i >= LED5; i--) {
      digitalWrite(i, HIGH); // LED 켜기
    }
  } else {
    for (int i = LED1; i >= LED5; i--) {
      digitalWrite(i, LOW); // LED 끄기
    }
  }

  // Button2: LED 5개 순차 점등
  if (Flag2) {
    for (int i = LED1; i >= LED5; i--) {
      digitalWrite(i, HIGH);
      delay(100);
      digitalWrite(i, LOW);
      delay(100);
    }
  }

  // Button3: LED 5개 징검다리 점등
  if (Flag3) {
    while (digitalRead(button3)) { 
      digitalWrite(LED1, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED4, LOW);
      delay(100);

      digitalWrite(LED1, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED4, HIGH);
      delay(100);
    }
  }
}
