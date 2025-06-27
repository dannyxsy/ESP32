void ConnectWifiS();
void ConnectWifiL();
void sendHttpRequest(const char* serverAddress, const char* command);
void sendHttpTempRequest(const char* serverAddress,const int highTemp, const int lowTemp);
void sendHttpHumRequest(const char* serverAddress,const int highHum,const int lowHum);
void sendRequestsToMultipleServers(const char* command);
void sendTempToMultipleServers(const int highTemp, const int lowTemp);
void sendHumToMultipleServers(const int highHum, const int lowHum);