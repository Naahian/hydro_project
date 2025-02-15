#ifndef ARDUINO_TEST_H
#define ARDUINO_TEST_H

/** common **/
float temperature = 25.0;   // Assuming its 25

/** network **/
#include <ArduinoJson.h>
#include <SoftwareSerial.h>

void setupNetwork();
void loopNetwork();
String getSensorData();
String getConfigData();
String readBT();
void writeBT(String text);

/** temp sensor **/
#include <OneWire.h>
#include <DallasTemperature.h>

void testTempSensor();
void setupTempSensor();
void loopTempSensor();

/** tds sensor **/
int readTDSRaw();
float tdsRawToVoltage(int rawValue);
float voltageToTDS(float voltage);
float tdsToEC(float tds);
void testTDS();
void setupTDS();
void loopTDS();

/** ph sensor **/
int readPHRaw();
float phRawToVoltage(int rawValue);
float voltageToPH(float voltage);
float compensatePH(float pH, float temp);
void testPH();
void setupPH();
void loopPH();


#endif
