//LED 5개 시리얼 통신을 이용해 점등하기

#define Pin_LED_len 5
#define DelayTime 1000

int Pin_LED[Pin_LED_len]={13, 12, 11, 10, 9};

void setup() {

  for(int i=0; i<Pin_LED_len; i++){
    pinMode(Pin_LED[i], OUTPUT);
  }

}

void loop() { 
 char userln;

  if(Serial.available()){
    userln = Serial.read();

    switch(userln){
      case 'n':
        for(int i=0; i<Pin_LED_len; i++){
          digitalWrite(Pin_LED[i], HIGH);
        } 
        break;
      case 'f':
        for(int i=0; i<Pin_LED_len; i++){
          digitalWrite(Pin_LED[i], LOW);
        }
        break;
      default:
        break;              
      }
  }
}
