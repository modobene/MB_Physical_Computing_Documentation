#include <WiFiNINA.h>
#include <MQTT.h>
#include "wifiCredentials.h"

#define ledPin 9

const char ssid[] = WIFI_SSID;
const char pass[] = WIFI_PASS;
unsigned long lastMillis = 0;
int ledBlink; 

WiFiClient net;
MQTTClient client;
int status = WL_IDLE_STATUS;  

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  // attempt to connect to Wifi network:
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    // failed, retry
    Serial.print("No WiFi connection");
    delay(5000);
  }
  
  // once you are connected :
  Serial.println("You're connected to the network");

  //start mqtt
  client.begin("modob.cloud.shiftr.io", net);
  //print message once is received
  client.onMessage(messageReceived);
  connect();
}

void loop() {
  client.loop();
  delay(10);

  // check if connected
  if (!client.connected()) {
    connect();
  }
}

void messageReceived(String &topic, String &payload) {
  Serial.println(topic + ": " + payload);
  analogWrite(ledPin, payload.toInt());
}

void connect() {
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("No Wifi connection...");
    delay(1000);
  }

  while (!client.connect("receiver", "modob", "zaVmh6y35V81os8F")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected to MQTT!");
  //subscribe to message "ledBlink"
  client.subscribe("ledBlink");
}