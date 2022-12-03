/* Moving a servo motor using a joystick */

#include <Servo.h>

#define joyX      A0  // connect to x axis of the joystick
#define servoMotor  2  // connect pin 2 to the servo motor


Servo servoX;  // create a servo object

void setup() {
  Serial.begin(9600) ;
  servoX.attach(servoMotor);  // attach a servo to the pin
}

void loop() {
  
  int valueX = analogRead(joyX);  // read the joystick's value

  int angleX = map(valueX, 0, 1023, 0, 180);  // change it to have the range of the servo

  servoX.write(angleX);  // move the servo depending on the scaled value of the joystick
