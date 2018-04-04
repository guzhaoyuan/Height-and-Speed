int pinInterrupt = 2; //中断（光电）信号的脚
int interval = 500; // output in every interval ms
int trigPerRev = 30; // 一圈有多少个齿、触发
float trigToSpeed =float(trigPerRev * interval) / 60000;
int count = 0;

void onChange()  
{
  if ( digitalRead(pinInterrupt) == HIGH ){ 
    count ++;
//    Serial.println(count);  
   }
}  

void setup() {
  Serial.begin(9600);
  
  // set io 2 = input
  pinMode( pinInterrupt, INPUT);

  attachInterrupt( digitalPinToInterrupt(pinInterrupt), onChange, RISING);  
}

void loop() {
  delay(interval);
  
//  Serial.print("speed(r/min):");
  Serial.println((count) / trigToSpeed);

  count = 0;
}
