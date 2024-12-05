int PinNum =2;
int ControlLED =8;

void setup() {
  Serial.begin(115200);
  pinMode(PinNum, INPUT);
  pinMode(ControlLED, OUTPUT);
}

void loop() {
  int flag;

  flag = digitalRead(PinNum);
  
  digitalWrite(ControlLED, flag);
}
