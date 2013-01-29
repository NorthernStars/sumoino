#include <Servo.h>
#include <Sumo.h>
#include <MeetAndroid.h>

// declare MeetAndroid so that you can call functions with it
MeetAndroid meetAndroid;
// initial moving speed
int movingSpeed = 0;

void setup()
{
  start();
  stop();
  Serial.begin(9600);
  
  // register callback functions, which will be called when an associated event occurs.
  meetAndroid.registerFunction(state, 'A');
}

void loop()
{
  // you need to keep this in your loop() to receive events
  meetAndroid.receive();
  if ( !BOTTOM_RIGHT ) {
    leftMotor(FORWARD, movingSpeed);
    rightMotor(BACKWARD, movingSpeed);
  } else if ( !BOTTOM_LEFT ) {
    leftMotor(BACKWARD, movingSpeed);
    rightMotor(FORWARD, movingSpeed);
  } else {
    leftMotor(FORWARD, movingSpeed);
    rightMotor(FORWARD, movingSpeed);
  }
}

// function to change the state
void state(byte flag, byte numOfValues)
{
  uint8_t buf[2];
  meetAndroid.getBuffer(buf);
  // when sad state was received
  if ( buf[1] == '0' ) {
    digitalWrite(13, HIGH);
    Serial.println("state changed to: sad");
    movingSpeed = 6;
  // when happy state was received
  } else {
    digitalWrite(13, LOW);
    Serial.println("state changed to: happy");
    movingSpeed = 100;
  }
  
}

