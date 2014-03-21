
const int forwardButton = 3;
const int rightButton = 2;
const int leftButton = 4;


void setup() {
  Serial.begin(9600);
  pinMode(forwardButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(leftButton, INPUT);
}

void loop() {
  int forwardState, rightState, leftState;
  
  forwardState = digitalRead(forwardButton);
  rightState = digitalRead(rightButton);
  leftState = digitalRead(leftButton);
  
  if ((forwardState == LOW) && (rightState == LOW)){
    Serial.print("bankright");
  }
  else if ((forwardState == LOW) && (leftState == LOW)){
    Serial.print("bankleft");
  }
  else if (forwardState == LOW){
    Serial.print("forward");
  }
  else if (rightState == LOW){
    Serial.print("right");
  }
  else if (leftState == LOW){
    Serial.print("left");
  }
    
  
}
