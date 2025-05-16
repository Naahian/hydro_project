#include <ArduinoJson.h>


DynamicJsonDocument sensorData(256);
DynamicJsonDocument configData(256);

String getSensorData() {
  String output;
  serializeJson(sensorData, output);
  return output;
}

String getConfigData() {
  String output;
  serializeJson(configData, output);
  return output;
}

void readSensorData(){
  
  float temp = getTemp();
  delay(100);
  float ec = getEC();
  delay(100);
  float ph = getPH();

  sensorData["name"] = "sensor_data";
  sensorData["temp(C)"] = temp;
  sensorData["ec"] = ec;
  sensorData["ph"] = ph;

  
  delay(800); //completing full 1 second delay
}


void testJsonSerialization() {
  Serial.println("[TEST] JSON Serialization Test");

  // Sample sensor data
  configData["name"] = "dummy_config_data";
  configData["temperature"] = 30.5;
  configData["humidity"] = 60.5;
  configData["ph"] = 6.5;

  // Sample config data
  sensorData["name"] = "dummy_sensor_data";
  sensorData["temp(C)"] = 25.5;
  sensorData["humidity"] = 50;
  sensorData["ph"] = 7;

  Serial.println("[TEST] Sensor Data JSON: " + getSensorData());
  Serial.println("[TEST] Config Data JSON: " + getConfigData());
}

void setupNetwork() {
  Serial.println("[NETWORK] Initializing...");
  testJsonSerialization();
  Serial.println("[NETWORK] Ready.");
}


