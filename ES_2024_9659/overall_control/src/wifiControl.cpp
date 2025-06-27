#include "display.h"
#include "wificonnected.h"
const char* ssid = "Redmi Note 13 Pro";
const char* password = "zhx130196";
const char* serverAddress1 = "192.168.132.252";
const char* serverAddress2 = "192.168.132.233";
const char* serverAddress3 = "192.168.132.183";
const char* serverAddress4 = "192.168.132.78"; // 接收端ESP32的IP地址
const int serverPort = 80; // 接收端ESP32的HTTP服务器端口
const int buttonPin = 16;
const char* serverAddresses[] = {serverAddress1,serverAddress2,serverAddress3,serverAddress4};
// bool lastButtonState = HIGH;
bool buttonPressed = false;


void ConnectWifiS(){
  Serial.begin(115200); 
  pinMode(buttonPin, INPUT_PULLUP);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
}

// void sendHttpRequest(const char* command) {
//   HTTPClient http;
  
//   String url = String("http://") + serverAddress1 + "/" + command;
//   http.begin(url);
  
//   int httpResponseCode = http.GET();
  
//   if (httpResponseCode > 0) {
//     String response = http.getString();
//     Serial.println(response);
//   } else {
//     Serial.printf("Error on sending GET: %d\n", httpResponseCode);
//   }

//   http.end();
// }
void sendHttpRequest(const char* serverAddress, const char* command) {
  HTTPClient http;
  
  String url = String("http://") + serverAddress + "/" + command;
  http.begin(url);
  
  int httpResponseCode = http.GET();
  
  if (httpResponseCode > 0) {
    String response = http.getString();
    Serial.println(response);
  } else {
    Serial.printf("Error on sending GET: %d\n", httpResponseCode);
  }

  http.end();
}
void sendHttpTempRequest(const char* serverAddress,const int highTemp, const int lowTemp) {
  HTTPClient http;
  
  String url = String("http://") + serverAddress + "/" + "?highTemp="+highTemp + "&lowTemp=" + lowTemp;
  http.begin(url);
  
  int httpResponseCode = http.GET();
  
  if (httpResponseCode > 0) {
    String response = http.getString();
    Serial.println(response);
  } else {
    Serial.printf("Error on sending GET: %d\n", httpResponseCode);
  }

  http.end();
}
void sendHttpHumRequest(const char* serverAddress,const int highHum,const int lowHum){
  HTTPClient http;
  String url = String("http://") + serverAddress + "/" + "?highHum="+highHum + "&lowHum=" + lowHum;
  http.begin(url);
  
  int httpResponseCode = http.GET();
  
  if (httpResponseCode > 0) {
    String response = http.getString();
    Serial.println(response);
  } else {
    Serial.printf("Error on sending GET: %d\n", httpResponseCode);
  }

  http.end();

}
void sendRequestsToMultipleServers(const char* command) {
 
  const int numServers = sizeof(serverAddresses) / sizeof(serverAddresses[0]);

  for (int i = 0; i < numServers; i++) {
    sendHttpRequest(serverAddresses[i], command);
  }
}
void sendTempToMultipleServers(const int highTemp, const int lowTemp) {
   Serial.printf("Temp sent");
  const int numServers = sizeof(serverAddresses) / sizeof(serverAddresses[0]);

  for (int i = 0; i < numServers; i++) {
    sendHttpTempRequest(serverAddresses[i],highTemp,lowTemp);
  }
}
void sendHumToMultipleServers(const int highHum, const int lowHum) {
  Serial.printf("Hum sent");
  const int numServers = sizeof(serverAddresses) / sizeof(serverAddresses[0]);

  for (int i = 0; i < numServers; i++) {
    sendHttpHumRequest(serverAddresses[i],highHum,lowHum);
  }
}


void ConnectWifiL(){
//   int buttonState = ;
    if (digitalRead(buttonPin) == LOW ){
        delay(50);
  // Check if button state changed from HIGH to LOW
  if (digitalRead(buttonPin) == LOW ) {
        delay(100);
        buttonPressed = !buttonPressed;
    if (buttonPressed) {
      sendRequestsToMultipleServers("FORWARD");
    } else {
      sendRequestsToMultipleServers("REVERSE");
    }while(digitalRead(buttonPin) == LOW){
        delay(10);
    }
  }
}
}
  // Update lastButtonState for the next iteration
//   lastButtonState = buttonState;

