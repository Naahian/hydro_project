

void readSensorData(){
  
  float temp = getTemp();
  delay(100);
  float ec = getEC();
  delay(100);
  float ph = getPH();


  SystemStatus["temp(C)"] = temp;
  SystemStatus["ec"] = ec;
  SystemStatus["ph"] = ph;

  delay(800); //100+100+800 completing full 1 second delay
}


void initSystemStatus(){
  SystemStatus["name"] = "System_Status";
  SystemStatus["solution_A_pump"] = false;
  SystemStatus["solution_B_pump"] = false;
  SystemStatus["sensing"] = false;
  SystemStatus["water_pump"] = false;
  SystemStatus["temp(C)"] = -1;
  SystemStatus["ec"] = -1;
  SystemStatus["ph"] = -1;
}


void initSystemConfig(
  float temp, float ec, float ph, 
  float ph_lower, float ph_upper, 
  float ec_lower, float ec_upper,
  String type, String stage, float solution_ratio
  ){
  
  Serial.println("[INIT] Setting Config Data...");
  //TODO: check for config from sd card
  if(SystemConfig.isNull()){
  SystemConfig["name"] = "System_Config";
  SystemConfig["temp(C)"] = round2(temp);
  SystemConfig["solution_ratio"] = solution_ratio;
  SystemConfig["ec_lower"] = 1.0;    // Example lower EC bound (adjust as needed)
  SystemConfig["ec_upper"] = 2.4;    // Example upper EC bound (adjust as needed)
  SystemConfig["ph_lower"] = 5.5;    // Example lower pH bound (adjust as needed)
  SystemConfig["ph_upper"] = 6.5;    // Example upper pH bound (adjust as needed)
  SystemConfig["sensor_on_duration"] = 7000;  // Sense for 7 sec duration
  SystemConfig["sensor_on_interval"] = 14000;  // Start sensing every 14 sec
  SystemConfig["type"] = type;
  SystemConfig["stage"] = stage;
  
  calibratePH();  //to set SystemConfig["ph_offset"] data
  }
}


void processInput(){
if (Serial.available()) {
    // 1. Read input (with timeout)
    String input = Serial.readStringUntil('\n');
    input.trim(); // Remove whitespace/newlines
    
    StaticJsonDocument<200> doc;
    DeserializationError error = deserializeJson(doc, input);   
    if (error) {
      Serial.print(F("JSON error: "));
      Serial.println(error.c_str());
      Serial.print(F("Input was: \""));
      Serial.print(input);
      Serial.println("\"");
    } else {
      Serial.print(doc["temp"].as<float>());
    }
    Serial.println("-----");
  }
}


// JSON Serialization
void printSystemStatus(){
  serializeJsonPretty(SystemStatus, Serial);
  Serial.println();
}

void printSystemConfig(){
  serializeJsonPretty(SystemConfig, Serial);
  Serial.println();
}

double round2(double value) {
   return (int)(value * 100 + 0.5) / 100.0;
}