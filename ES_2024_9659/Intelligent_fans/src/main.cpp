#include "extern.h"
#include "physical.h"
#include "temperature.h"
void setup() {
      th_s();
     automatic_FAN_s();
     physcicalS();
     

}

void loop() {
   
   physcicalL();
   automatic_FAN_l();
   th_l();
 
}

