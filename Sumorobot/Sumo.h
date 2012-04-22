/*
  Sumo.h - Sumorobot library for Arduino
  Copyright (c) 2011 The Estonian Information Technology College.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
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
#define FORWARD 0
#define BACKWARD 1
#define MAX_SPEED 100 // the % of max speed
#define MAX_FORWARD 180 // max forward speed
#define MIDPOINT 94 // servo midpoint, break
#define MAX_BACKWARD 0 // max backward speed
/* pins */
#define RIGHT_WHEEL 6
#define LEFT_WHEEL 5
#define FRONT_RIGHT_SENSOR 0
#define FRONT_LEFT_SENSOR 1
#define BOTTOM_RIGHT_SENSOR 3
#define BOTTOM_LEFT_SENSOR 4
#define BOTTOM_MIDDLE_SENSOR 5
/* calibration */
#define LIGHT_INTENSITY_RIGHT 800
#define LIGHT_INTENSITY_LEFT 800
#define LIGHT_INTENSITY_MIDDLE 800
#define OPPONENT_DISTANCE_LEFT 90
#define OPPONENT_DISTANCE_RIGHT 90

/* motors */

static Servo rightWheel;
static Servo leftWheel;

/* english version */

/* movement */
void start();
int getSpeed(int, int);
void stop();
void forward();
void backward();
void right();
void left();
int rightMotor(int);
int leftMotor(int);

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
#define test() \
{ \
    if(BOTTOM_RIGHT) stop(); \
    else if(BOTTOM_LEFT) stop(); \
    else if(BOTTOM_MIDDLE) backward(); \
    else if(OPPONENT_LEFT && OPPONENT_RIGHT) forward(); \
    else if(OPPONENT_LEFT) left(); \
    else if(OPPONENT_RIGHT) right(); \
    else forward(); \
}
#define test_opponent() \
{ \
    if(OPPONENT_LEFT && OPPONENT_RIGHT) forward(); \
    else if(OPPONENT_LEFT) left(); \
    else if(OPPONENT_RIGHT) right(); \
    else stop(); \
}
#define test_line() \
{ \
    if(BOTTOM_RIGHT) { \
		rightMotor(getSpeed(BACKWARD, MAX_SPEED)); \
		leftMotor(getSpeed(BACKWARD, MAX_SPEED)); \
		delay(500); \
    } \
	else if(BOTTOM_LEFT) { \
		rightMotor(getSpeed(FORWARD, MAX_SPEED)); \
		leftMotor(getSpeed(FORWARD, MAX_SPEED)); \
		delay(500); \
    } \
    else if(BOTTOM_MIDDLE) { backward(); delay(500); }  \
    else forward(); \
}
#define test_sensor() \
{ \
    Serial.print( "parem: " ); \
    Serial.print( analogRead(FRONT_RIGHT_SENSOR) ); \
    Serial.print( " vasak: " ); \
    Serial.print( analogRead(FRONT_LEFT_SENSOR) ); \
    Serial.print( " joon vasak: "); \
    Serial.print( analogRead(BOTTOM_LEFT_SENSOR) ); \
    Serial.print( " joon kesk: "); \
    Serial.print( analogRead(BOTTOM_MIDDLE_SENSOR) ); \
    Serial.print( " joon parem: "); \
    Serial.println( analogRead(BOTTOM_RIGHT_SENSOR) ); \
    delay(1000); \
}
/* end of english version */


/* estonian version */

/* sensors */
/* opponent */
#define VASTANE_PAREM OPPONENT_RIGHT
#define VASTANE_VASAK OPPONENT_LEFT
#define VASTANE_EES OPPONENT_FRONT
/* field */
#define ALL_PAREM BOTTOM_RIGHT
#define ALL_VASAK BOTTOL_LEFT
#define ALL_KESKMINE BOTTOM_MIDDLE

/* movement */
#define viivitus(time) (delay(time))
#define stop() (stop())
#define edasi() (forward())
#define tagasi() (backward())
#define paremale() (right())
#define vasakule() (left())
#define paremMootor(rSpeed) (rightMotor(rSpeed))
#define vasakMootor(lSpeed) (leftMotor(lSpeed))

/* for testing */
#define test_vastane() test_opponent()
#define test_joon() test_line()
#define test_andur() test_sensor()

/* end of estonian version */

#endif