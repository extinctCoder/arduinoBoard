#include <IRremote.h>


#define PWR 0x800FFA25D
#define bACK  0x800FF02FD
#define vOL 0x800FF9867
#define PREV 0x800FFE01F
#define pLAY 0x800FF906F
#define irPin 7
#define echoPinFront 12
#define trigPinFront 13
int motor_A_1 = 11;
int motor_A_2 = 10;
int motor_B_1 = 9;
int motor_B_2 = 8;
boolean isNear();
void stopMotor();
void forwardDerection();
void reverseDerection();
void leftDerection();
void rightDerection();


byte ledState;
IRrecv irrecv(irPin);
decode_results results;

void setup() {
  Serial.begin(9600);
  pinMode(motor_A_1, OUTPUT);
  pinMode(motor_A_2, OUTPUT);
  pinMode(motor_B_1, OUTPUT);
  pinMode(motor_B_2, OUTPUT);
  pinMode(trigPinFront, OUTPUT);
  pinMode(echoPinFront, INPUT);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    switch (results.value) {
      case PWR:
        stopMotor();
        delay(7000);
        exit;
      case bACK:
        forwardDerection();
        delay(200);
        irrecv.resume();
        stopMotor();
        break;
      case vOL:
        reverseDerection();
        irrecv.resume();
        delay(200);
        stopMotor();
        break;
      case PREV:
        rightDerection();
        irrecv.resume();
        delay(200);
        stopMotor();
        break;
      case pLAY:
        leftDerection();
        irrecv.resume();
        delay(200);
        stopMotor();
        break;
      default:
        irrecv.resume();
        stopMotor();
    }
  }
  else {
    if (isNear()) {
      stopMotor();
      leftDerection();
      delay(170);
      stopMotor();
      if (isNear()) {
        stopMotor();
        rightDerection();
        delay(330);
        stopMotor();
        if (isNear()) {
          stopMotor();
          rightDerection();
          delay(170);
          stopMotor();
        }
      }
    }
    else {
      forwardDerection();
    }
  }
}
boolean isNear() {
  digitalWrite(trigPinFront, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinFront, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinFront, LOW);
  if (pulseIn(echoPinFront, HIGH) >= 500) {
    return false;
  }
  return true;
}
void stopMotor() {
  digitalWrite(motor_A_1, LOW);
  digitalWrite(motor_A_2, LOW);
  digitalWrite(motor_B_1, LOW);
  digitalWrite(motor_B_2, LOW);
  delay(500);
}
void forwardDerection() {
  digitalWrite(motor_A_1, HIGH);
  digitalWrite(motor_A_2, LOW);
  digitalWrite(motor_B_1, HIGH);
  digitalWrite(motor_B_2, LOW);
}
void reverseDerection() {
  digitalWrite(motor_A_1, LOW);
  digitalWrite(motor_A_2, HIGH);
  digitalWrite(motor_B_1, LOW);
  digitalWrite(motor_B_2, HIGH);
}
void leftDerection() {
  digitalWrite(motor_A_1, HIGH);
  digitalWrite(motor_A_2, LOW);
  digitalWrite(motor_B_1, LOW);
  digitalWrite(motor_B_2, HIGH);
}
void rightDerection() {
  digitalWrite(motor_A_1, LOW);
  digitalWrite(motor_A_2, HIGH);
  digitalWrite(motor_B_1, HIGH);
  digitalWrite(motor_B_2, LOW);
}
