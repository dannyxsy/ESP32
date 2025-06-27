#ifndef COMMON_H
#define COMMON_H
#include "DHT.h" 
#include <WiFi.h>
#include <Arduino.h>
// Declare the variables as extern
extern const char* ssid;
extern const char* password;
extern const int motorPin1;
extern const int motorPin2;
extern const int switchPin;
extern const int anglePin;
extern const int speedPin;

extern WiFiServer server;
// extern bool motorDirection ;  // 电机方向，false表示正转，true表示反转
// extern int currentSpeed;          // 当前速度档位，初始为0表示最低转速
// extern int switchPressCount;
// extern bool motorOpen ;
extern bool fanOn ;     // 风扇状态
extern int motorSpeed ;    // 默认速度 (PWM值, 85 对应慢速)
extern bool reverse ;   // 方向标志
extern int middle;
extern int low;
extern int high;
extern int THIGH ;
extern int TLOW ;
extern int HHIGH;
extern int HLOW;
extern const int DHTPIN;     // 定义DHT11的数据引脚   // DHT 11
extern DHT dht;
#endif // COMMON_H
