#include <RedBot.h>

#define FORWARD 0x1
#define BACKWARD 0x2
#define RIGHT 0x3
#define LEFT 0x4
#define BANK_RIGHT 0x5
#define BANK_LEFT 0x5

RedBotMotor motor;
RedBotSoftwareSerial link;


void setup() {
  link.begin(9600);

}

void loop() {
  
  int distanceValue = (analogRead(A2));
  
  if (Serial.available() > 0){
    executeCommand();
  }
}
  
  
void executeCommand(){
  int command = Serial.read();
  
  if (command == BANK_RIGHT){
    motor.rightDrive(128);
    motor.leftDrive(255);
  }
  else if (command == BANK_LEFT){
    motor.rightDrive(255);
    motor.leftDrive(128);
  }
  else if (command == FORWARD){
    motor.rightDrive(255);
    motor.leftDrive(255);
  }
  else if (command == RIGHT){
    motor.rightDrive(-255);
    motor.leftDrive(255);
  }
  else if (command == LEFT){
    motor.rightDrive(255);
    motor.leftDrive(-255);
  }
  
}
