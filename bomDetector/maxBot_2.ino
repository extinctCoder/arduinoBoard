int leftPwm = 2;
int leftPin_1 = 3; 
int leftPin_2 = 4; 
int rightPin_1 = 5; 
int rightPin_2 = 6; 
int rightPwm = 7;

int botSpeed = 100;
int turnSpeed = 80;

int sonarVcc = 8;
int sonarTrig = 9;
int sonarEcho = 10;
int sonarGnd = 11;

int minDistance = 40; //cm


#include <Servo.h>
int servoPin = 22;

int servoPos = 90;

Servo servo;

int metalPin = 24; 

int sprayPin = 26;

int stopTime = 10000;

int dTime = 1000;

int btData;

bool isAuto = false;

int bluVcc = 48;
int bluGnd = 49;
int bluRx = 50;
int bluTx = 51;

void setup(){

  pinInit();
  
  servo.attach(servoPin);
  servo.write(servoPos);
  
  Serial.begin(9600);
  btData = int("x");
  }
 
void loop(){
  if(Serial.available()>0){
    btData = Serial.read();
    }
    runner();
    
  }

  void runner(){
    if(isMetal()){
    sBot();
    digitalWrite(sprayPin,HIGH);
    delay(stopTime);
    digitalWrite(sprayPin,LOW);
    runServo(180);
    if(isNear()){
      runServo(90);
      rBot();
      delay(dTime);
      fBot();
      delay(dTime);
      lBot();
      delay(dTime);
      }
      else{
        runServo(90);
        lBot();
      delay(dTime);
      fBot();
      delay(dTime);
      rBot();
      delay(dTime);
        }
    }
  else
  {
    switch(btData)
    {
     case 'w' : fBot();
     isAuto = false;
     break;
     case 's' : bBot();
     isAuto = false;
     break;
     case 'a' : lBot();
     isAuto = false;
     break;
     case 'd' : rBot();
     isAuto = false;
     break;
     case 'x' : sBot();
     isAuto = false;
     break;
     case 'b' : autoMode();
     isAuto = true;
     break;
     default :
     break;
    }
    if(isAuto){
      autoMode();}
    }
    runServo(90);
    }
void autoMode(){
  if(isNear()){
      sBot();
      delay(dTime);
      runServo(180);
      
    if(isNear()){
      sBot();
      delay(dTime);
      runServo(0);
      
    if(isNear()){
       bBot();
      delay(dTime*2);
      }
      else{
        rBot();
      delay(dTime);
        }
      }
      else{
        lBot();
      delay(dTime);
        }
      }
      else{
        fBot();  
        }
    
  }
void pinInit(){
  pinMode(leftPin_1,OUTPUT);
  pinMode(leftPin_2,OUTPUT);
  pinMode(rightPin_1,OUTPUT);
  pinMode(rightPin_2,OUTPUT);

  analogWrite(leftPwm,botSpeed);
  analogWrite(rightPwm,botSpeed);

  pinMode(sonarVcc,OUTPUT);
  pinMode(sonarTrig,OUTPUT);
  pinMode(sonarEcho,INPUT);
  pinMode(sonarGnd,OUTPUT);

  digitalWrite(sonarVcc,HIGH);
  digitalWrite(sonarGnd,LOW);

  pinMode(metalPin,INPUT);

  pinMode(sprayPin,OUTPUT);

  
  pinMode(bluVcc,OUTPUT);
  pinMode(bluGnd,OUTPUT);

  digitalWrite(bluVcc,HIGH);
  digitalWrite(bluGnd,LOW);
  }
bool isMetal(){
  if(digitalRead(metalPin)==HIGH){
    return true;
    }
  else{
    return false;
    }
  }
void runServo(int angle){
    servo.write(angle);
  }
bool isNear(){
  long duration, distance;
  digitalWrite(sonarTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(sonarTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sonarTrig, LOW);
  duration = pulseIn(sonarEcho, HIGH);
  distance = (duration/2) / 29.1;
 
  if (distance >= 200 || distance <= 0){
    
  }
  else {
    if (distance <= minDistance){
      return true;
      } 
    else{
      return false;
      }
  }
  }
void fBot(){  
  analogWrite(leftPwm,botSpeed);
  analogWrite(rightPwm,botSpeed);
  digitalWrite(leftPin_1, HIGH);
  digitalWrite(leftPin_2, LOW);
  digitalWrite(rightPin_1, HIGH);
  digitalWrite(rightPin_2, LOW);
  }
void bBot(){
  analogWrite(leftPwm,botSpeed);
  analogWrite(rightPwm,botSpeed);
  digitalWrite(leftPin_1, LOW);
  digitalWrite(leftPin_2, HIGH);
  digitalWrite(rightPin_1, LOW);
  digitalWrite(rightPin_2, HIGH);
  }
void lBot(){
  analogWrite(leftPwm,botSpeed+turnSpeed);
  analogWrite(rightPwm,botSpeed+turnSpeed);
  digitalWrite(leftPin_1, HIGH);
  digitalWrite(leftPin_2, LOW);
  digitalWrite(rightPin_1, LOW);
  }
void rBot(){
  analogWrite(leftPwm,botSpeed+turnSpeed);
  analogWrite(rightPwm,botSpeed+turnSpeed);
  digitalWrite(leftPin_1, LOW);
  digitalWrite(leftPin_2, HIGH);
  digitalWrite(rightPin_1, HIGH);
  digitalWrite(rightPin_2, LOW);
  }
void sBot(){
  analogWrite(leftPwm,0);
  analogWrite(rightPwm,0);
  digitalWrite(leftPin_1, LOW);
  digitalWrite(leftPin_2, LOW);
  digitalWrite(rightPin_1, LOW);
  digitalWrite(rightPin_2, LOW);
  }
