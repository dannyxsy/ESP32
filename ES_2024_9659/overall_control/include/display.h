#include <Arduino.h>
#include <U8g2lib.h>
#include <WiFi.h>
#include <HTTPClient.h>

extern const char* ssid ;
extern const char* password ;
extern const char* serverAddress ; // 接收端ESP32的IP地址
extern const int serverPort ; // 接收端ESP32的HTTP服务器端口
extern const int buttonPin ;

extern bool lastButtonState ;
extern bool buttonPressed ;

extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2;

extern enum Page {
  MAIN_MENU,
  SET_TEMPERATURE_HIGH,
  SET_TEMPERATURE_LOW,
  SET_WET_HIGH,
  SET_WET_LOW,
  SET_CO2_HIGH,
  SET_CO2_LOW,
  SET_ALL_CONTROL
}currentPage;

extern int tempHigh ;
extern int tempLow ;
extern int WetHigh;
extern int WetLow;
extern int FANNUM;
extern int CO2High;
extern int CO2Low;
void displayMainMenu() ;
void displaySetTemperatureHigh() ;
void displaySetTemperatureLow() ;
void handleInput(char key) ;
void displaySetWetHigh();
void displaySetWetLow();
void displaySetFanNum();
void displaySetCO2High();
void displaySetCO2Low();
