#include "extern.h"


// Define the variables
const char* ssid = "Redmi Note 13 Pro";
const char* password = "zhx130196";

const int motorPin1 = 32; // 电机控制引脚1
const int motorPin2 = 33; // 电机控制引脚2
const int switchPin = 22;
const int anglePin = 23;
const int speedPin = 25;
const int DHTPIN=18;
WiFiServer server(80);
bool motorDirection = false;  // 电机方向，false表示正转，true表示反转
bool motorOpen = false;
int currentSpeed = 0;          // 当前速度档位，初始为0表示最低转速
int switchPressCount = 1;  

bool fanOn = false;     // 风扇状态
int motorSpeed = 100;    // 默认速度 (PWM值, 85 对应慢速)
bool reverse = false;   // 方向标志
int middle = 170;
int low =100;
int high = 240;
int THIGH = 0;
int TLOW =0;
int HHIGH=0;
int HLOW=0;
     // 定义DHT11的数据引脚   // DHT 11
DHT dht(DHTPIN, DHT11);