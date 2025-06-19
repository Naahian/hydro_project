#include "arduino.h"

// WARNING: Remove bluetooth TX,RX pins when uploading.
//pins
#define TEMP_PIN A2
#define TDS_PIN A7  
#define PH_PIN A0    
#define relayPump_PIN 4
#define relaySensor_PIN 2

//global constants
unsigned long previousMillis = 0;  // Tracks last state change


void setup(){
  Serial.begin(9600);
  Serial.println("*********** Vertical Hydroponic System ***********");
  
  setupRelay();
  relaySensorOn();  
  initSystemConfig(25.3, 1.8, 6.2, 5.5, 6.5, 1.0, 2.4, "leafy", "seed", 0.5);
  printSystemConfig();
  calibratePH();  //to set SystemConfig["ph_offset"] data
  initSystemStatus();
  
  setupTempSensor();
  setupPH();
  setupTDS();
  // setupCurrentSensor();
  // delay(100);

  relaySensorOff();
  delay(1000);
}


void loop(){ 
  //check and process incoming data from BT
  processInput();
  unsigned long currentMillis = millis();


  // sense every X second for Y duration.
  // for example, sense every 12 hours for 1 min.
  unsigned long onDuration = SystemConfig["sensor_on_duration"].as<unsigned long>();
  unsigned long interval = SystemConfig["sensor_on_interval"].as<unsigned long>();
  bool isSensing = SystemStatus["sensing"].as<bool>();
  
  if (currentMillis - previousMillis >= (isSensing ?  onDuration : (interval -  onDuration))) {
    previousMillis = currentMillis;
    SystemStatus["sensing"] = !SystemStatus["sensing"];     // Toggle state
 }

  if (SystemStatus["sensing"]) {
      relaySensorOn();
      delay(100);            
      readSensorData();     //takes around 1sec delay
      printSystemStatus();
      // adjustPH();
      // adjustEC();
    } else{
      relaySensorOff();           
    }
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