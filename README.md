# 🗑️ Smart Dustbin [Waste Monitoring System(Arduino-Based)]

## 📌 Project Overview

The **Smart Waste Monitoring System** is an embedded systems project developed using Arduino.  
The system automates dustbin lid operation while simultaneously monitoring the fill level of the bin and providing visual and audio alerts when the bin reaches capacity.

This project integrates sensing, actuation, and real-time monitoring into a low-cost and efficient waste management prototype.

---

## 🎯 Objectives

- Automate lid opening using ultrasonic sensing
- Monitor bin fill level using an analog sensor
- Provide LED status indication
- Trigger buzzer alert when bin is full
- Develop a scalable smart waste prototype

---

## 🧰 Hardware Components

- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- SG90 Servo Motor
- Potentiometer (simulated bin level sensor)
- Red LED
- Green LED
- Blue LED
- Buzzer
- Jumper wires
- External power supply

---

## ⚙️ System Architecture

The system consists of three functional modules:

### 1️⃣ Sensing Unit
- Ultrasonic sensor detects hand proximity
- Analog input monitors bin fill level

### 2️⃣ Control Unit
- Arduino processes sensor data
- Compares bin level against threshold

### 3️⃣ Actuation & Alert Unit
- Servo motor controls lid
- LEDs indicate system state
- Buzzer activates when bin is full

---

## 🔄 Working Principle

### ✅ Normal Condition (Bin Not Full)
- Green LED remains ON
- System detects hand within threshold distance
- Lid opens automatically
- Blue LED indicates lid open
- Lid closes after delay

### 🚨 Full Bin Condition
- Red LED turns ON
- Buzzer beeps continuously
- Lid remains closed
- Hand detection is disabled

---

## 📊 System Status Table

| Condition        | Green LED | Blue LED | Red LED | Buzzer | Lid Status |
|------------------|----------|----------|---------|--------|------------|
| System Ready     | ON       | OFF      | OFF     | OFF    | Closed     |
| Hand Detected    | OFF      | ON       | OFF     | OFF    | Open       |
| Bin Full         | OFF      | OFF      | ON      | ON     | Closed     |

---

## 💻 Program File

Main Arduino file:

```
Smart_Waste_Monitoring_System.ino
```

The program:
- Reads bin level from analog input
- Compares against threshold value
- Uses ultrasonic sensor for distance measurement
- Controls servo motor position
- Activates LEDs and buzzer accordingly

---

## 🖼️ Project Media

### 🔹 Circuit Design
(Add your Proteus/Tinkercad screenshot here)

```
/images/circuit-design.png
```

### 🔹 Hardware Prototype
(Add real project image here)

```
/images/hardware-setup.jpg
```

### 🔹 System Flowchart
(Add flowchart image here)

```
/images/system-flowchart.png
```

---

## 🚀 Features

- Contactless lid operation
- Real-time bin level monitoring
- Audio-visual alert system
- Modular and scalable design
- Low-cost embedded solution

---

## 🔮 Future Improvements

- LCD display for real-time system status
- IoT-based monitoring dashboard
- GSM notification when bin is full
- Load cell for weight-based measurement
- Solar-powered implementation

---

## 📚 Academic Context

This project was developed as part of an Embedded Systems / Electronics Engineering coursework to demonstrate integration of sensors, actuators, and monitoring systems in a practical application.

---

## 👥 Project Team

- Your Name
- Group Member 1
- Group Member 2

---

## 📜 License

This project is developed for academic purposes.  
Open for modification and educational use with proper credit.
