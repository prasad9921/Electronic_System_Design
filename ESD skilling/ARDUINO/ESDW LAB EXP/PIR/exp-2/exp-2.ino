const int bzr=13;
const int PIR=6;
const int MAG=7;                       // Digital Pin 5
void setup() {                
  Serial.begin(9600);                  // enable software serial
  pinMode(PIR,INPUT); 
  pinMode(MAG,INPUT);
  pinMode(bzr,OUTPUT);
//digitalWrite(PIR,1);
  digitalWrite(MAG,1); 
  digitalWrite(bzr,0); 
}

void loop() {
  if((digitalRead(PIR)) ||( digitalRead(MAG)))
  {
    digitalWrite(bzr,1);
    Serial.println("Sensor Detected!");
    delay(1000);
  }
  else{
  digitalWrite(bzr,0);  
  delay(1000);
}}

