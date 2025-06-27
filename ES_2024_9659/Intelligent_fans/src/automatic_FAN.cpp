#include "automatic_FAN.h"
#include "extern.h"
#include "physical.h"
// Wi-Fi credentials
// char* ssid = "Redmi Note 13 Pro";
// char* password = "zhx130196";

// // Motor control pins
// int motorPin1 = 32; // 电机控制引脚1
// int motorPin2 = 33; // 电机控制引脚2

// // Create a WiFi server on port 80
// WiFiServer server(80);

void automatic_FAN_s() {
 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Start the server
  server.begin();
  Serial.println("Server started");
}

void automatic_FAN_l() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  Serial.println("New Client connected");

  // Wait until the client sends some data
  while (!client.available()) {
    delay(1);
  }

  // Read the request line
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // Handle the request
  if (request.indexOf("GET /FORWARD") >= 0) {
    // Forward direction
   analogWrite(motorPin1, middle);
   analogWrite(motorPin2, 0);
    Serial.println("Motor moving FORWARD");
  } else if (request.indexOf("GET /REVERSE") >= 0) {
    // Reverse direction
   stopMotor();
    Serial.println("Motor moving REVERSE");
    
  } else if (request.indexOf("highTemp=") >= 0) {
      String highTempStr = request.substring(request.indexOf("highTemp=") + 9);
      highTempStr = highTempStr.substring(0, highTempStr.indexOf('&'));
      THIGH = highTempStr.toInt();
      Serial.print("Updated THIGH: ");
      Serial.println(THIGH);
      String lowTempStr = request.substring(request.indexOf("lowTemp=") + 8);
      lowTempStr = lowTempStr.substring(0, lowTempStr.indexOf(' '));
      TLOW = lowTempStr.toInt();
      Serial.print("Updated TLOW: ");
      Serial.println(TLOW);
    }
    // else if (request.indexOf("lowTemp=") >= 0) {
     
    // }
    else if (request.indexOf("highHum=") >= 0) {
      String highHumStr = request.substring(request.indexOf("highHum=") + 8);
      highHumStr = highHumStr.substring(0, highHumStr.indexOf('&'));
      HHIGH = highHumStr.toInt();
      Serial.print("Updated highHum: ");
      Serial.println(HHIGH);
      String lowHumStr = request.substring(request.indexOf("lowHum=") + 7);
      lowHumStr = lowHumStr.substring(0, lowHumStr.indexOf(' '));
      HLOW = lowHumStr.toInt();
      Serial.print("Updated lowHum: ");
      Serial.println(HLOW);
    }
    // else if (request.indexOf("lowHum=") >= 0) {
      
    // }

  // Send HTTP response
  client.println("HTTP/1.1 200 OK");
  client.println("Command received");

  delay(1);
  client.stop();
  Serial.println("Client disconnected");
}