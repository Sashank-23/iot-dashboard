# IoT Cloud Environmental Monitoring Dashboard

## Project Overview

This project demonstrates a cloud-connected IoT monitoring system that visualizes environmental and electrical sensor data through a web dashboard. Since physical hardware was not available during development, realistic synthetic sensor data was generated and stored in Firebase to simulate real IoT device behavior.

The system replicates how a real IoT pipeline works:
Sensor Layer → Cloud Database → Web Dashboard → Data Visualization.

The dashboard fetches cloud data and simulates real-time sensor streaming by updating readings every 2 seconds.

---

## Objectives

* Demonstrate IoT cloud integration
* Simulate real-time sensor monitoring
* Build a professional monitoring dashboard
* Show data pipeline architecture used in real IoT deployments
* Develop a hardware-independent prototype

---

## Sensors Simulated

### BME280 Environmental Sensor

Used to simulate environmental monitoring:

* Temperature (°C)
* Humidity (%)
* Pressure (hPa)
* Gas resistance (synthetic air quality indicator)

### INA219 Power Monitoring Sensor

Used for electrical monitoring:

* Voltage (V)
* Current (A)
* Power (W)

### HC-SR04 Ultrasonic Sensor

Used for distance measurement:

* Distance (cm)

---

## System Architecture

Synthetic Dataset Generator → Firebase Realtime Database → Web Dashboard

### Working Flow:

1. Synthetic sensor data (300 readings) generated
2. Data stored in Firebase Realtime Database
3. Web dashboard fetches the dataset
4. Data replayed sequentially to simulate live sensors
5. Dashboard updates every 2 seconds
6. Current system time displayed like NTP synchronization

---

## Features

### Cloud Integration

* Firebase Realtime Database used as IoT cloud backend
* Demonstrates real IoT cloud communication concept

### Real-Time Simulation

* Sensor readings update every 2 seconds
* Sequential playback of 300 readings
* Simulates real IoT device streaming

### Dashboard Interface

* Modern responsive UI
* Sensor data cards
* Status indicators
* Live clock display
* Environmental monitoring layout

### Data Visualization Ready

* Structured database format
* Timestamp indexed readings
* Scalable for graph integration

### Hardware Scalability

The system is designed so synthetic data can be replaced by:

* ESP32
* Raspberry Pi
* MQTT devices
* Real sensor networks

---

## Technologies Used

Frontend:

* HTML5
* CSS3
* JavaScript

Cloud:

* Firebase Realtime Database

Development Tools:

* VS Code
* GitHub Pages (deployment)

Concepts Demonstrated:

* IoT Architecture
* Cloud Data Streaming
* Real-Time Dashboard Design
* Sensor Data Simulation
* Web-based Monitoring Systems

---

## Deployment

The dashboard is deployed using GitHub Pages:

Live Dashboard:
https://sashank-23.github.io/iot-dashboard/

---

## Future Improvements

* Real ESP32 sensor integration
* MQTT communication layer
* Live data graphs
* Alert notification system
* Device health monitoring
* CSV data export
* User authentication
* Mobile dashboard app

---

## Learning Outcomes

Through this project I learned:

* IoT cloud architecture design
* Firebase database integration
* Real-time data visualization
* Dashboard UI design principles
* Sensor data structuring
* GitHub deployment workflow

---

## Conclusion

This project demonstrates how IoT monitoring systems can be built even without hardware by simulating sensor data. The architecture is scalable and can be directly connected to real sensors in production environments.

This prototype represents a typical industry IoT monitoring workflow and demonstrates cloud integration, data streaming, and dashboard visualization.
