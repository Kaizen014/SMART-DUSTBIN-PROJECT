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

#include <Servo.h>

Servo myservo;  

// Ultrasonic pins
const int trigPin = 2;
const int echoPin = 3;

// Bin level
const int binLevelPin = A0;  
int binLevel;
int threshold = 700;  

// LEDs
const int greenLED = 8;
const int blueLED  = 9;
const int redLED   = 12;

// Buzzer
const int buzzerPin = 10;

long duration;
int distance;

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  
  pinMode(buzzerPin, OUTPUT);

  myservo.attach(7);
  myservo.write(3); 

  Serial.begin(9600);
}

void loop() 
{
  // Read bin level
  binLevel = analogRead(binLevelPin);

  if(binLevel > threshold) {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);
    myservo.write(3); 
    
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);
    delay(500);
    return;
  } 
  else {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(buzzerPin, LOW);
  }

  // Ultrasonic
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  int D = map(distance, 10, 1095, 2, 400);

  if(D < 60) {
    myservo.write(93);
    digitalWrite(blueLED, HIGH);
    digitalWrite(greenLED, LOW);
    delay(1000);
  } 
  else {
    myservo.write(3);
    digitalWrite(blueLED, LOW);
    digitalWrite(greenLED, HIGH);
  }

  delay(200);
}
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
This project was developed as part of a Robotics course in the Mechatronics Engineering program. It demonstrates the integration of sensing, actuation, and control systems to solve a real-world automation problem using embedded hardware.
---

## 👥 Project Team

- OLADUNJOYE PAUL TOLUWALASE
- ASOBIE-JERRY JASHER CHIMZURUM
- SANUSI ABDULROBI KOLAPO
- KOKO OLUWASEYI ELIJAH
- ONWUBIKO CHIKANYEM CHIMAOBI

---

## 📜 License

This project is developed for academic purposes.  
Open for modification and educational use with proper credit.
