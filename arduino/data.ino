void readSensorData(){
  float temp = getTemp();
  float ec = getEC();
  float ph = getPH();
  
  sensorData["name"] = "sensor_data";
  sensorData["temp(C)"] = round2(temp);
  sensorData["ec"] = round2(ec);
  sensorData["ph"] = round2(ph);
}

void writeConfigData(float temp, float ec, float ph, String type, String stage){
  Serial.println("Setting Config Data...");

  configData["name"] = "config_data";
  configData["temp(C)"] = round2(temp);
  configData["ec"] = round2(ec);
  configData["ph"] = round2(ph);
  configData["type"] = type;
  configData["stage"] = stage;

  String configData = getConfigData();
  Serial.println(configData);
}

// JSON Serialization
String getSensorData(){
  String output;
  serializeJson(sensorData, output);
  return output;
}

String getConfigData(){
  String output;
  serializeJson(configData, output);
  return output;
}

double round2(double value) {
   return (int)(value * 100 + 0.5) / 100.0;
}