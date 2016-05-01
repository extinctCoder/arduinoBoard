int motor_A_1 = 3;
int motor_A_2 = 4;
int motor_B_1 = 5;
int motor_B_2 = 6;
int motor_C_1 = 7;
int motor_C_2 = 8;
int motor_D_1 = 9;
int motor_D_2 = 10;
void setup() {
  Serial.begin(9600);
  pinMode(motor_A_1,OUTPUT);
  pinMode(motor_A_2,OUTPUT);
  pinMode(motor_B_1,OUTPUT);
  pinMode(motor_B_2,OUTPUT);
  pinMode(motor_C_1,OUTPUT);
  pinMode(motor_C_2,OUTPUT);
  pinMode(motor_D_1,OUTPUT);
  pinMode(motor_D_2,OUTPUT);
  Serial.println("robo fighter is ready to roll");
}
void loop() {
  if(Serial.available()>0)
  {
    int input = Serial.read();
    switch(input)
    {
     case 'w' : forwardDerection();
     break;
     case 's' : reverseDerection();
     break;
     case 'a' : leftDerection();
     break;
     case 'd' : rightDerection();
     break;
     case 'q' : forntLeftDerection();
     break;
     case 'e' : frontRightDerection();
     break;
     case 'z' : BackLeftDerection();
     break;
     case 'c' : BackRightDerection();
     break;
     case 'x' : stopMotor();
     break;
     default : break;
    }
  } 
  delay(50);
}
void forwardDerection(){
  digitalWrite(motor_A_1,HIGH);
  digitalWrite(motor_A_2,LOW);
  digitalWrite(motor_B_1,HIGH);
  digitalWrite(motor_B_2,LOW);
  digitalWrite(motor_C_1,HIGH);
  digitalWrite(motor_C_2,LOW);
  digitalWrite(motor_D_1,HIGH);
  digitalWrite(motor_D_2,LOW);
  }
void reverseDerection(){
  digitalWrite(motor_A_1,LOW);
  digitalWrite(motor_A_2,HIGH);
  digitalWrite(motor_B_1,LOW);
  digitalWrite(motor_B_2,HIGH);
  digitalWrite(motor_C_1,LOW);
  digitalWrite(motor_C_2,HIGH);
  digitalWrite(motor_D_1,LOW);
  digitalWrite(motor_D_2,HIGH);
  }
void rightDerection(){
  digitalWrite(motor_A_1,HIGH);
  digitalWrite(motor_A_2,LOW);
  digitalWrite(motor_B_1,LOW);
  digitalWrite(motor_B_2,HIGH);
  digitalWrite(motor_C_1,HIGH);
  digitalWrite(motor_C_2,LOW);
  digitalWrite(motor_D_1,LOW);
  digitalWrite(motor_D_2,HIGH);
  delay(10);
  }
void leftDerection(){
  digitalWrite(motor_A_1,LOW);
  digitalWrite(motor_A_2,HIGH);
  digitalWrite(motor_B_1,HIGH);
  digitalWrite(motor_B_2,LOW);
  digitalWrite(motor_C_1,LOW);
  digitalWrite(motor_C_2,HIGH);
  digitalWrite(motor_D_1,HIGH);
  digitalWrite(motor_D_2,LOW);
  delay(10);
  }
void frontRightDerection(){
  Serial.println("forntLeftDerection");
  digitalWrite(motor_A_1,LOW);
  digitalWrite(motor_A_2,HIGH);
  digitalWrite(motor_B_1,LOW);
  digitalWrite(motor_B_2,HIGH);
  digitalWrite(motor_C_1,LOW);
  digitalWrite(motor_C_2,HIGH);
  digitalWrite(motor_D_1,LOW);
  digitalWrite(motor_D_2,HIGH);
  delay(5);
  }
void forntLeftDerection(){
  Serial.println("frontRightDerection");
  digitalWrite(motor_A_1,HIGH);
  digitalWrite(motor_A_2,LOW);
  digitalWrite(motor_B_1,LOW);
  digitalWrite(motor_B_2,HIGH);
  digitalWrite(motor_C_1,HIGH);
  digitalWrite(motor_C_2,LOW);
  digitalWrite(motor_D_1,LOW);
  digitalWrite(motor_D_2,HIGH);
  delay(5);
  }
void BackRightDerection(){
  Serial.println("BackLeftDerection");
  digitalWrite(motor_A_1,HIGH);
  digitalWrite(motor_A_2,LOW);
  digitalWrite(motor_B_1,LOW);
  digitalWrite(motor_B_2,HIGH);
  digitalWrite(motor_C_1,HIGH);
  digitalWrite(motor_C_2,LOW);
  digitalWrite(motor_D_1,LOW);
  digitalWrite(motor_D_2,HIGH);
  delay(5);
  }
void BackLeftDerection(){
  Serial.println("BackRightDerection");
  digitalWrite(motor_A_1,LOW);
  digitalWrite(motor_A_2,HIGH);
  digitalWrite(motor_B_1,LOW);
  digitalWrite(motor_B_2,HIGH);
  digitalWrite(motor_C_1,LOW);
  digitalWrite(motor_C_2,HIGH);
  digitalWrite(motor_D_1,LOW);
  digitalWrite(motor_D_2,HIGH);
  delay(5);
  }
void stopMotor(){
  Serial.println("stopMotor");
  digitalWrite(motor_A_1,LOW);
  digitalWrite(motor_A_2,LOW);
  digitalWrite(motor_B_1,LOW);
  digitalWrite(motor_B_2,LOW);
  digitalWrite(motor_C_1,LOW);
  digitalWrite(motor_C_2,LOW);
  digitalWrite(motor_D_1,LOW);
  digitalWrite(motor_D_2,LOW);
  delay(5);
  }
