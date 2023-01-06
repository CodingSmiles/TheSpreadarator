#include <Servo.h>

Servo one;
Servo two;
Servo three;
Servo four;
Servo five;
Servo six;
Servo seven;
Servo eight;
Servo nine;
Servo ten;

void setup() {
  one.attach(1);
  two.attach(2);
  three.attach(3);
  four.attach(4);
  five.attach(5);
  six.attach(6);
  seven.attach(7);
  eight.attach(8);
  nine.attach(9);
  ten.attach(10);
}

void rampUpAll() {
  one.write(13);
  two.write(26);
  three.write(39);
  four.write(52);
  five.write(65);
  six.write(78);
  seven.write(91);
  eight.write(104);
  nine.write(117);
  ten.write(130);
  delay(5000);
  one.write(0);
  two.write(0);
  three.write(0);
  four.write(0);
  five.write(0);
  six.write(0);
  seven.write(0);
  eight.write(0);
  nine.write(0);
  ten.write(0);
}

void loop() {
  rampUpAll();
}
