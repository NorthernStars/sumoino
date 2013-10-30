// die Lichtsensoren von dem Sumoroboter benutzen
 
// die bilbiotheken
#include <Servo.h> 
#include <Sumo.h> 
 
void setup() 
{ 
  // die Servo Motore initialisieren 
  start(); 
} 
 
// versuche so zu fahren das der Sumoroboter den Ring nicht verlässt 
// TIP: man kann auch den Sensor UNTEN_MITTE benutzen
//      (versuche: if ( UNTEN_MITTE ) rueckwaerts()) 
void loop() 
{ 
  if ( UNTEN_RECHTS ) links();      // wenn die Linie rechts liegt, gehe nach links 
  else if ( UNTEN_LINKS ) rechts(); // wenn die Linie links liegt, gehe nach rechts 
  else vorwaerts();                 // ansonsten gehe vorwaerts
} 
 