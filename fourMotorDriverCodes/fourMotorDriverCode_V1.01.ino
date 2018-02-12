#include <AFMotor.h>
AF_DCMotor motor_A(1);
AF_DCMotor motor_B(2);
AF_DCMotor motor_C(3);
AF_DCMotor motor_D(4);
void setup() {
  motor_A.setSpeed(200);
  motor_B.setSpeed(200);
  motor_C.setSpeed(200);
  motor_D.setSpeed(200);
  motor_A.run(RELEASE);
  motor_B.run(RELEASE);
  motor_C.run(RELEASE);
  motor_D.run(RELEASE);
}
void loop() {
  uint8_t i; 
  motor_A.run(FORWARD);
  motor_B.run(FORWARD);
  motor_C.run(FORWARD);
  motor_D.run(FORWARD);
  for (i=0; i<255; i++) {
    motor_A.setSpeed(i);
    motor_B.setSpeed(i);
    motor_C.setSpeed(i);
    motor_D.setSpeed(i);  
    delay(10);
 } 
  for (i=255; i!=0; i--) {
    motor_A.setSpeed(i);
    motor_B.setSpeed(i);
    motor_C.setSpeed(i);
    motor_D.setSpeed(i);    
    delay(10);
 }
  motor_A.run(BACKWARD);
  motor_B.run(BACKWARD);
  motor_C.run(BACKWARD);
  motor_D.run(BACKWARD);
  for (i=0; i<255; i++) {
    motor_A.setSpeed(i);
    motor_B.setSpeed(i);
    motor_C.setSpeed(i);
    motor_D.setSpeed(i);    
    delay(10);
 }
  for (i=255; i!=0; i--) {
    motor_A.setSpeed(i);
    motor_B.setSpeed(i);
    motor_C.setSpeed(i);
    motor_D.setSpeed(i);   
    delay(10);
 }
  delay(1000);
}
