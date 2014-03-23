#include <RedBot.h>

RedBotMotor motor;



void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int rightSensor = (analogRead(A0));
  int leftSensor = (analogRead(A1));
  
  motor.rightDrive(255);
  motor.leftDrive(255);
  
  if (rightSensor >= 300){
    Serial.println(rightSensor);
    Serial.println("Obstacle on right detected");
    motor.rightDrive(255);
    motor.leftDrive(-255);
    delay(500);
  }
  else if (leftSensor >= 300){
    Serial.println("Obstacle on left detected");
    motor.rightDrive(-255);
    motor.leftDrive(255);
    delay(500);
  }
}
