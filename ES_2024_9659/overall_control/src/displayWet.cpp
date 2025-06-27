#include "display.h"
void displaySetWetHigh() {
  u8g2.clearBuffer();

  u8g2.setCursor(7, 15); // 指定显示位置
  u8g2.print("Set High Hum:");

  u8g2.setCursor(7, 30); // 显示高温
  u8g2.print("High: ");
  u8g2.print(WetHigh);
  u8g2.print("%");

  u8g2.setCursor(7, 45); // 提示按键
  u8g2.print("Enter to confirm");

  u8g2.sendBuffer();
}

void displaySetWetLow() {
  u8g2.clearBuffer();

  u8g2.setCursor(7, 15); // 指定显示位置
  u8g2.print("Set Low Hum:");

  u8g2.setCursor(7, 30); // 显示低温
  u8g2.print("Low: ");
  u8g2.print(WetLow);
  u8g2.print("%");

  u8g2.setCursor(7, 45); // 提示按键
  u8g2.print("Enter to confirm");

  u8g2.sendBuffer();
}