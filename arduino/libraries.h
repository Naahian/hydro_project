#ifndef ARDUINO_H
#define ARDUINO_H

/** libraries **/
#include <ArduinoJson.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <Adafruit_INA219.h>
#include <BluetoothSerial.h>


/** Global Constants **/
BluetoothSerial SerialBT;
StaticJsonDocument<640> incomingDoc;          // Buffer for parsing input
DynamicJsonDocument SystemConfig(640);        // Enough for your JSON
DynamicJsonDocument SystemStatus(256);         // Small: just status flags

const String TYPE_LEAFY = "leafy";
const String TYPE_FRUITY = "fruity";

const String STAGE_SEED = "seed";
const String STAGE_GROWTH = "growth";
const String STAGE_FRUIT = "fruit";


/** Temp Sensor **/
void setupTempSensor();
float getTemp();


/** TDS Sensor **/
int readTDSRaw();
float tdsRawToVoltage(int rawValue);
float voltageToTDS(float voltage);
float tdsToEC(float tds);
float getEC();
void setupTDS();


/** pH Sensor **/
int readPHRaw();
float phRawToVoltage(int rawValue);
float voltageToPH(float voltage);
float compensatePH(float pH, float temp);
void setupPH();
float getPH();
void calibratePH();


/** Data **/
void readSensorData();
void initSystemStatus();
void initSystemConfig(float temp, float ec, float ph, 
                     float ph_lower, float ph_upper,
                     float ec_lower, float ec_upper,
                     String type, String stage, float solution_ratio);
void processInput();
void printSystemStatus();
void printSystemConfig();
double round2(double value);


/** Current Sensor **/ 
Adafruit_INA219 ina219;
void setupCurrentSensor();
void readCurrentSensor();


/** System Adjust Functions **/
void adjustPH();
void adjustPH();

/** Acuators:Motors, relays, pumps etc. **/
void setupRelay();
void relayPumpOn();
void relayPumpOff();
void relayProbeOn();
void relayProbeOff();

#endif
