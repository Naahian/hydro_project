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