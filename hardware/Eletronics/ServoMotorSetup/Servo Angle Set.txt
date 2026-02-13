#include<Servo.h>

Servo myServo;

void setup()
{
  myServo.attach(3);    //Connect Servo to Pin 3
}

void loop()
{
  myServo.write(0);   //Set Servo Position to 0
}
