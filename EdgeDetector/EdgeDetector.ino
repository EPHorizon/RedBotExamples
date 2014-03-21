/*

This sketch causes the Bot to continuously drive forward, unil
it detects an edge, where it backs up, and turns around.

NOTE: In order for the edge detection to work consistantly,
the Bot must be powered on with the Line Follower Sensor 
slightly above where it would be normally. In other words,
lift the front of the robot up about an inch off the ground,
then turn it on. After than it should be fine.

Coded by Robert Davis
3/20/14

*/

#include <RedBot.h>

RedBotMotor motor;
RedBotSensor right = RedBotSensor(A0);
RedBotSensor left = RedBotSensor(A1);


void setup()
{
  Serial.begin(9600);
  right.setDetectLevel();
  //left.setDetectLevel();
  right.setBGLevel();
  //left.setBGLevel();
}

void loop()
{
 
  motor.rightDrive(100);
  motor.leftDrive(100);
  
  if (!(right.check())){
    Serial.println("Edge detected");
    brake();
    delay(1);
    motor.drive(-150);
    delay(500);
    motor.pivot(255);
    delay(1500);
  }
  
}
