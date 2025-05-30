void adjustPH(){
  if(SystemStatus["ph"] < SystemConfig["ph_lower"]){
    //dose Solution A
    Serial.println("ph: Acidic");
    Serial.println("dosing Solution A");
  }
  else if(SystemStatus["ph"] > SystemConfig["ph_uppper"]){
    //dose Solution B
    Serial.println("ph: Basic");
    Serial.println("dosing Solution B");
  }
}

void adjustEC(){
  if(SystemStatus["ec"] < SystemConfig["ec_lower"]){
    //dose Solution A + Solution B (according to ratio)
    Serial.println("ec: low EC");
    Serial.println("dosing Solution A,B for 4:7");
  }
  else if(SystemStatus["ec"] > SystemConfig["ec_upper"]){
    //dose water
    Serial.println("ec: High EC");
    Serial.println("dosing Water");
  }
}

void adjustTemp(){
  if(SystemStatus["temp(C)"] < SystemConfig["temp(C)"]){
    
  }
  else if(SystemStatus["temp(C)"] > SystemConfig["temp(C)"]){
    
  }
}