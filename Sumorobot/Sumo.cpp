/*
Sumo.cpp - Sumorobot library for Arduino

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

#include "Sumo.h"

/* init function */
void start()
{
  /* initialize the wheels */
  rightWheel.attach(RIGHT_WHEEL);
  leftWheel.attach(LEFT_WHEEL);
}

/* function to calculate the the motor speed given the wheel, directory and speed in precentage
 @param wheel ( RIGHT_WHEEL or LEFT_WHEEL )
 @param dir ( BACKWARD or FORWARD )
 @param speed_percentage ( 0 to 100 )
 @return errorcode
 */
int getSpeed(uint8_t wheel, uint8_t dir, uint8_t speed_percentage)
{
  /* if precentage out of rage, return error */
  if ( speed_percentage < 0 || speed_percentage > 100 ) return -3;
  /* if the wheel is unknown, return error */
  if ( wheel != RIGHT_WHEEL && wheel != LEFT_WHEEL ) return -2;
  /* if the we operate with the right wheen, we need to turn the direction, because the motor is flipped */
  if ( wheel == RIGHT_WHEEL ) dir = !dir;
  if (dir == FORWARD) {
    /* the forward speed is MIDPOINT - MAX_FORWARD, for speed calculation we need to move the 0 point */
    return ((speed_percentage / 100.0) * (MAX_FORWARD - MIDPOINT)) + MIDPOINT;
  } else if (dir == BACKWARD) {
    /* the backward speed is MIDPOINT - MAX_BACKWARD, for speed calculation we need to revert the result */
    return abs(((speed_percentage / 100.0) * MIDPOINT) - MIDPOINT);
  } else {
    /* if the direction was not valid return error */
    return -1;
  }
}

/* to break  */
void stop()
{
  rightWheel.write(MIDPOINT);
  leftWheel.write(MIDPOINT);
}

/*  */
void forward()
{
  rightWheel.write(getSpeed(RIGHT_WHEEL, FORWARD, MAX_SPEED));
  leftWheel.write(getSpeed(LEFT_WHEEL, FORWARD, MAX_SPEED));
}

void backward()
{
  rightWheel.write(getSpeed(RIGHT_WHEEL, BACKWARD, MAX_SPEED));
  leftWheel.write(getSpeed(LEFT_WHEEL, BACKWARD, MAX_SPEED));
}

void right()
{
  rightWheel.write(getSpeed(RIGHT_WHEEL, FORWARD, MAX_SPEED / 25));
  leftWheel.write(getSpeed(LEFT_WHEEL, FORWARD, MAX_SPEED));
}

void left()
{
  rightWheel.write(getSpeed(RIGHT_WHEEL, FORWARD, MAX_SPEED));
  leftWheel.write(getSpeed(LEFT_WHEEL, FORWARD, MAX_SPEED / 25));
}

/* function to move right wheel forward or backward with a specific speed
 @param dir ( FORWARD or BACKWARD )
 @param speed_percentage ( 0 to 100 )
 */
int rightMotor(uint8_t dir, uint8_t speed_percentage)
{
  int speed = getSpeed(RIGHT_WHEEL, dir, speed_percentage);
  /* if parameters out of range, return error */
  if ( speed < 0 ) return speed;
  /* otherwise set the speed for the wheel */
  rightWheel.write(speed);
}

/* function to move left wheel forward or backward with a specific speed
 @param dir ( FORWARD or BACKWARD )
 @param speed_percentage ( 0 to 100 )
 */
int leftMotor(uint8_t dir, uint8_t speed_percentage)
{
  int speed = getSpeed(LEFT_WHEEL, dir, speed_percentage);
  /* if parameters out of range, return error */
  if ( speed < 0 ) return speed;
  /* otherwise set the speed for the wheel */
  leftWheel.write(speed);
}
