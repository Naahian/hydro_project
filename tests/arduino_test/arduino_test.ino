#include "arduino_test.h"

void setup() {
  Serial.begin(19200);
  Serial.println("************** TEST Hydro_Project ***************");
  
  setupNetwork();
  // setupTDS();
  setupTempSensor();
  // setupPH();
  
}

void loop(){
  loopNetwork();
  // loopTDS();
  // loopTempSensor();
  // loopPH();
}