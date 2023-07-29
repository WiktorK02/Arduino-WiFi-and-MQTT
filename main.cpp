#include <PubSubClient.h>
#include <WiFiNINA.h>

const char* ssid = "******";
const char* password = "******";
const char* mqttServer = "******";
const int mqttPort = 1883;
const char* mqttTopic = "led/control";
const char* mqttTopicStatus = "pin/status";
const char* mqttClientID = "arduino-client";

const int ledPin13 = 13;
const int ledPin12 = 12;
const int ledPin8 = 8;
//const int monitoredPin = 7;
boolean ledState = LOW;

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

void setup() {
  pinMode(ledPin13, OUTPUT);
  pinMode(ledPin12, OUTPUT); // Assuming ledPin12 is used for an LED
  pinMode(ledPin8, OUTPUT);  // Assuming ledPin8 is used for an LED
  //pinMode(monitoredPin, OUTPUT); // Using INPUT_PULLUP to enable the internal pull-up resistor
  
  digitalWrite(ledPin, ledState);
  
  Serial.begin(9600);
  setupWiFi();
  mqttClient.setServer(mqttServer, mqttPort);
  mqttClient.setCallback(handleMqttMessage);
  reconnect();
}

void loop() {
  if (!mqttClient.connected()) {
    reconnect();
  }
  mqttClient.loop();

  /* String statusMessage = "";
  if (val == LOW){
    statusMessage = "OFF"; // Assuming the monitoredPin is connected to GND when it's ON
  }
  else{
    statusMessage = "ON"; // Assuming the monitoredPin is HIGH (pulled up) when it's OFF
  }
  mqttClient.publish(mqttTopicStatus, statusMessage.c_str());*/

  // Delay added for stability and to avoid flooding the MQTT broker with messages
  delay(1000);
}

void setupWiFi() {
  delay(10);
  Serial.print("Connecting to WiFi ");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  digitalWrite(ledPin12, HIGH); 
}

void reconnect() {
  while (!mqttClient.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (mqttClient.connect(mqttClientID)) {
      Serial.println("connected");
      mqttClient.subscribe(mqttTopic);
      digitalWrite(ledPin8, HIGH);
    } else {
      Serial.print("failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void handleMqttMessage(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  Serial.print("Received MQTT message: ");
  Serial.println(message);

  if (message.equals("ON")) {
    ledState = HIGH;
    digitalWrite(ledPin13, ledState);
    Serial.println("LED is ON");
  } else if (message.equals("OFF")) {
    ledState = LOW;
    digitalWrite(ledPin13, ledState);
    Serial.println("LED is OFF");
  }
}
