// Sevo Motore von dem Sumoroboter steuern

// die bilbiotheken
#include <Servo.h> 
#include <Sumo.h> 
 
void setup() 
{ 
  // die Servo Motore initialisieren
  start(); 
} 
 
// lassen wir den Roboter eine Sekunde vorwaerts und rueckwaerts bewegen xD 
// TIP: manchmal will man die Motore separat ansteuern 
//      linkerMotor(richtung, geschwindigkeit) rechterMotor(richtung, geschwindigkeit)
//      wo richtung FORWAERTS oder RUECKWAERTS ist und die geschwindigkeit 0 kuni 100
//      (probiere: linkerMotor(FORWAERTS, 55) rechterMotor(RUECKWAERTS, MAX_SPEED) vasakMootor(FORWAERTS, LANGSAM)) 
void loop() 
{
  vorwaerts();      // die richtung bestimmen 
  warte( SEKUNDE ); // eine Sekunde ausführen
  tagasi();         // die richtung bestimmen
  warte( SEKUNDE ); // eine Sekunde ausführen
} 
