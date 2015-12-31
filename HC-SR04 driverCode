#define echoPinFront 8
#define trigPinFront 9
int durationFront = 0;
int durationRight = 0;
void setup() {
  Serial.begin (9600);
  pinMode(trigPinFront, OUTPUT);
  pinMode(echoPinFront, INPUT);
}
void loop() {
  digitalWrite(trigPinFront, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinFront, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinFront, LOW);
  durationFront = pulseIn(echoPinFront, HIGH);
  Serial.print("durationFront: ");
  Serial.println(durationFront);
  delay(200);
}
