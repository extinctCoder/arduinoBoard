#define DT A0
#define SCK A1
#define sw 2 //hard calibration switch
long sample=0;
float val=0;
long count=0;
int w = 0;
int tempW = -1;
int calibratingWeight = 1;
unsigned long readCount(void)
{
  unsigned long Count;
  unsigned char i;
  pinMode(DT, OUTPUT);
  digitalWrite(DT,HIGH);
  digitalWrite(SCK,LOW);
  Count=0;
  pinMode(DT, INPUT);
  while(digitalRead(DT));
  for (i=0;i<24;i++)
  {
    digitalWrite(SCK,HIGH);
    Count=Count<<1;
    digitalWrite(SCK,LOW);
    if(digitalRead(DT)) 
    Count++;
  }
  digitalWrite(SCK,HIGH);
  Count=Count^0x800000;
  digitalWrite(SCK,LOW);
  return(Count);
}

void setup()
{
  Serial.begin(9600);
  pinMode(SCK, OUTPUT);
  pinMode(sw, INPUT_PULLUP);
  Serial.println("wellcome to load cell calculation secipt");
  delay(1000);
  calibrate();
}

void loop()
{
  count= readCount();
  w=(((count-sample)/val)-2*((count-sample)/val));
  if(w!=tempW){
    if(w<0){
      w=-w;
      }
    Serial.print("weight:\t\t\t");
    Serial.print((int)w);
    Serial.println("g");
    tempW=w;
    }
  if(digitalRead(sw)==0)
  {
    Serial.println("Requesting for hard calibration....");
    val=0;
    sample=0;
    w=0;
    count=0;
    calibrate();
  }
}

void calibrate()
{
  Serial.println("Calibrating...");
  Serial.println("Please Wait...");
  for(int i=0;i<100;i++)
  {
    count=readCount();
    sample+=count;
    Serial.print(count);
    Serial.print(", ");
  }
  sample/=100;
  Serial.print("Avg: ");
  Serial.println(sample);
  Serial.print("Put ");
  Serial.print(calibratingWeight);
  Serial.println("g and wait.");
  count=0;
  while(count<100)
  {
    count=readCount();
    count=sample-count;
    Serial.print(count);
    Serial.print(", ");
  }
  Serial.println();
  Serial.println("Please Wait....");
  delay(2000);
  for(int i=0;i<100;i++)
  {
    count=readCount();
    val+=sample-count;
    Serial.print(count-sample);
    Serial.print(", ");
  }
  val=val/100.0;
  val=val/calibratingWeight;
}
