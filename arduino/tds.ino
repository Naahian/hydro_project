#define TDS_PIN A1     // Analog pin for TDS sensor
#define VREF 5.0       // Reference voltage for ADC (change if using 3.3V)
#define SAMPLES 10     // Number of samples for averaging
#define TEMP_COEFF 0.02 // Compensation factor per °C


int readTDSRaw() {
    int rawValue = 0;
    for (int i = 0; i < SAMPLES; i++) {
        rawValue += analogRead(TDS_PIN);
        delay(10);
    }
    return rawValue / SAMPLES;  // Return averaged value
}

float tdsRawToVoltage(int rawValue) {
    return (rawValue / 1023.0) * VREF;
}

float voltageToTDS(float voltage) {
    float tdsValue = (133.42 * voltage * voltage * voltage - 
                      255.86 * voltage * voltage + 
                      857.39 * voltage) * (1.0 + TEMP_COEFF * (temperature - 25.0));
    return tdsValue;
}

float tdsToEC(float tds) {
    return tds * 0.5;
}

void setupTDS() {
    pinMode(TDS_PIN, INPUT);
    Serial.println("[INIT] TDS Sensor Initialized.");
}

void testTDS() {
    Serial.println("[TEST] Reading TDS Sensor...");
    
    int rawValue = readTDSRaw();
    float voltage = tdsRawToVoltage(rawValue);
    float tdsValue = voltageToTDS(voltage);
    float ecValue = tdsToEC(tdsValue);
    
    // Detect invalid readings
    if (rawValue < 10) {
        Serial.println("[ERROR] TDS Sensor not detected!");
    } else {
        Serial.print("[TEST] Raw ADC: "); Serial.print(rawValue);
        Serial.print(" | Voltage: "); Serial.print(voltage, 2);
        Serial.print("V | TDS: "); Serial.print(tdsValue, 2);
        Serial.print(" ppm | EC: "); Serial.print(ecValue, 2);
        Serial.println(" µS/cm");
    }
}

void loopTDS() {
    testTDS();
    delay(2000); 
}
