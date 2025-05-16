#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(TEMP_PIN);
DallasTemperature tempSensor(&oneWire);

void setupTempSensor()
{
    tempSensor.begin();
    Serial.println("[INIT] Temperature Sensor Initialized.");
}

float getTemp()
{   
    tempSensor.requestTemperatures();
    return tempSensor.getTempCByIndex(0);
}

void testTempSensor() {
    Serial.println("[TEST] Requesting temperature...");


    float tempC = getTemp();
    float temperature = getTemp();   // Assuming its 25

    if (tempC == DEVICE_DISCONNECTED_C) {  // Check if the sensor is disconnected
        Serial.println("[ERROR] Temperature Sensor not detected!");
    } else {
        Serial.print("[TEST] Temp(C): ");
        Serial.println(tempC);
        temperature = tempC;
    }
}

void loopTempSensor() {
    testTempSensor();
    delay(2000);
}
