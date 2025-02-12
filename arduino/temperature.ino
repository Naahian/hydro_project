#include <OneWire.h>
#include <DallasTemperature.h>

#define TEMP_PIN A0  

OneWire oneWire(TEMP_PIN);
DallasTemperature tempSensor(&oneWire);

void setupTempSensor() {
    tempSensor.begin();
    Serial.println("[INIT] Temperature Sensor Initialized.");
}

void testTempSensor() {
    Serial.println("[TEST] Requesting temperature...");
    tempSensor.requestTemperatures();
    float tempC = tempSensor.getTempCByIndex(0);
    
    if (tempC == DEVICE_DISCONNECTED_C) {  // Check if the sensor is disconnected
        Serial.println("[ERROR] Temperature Sensor not detected!");
    } else {
        Serial.print("[TEST] Temp(C): ");
        Serial.println(tempC);
    }
}

void loopTempSensor() {
    testTempSensor();
    delay(2000);
}
