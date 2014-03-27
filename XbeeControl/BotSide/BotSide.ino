/*

This sketch acts as the RedBot side for an Xbee communications
link with another arduino or a computer. The RedBot should have
its serial switch set to "Xbee HW Serial" in order to work.

Coded by Robert Davis

*/

#include <RedBot.h>

#define FORWARD 0x1
#define BACKWARD 0x2
#define RIGHT 0x3
#define LEFT 0x4 
#define BANK_RIGHT 0x5
#define BANK_LEFT 0x6

RedBotMotor motor;


void setup() 
{
  Serial.begin(57600);  //Set to whatever baudrate your Xbee is configured to
}

void loop() 
{  
  if (Serial.available() > 0)
  {
    executeCommand();
  }
  else
  {
    motor.stop();
  }
}
  
  
void executeCommand()
{
  int command = Serial.read();
  
  if (command == BANK_RIGHT)
  {
    motor.rightDrive(128);
    motor.leftDrive(255);
  }
  else if (command == BANK_LEFT)
  {
    motor.rightDrive(255);
    motor.leftDrive(128);
  }
  else if (command == FORWARD)
  {
    motor.rightDrive(255);
    motor.leftDrive(255);
  }
  else if (command == RIGHT)
  {
    motor.rightDrive(-255);
    motor.leftDrive(255);
  }
  else if (command == LEFT)
  {
    motor.rightDrive(255);
    motor.leftDrive(-255);
  }
}
