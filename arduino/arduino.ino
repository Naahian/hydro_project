#include "arduino.h"

//pins
#define TEMP_PIN A2
#define TDS_PIN A7  
#define PH_PIN A0    

// WARNING: Remove bluetooth TX,RX pins when uploading.

void setup(){
  Serial.begin(9600);
  Serial.println("*********** Vertical Hydroponic System ***********");

  setupTempSensor();
  setupPH();
  setupTDS();

  writeConfigData(25, 150, 7.0, TYPE_LEAFY, STAGE_SEED);
  calibratePH();


}


void loop(){  
  readSensorData();
  String sensordata = getSensorData();
  Serial.println(sensordata); 
  
}



  /** TODO:
   * create and init motor/actuators
   * irrigate with pump
   * mix with motor
   * dosing pump, store total dosage in new JsonDocument and send via network.
   * sensor array with servo + ph sensor water spray
   * complete adjust functions 
   * ...
  **/

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