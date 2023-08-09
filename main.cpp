#include <PubSubClient.h>
#include <WiFiNINA.h>

const char* ssid = "***";
const char* password = "***";
const char* mqttServer = "***";
const int mqttPort = 1883;
const char* mqttTopic = "led/control";
const char* mqttTopicStatus = "pin/status";
const char* mqttClientID = "arduino-client";

const int ledPin = 13; // LED pin
const int ledPin12 = 12;
const int ledPin8 = 8;
const int buttonPin = 2;
 
int ledState = LOW;     
int lastButtonState = HIGH; 

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin12, OUTPUT); 
  pinMode(ledPin8, OUTPUT); 

  pinMode(buttonPin, INPUT_PULLUP);
  
  digitalWrite(ledPin, ledState);
  
  Serial.begin(9600);
  setupWiFi();
  mqttClient.setServer(mqttServer, mqttPort);
  mqttClient.setCallback(handleMqttMessage);
  reconnect();
}

void loop() {
  // Manual turn ON/OFF LED (pin13)
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    delay(50);  // Debounce delay
    reading = digitalRead(buttonPin);  // Read button again after debounce delay

    if (reading != lastButtonState) {
      lastButtonState = reading;

      if (reading == LOW) {
        ledState = !ledState;  

        if (ledState == HIGH) {
          digitalWrite(ledPin, HIGH); 
        } else {
          digitalWrite(ledPin, LOW);  
        }
      }
    }
  }
  
  if (!mqttClient.connected()) {
    reconnect();
  }
  mqttClient.loop();
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
  digitalWrite(ledPin12, HIGH); // Assuming ledPin12 is used for an LED
}

void reconnect() {
  while (!mqttClient.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (mqttClient.connect(mqttClientID)) {
      Serial.println("connected");
      mqttClient.subscribe(mqttTopic);
      digitalWrite(ledPin8, HIGH); // Assuming ledPin8 is used for an LED
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
    digitalWrite(ledPin, ledState);
    Serial.println("LED is ON");
  } else if (message.equals("OFF")) {
    ledState = LOW;
    digitalWrite(ledPin, ledState);
    Serial.println("LED is OFF");
  }
}
