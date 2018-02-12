int stripRed = 10;
int stripGreen = 9;
int stripBlue = 11;

int brightness = 0;
int fadeAmount = 5;
int timeDelay = 30;

int soundPin = A0;
int soundDesity = 0;

int soundDesityCal =0;
void setup() {
  pinMode(stripRed, OUTPUT);
  pinMode(stripGreen, OUTPUT);
  pinMode(stripBlue, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  updateSoundDesity();
  lightRGB();
}
void updateSoundDesity(){
  soundDesity = analogRead(A0);
  if(soundDesityCal>=soundDesity){
    soundDesity = 0;
    }
  else{
    soundDesity -= soundDesityCal;
    }
  Serial.print(soundDesity);
  soundDesity = map(soundDesity, 0, 1023 - soundDesityCal, 0, 255);
  Serial.print(" , ");
  Serial.println(soundDesity);
  }
void lightRGB(){
  if(soundDesity>=0&&soundDesity<=85){
    analogWrite(stripRed, 0);
    analogWrite(stripBlue, 0);
    analogWrite(stripGreen, soundDesity);
    Serial.println("stripGreen");
    }
  else if(soundDesity>=86&&soundDesity<=170){
    analogWrite(stripRed, 0);
    analogWrite(stripBlue, soundDesity);
    analogWrite(stripGreen, 0);
   Serial.println("stripBlue");
    }
  else if(soundDesity>=171&&soundDesity<=255){
    analogWrite(stripRed, soundDesity);
    analogWrite(stripBlue, 0);
    analogWrite(stripGreen, 0);
    Serial.println("stripRed");
    }
  }
void cycle_rgb(){
  for(brightness = 0; brightness <=255; brightness++){
    analogWrite(stripRed, brightness);
    delay(timeDelay);
  }
  for(brightness = 255; brightness >=0; brightness--){
    analogWrite(stripRed, brightness);
    delay(timeDelay);
  }
   analogWrite(stripRed, 0);
  for(brightness = 0; brightness <=255; brightness++){
    analogWrite(stripGreen, brightness);
    delay(timeDelay);
  }
  for(brightness = 255; brightness >=0; brightness--){
    analogWrite(stripGreen, brightness);
    delay(timeDelay);
  }
  analogWrite(stripGreen, 0);
  for(brightness = 0; brightness <=255; brightness++){
    analogWrite(stripBlue, brightness);
    delay(timeDelay);
  }
  for(brightness = 255; brightness >=0; brightness--){
    analogWrite(stripBlue, brightness);
    delay(timeDelay);
  }
  analogWrite(stripBlue, 0);
  }
