# 🌡️ Temperature & Humidity Monitoring System (IoT with Blynk)

## 📌 Project Overview
This project monitors **temperature** and **humidity** using a **3-pin DHT11 sensor** connected to a **NodeMCU (ESP8266)**.  
The sensor data is sent to the **Blynk IoT platform** for real-time monitoring on a smartphone app.  

## ⚡ Features
- Reads temperature & humidity values from a 3-pin DHT11 sensor  
- Connects NodeMCU to Wi-Fi  
- Sends real-time data to the Blynk app  
- Allows real-time monitoring from anywhere  
- Simple and cost-effective IoT solution  

## 🛠️ Hardware Components
- NodeMCU ESP8266  
- DHT11 Temperature & Humidity Sensor (3-pin module: VCC, GND, DATA)  
- Jumper Wires  
- Breadboard  
- Power Supply  

## 💻 Software Requirements
- Arduino IDE  
- Blynk App (Install on Android/iOS)  
- Required Libraries:  
  - `DHT.h`  
  - `ESP8266WiFi.h`  
  - `BlynkSimpleEsp8266.h`  

## 🚀 How to Run
1. Clone this repository:  
   ```bash
   git clone    https://github.com/kondakkagarisaichandana/Temperature-and-Humidity-Detection

2. Open code.ino in Arduino IDE.

3. Install the required libraries from Arduino IDE Library Manager.

4. Update your Wi-Fi SSID, Password, and Blynk Auth Token in the code.

5. Connect the DHT11 sensor (3-pin) as follows:

VCC → 3.3V

GND → GND

DATA → D4 (GPIO2)

6. Upload the code to NodeMCU.

7. Open the Blynk app and add two value displays:

V5 → Temperature (°C)

V6 → Humidity (%)

📊 Output

Live temperature and humidity values shown on the Blynk app.

Data updates every 2 seconds.

Can be extended with notifications and automation.