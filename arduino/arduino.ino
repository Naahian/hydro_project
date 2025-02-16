#include "arduino.h"

void setup(){
  Serial.begin(19200);
  Serial.println("*********** Hydro_Project ***********");
  
  setupTempSensor();
  setupPH();
  setupTDS();
  setupNetwork();
  //TODO: create and init motor/actuators

  writeConfigData(25, 150, 7.0, TYPE_LEAFY, STAGE_SEED);
  calibratePH();

}

void loop(){  
  readSensorData();
  String sensorData = getSensorData();
  String configData = getConfigData();
  writeBT(sensorData);
  /**
  TODO:
    - compare sensor and config data
    - dosing, mixing, watering to adjust
  **/

  delay(2000);
}




/*
start
    -done-> init sensors
    --> init actuators
    -done-> load/init target values
    loop
        -done-> start sensing(temp -> tds -> ph -> current)
        -done-> store reading values
        --> compare with target
        --> adjust via actuators(dosing pump(solution, water), mixing motor)

*/