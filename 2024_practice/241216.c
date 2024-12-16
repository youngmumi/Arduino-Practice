int red = 10;
int yellow = 11;
int blue = 13;

int button1 = 5;
int button2 = 3;
int button3 = 2;

void setup()
{
  Serial.begin(115200);
  
  pinMode (red, OUTPUT);
  pinMode (yellow, OUTPUT);
  pinMode (blue, OUTPUT);
  
  pinMode (button1, INPUT);
  pinMode (button2, INPUT);
  pinMode (button3, INPUT);
}

void loop()
{
  int Flag1 = digitalRead(button1);
  int Flag2 = digitalRead(button2);
  int Flag3 = digitalRead(button3);
  
  char userln;
  
  int i;
  
  if(Flag1 == 1){
    digitalWrite(red, HIGH);
  }else if(Flag1==0){
    digitalWrite(red, LOW);
  }
  
  if(Flag2 == 1){
    for(i = 1; i<=255; i++)
    	analogWrite(yellow, i);
  }else if(Flag2==0){
    digitalWrite(yellow, LOW);
  }
  
  if(Flag3 == 1){
    digitalWrite(blue, HIGH);
    delay(100);
    digitalWrite(blue, LOW);
    delay(100);
  }
  
  if(Serial.available()){
	userln=Serial.read();
    
    switch(userln){
      case 'n':
      	digitalWrite(red, HIGH);
      	break;
      case 'f':
      	digitalWrite(red, LOW);
      	break;
      default:
      	Serial.println("Wrong");
      	break;
    }
  }
  
}
