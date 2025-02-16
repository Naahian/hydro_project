#include <ArduinoJson.h>
#include <SoftwareSerial.h>

#define BT_BaudRate 9600
SoftwareSerial BTSerial(5, 6); // TX, RX

// Bluetooth
String readBT(){
  if (BTSerial.available())
  {
    String data = BTSerial.readString();
    Serial.println("[BT] Recieved: " + data);
  }
  return "";
}

void writeBT(String text){
  Serial.println("[BT] Sending: " + text);
  BTSerial.println(text);
}

void setupNetwork(){
  Serial.println("[NETWORK] Initializing...");
  BTSerial.begin(BT_BaudRate); // Bluetooth module baud rate
  Serial.println("[NETWORK] Ready.");
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
