#include <IRremote.h>
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
#define PWR 0x800FFA25D
#define STP 0x800FF629D
int motor_1= 10;
int motor_2= 9;
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(motor_1,OUTPUT);
  pinMode(motor_2,OUTPUT);
  digitalWrite(motor_1, LOW);
  digitalWrite(motor_2, LOW);
}
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    switch (results.value) {
      case PWR:
        digitalWrite(motor_1, HIGH);
        digitalWrite(motor_2, LOW);
        break;
      case STP:
        digitalWrite(motor_1, LOW);
        digitalWrite(motor_2, LOW);
        break;
        }
    irrecv.resume();
  }
}
