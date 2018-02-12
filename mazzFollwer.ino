int motor_A_1 = 11;
int motor_A_2 = 10;
int motor_B_1 = 9;
int motor_B_2 = 8;
int s0 = 0;
int s1 = 0;
int s2 = 0;
int s3 = 0;
int s4 = 0;
int mid = 0;
int mn = 0;
int mx = 0;
int array[600];
int count = 0;
boolean ifCircleFound = false; 
void setup()
{
  Serial.begin(115200);
  stopMotor();
}
void loop()
{
  initializeSensor();
  takeTurn();
}
void takeTurn(){ 
  if(ifCircleFound == true && count != -1){
    if(s0>930&&s1>930&&s3<930&&s4<930 && array[count] == 1)
  {
    rightDerection();
    Serial.print(" RIGHT");
    count --;
    delay(10);
  }
  else if(s0<930&&s1<930&&s3>930&&s4>930  && array[count] == -1)
  {
    leftDerection();
    Serial.print(" LEFT");
    count--;
    delay(10);
  }
  else if(s0>=930&&s1>=930&&s2>=930&&s3>=930&&s4>=930)
  {
    stopMotor();
    delay(10);
    forwardDerection();
      if(s0>=930&&s1>=930&&s2>=930&&s3>=930&&s4>=930){
        delay(100);
        ifCircleFound = true;
        count == -1;
        Serial.print(" CIRCLE FOUND");
        }
      else{
        reverseDerection();
        delay(100);
        rightDerection();
        Serial.print(" LEFT");
        count--;
        delay(10);
        }
  }
  else if(count != -1){                  
    forwardDerection();
    Serial.print(" FORWORD");
    delay(10);
   }
    }
  else{
    if(s0>930&&s1>930&&s3<930&&s4<930)
  {
    rightDerection();
    Serial.print(" RIGHT");
    array[count++]=-1;
    delay(10);
  }
  else if(s0<930&&s1<930&&s3>930&&s4>930)
  {
    leftDerection();
    Serial.print(" LEFT");
    array[count++]=1;
    delay(10);
  }
  else if(s0>=930&&s1>=930&&s2>=930&&s3>=930&&s4>=930)
  {
    stopMotor();
    delay(10);
    forwardDerection();
      if(s0>=930&&s1>=930&&s2>=930&&s3>=930&&s4>=930){
        delay(100);
        ifCircleFound = true;
        Serial.print(" CIRCLE FOUND");
        }
      else{
        reverseDerection();
        delay(100);
        leftDerection();
        Serial.print(" LEFT");
        array[count++]=1;
        delay(10);
      }
  }
  else {                  
    forwardDerection();
    Serial.print(" FORWORD");
    delay(10);
   }
    }             
}
void initializeSensor(){
  for(int k=0; k<50; k++){
    digitalWrite(13, HIGH);
    delay(10);
    digitalWrite(13, LOW);
    delay(10);
  }
  s0 = analogRead(0);
  s1 = analogRead(1);
  s2 = analogRead(2);
  s3 = analogRead(3);
  s4 = analogRead(4); 
  Serial.print(" ");
  Serial.print(s0); 
  Serial.print(" ");
  Serial.print(s1); 
  Serial.print(" ");
  Serial.print(s2); 
  Serial.print(" ");
  Serial.print(s3); 
  Serial.print(" ");
  Serial.print(s4); 
  Serial.println();
}
void stopMotor(){
  digitalWrite(motor_A_1,LOW);
  digitalWrite(motor_A_2,LOW);
  digitalWrite(motor_B_1,LOW);
  digitalWrite(motor_B_2,LOW);
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
