#include "extern.h"
#include "thread"
#include "physical.h"
#include "temperature.h"
void startMotor() {
  if (reverse) {
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, motorSpeed);
  } else {
    analogWrite(motorPin1, motorSpeed);
    analogWrite(motorPin2, 0);
  }
}

void stopMotor() {
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
}

void toggleSpeed() {
  // 循环切换三个速度等级
  if (motorSpeed == low) {
    motorSpeed = middle; // 中速
  } else if (motorSpeed == middle) {
    motorSpeed = high; // 高速
  } else {
    motorSpeed = low; // 低速
  }
  // 调整电机速度
  startMotor();
}

void toggleDirection() {
  reverse = !reverse; // 切换方向标志
  // 调整电机方向
  startMotor();
}


void toggleFan() {
  fanOn = !fanOn; // 切换风扇状态
  if (fanOn) {
    startMotor();
  } else {
    stopMotor();
  }
}
void physcicalS(){

  pinMode(switchPin, INPUT_PULLUP);
  pinMode(speedPin, INPUT_PULLUP);
  pinMode(anglePin, INPUT_PULLUP);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  // 初始化电机停止状态
  stopMotor();
}


unsigned long lastDebounceTime = 0;  // 上一次去抖动时间
const unsigned long debounceDelay = 50;  // 去抖动延时（毫秒）

void physcicalL() {
  unsigned long currentTime = millis();
  
  // 检查开关状态
  if (digitalRead(switchPin) == LOW) {
    if ((currentTime - lastDebounceTime) > debounceDelay) {
      toggleFan();
      lastDebounceTime = currentTime;
      while (digitalRead(switchPin) == LOW);
    }
  }

  if (fanOn) {
    if (digitalRead(anglePin) == LOW) {
      if ((currentTime - lastDebounceTime) > debounceDelay) {
        toggleDirection();
        lastDebounceTime = currentTime;
        while (digitalRead(anglePin) == LOW);
      }
    }

    if (digitalRead(speedPin) == LOW) {
      if ((currentTime - lastDebounceTime) > debounceDelay) {
        toggleSpeed();
        lastDebounceTime = currentTime;
        while (digitalRead(speedPin) == LOW);
      }
    }
  }

}
