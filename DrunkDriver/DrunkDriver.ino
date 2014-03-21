#include <RedBot.h>

RedBotMotor motor;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  
  int choice  = random(1,7);
  int motorSpeedRight;
  int motorSpeedLeft;
  
  if (choice == 1){
    motorSpeedRight = 255;
    motorSpeedLeft = 255;
    }
  else if (choice == 2){
    motorSpeedRight = 255;
    motorSpeedLeft = 128;
  }
  else if (choice == 3){
    motorSpeedRight = 128;
    motorSpeedLeft = 255;
  }
  else if (choice == 4){
    motorSpeedRight = 255;
    motorSpeedLeft = -255;
  }
  else if (choice == 5){
    motorSpeedRight = -255;
    motorSpeedLeft = 255;
  }
  else if (choice == 6){
    motorSpeedRight = -255;
    motorSpeedLeft = -255;
  }
  motor.rightDrive(motorSpeedRight);
  motor.leftDrive(motorSpeedLeft);
  clearAhead(motorSpeedRight, motorSpeedLeft);
    
}
void clearAhead(int right, int left)
{
  for (int i = 0; i<10; i++){
    int sensorValue = (analogRead(A2));
    if (sensorValue >= 300){
          Serial.println("Turning");
          motor.rightDrive(255);
          motor.leftDrive(-255);
          delay(250);
        }
    motor.rightDrive(right);
    motor.leftDrive(left);
    delay(100);
    
  }
}
  
      
