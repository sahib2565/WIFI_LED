#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoJson.h>

// Replace with your network credentials
const char* ssid = ""; // your wifi name
const char* password = ""; // your wifi password

// Create an instance of the WebServer
WebServer server(80);

// Define the endpoint for receiving switch state data
const char* switchEndpoint = "/switch";

// Define a variable to store the current switch state
bool switchState = false;

void handleSwitch() {
  // Parse the incoming JSON data
  DynamicJsonDocument json(1024);
  deserializeJson(json, server.arg("plain"));

  // Extract the switch state from the JSON data
  bool newState = json["plain"];

  //Serial.println(newState);

  // Perform the desired action based on the switch state
  if (newState != switchState) {
    switchState = newState;

    if (switchState) {
      // Do something when the switch is turned on
      digitalWrite(23,HIGH);
      Serial.println("ON");
    } else {
      // Do something when the switch is turned off
      digitalWrite(23,LOW);
      Serial.println("OFF");
    }
  }

  // Send a response back to the client
  server.send(200, "text/plain", "OK");
}


void setup() {
  // Start the serial communication
  Serial.begin(9600);
  pinMode(23, OUTPUT);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  // Print the IP address
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Register the switch endpoint handler
  server.on(switchEndpoint, handleSwitch);

  // Start the server
  server.begin();
  Serial.println("Server started");
}

void loop() {
  // Handle incoming client requests
  server.handleClient();
}
