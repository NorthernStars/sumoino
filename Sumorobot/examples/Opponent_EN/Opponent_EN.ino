// Controlling sumorobts servos and distance sensors 
// by EIK Robotics Club <http://robot.itcollege.ee> 
 
// add necessary libraries 
#include <Servo.h> 
#include <Sumo.h> 
 
void setup() 
{ 
  // initilize the servo motors 
  start(); 
} 
 
// try to push out the opponent without attention to the sumoring 
// HINT: try to search for the opponent, when he is not visible to the sensors 
//       (example: use rightMotor(FORWARD, SLOW) and leftMotor(BACKWARD, SLOW) to spin 
//                 instead of SLOW, MAX_SPEED or 0 to 100 can be used) 
void loop() 
{ 
  if ( OPPONENT_FRONT ) forward();    // when opponent is in front of us, we go forward 
  else if ( OPPONENT_LEFT ) left();   // when the opponent is on the left side, we go left 
  else if ( OPPONENT_RIGHT ) right(); // when the opponent is on the right side, we go right 
  else stop();                        // when there is no opponent 
} 
 