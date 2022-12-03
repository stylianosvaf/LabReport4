/* Controlling a servo motor using a LDR */

#include <Servo.h>
Servo servoX;  // create a servo object

void setup() {

servoX.attach (9);  // attach pin 9 to servo

}

void loop() {

int lightValue = analogRead (A0);  // Read the light  value
servoAngle = map (lightValue, 0, 1023, 0, 180)  // map the light to the range of the servo
servoX.write (servoAngle)  // move the servo depending on the scaled value of light

}