#include "arduino_test.h"

void setup() {
  Serial.begin(19200);
  Serial.println("************** TEST Hydro_Project ***************");
  
  setupNetwork();
  setupTempSensor();
  setupTDS();
  setupPH();
  
  pinMode(A0, INPUT);
  
}

void loop(){
  // loopNetwork();
  // loopTempSensor();
  // loopTDS();
  // loopPH();

}

void testRaw(){
  int tempRAW = analogRead(A0);
  int tdsRAW = analogRead(A1);
  int phRAW = analogRead(A2);

  Serial.print("temp:"); Serial.print(tempRAW);
  Serial.print(" tds:"); Serial.print(tdsRAW); 
  Serial.print(" ph:"); Serial.println(phRAW);  
  delay(2000);
}