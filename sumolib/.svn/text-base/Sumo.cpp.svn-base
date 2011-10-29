/*
  Sumo.cpp - Sumorobot library for Arduino
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

#include "Sumo.h"

void start()
{
  /* prepare the wheels */
  rightWheel.attach(RIGHT_WHEEL);
  leftWheel.attach(LEFT_WHEEL);
}

int getSpeed(int dir, int precent)
{
  if (dir == FORWARD) {
    /* the forward speed is MIDPOINT - MAX_FORWARD, for speed calculation we need to move the 0 point */
    return ((precent / 100.0) * (MAX_FORWARD - MIDPOINT)) + MIDPOINT;
  } else if (dir == BACKWARD) {
    /* the backward speed is MIDPOINT - MAX_BACKWARD, for speed calculation we need to revert the result */
    return abs(((precent / 100.0) * MIDPOINT) - MIDPOINT);
  } else {
    /* if the direction was not valid return error */
    return -1;
  }
}

/* english version */

/* movement */
void stop()
{
  rightWheel.write(MIDPOINT);
  leftWheel.write(MIDPOINT);
}

void forward()
{
  rightWheel.write(getSpeed(BACKWARD, MAX_SPEED));
  leftWheel.write(getSpeed(FORWARD, MAX_SPEED));
}

void backward()
{
  rightWheel.write(getSpeed(FORWARD, MAX_SPEED));
  leftWheel.write(getSpeed(BACKWARD, MAX_SPEED));
}

void right()
{
  rightWheel.write(getSpeed(BACKWARD, MAX_SPEED / 25));
  leftWheel.write(getSpeed(FORWARD, MAX_SPEED));
}

void left()
{
  rightWheel.write(getSpeed(BACKWARD, MAX_SPEED));
  leftWheel.write(getSpeed(FORWARD, MAX_SPEED / 25));
}

int rightMotor(int rSpeed)
{
  if (rSpeed >= MAX_BACKWARD && rSpeed <= MAX_FORWARD) {
    rightWheel.write(rSpeed);
  } else {
    return -1;
  }
}

int leftMotor(int lSpeed)
{
  if (lSpeed >= MAX_BACKWARD && lSpeed <= MAX_FORWARD) {
    leftWheel.write(lSpeed);
  } else {
    return -1;
  }
}

/* end of english version */
