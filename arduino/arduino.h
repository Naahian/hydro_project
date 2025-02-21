#ifndef ARDUINO_H
#define ARDUINO_H

/** common **/
#include <ArduinoJson.h>

float temperature = 25.0; // Assuming its 25
DynamicJsonDocument sensorData(256);
DynamicJsonDocument configData(256);

/** Constants **/
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

/** temp sensor **/
#include <OneWire.h>
#include <DallasTemperature.h>

void setupTempSensor();
float getTemp();

/** tds sensor **/
int readTDSRaw();
float tdsRawToVoltage(int rawValue);
float voltageToTDS(float voltage);
float tdsToEC(float tds);
float getEC();
void setupTDS();

/** ph sensor **/
int readPHRaw();
float phRawToVoltage(int rawValue);
float voltageToPH(float voltage);
float compensatePH(float pH, float temp);
void setupPH();
float getPH();
void calibratePH();

/** data **/
void readSensorData();
void writeConfigData(float temp, float ec, float ph, String type, String stage);
String getSensorData();
String getConfigData();

#endif
