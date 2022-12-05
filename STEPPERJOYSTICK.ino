/* Control a stepper motor using a joystick */

int IN1 = 5;
int IN2 = 6;
int IN3 = 7;
int IN4 = 8;  // create variables for each part of the motor's h bridge
int x;  // create variable for ease of use during math

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);  // set all as outputs
  pinMode(A0, INPUT);  // set joystick as input
 }

void loop() {

  x = analogRead(A0);
  
  if(x<475)  // if the joystick's bit value is less than 475, it turns clockwise
  {
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
 delay(5);
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
 delay(5);
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
 delay(5);
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);
 delay(5);
 }

 else if(x>550)  // else if the joystick's bit value is more than 550, it turns counter clockwise
 {
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);
 delay(5);
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
 delay(5);
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
 delay(5);
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
 delay(5);
 }

 else if(x > 475 && x < 550)  // else if when the joystick is resting, the motor does not move
                              // put a range of 475 to 550 to stop any unwanted drift of the motor
 {
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
 }
}