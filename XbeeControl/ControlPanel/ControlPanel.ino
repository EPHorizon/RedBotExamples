#define FORWARD 0x1
#define BACKWARD 0x2
#define RIGHT 0x3
#define LEFT 0x4
#define BANK_RIGHT 0x5
#define BANK_LEFT 0x5

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
    Serial.write(BANK_RIGHT);
  }
  else if ((forwardState == LOW) && (leftState == LOW)){
    Serial.write(BANK_LEFT);
  }
  else if (forwardState == LOW){
    Serial.write(FORWARD);
  }
  else if (rightState == LOW){
    Serial.write(RIGHT);
  }
  else if (leftState == LOW){
    Serial.write(LEFT);
  }
    
  
}
