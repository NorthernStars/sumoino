// Sumoroboti servode ja valgusandurite juhtimine 
// EIK Robootikaklubi <http://robot.itcollege.ee> 
 
// lisame vajalikud teegid 
#include <Servo.h> 
#include <Sumorobot.h> 
 
void setup() 
{ 
  // initsialiseerime servo mootorid 
  start(); 
} 
 
// proovime soita nii, et sumorobt ei lahkuks sumoringist 
// VIHJE: saab ka kasutada ALL_KESKMINE andurit 
//       (proovi: if ( ALL_KESKMINE ) tagasi()) 
void loop() 
{ 
  if ( ALL_PAREM ) vasakule();      // kui joon on paremal, mine vasakule 
  else if ( ALL_VASAK ) paremale(); // kui joon on vasakul, mine paremale 
  else edasi();                     // muuljuhul mine otse 
} 
 