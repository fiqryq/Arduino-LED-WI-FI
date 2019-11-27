#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
#define LED D1

char ssid[] = "Andromeda"; // your network SSID (name)
char pass[] = "gakperlutahu"; // your network password
int status = WL_IDLE_STATUS;
WiFiClient client;
int readValue;

unsigned long myChannelNumber = 922523; // modify thiswith your own Channel Number
const char * myReadAPIKey = "FEE3JWNBXUYH6XTJ"; //modify this yourown ReadAPIKey

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  ThingSpeak.begin(client);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}
void loop() {
  readValue = ThingSpeak.readIntField(
    myChannelNumber,
    1, 
    myReadAPIKey);
  Serial.print("readValue = ");
  Serial.println(readValue);
  if ( readValue == 1) {
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }
}
