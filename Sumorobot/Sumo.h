/*
Sumo.h - Sumorobot library for Arduino

Author (C) 2012 The Estonian Information Technology College Robotics Club
Author (C) 2012 Silver Kuusik <silver.kuusik@gmail.com>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef Sumo_h
#define Sumo_h

#include "../Servo/Servo.h"

/* for C style compilation */
extern "C" {
  #include "stdlib.h"
}

/* configuration */
/* movement */
#define MAX_FORWARD 180 // max forward speed
#define MIDPOINT 90     // servo midpoint, brake
#define MAX_BACKWARD 0  // max backward speed
/* pins */
#define RIGHT_WHEEL 6
#define LEFT_WHEEL 5
#define FRONT_RIGHT_SENSOR 0
#define FRONT_LEFT_SENSOR 1
#define BOTTOM_RIGHT_SENSOR 2
#define BOTTOM_MIDDLE_SENSOR 3
#define BOTTOM_LEFT_SENSOR 4
/* calibration */
#define LIGHT_INTENSITY 600
#define OPPONENT_DISTANCE 200
/* for further calibration */
#define OPPONENT_DISTANCE_LEFT OPPONENT_DISTANCE
#define OPPONENT_DISTANCE_RIGHT OPPONENT_DISTANCE
#define LIGHT_INTENSITY_RIGHT LIGHT_INTENSITY
#define LIGHT_INTENSITY_LEFT LIGHT_INTENSITY
#define LIGHT_INTENSITY_MIDDLE LIGHT_INTENSITY


/* motors */
static Servo rightWheel;
static Servo leftWheel;

/* english version */

/* constants */
#define SECOND 1000
#define MAX_SPEED 100   // 100% of speed
#define SLOW 10         // 10% of speed
#define FORWARD 0       // forward direction
#define BACKWARD 1      // backward direction

/* initialization */
void start();
/* movement */
int getSpeed(uint8_t, uint8_t, uint8_t);
void stop();
void forward();
void backward();
void right();
void left();
int rightMotor(uint8_t, uint8_t);
int leftMotor(uint8_t, uint8_t);

/* sensors */
#define READ_OPPONENT(analog, distance) (analogRead(analog) > distance)
#define READ_BOTTOM(analog, distance) (analogRead(analog) < distance)
/* opponent */
#define OPPONENT_RIGHT READ_OPPONENT(FRONT_RIGHT_SENSOR, OPPONENT_DISTANCE_RIGHT)
#define OPPONENT_LEFT READ_OPPONENT(FRONT_LEFT_SENSOR, OPPONENT_DISTANCE_LEFT)
#define OPPONENT_FRONT (OPPONENT_LEFT && OPPONENT_RIGHT)
/* field */
#define BOTTOM_RIGHT READ_BOTTOM(BOTTOM_RIGHT_SENSOR, LIGHT_INTENSITY_RIGHT)
#define BOTTOM_LEFT READ_BOTTOM(BOTTOM_LEFT_SENSOR, LIGHT_INTENSITY_LEFT)
#define BOTTOM_MIDDLE READ_BOTTOM(BOTTOM_MIDDLE_SENSOR, LIGHT_INTENSITY_MIDDLE)

/* for testing */
#define followLine() \
{ \
    if (BOTTOM_RIGHT) { right(); } \
		else if (BOTTOM_LEFT) { left(); } \
    else forward(); \
}
#define testOpponent() \
{ \
    if (OPPONENT_FRONT) forward(); \
    else if (OPPONENT_LEFT) left(); \
    else if (OPPONENT_RIGHT) right(); \
    else stop(); \
}
#define testLine() \
{ \
    if (BOTTOM_RIGHT) { left(); } \
		else if (BOTTOM_LEFT) { right(); } \
    else forward(); \
}
#define testSensors() \
{ \
    Serial.print( "right: " ); \
    Serial.print( analogRead(FRONT_RIGHT_SENSOR) ); \
    Serial.print( " left: " ); \
    Serial.println( analogRead(FRONT_LEFT_SENSOR) ); \
    Serial.print( " line_left: "); \
    Serial.print( analogRead(BOTTOM_LEFT_SENSOR) ); \
    Serial.print( " line_middle: "); \
    Serial.print( analogRead(BOTTOM_MIDDLE_SENSOR) ); \
    Serial.print( " line_right: "); \
    Serial.println( analogRead(BOTTOM_RIGHT_SENSOR) ); \
    Serial.println(); \
}
/* end of english version */

/* estonian version */

/* constants */
#define SECOND 1000
#define MAX_KIIRUS 100 	// 100% of speed
#define AEGLANE 10      // 10% of speed
#define EDASI 0       	// forward direction
#define TAGASI 1      	// backward direction

/* sensors */
/* opponent */
#define VASTANE_PAREM OPPONENT_RIGHT
#define VASTANE_VASAK OPPONENT_LEFT
#define VASTANE_EES OPPONENT_FRONT
/* field */
#define ALL_PAREM BOTTOM_RIGHT
#define ALL_VASAK BOTTOM_LEFT
#define ALL_KESKMINE BOTTOM_MIDDLE

/* movement */
#define viivitus(time) (delay(time))
#define stopp() (stop())
#define edasi() (forward())
#define tagasi() (backward())
#define paremale() (right())
#define vasakule() (left())
#define paremMootor(dir, speed_percentage) (rightMotor(dir, speed_percentage))
#define vasakMootor(dir, speed_percentage) (leftMotor(dir, speed_percentage))

/* end of estonian version */

/* german version */

/* constants */
#define SEKUNDE 1000
#define MAX_TEMPO 100 	// 100% of speed
#define LANGSAM 10 			// 10% of speed
#define VORWAERTS 0 		// forward direction
#define RUECKWAERTS 1 	// backward direction

/* sensors */
/* opponent */
#define GEGNER_RECHTS OPPONENT_RIGHT
#define GEGNER_LINKS OPPONENT_LEFT
#define GEGNER_VORNE OPPONENT_FRONT
/* field */
#define UNTEN_RECHTS BOTTOM_RIGHT
#define UNTEN_LINKS BOTTOM_LEFT
#define UNTEN_MITTE BOTTOM_MIDDLE

/* movement */
#define warte(time) (delay(time))
#define stop() (stop())
#define vorwaerts() (forward())
#define rueckwaerts() (backward())
#define rechts() (right())
#define links() (left())
#define rechterMotor(dir, speed_percentage) (rightMotor(dir, speed_percentage))
#define linkerMotor(dir, speed_percentage) (leftMotor(dir, speed_percentage))

/* end of german version */

#endif
