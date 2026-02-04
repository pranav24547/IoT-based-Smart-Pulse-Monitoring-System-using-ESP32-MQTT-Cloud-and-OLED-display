# 🔥 ESP32 IoT Pulse Monitoring System using MQTT & OLED

An IoT-based real-time pulse monitoring system built using ESP32, MQTT protocol, MQTT Cloud, and SSD1306 OLED display. The system reads pulse sensor data, classifies heart rate status (LOW, GOOD, HIGH), displays values locally on OLED, and transmits data securely to the cloud for remote monitoring.

---

## 🚀 Features

- Real-time pulse monitoring
- BPM classification (LOW / GOOD / HIGH)
- SSD1306 OLED live display
- Secure MQTT communication (TLS)
- MQTT Cloud integration
- Remote data monitoring
- Wokwi simulation support
- Lightweight and fast execution

---

## 🛠 Hardware Components

- ESP32 Dev Board  
- Pulse Sensor (Potentiometer for simulation)  
- SSD1306 OLED Display (I2C)  
- Jumper Wires  

---

## ⚙ Software & Technologies Used

- Arduino IDE
- ESP32 Core
- MQTT Protocol
- MQTT Cloud Platform
- PubSubClient Library
- Adafruit SSD1306 & GFX Libraries
- Wokwi Simulator

---

## 🔌 Pin Connections

### Pulse Sensor (Potentiometer)

| Component | ESP32 Pin |
----------|----------
Signal | GPIO34  
VCC | 3.3V  
GND | GND  

### OLED Display (I2C)

| OLED Pin | ESP32 Pin |
---------|----------
SDA | GPIO21  
SCL | GPIO22  
VCC | 3.3V  
GND | GND  

---

## 🔌 Schematic Diagram

<img src="https://github.com/pranav24547/IoT-based-Smart-Pulse-Monitoring-System-using-ESP32-MQTT-Cloud-and-OLED-display/blob/main/esp schematic diagram.png">

---

## 🧠 Working Principle

1. Pulse sensor sends analog signal to ESP32 ADC.
2. ESP32 processes signal and calculates BPM.
3. BPM is classified into LOW, GOOD or HIGH.
4. Data is displayed on OLED screen.
5. Pulse data is securely transmitted to HiveMQ Cloud using MQTT.
6. Remote clients can subscribe and monitor real-time data.

---

## 📟 Serial Monitor Output

<img src="https://github.com/pranav24547/IoT-based-Smart-Pulse-Monitoring-System-using-ESP32-MQTT-Cloud-and-OLED-display/blob/main/serial output.png">

---

## ☁ MQTT Server

<img src="https://github.com/pranav24547/IoT-based-Smart-Pulse-Monitoring-System-using-ESP32-MQTT-Cloud-and-OLED-display/blob/main/Mqtt Output.png">

---

## 📜 License

Developed by **Pranav Thanavel**  
For academic and educational purposes.

---

⭐ If you find this project helpful, consider giving it a star on GitHub!
