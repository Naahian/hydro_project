

# 🌱 Automated Vertical Hydroponics System  

## Overview  
This project aims to **simplify farming in urban and tight spaces** by automating a **hydroponic vertical farming system** with **four tower pipes**. It optimizes resource usage by **automating nutrient dosing, pH balancing, temperature control, and real-time monitoring**, ensuring a **sustainable and efficient farming system**. The system also helps **reduce water and energy waste** while maintaining ideal growing conditions, making urban farming more accessible and manageable.  

## Features  
- **Automated Nutrient & pH Dosing** – Ensures optimal EC & pH levels.  
- **Real-time Monitoring** – Tracks **temperature, pH, EC, and power consumption**.  
- **Web Dashboard** – A **Bootstrap 5-based** UI for live sensor data & historical insights.  
- **Bluetooth & WiFi Connectivity** – For remote control & monitoring.  
- **State Management** – Tracks the plant's **growth stage** *(Seed → Growth → Fruit)*.  
- **Energy Efficiency Monitoring** – Logs **current consumption per hour**.  
- **Action Logging** – Keeps a **history of watering, dosing, and sensing actions**.  


## Project Structure  
```bash
📦 Automated-Hydroponics  
 ├── 📁 arduino/              # Arduino firmware  
 │   ├── main.ino            # Main controller logic  
 │   ├── network.cpp         # WiFi & Bluetooth handling  
 │   ├── sensors.cpp         # Sensor data acquisition  
 │   ├── actuator.cpp        # Pumps & dosing control  
 │   └── config.h            # System configurations  
 │  
 ├── 📁 dashboard/            # Web Dashboard (HTML, CSS, JS)  
 │   ├── index.html          # Dashboard UI  
 │   ├── style.css           # Stylesheet  
 │   ├── script.js           # Graphs & real-time updates  
 │   └── api/                # Backend API (Flask/Node.js)  
 │  
 ├── 📁 docs/                 # Documentation  
 ├── README.md                # Project Overview  
 └── LICENSE                   # Open-source license  
```


## Connectivity & Communication  
- **Bluetooth** – Used for local communication with the mobile app.  
- **WiFi (ESP32)** – Sends data to the **web dashboard**.  
- **MQTT Support** *(Planned)* – For cloud integration.  


## Future Enhancements  
- **Machine Learning-based growth optimization(Planned)** 🌿  
- **Mobile App Integration (Planned)** 📱  
- **Cloud-based Data Logging(Planned)** ☁️  

