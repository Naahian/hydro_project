  /** TODO:
   * create and init motor/actuators
   * irrigate with pump
   * mix with motor
   * dosing pump, store total dosage in new JsonDocument and send via network.
   * sensor array with servo + ph sensor water spray
   * complete adjust functions 
   * ...
  **/

#include "arduino.h"

void setup(){
  Serial.begin(19200);
  Serial.println("*********** Hydro_Project ***********");
  
  setupTempSensor();
  setupPH();
  setupTDS();
  setupNetwork();

  writeConfigData(25, 150, 7.0, TYPE_LEAFY, STAGE_SEED);
  calibratePH();

}

void loop(){  
  readSensorData();
  String sensordata = getSensorData();
  String configdata = getConfigData();
  writeBT(sensordata);
  
  adjustPH();
  adjustEC();
  adjustTemp();

  delay(2000);
}


void adjustPH(){
  if(sensorData["ph"] < configData["ph"]){
    //dose Solution A
  }
  else if(sensorData["ph"] > configData["ph"]){
    //dose Solution B
  }
}

void adjustEC(){
  if(sensorData["ec"] < configData["ec"]){
    //dose Solution A + Solution B (according to ratio)
  }
  else if(sensorData["ec"] > configData["ec"]){
    //dose water
  }
}

void adjustTemp(){
  if(sensorData["temp(C)"] < configData["temp(C)"]){
    
  }
  else if(sensorData["temp(C)"] > configData["temp(C)"]){
    
  }
}

/*
start
    --> init sensors  (done)
    --> init actuators
    --> load/init target values (done)
    loop
        --> start sensing(temp -> tds -> ph -> current)   (done)
        --> store reading values  (done)
        --> compare with target
        --> adjust via actuators(dosing pump(solution, water), mixing motor)

*/