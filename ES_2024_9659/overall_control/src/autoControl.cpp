#include "display.h"
#include "wificonnected.h"
void displaySetFanNum() {
  u8g2.clearBuffer();

  u8g2.setCursor(7, 15); // 指定显示位置
  u8g2.print("Start Fan ");
  

  u8g2.setCursor(7, 30); // 提示按键
  u8g2.print("Press to open and close");
  ConnectWifiL();

  u8g2.setCursor(7, 45); // 提示按键
  u8g2.print("Enter to confirm");

  u8g2.sendBuffer();
  }