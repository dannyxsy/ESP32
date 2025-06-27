#include <Arduino.h>
#include "DHT.h" //加载DHT11库
#include "temperature.h"
#include "extern.h"
#include "physical.h"

// const int IA = 26;  //  pin 26 connected to pin IA
// const int IB = 27;  //  pin 27 connected to pin IB

int speed = 240;  // L9110转速设为255


void forward()
{
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, speed);
}
void backward()
{
  analogWrite(motorPin1, speed);
  analogWrite(motorPin2, 0);
}

void th_s() 
{
  Serial.begin(115200); //设置波特率为9600
  dht.begin();
}

unsigned long previousMillis = 0;  // 存储上一次读取时间
const long interval = 1000;  // 读取间隔时间（毫秒）

void th_l() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // 保存上一次读取的时间
    previousMillis = currentMillis;

    // 读取温度和湿度
    float t = dht.readTemperature();
    Serial.print(F("Temperature: "));
    Serial.print(t);
    Serial.println(F("°C"));

    float h = dht.readHumidity();
    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.println(F("%"));

    // 逻辑判断以控制风扇
    // if ((HHIGH != 0 && HLOW != 0) || (THIGH != 0 && TLOW != 0)) {
      if((HHIGH != 0 && HLOW != 0)){
        if(h > float(HHIGH)){
          speed = high;
        Serial.println("da yu zui da zhi H");
        forward();
        }else if(h < float(HLOW)){
          speed = low;
         Serial.println("xiao yu zui xiao zhi H");
        backward();
        }else if(float(HLOW) <= h&& h <= float(HHIGH)){
             Serial.println("qu jian H");
            stopMotor();
        }
        
      }
      else if((THIGH != 0 && TLOW != 0)) {
          if(t > float(THIGH)){
          speed = high;
        Serial.println("da yu zui da zhi T");
        forward();
        }else if(t < float(TLOW)){
          speed = low;
         Serial.println("xiao yu zui xiao zhi T");
        backward();
        }else if(float(TLOW) <= t&& t <= float(THIGH)){
             Serial.println("qu jian T");
            stopMotor();
        }

      }
    //   if((h > float(HHIGH)&&t!=0 )|| (t > float(THIGH)&&h!=0)) {
    //     speed = high;
    //     Serial.println("da yu zui da zhi");
    //     forward();
    //   } else if((h < float(HLOW)&&t!=0) || (t < float(TLOW)&&h!=0)) {
    //     speed = low;
    //      Serial.println("xiao yu zui xiao zhi");
    //     backward();
    //   }else if((float(HLOW) <= h&& h <= float(HHIGH))||(float(TLOW) <= t&&t <= float(THIGH))){
    //          Serial.println("qu jian");
    //         stopMotor();
    //   }
    // }else{
    //   stopMotor();
    // }
  // }
  }
}


