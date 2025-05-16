
#define VREF 5.0         // Reference voltage for ADC (use 3.3V if applicable)
#define SAMPLES 10       // Number of samples for averaging
#define TEMP_COEFF 0.03  // Temperature coefficient (approximate)

float pH_Offset = 0.0;      // Offset for calibration
float pHValue = 7.0;

int readPHRaw() {
    int rawValue = 0;
    for (int i = 0; i < SAMPLES; i++) {
        rawValue += analogRead(PH_PIN);
        delay(10);
    }
    return rawValue / SAMPLES;  // Return averaged value
}

float phRawToVoltage(int rawValue) {
    return (rawValue / 1023.0) * VREF;
}

float voltageToPH(float voltage) {
    float pHValue = 7.0 + ((2.5 - voltage) * 3.5) + pH_Offset;
    return pHValue;
}

float readVoltage(int pin) {
    int raw = 0;
    for (int i = 0; i < SAMPLES; i++) {
        raw += analogRead(pin);
        delay(10);
    }
    return (raw / (float)SAMPLES) * (VREF / 1023.0);  // Convert ADC to voltage
}

// Apply temperature compensation)
float compensatePH(float pH, float temp) {
    return pH - TEMP_COEFF * (temp - 25.0);
}

void calibratePH() {
  Serial.println("Place Probe in pH-7 buffer.");
  int countdown = 8;
  Serial.print("Caliberation starts in..");
  while(countdown--){
    Serial.print("...");
    Serial.print(countdown);
    delay(1000);
  }
  Serial.println();
  
  int rawValue = readPHRaw();
  float voltage = phRawToVoltage(rawValue);
  pHValue = voltageToPH(voltage);
  pH_Offset = 7 - pHValue;
  
  Serial.print("One pint(pH:7) Caliberation done! Offset: "); Serial.println(pH_Offset);
  delay(2000);
}

float getPH(){
        
    float temperature = getTemp();   // Assuming its 25
    int raw = readPHRaw();
    int rawValue = readPHRaw();
    float voltage = phRawToVoltage(rawValue);
    pHValue = voltageToPH(voltage);
    float pHCompensated = compensatePH(pHValue, temperature);

  return pHCompensated;
}

void testPH() {
    Serial.println("[TEST] Reading pH Sensor...");

    float temperature = getTemp();   // Assuming its 25
    int rawValue = readPHRaw();
    float voltage = phRawToVoltage(rawValue);
    pHValue = voltageToPH(voltage);
    float pHCompensated = compensatePH(pHValue, temperature);

    // Detect invalid readings
    if (rawValue < 10) {
        Serial.println("[ERROR] pH Sensor not detected!");
    } else {
        Serial.print("[TEST] Raw ADC: "); Serial.print(rawValue);
        Serial.print(" | Voltage: "); Serial.print(voltage, 2);
        Serial.print("V | pH: "); Serial.print(pHValue, 2);
        Serial.print(" | Compensated pH: "); Serial.println(pHCompensated, 2);
    }
}

void setupPH() {
    pinMode(PH_PIN, INPUT);
    Serial.println("[INIT] pH Sensor Initialized.");
    calibratePH();
    delay(1000);
}


void loopPH() {
    testPH();
    delay(2000);  
}
