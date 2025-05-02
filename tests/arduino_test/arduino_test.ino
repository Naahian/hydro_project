#include "arduino_test.h"

// *** current pin config ***

#define TEMP_PIN A6
#define TDS_PIN A7  
#define PH_PIN A0        

void testRaw();

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
  loopNetwork();
  if(Serial.available()){
    String input = Serial.readString();
    writeBT(input);
  }
  loopTempSensor();
  // loopTDS();
  // loopPH();
  // testRaw();

}

void testRaw(){
  int tempRAW = analogRead(A6);
  int tdsRAW = analogRead(A7);
  int phRAW = analogRead(A0);

  Serial.print("temp:"); Serial.print(tempRAW);
  Serial.print(" tds:"); Serial.print(tdsRAW); 
  Serial.print(" ph:"); Serial.println(phRAW);  
  delay(2000);
}