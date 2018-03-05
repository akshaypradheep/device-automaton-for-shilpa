#include<EEPROM.h>
#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
int i = 0;
int H = 0;
int M = 0;
int S = 0;
int setting_value;
const int gnd = 16;
const int vcc = 17;
const int dev = 13;
const int P = A3;
const int N = A2;
const int setting_address = 0;
const int over_ride_off = 11;
boolean bell_status = true;
boolean Over_ride = true;
void setup(){
  pinMode(dev,OUTPUT);
  //********************************power supply***********************
  pinMode(gnd, OUTPUT);
  pinMode(vcc, OUTPUT);
  digitalWrite(vcc,HIGH);
  digitalWrite(gnd,LOW);
  //-------------------------------------------------------------------
  Serial.begin(9600);
  digitalWrite(dev,LOW);
  
}
void loop() {

  tmElements_t tm;
  if (RTC.read(tm))
  {
  H = tm.Hour;
  M = tm.Minute;
  S = tm.Second;
  Serial.print("TIME:");
  Serial.print(tm.Hour);
  Serial.print(":");
  Serial.print(tm.Minute);
  Serial.print(":");
  Serial.print(tm.Second);
  Serial.println();
  delay(1000);
  }
  if(H==13 && M==00 && S==00){
    digitalWrite(dev,HIGH);
  }
  if(H==13 && M==30 && S==00){
    digitalWrite(dev,LOW);
  }
}

