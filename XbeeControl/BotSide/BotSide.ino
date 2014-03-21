#include <RedBot.h>

RedBotMotor motor;
RedBotSoftwareSerial link;


void setup() {
  link.begin(9600);

}

void loop() {
  
  int distanceValue = (analogRead(A2));
  String command;
  
  while (link.available() > 0){
    char letter = Serial.read();
    command+= letter;
  }
  
  if (command == "bankright"){
    motor.rightDrive(128);
    motor.leftDrive(255);
  }
  else if (command == "bankleft"){
    motor.rightDrive(255);
    motor.leftDrive(128);
  }
  else if (command == "forward"){
    motor.rightDrive(255);
    motor.leftDrive(255);
  }
  else if (command == "right"){
    motor.rightDrive(-255);
    motor.leftDrive(255);
  }
  else if (command == "left"){
    motor.rightDrive(255);
    motor.leftDrive(-255);
  }
  
}
