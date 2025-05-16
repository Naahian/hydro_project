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
