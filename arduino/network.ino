#include <ArduinoJson.h>
#include <SoftwareSerial.h>

#define BT_BaudRate 9600

DynamicJsonDocument sensorData(256);
DynamicJsonDocument configData(256);
SoftwareSerial BTSerial(5, 6);  // TX, RX

// JSON Serialization
String getSensorData() {
  String output;
  serializeJson(sensorData, output);
  return output;
}

String getConfigData() {
  String output;
  serializeJson(configData, output);
  return output;
}

// Bluetooth   
String readBT() {
 if (BTSerial.available()) {
    String data = BTSerial.readString();
    Serial.println("[BT] Recieved: " + data);
  }
  return "";
}

void writeBT(String text) {
  Serial.println("[BT] Sending: " + text);
  BTSerial.println(text);
}

// Tests
void testBluetooth() {
  Serial.println("[TEST] Bluetooth Test Started");
  writeBT("Bluetooth Test Message");
  Serial.println("[TEST] send JsonData test.");
  writeBT(getSensorData());
  delay(1000);
  Serial.println("[TEST] Check if message is received via Bluetooth.");
}

void testJsonSerialization() {
  Serial.println("[TEST] JSON Serialization Test");

  // Sample sensor data
  sensorData["name"] = "dummy_sensor_data";
  sensorData["temperature"] = 30.5;
  sensorData["humidity"] = 60.5;
  sensorData["ph"] = 6.5;

  // Sample config data
  configData["name"] = "dummy_config_data";
  sensorData["temperature"] = 25.5;
  sensorData["humidity"] = 50;
  sensorData["ph"] = 7;

  Serial.println("[TEST] Sensor Data JSON: " + getSensorData());
  Serial.println("[TEST] Config Data JSON: " + getConfigData());
}

void setupNetwork() {
  Serial.println("[NETWORK] Initializing...");
  BTSerial.begin(BT_BaudRate);  // Bluetooth module baud rate
  // Run tests
  testJsonSerialization();
  testBluetooth();

  Serial.println("[NETWORK] Ready.");
}

void loopNetwork() {
  String btMsg = readBT();
  if (btMsg.length() > 0) {
    Serial.println("[BT] Processing: " + btMsg); 
    writeBT("Echo: " + btMsg);
  }
  else if(Serial.available()){
    String msg = Serial.readString();
    Serial.println("[BT] Processing: " + msg); 
    writeBT(msg);
  }
  delay(500);
}

void changeBTBaudrate(){

}

// check if bluetooth Module Working

// #include <SoftwareSerial.h>

// SoftwareSerial BTSerial(5, 6);  // RX, TX

// void setup() {
//   Serial.begin(19200);  // For debugging
//   BTSerial.begin(9600);  // Bluetooth module baud rate

//   Serial.println("Bluetooth Ready!");
// }

// void loop() {
//   if (BTSerial.available()) {
//     String data = BTSerial.readString();
//     Serial.println("[Received]: " + data);
//   }
  
//   if (Serial.available()) {
//     String msg = Serial.readString();
//     Serial.println("[Sent]: " + msg);
//     BTSerial.println(msg);
//   }
// }
