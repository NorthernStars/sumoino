// Sumoroboti servode ja kaugusandurite juhtimine 
// EIK Robootikaklubi <http://robot.itcollege.ee> 
 
// lisame vajalikud teegid 
#include <Servo.h> 
#include <Sumo.h> 
 
void setup() 
{ 
  // initsialiseerime servo mootorid 
  start(); 
} 
 
// proovime vastasele otsa liikuda, et ta ringilt lahkuma sundida 
// VIHJE: proovi vastane leida, kui andurid teda hetkel olevas positsioonis ei suuda leida 
//       (proovi: paremMootor(EDASI, AEGLANE) and vasakMootor(TAGASI, AEGLANE) keerlemiseks 
//                AEGLANE asemel saab kasutada, MAX_KIIRUS ning 0% kuni 100%) 
void loop() 
{ 
  if ( VASTANE_EES ) edasi();             // kui vastane on otse ees, liigume edasi 
  else if ( VASTANE_VASAKUL ) vasakule(); // kui vastane on vasakul, liigume vasakule 
  else if ( VASTANE_PAREMAL ) paremale(); // kui vastane on paremal, liigume paremale 
  else stopp();                           // kui vastane pole anduritele leitav 
} 
 