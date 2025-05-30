void setupCurrentSensor() {
  Serial.println("[INIT] Initializing INA219 Current Sensor...");

  if (!ina219.begin()) {
    Serial.println("[WARN] Trying alternative address 0x41...");
    if (!ina219.begin(0x41)) {
      Serial.println("[ERROR] Failed to find INA219 chip at either address");
    }
  }else{
    Serial.println("[INIT] INA219 Sensor Initialized.");
  }
}

void readCurrentSensor() {
  float power_mW = ina219.getPower_mW();
  SystemStatus["power(mW)"] = power_mW;
}
