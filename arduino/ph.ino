#define VREF 5.0        // Reference voltage for ADC (use 3.3V if applicable)
#define SAMPLES 10      // Number of samples for averaging
#define TEMP_COEFF 0.03 // Temperature coefficient (approximate)

float ph_offset = 0.0;      // Offset for calibration
float pHValue = 7.0;

int readPHRaw(){
    int rawValue = 0;
    for (int i = 0; i < SAMPLES; i++)
    {
        rawValue += analogRead(PH_PIN);
        delay(10);
    }
    return rawValue / SAMPLES; // return average
}

float phRawToVoltage(int rawValue){
    return (rawValue / 1023.0) * VREF;
}

float voltageToPH(float voltage){
    float pHValue = 7.0 + ((2.5 - voltage) * 3.5) + ph_offset;
    return pHValue;
}

// Apply temperature compensation)
float compensatePH(float pH, float temp){
    return pH - TEMP_COEFF * (temp - 25.0);
}

void calibratePH() {
  Serial.println("Place in pH 7 buffer.");
  int countdown = 6;
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
  float ph_offset = 7 - pHValue;
  
  SystemConfig["ph_offset"] = ph_offset;
  Serial.print("One pint(pH:7) Caliberation done! Offset: "); Serial.println(ph_offset);
  delay(2000);
}

float getPH(){
  int raw = readPHRaw();
  float voltage  = phRawToVoltage(raw);
  float ph = voltageToPH(voltage);
  float temp = getTemp();
  float compPH = compensatePH(ph, temp);

  return compPH;
}

void setupPH()
{
    pinMode(PH_PIN, INPUT);
    Serial.println("[INIT] pH Sensor Initialized.");
}
