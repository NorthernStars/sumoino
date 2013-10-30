// die Servo Motoren und die Abstand Sensoren von den Sumoroboter ansetzen
 
// die bilbiotheken
#include <Servo.h> 
#include <Sumo.h> 
 
void setup() 
{ 
  // die Servo Motore initialisieren 
  start(); 
} 
 
// proovime vastasele otsa liikuda, et ta ringilt lahkuma sundida 
// TIP: proovi vastane leida, kui andurid teda hetkel olevas positsioonis ei suuda leida 
//      (proovi: paremMootor(EDASI, AEGLANE) and vasakMootor(TAGASI, AEGLANE) keerlemiseks 
//      AEGLANE asemel saab kasutada, MAX_KIIRUS ning 0 kuni 100 protsenti) 
void loop() 
{ 
  if ( GEGNER_VORNE ) vorwaerts();    // wenn der Gegner vorne steht, gehe vorwaerts 
  else if ( GEGNER_LINKS ) links();   // wenn der Gegner links steht, gehe links
  else if ( GEGNER_RECHTS ) rechts(); // wenn der Gegner rechts steht, gehe rechts
  else stop();                        // wenn kein Gegner in der zusehen ist, stoppen
} 
 