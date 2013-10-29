// Controlling sumorobts servos 
// by EIK Robotics Club <http://robot.itcollege.ee> 
 
// add necessary libraries 
#include <Servo.h> 
#include <Sumorobot.h> 
 
void setup() 
{ 
  // initilize the servo motors 
  start(); 
} 
 
// we just make the robot go 1 second forward and backward xD 
// HINT: sometimes you want to control the wheels separately, use leftMotor(dir, speed) rightMotor(dir, speed) 
//       (example: leftMotor(FORWARD, 55) or rightMotor(BACKWARD, MAX_SPEED) or leftMotor(FORWARD, SLOW)) 
//       (remember: the speed range is in percentage 0% to 100%) 
void loop() 
{ 
  forward();       // give command to drive forward 
  delay( SECOND ); // go forward for 1 second 
  backward();      // give command to drive backward 
  delay( SECOND ); // go backward for 1 second 
} 
 