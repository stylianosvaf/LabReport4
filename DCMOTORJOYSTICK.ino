/* Controlling a DC motor using a joystick */

int speedPin = 5;
int output1 = 4;
int output2 = 3;
int Speed;
int joyPin = A0;
int joyVal;  // set integers
 
void setup() {

pinMode(speedPin, OUTPUT);
pinMode(output1, OUTPUT);
pinMode(output2, OUTPUT);
pinMode(joyPin, INPUT);  // make the motor pins outputs and the joystick an input
Serial.begin(9600);
}
 
void loop() {

joyVal = analogRead(joyPin);  // set joyVal as the recorded joyPin
 
Serial.println(joyVal);

if (joyVal < 512){
digitalWrite(output1, LOW);
digitalWrite(output2, HIGH);
Speed=-255./512. * joyVal+255.;
analogWrite(speedPin, Speed);  // if the joystick value is less than 512, turn the motor clockwise and calculate speed by finding m in y = mx + b
}

if(joyVal>=512){
digitalWrite(output1, HIGH);
digitalWrite(output2, LOW);
Speed=(255./512.) * joyVal-255.;
analogWrite(speedPin, Speed);  // repeat process but if the joystick value is more than 512, it goes counter clockwise
}
}