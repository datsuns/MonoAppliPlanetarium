#include <SPI.h>
#include <WiFi.h>
//#include <Bounce.h>
#include <CapSense.h>

//#define SENSER 2
#define LED 12

int ledValue = LOW;
//Bounce bouncer = Bounce( SENSER, 10 ); 

//CapSense
CapSense cs_4_2 = CapSense(4,2);

char ssid[] = "UI-hall-4"; //  your network SSID (name) 
char pass[] = "osaka2013";    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;            // your network key Index number (needed only for WEP)

int status = WL_IDLE_STATUS;
// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
IPAddress server(192,168,1,4);  // numeric IP for Google (no DNS)
//char server[] = "www.google.com";    // name address for Google (using DNS)

// Initialize the Ethernet client library
// with the IP address and port of the server 
// that you want to connect to (port 80 is default for HTTP):
WiFiClient client;
int startflg  = 0;

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
  
  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present"); 
    // don't continue:
    while(true);
  } 
  
  // attempt to connect to Wifi network:
  while ( status != WL_CONNECTED) { 
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:    
    status = WiFi.begin(ssid, pass);
  
    // wait 10 seconds for connection:
    delay(10000);
  } 
  Serial.println("Connected to wifi");
  printWifiStatus();
/*
  Serial.println("\nStarting connection to server...");
  // if you get a connection, report back via serial:
  if (client.connect(server, 80)) {
    Serial.println("connected to server");
    // Make a HTTP request:
    client.println("GET http://monoappli.kimulabo.jp/star/add.php");
//    client.println("http://monoappli.kimulabo.jp/star/add.php");
//    client.println("Connection: close");
    client.println();
  }
  */
}

void connectServer(){
  // if you get a connection, report back via serial:
//  if (client.connect(server, 8888)) {
//    Serial.println("connected to server");
    // Make a HTTP request:
//    client.println("GET http://monoappli.kimulabo.jp/star/add.php");
    client.println("1");
    client.println("");
//    client.println();
//  }  
}

void startServer(){
  client.connect(server,8888);  
}

void loop() {
  if(startflg == 0){
    Serial.println("start");
    //startServer();
    startflg = 1;
  }
  digitalWrite(LED,LOW);  
  long start = millis();
  long total =  cs_4_2.capSense(30);

  if(total > 50){
    Serial.print(total);
    Serial.print("\t");
    Serial.println("");
    
    digitalWrite(LED,HIGH);
    //connectServer();
    delay(1000);
  }
  client.println("0");
  delay(100);
}


void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}





