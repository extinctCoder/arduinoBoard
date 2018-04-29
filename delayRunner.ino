int motor_Pin_A = 5;
int motor_Pin_B = 4;
int motor_Pwm = 9;
int run_delay = 750;
int stop_delay = 4000;
int motorPwmRzte = 60;

void setup(){
  pinMode(motor_Pin_A, OUTPUT);
  pinMode(motor_Pin_B, OUTPUT);
  analogWrite(motor_Pwm, motorPwmRzte);
  }
void loop(){
  for(int i = 0; i <5; i++){
    forward();
    delay(run_delay);
    stopBot();
    delay(stop_delay);
    } 
  delay(stop_delay);
  for(int i = 0; i <5; i++){
    backward();
    delay(run_delay);
    stopBot();
    delay(stop_delay);
    } 
  delay(stop_delay);
  }

void forward(){
  digitalWrite(motor_Pin_A, HIGH);
  digitalWrite(motor_Pin_B, LOW);
  }

void backward(){
  digitalWrite(motor_Pin_A, LOW);
  digitalWrite(motor_Pin_B, HIGH);
  }
void stopBot(){
  digitalWrite(motor_Pin_A, LOW);
  digitalWrite(motor_Pin_B, LOW);
  }
