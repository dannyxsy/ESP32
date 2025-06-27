#include <Arduino.h>
#include <U8g2lib.h>
#include "display.h"
#include "wificonnected.h"
// put function declarations here:
int myFunction(int, int);
//定义行引脚数组
int row_pins[4]={13,12,14,27};
//定义列引脚数组
int col_pins[4]={26,25,33,32};
char key;


char read_keypad(){
  char keys[4][4]={
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'},
  };
  for(int j=0;j<4;j++){
    digitalWrite(col_pins[j],LOW);
    for(int i=0;i<4;i++){
      if(!digitalRead(row_pins[i])){
        return keys[i][j];
      }
    }
    digitalWrite(col_pins[j],HIGH);
  }
  return '\0';
}





void setup() {

  ConnectWifiS();
  u8g2.begin();
  u8g2.enableUTF8Print();
  for(int i=0;i<4;i++){
    pinMode(row_pins[i],INPUT_PULLUP);
    pinMode(col_pins[i],OUTPUT);
    digitalWrite(col_pins[i],HIGH); 
  }
  
}
//获取按键值函数

void loop() {

  // ConnectWifiL();
  // put your main code here, to run repeatedly:
  key=read_keypad();
  u8g2.setFont(u8g2_font_unifont_t_symbols);

if (key) {
    if (currentPage == MAIN_MENU && key == 'A') {
      currentPage = SET_TEMPERATURE_HIGH;
     
    } 
    else if(currentPage == MAIN_MENU && key == 'B')
    {
      currentPage = SET_WET_HIGH;
    }
    else if(currentPage == MAIN_MENU && key == 'C')
    {
      currentPage = SET_CO2_HIGH;
    }
    else if(currentPage == MAIN_MENU && key == 'D')
    {
      currentPage = SET_ALL_CONTROL;
    }
    else{
      handleInput(key);
    }
    
  }


  switch (currentPage)
  {
  case  SET_TEMPERATURE_HIGH:
      displaySetTemperatureHigh();
    /* code */
    break;
   case  SET_TEMPERATURE_LOW:
      displaySetTemperatureLow();
    /* code */
    break;
    case  SET_WET_HIGH:
      displaySetWetHigh();
    /* code */
    break;
    case  SET_WET_LOW:
      displaySetWetLow();
    /* code */
    break;
     case  SET_ALL_CONTROL:
      displaySetFanNum();
    /* code */
    break;
    case  SET_CO2_LOW:
      displaySetCO2Low();
      break;
    case  SET_CO2_HIGH:
      displaySetCO2High();
    /* code */
    break;
    /* code */


  default:
  displayMainMenu();
    break;
  }

  delay(200); // 添加延迟以避免抖动



}



