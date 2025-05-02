// Acuators are output modules relay, pump and stuff
#define relayPump_PIN 8
#define relayProbe_PIN 9

//TODO: Solution A pump, Solution B pump

void setupRelay() {
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(relayProbe_PIN, OUTPUT);
  
  // Initialize both relays to OFF state
  digitalWrite(RELAY1_PIN, HIGH);
  digitalWrite(relayProbe_PIN, HIGH);

  Serial.println("[INIT] Relay module initialized.");
}

// Relay Water Pump controls
void relayPumpOn() {
  digitalWrite(relayPump_PIN, LOW);  // LOW = ON for most relay modules
  Serial.println("Relay 1 ON");
}

void relayPumpOff() {
  digitalWrite(relayPump_PIN, HIGH); // HIGH = OFF
  Serial.println("Relay 1 OFF");
}

// Relay Sensor Probe controls
void relayProbeOn() {
  digitalWrite(relayProbe_PIN, LOW);
  Serial.println("Relay 2 ON");
}

void relayProbeOff() {
  digitalWrite(relayProbe_PIN, HIGH);
  Serial.println("Relay 2 OFF");
}

