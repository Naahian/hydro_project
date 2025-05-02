float busVoltage = 0;
float shuntVoltage = 0;
float current_mA = 0;
float power_mW = 0;


void setupCurrentSensor() {
  Serial.println("[INIT] Initializing INA219 Current Sensor...");

  if (!ina219.begin()) {
    Serial.println("[ERROR] Failed to find INA219 chip");
    while (1) { delay(10); }
  }

  Serial.println("[INIT] INA219 Sensor Initialized.");
}

void readCurrentSensor() {
  shuntVoltage = ina219.getShuntVoltage_mV();
  busVoltage = ina219.getBusVoltage_V();
  current_mA = ina219.getCurrent_mA();
  power_mW = ina219.getPower_mW();

  Serial.print("[INA219] Bus Voltage: "); Serial.print(busVoltage); Serial.println(" V");
  Serial.print("[INA219] Shunt Voltage: "); Serial.print(shuntVoltage); Serial.println(" mV");
  Serial.print("[INA219] Current: "); Serial.print(current_mA); Serial.println(" mA");
  Serial.print("[INA219] Power: "); Serial.print(power_mW); Serial.println(" mW");
}
