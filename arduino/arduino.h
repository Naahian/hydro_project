#ifndef ARDUINO_H
#define ARDUINO_H

/** common **/
#include <ArduinoJson.h>

/** Constants **/
DynamicJsonDocument SystemStatus(128);
DynamicJsonDocument SystemConfig(128);
// float temperature = 25.0; // Assuming its 25
const String TYPE_LEAFY = "leafy";
const String TYPE_FRUITY = "fruity";

const String STAGE_SEED = "seed";
const String STAGE_GROWTH = "growth";
const String STAGE_FRUIT = "fruit";

/** network **/
#include <SoftwareSerial.h>

void setupNetwork();

String readBT();
void writeBT(String text);

/** Temp Sensor **/
#include <OneWire.h>
#include <DallasTemperature.h>

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
#include <Wire.h>
#include <Adafruit_INA219.h>

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
