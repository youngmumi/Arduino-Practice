const int Button01_Pin = 8;
int Array_Pin[4] = {7, 6, 5, 4};

void setup()
{
  int i;
  
  Serial.begin(115200);
  pinMode(Button01_Pin, INPUT);
  
  for(i=0; i<4; i++){
    pinMode(Array_Pin[i], OUTPUT);
  }
}

void loop()
{
  int i;
  
  int Flag;
  Flag = digitalRead(Button01_Pin);
  
  if(Flag ==1){
    for(i=0; i<4; i++){
    	digitalWrite(Array_Pin[i], HIGH);
  	}
  }else {
  	for(i=0; i<4; i++){
    	digitalWrite(Array_Pin[i], LOW);
  	}
  }
 
}
