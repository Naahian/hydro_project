void adjustPH(){
  if(sensorData["ph"] < configData["ph"]){
    //dose Solution A
  }
  else if(sensorData["ph"] > configData["ph"]){
    //dose Solution B
  }
}

void adjustEC(){
  if(sensorData["ec"] < configData["ec"]){
    //dose Solution A + Solution B (according to ratio)
  }
  else if(sensorData["ec"] > configData["ec"]){
    //dose water
  }
}

void adjustTemp(){
  if(sensorData["temp(C)"] < configData["temp(C)"]){
    
  }
  else if(sensorData["temp(C)"] > configData["temp(C)"]){
    
  }
}