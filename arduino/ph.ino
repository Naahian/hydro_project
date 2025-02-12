#define PH_PIN A2        // Analog pin for pH sensor
#define VREF 5.0         // Reference voltage for ADC (use 3.3V if applicable)
#define SAMPLES 10       // Number of samples for averaging
#define TEMP_COEFF 0.03  // Temperature coefficient (approximate)
#define pH_Offset 0.00   // Calibration offset (adjust based on calibration solution)


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

// Apply temperature compensation)
float compensatePH(float pH, float temp) {
    return pH - TEMP_COEFF * (temp - 25.0);
}

void setupPH() {
    pinMode(PH_PIN, INPUT);
    Serial.println("[INIT] pH Sensor Initialized.");
}

void testPH() {
    Serial.println("[TEST] Reading pH Sensor...");

    int rawValue = readPHRaw();
    float voltage = phRawToVoltage(rawValue);
    float pHValue = voltageToPH(voltage);
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

void loopPH() {
    testPH();
    delay(2000);  
}
