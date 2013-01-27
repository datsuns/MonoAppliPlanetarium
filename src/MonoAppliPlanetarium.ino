#include <SPI.h>
#include <WiFi.h>
#include <CapSense.h>

//#define SENSER 2
#define LED 13

#define THRESHOLD 1000

int ledValue = LOW;

//CapSense
CapSense cs_4_2 = CapSense(4,2);

void setup() {

//  pinMode(SENSER,INPUT);
  pinMode(LED,OUTPUT);
//  digitalWrite(SENSER,HIGH);
  digitalWrite(LED,LOW);

  //Initialize serial and wait for port to open:
  Serial.begin(9600); 
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
}


void loop() {
  static boolean current = false;
  static boolean previous = false;

  digitalWrite(LED,LOW);  
  long sensed_total =  cs_4_2.capSense(30);

  // DEBUG
  Serial.println(sensed_total);

  current = sensed_total > THRESHOLD;
  if( current ){
    if( !previous ){
      Serial.println("1");

      previous = current;

      digitalWrite(LED,HIGH);
      delay(250);
    }
  }
  else{
    previous = false;
  }
    
  delay(100);
}




