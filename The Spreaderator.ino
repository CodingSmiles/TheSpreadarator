#include <Servo.h>

Servo Parachute;
Servo esc_signal;
int pos = 0;
bool canRun = true;    

void setup() {
  Parachute.attach(9); // Pin for the Parashooter
  esc_signal.attach(12);  //Specify here the pin number on which the signal pin of ESC is connected.
  esc_signal.write(30);   //ESC arm command. ESCs won't start unless input speed is less during initialization.
  delay(3000); 
} 

void motorRampUp() {
  if (canRun == true) { 
    esc_signal.write(50);    //Vary this between 40-130 to change the speed of motor. Higher value, higher speed.
    delay(5000);
    esc_signal.write(65);    //Vary this between 40-130 to change the speed of motor. Higher value, higher speed.
    delay(15000);
    esc_signal.write(130);    //Vary this between 40-130 to change the speed of motor. Higher value, higher speed.
    delay(10000);
    esc_signal.write(0);
    delay(15);
  }
  else {
    
  }
}

void parachuteDeploy()
{
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);
    esc_signal.write(0);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  canRun = false;
}


void loop() {
  motorRampUp();
  parachuteDeploy();
}