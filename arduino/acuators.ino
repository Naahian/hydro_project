// Acuators are output modules relay, pump and stuff


//TODO: Solution A pump, Solution B pump

void setupRelay() {
  pinMode(relayPump_PIN, OUTPUT);
  pinMode(relaySensor_PIN, OUTPUT);
  
  // Initialize both relays to OFF state
  digitalWrite(relayPump_PIN, HIGH);
  digitalWrite(relaySensor_PIN, HIGH);

  Serial.println("[INIT] Relay module initialized.");
}

// Relay Water Pump controls
void relayPumpOn() {
  digitalWrite(relayPump_PIN, LOW);  // LOW = ON for most relay modules
  SystemStatus["solution_A_pump"] = true;
  SystemStatus["solution_B_pump"] = true;
}

void relayPumpOff() {
  digitalWrite(relayPump_PIN, HIGH); // HIGH = OFF
  SystemStatus["solution_A_pump"] = false;
  SystemStatus["solution_B_pump"] = false;
}

// Relay Sensor Probe controls
void relaySensorOn() {
  digitalWrite(relaySensor_PIN, LOW);
}

void relaySensorOff() {
  digitalWrite(relaySensor_PIN, HIGH);
}

