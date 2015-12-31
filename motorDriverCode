int motor_A_1 = 11;
int motor_A_2 = 10;
int motor_B_1 = 9;
int motor_B_2 = 8;
void setup() {
  pinMode(motor_A_1,OUTPUT);
  pinMode(motor_A_2,OUTPUT);
  pinMode(motor_B_1,OUTPUT);
  pinMode(motor_B_2,OUTPUT);
}

void loop() {
  forwardDerection();
  delay(1000);
  reverseDerection();
  delay(1000);
  leftDerection();
  delay(1000);
  rightDerection();
  delay(1000);
}
void forwardDerection(){
  digitalWrite(motor_A_1,HIGH);
  digitalWrite(motor_A_2,LOW);
  digitalWrite(motor_B_1,HIGH);
  digitalWrite(motor_B_2,LOW);
  }
void reverseDerection(){
  digitalWrite(motor_A_1,LOW);
  digitalWrite(motor_A_2,HIGH);
  digitalWrite(motor_B_1,LOW);
  digitalWrite(motor_B_2,HIGH);
  }
void leftDerection(){
  digitalWrite(motor_A_1,HIGH);
  digitalWrite(motor_A_2,LOW);
  digitalWrite(motor_B_1,LOW);
  digitalWrite(motor_B_2,HIGH);
  }
void rightDerection(){
  digitalWrite(motor_A_1,LOW);
  digitalWrite(motor_A_2,HIGH);
  digitalWrite(motor_B_1,HIGH);
  digitalWrite(motor_B_2,LOW);
  }
