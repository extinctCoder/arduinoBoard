int Light_1 = 8;
int Light_2 = 9;
int Light_3 = 10;
int Light_4 = 11;
int Light_5 = 12;
int Light_6 = 13;
void setup() {
  Serial.begin(9600);
  pinMode(Light_1,OUTPUT);
  pinMode(Light_2,OUTPUT);
  pinMode(Light_3,OUTPUT);
  pinMode(Light_4,OUTPUT);
  pinMode(Light_5,OUTPUT);
  pinMode(Light_6,OUTPUT);
  digitalWrite(Light_1,LOW);
  digitalWrite(Light_2,LOW);
  digitalWrite(Light_3,LOW);
  digitalWrite(Light_4,LOW);
  digitalWrite(Light_5,LOW);
  digitalWrite(Light_6,LOW);
  Serial.println("Ready...!!!");
}
void loop() {
  if(Serial.available()>0)
  {
    int input = Serial.read();
    switch(input)
    {
     case 'A' : light_1On();
     break;
     case 'B' : light_2On();
     break;
     case 'C' : light_3On();
     break;
     case 'D' : light_4On();
     break;
     case 'E' : light_5On();
     break;
     case 'F' : light_6On();
     break;
     case 'a' : light_1Off();
     break;
     case 'b' : light_2Off();
     break;
     case 'c' : light_3Off();
     break;
     case 'd' : light_4Off();
     break;
     case 'e' : light_5Off();
     break;
     case 'f' : light_6Off();
     break;
     default : Serial.println("Wrong Command...!!!");
     break;
    }
  }
}
void light_1On(){
  Serial.println("Light_1 ON");
  digitalWrite(Light_1,HIGH);
  }
void light_2On(){
  Serial.println("Light_2 ON");
  digitalWrite(Light_2,HIGH);
  }
void light_3On(){
  Serial.println("Light_3 ON");
  digitalWrite(Light_3,HIGH);
  }
void light_4On(){
  Serial.println("Light_4 ON");
  digitalWrite(Light_4,HIGH);
  }
void light_5On(){
  Serial.println("Light_5 ON");
  digitalWrite(Light_5,HIGH);
  }
void light_6On(){
  Serial.println("Light_6 ON");
  digitalWrite(Light_6,HIGH);
  }
void light_1Off(){
  Serial.println("Light_1 OFF");
  digitalWrite(Light_1,LOW);
  }
void light_2Off(){
  Serial.println("Light_2 OFF");
  digitalWrite(Light_2,LOW);
  }
void light_3Off(){
  Serial.println("Light_3 OFF");
  digitalWrite(Light_3,LOW);
  }
void light_4Off(){
  Serial.println("Light_4 OFF");
  digitalWrite(Light_4,LOW);
  }
void light_5Off(){
  Serial.println("Light_5 OFF");
  digitalWrite(Light_5,LOW);
  }
void light_6Off(){
  Serial.println("Light_6 OFF");
  digitalWrite(Light_6,LOW);
  }
 
