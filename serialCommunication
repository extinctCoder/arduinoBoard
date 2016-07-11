int data = -1;
void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  digitalWrite(13, HIGH);
}
void loop() {
  if(Serial.available())
  {
    data=Serial.read();
    if(data=='1'){
      Serial.println("turning led on");    
      digitalWrite(13, HIGH);
      Serial.println("led on");
      }
    else if(data=='0'){
      Serial.println("turning led off");    
      digitalWrite(13, LOW);
      Serial.println("led off");
      }
    else{
      Serial.println("wrong command");
      }
  }
}
