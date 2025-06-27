#include "display.h"
void displaySetCO2High() {
  u8g2.clearBuffer();

  u8g2.setCursor(8, 15); // 指定显示位置
  u8g2.print("Set High CO2:");

  u8g2.setCursor(8, 30); // 显示高温
  u8g2.print("High: ");
  u8g2.print(CO2High);
  u8g2.print("PPM");

  u8g2.setCursor(8, 45); // 提示按键
  u8g2.print("Enter to confirm");

  u8g2.sendBuffer();
}

void displaySetCO2Low() {
  u8g2.clearBuffer();

  u8g2.setCursor(8, 15); // 指定显示位置
  u8g2.print("Set Low CO2:");

  u8g2.setCursor(8, 30); // 显示低温
  u8g2.print("Low: ");
  u8g2.print(CO2Low);
  u8g2.print("PPM");


  u8g2.setCursor(8, 45); // 提示按键
  u8g2.print("Enter to confirm");

  u8g2.sendBuffer();
}