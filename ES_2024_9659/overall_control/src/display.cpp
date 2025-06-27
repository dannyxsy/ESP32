#include "display.h"
#include "wificonnected.h"

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE, /* clock=*/22, /* data=*/21);

Page currentPage = MAIN_MENU;

int tempHigh = 0;
int tempLow = 0;
int WetHigh = 0;
int WetLow = 0;
int FANNUM =0;
int CO2Low = 0;
int CO2High =0;
void displayMainMenu() {
  u8g2.clearBuffer();

  u8g2.setCursor(7, 15); // 指定显示位置
  u8g2.print("A. Temperature");

  u8g2.setCursor(7, 30); // 指定显示位置
  u8g2.print("B. Humidity");

  u8g2.setCursor(7, 45); // 指定显示位置
  u8g2.print("C. CO2");

  u8g2.setCursor(7, 60); // 指定显示位置
  u8g2.print("D. Auto Control");

  u8g2.sendBuffer();
}




void handleInput(char key) {
  if (key >= '0' && key <= '9') {
    switch (currentPage)
    {
    case SET_TEMPERATURE_HIGH:
     tempHigh = tempHigh * 10 + (key - '0');
        /* code */
        break;
    case SET_TEMPERATURE_LOW:
      tempLow = tempLow * 10 + (key - '0');
        /* code */
        break;
    case SET_WET_HIGH:
     WetHigh = WetHigh* 10 + (key - '0');
        /* code */
        break;
    case SET_WET_LOW:
      WetLow = WetLow* 10 + (key - '0');
        /* code */
        break;
    // case SET_ALL_CONTROL:
    //     FANNUM = 4-'0';
    //     break;
    case SET_CO2_LOW:
      CO2Low = CO2Low* 10 + (key - '0');
        /* code */
        break;
    case SET_CO2_HIGH:
      CO2High = CO2High* 10 + (key - '0');
        /* code */
        break;
    }
  } else if (key == '#') { 
    // 使用 '#' 键来确认设置
    switch (currentPage)
    {
    case SET_TEMPERATURE_HIGH:
     currentPage = SET_TEMPERATURE_LOW;
        /* code */
        break;
    case SET_TEMPERATURE_LOW:
     currentPage = MAIN_MENU;
     sendTempToMultipleServers(tempHigh,tempLow);
     
     
        /* code */
        break;
    case SET_WET_HIGH:
     currentPage = SET_WET_LOW;
        /* code */
        break;
    case SET_WET_LOW:
    currentPage = MAIN_MENU;
    sendHumToMultipleServers(WetHigh, WetLow);
    
        /* code */
        break;
    case SET_ALL_CONTROL:
     currentPage = MAIN_MENU;
        /* code */
        break;
     case SET_CO2_LOW:
     currentPage = MAIN_MENU;
        /* code */
        break;
      case SET_CO2_HIGH:
     currentPage = SET_CO2_LOW;
        /* code */
        break;
    
    }
  } else if (key == '*') { 
    // 使用 '*' 键来重置当前设置
     switch (currentPage)
    {
    case SET_TEMPERATURE_HIGH:
        tempHigh= 0;
        /* code */
        break;
    case SET_TEMPERATURE_LOW:
        tempLow = 0;
        /* code */
        break;
    case SET_WET_HIGH:
        WetHigh = 0;
        /* code */
        break;
    case SET_WET_LOW:
        WetLow = 0;
        /* code */
        break;
    case SET_ALL_CONTROL:
        FANNUM = 0;
        /* code */
        break;
    case SET_CO2_LOW:
        CO2Low = 0;
        /* code */
        break;
    case SET_CO2_HIGH:
        CO2High = 0;
        /* code */
        break;
    
  }
}
}