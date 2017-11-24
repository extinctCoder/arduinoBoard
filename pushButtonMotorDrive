int motor_1_1 = 12;
int motor_1_2 = 11;
int motor_2_1 = 10;
int motor_2_2 = 9;
int f = 8;
int b = 7;
int l = 6;
int r = 5;
void forward(){
  digitalWrite(motor_1_1,HIGH);
  digitalWrite(motor_1_2,LOW);
  digitalWrite(motor_2_1,HIGH);
  digitalWrite(motor_2_2,LOW);
}
void backward(){
  digitalWrite(motor_1_1,LOW);
  digitalWrite(motor_1_2,HIGH);
  digitalWrite(motor_2_1,LOW);
  digitalWrite(motor_2_2,HIGH);
}
void left(){
  digitalWrite(motor_1_1,LOW);
  digitalWrite(motor_1_2,HIGH);
  digitalWrite(motor_2_1,HIGH);
  digitalWrite(motor_2_2,LOW);
}
void right(){
  digitalWrite(motor_1_1,HIGH);
  digitalWrite(motor_1_2,LOW);
  digitalWrite(motor_2_1,LOW);
  digitalWrite(motor_2_2,HIGH);  
}
void setup() {
  pinMode(motor_1_1,OUTPUT);
  pinMode(motor_1_2,OUTPUT);
  pinMode(motor_2_1,OUTPUT); 
  pinMode(motor_2_2,OUTPUT);
  pinMode(f,INPUT); 
  pinMode(b,INPUT);
  pinMode(l,INPUT);
  pinMode(r,INPUT);
}

void loop() {
  if(digitalRead(f)==HIGH){
    forward();
  }
  if(digitalRead(b)==HIGH){
    backward();
  }
  if(digitalRead(l)==HIGH){
    right();
  }
  if(digitalRead(r)==HIGH){
    left();
  }
}
