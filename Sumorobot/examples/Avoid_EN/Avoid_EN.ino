// Controlling sumorobts servos and light sensors 
// by EIK Robotics Club <http://robot.itcollege.ee> 
 
// add necessary libraries 
#include <Servo.h> 
#include <Sumo.h> 
 
void setup() 
{ 
  // initilize the servo motors 
  start(); 
} 
 
// try to avoid driving out of the sumoring 
// HINT: the BOTTOM_MIDDLE sensor can also be used 
//       (example: if ( BOTTOM_MIDDLE ) backward()) 
void loop() 
{ 
  if ( BOTTOM_RIGHT ) left();      // when the line is on the right, we drive left 
  else if ( BOTTOM_LEFT ) right(); // when the line is on the left, we drive right 
  else forward();                  // otherwise we go forward 
} 
 