int temp,hum;
#include "DHT.h"
#define DHTPIN 6                       // Digital Pin 5
#define DHTTYPE DHT11                  // We are Using DHT11
DHT dht(DHTPIN, DHTTYPE);
unsigned char j=0; 
void setup() {                
  Serial.begin(9600);                  // enable software serial
  dht.begin();
}

void loop() {
  
  hum =  dht.readHumidity();             // Reading Humidity Value
  temp = dht.readTemperature();        // Reading Temperature Valuet
  
  
  Serial.print("T:");
  Serial.print(temp);
  Serial.println("  Cen.Deg ");

  Serial.print("H:");
  Serial.print(hum);
  Serial.println("  %RH");
  delay(1000);
}

