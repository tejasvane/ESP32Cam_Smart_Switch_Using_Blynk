# 💡 ESP32-CAM Smart Switch Using Blynk (PWM Controlled)

An Internet of Things (IoT) project implementing a wireless, multi-channel smart switch and dimmer using the **ESP32-CAM** module and the **Blynk** cloud platform. This Micro Project was developed for the course **Circuits & Networks (313325)**.

---

## 🎯 Aim of the Project

The primary aim is to design and implement an IoT-based smart switch system using the ESP32-CAM module:
* To control multiple electrical loads (LEDs or appliances) wirelessly through the Blynk IoT platform.
* To apply practical concepts of circuit, network principles, and GPIO interfacing.
* To demonstrate energy-efficient and convenient device control through smart technology.

---

## 🌟 Features

* **Wireless Control:** Control loads remotely from a smartphone.
* **4-Channel Output:** Independently controls four distinct loads (LEDs).
* **PWM Control:** Supports Pulse Width Modulation for adjustable brightness (dimming).
* **IoT Communication:** Uses the built-in Wi-Fi of the ESP32-CAM to connect to the Blynk Cloud.
* **Triple Wi-Fi Failover:** The code attempts connection to up to three different Wi-Fi networks for robust connectivity.

---

## 🛠️ Hardware & Software Requirements

### Hardware Components
| Sr. No. | Component | Specification | Qty. |
| :---: | :--- | :--- | :---: |
| 1 | ESP32-CAM Module | AI Thinker, Wi-Fi enabled | 1 |
| 2 | LED | 5mm, Red/Green/Yellow | 4 |
| 3 | Resistor | 220Ω – 470Ω | 4 |
| 4 | USB to TTL Programmer / FTDI | 5V, 3.3V logic compatible | 1 |
| 5 | Power Supply | 5V regulated | 1 |

### Software Tools
* Arduino IDE (for programming)
* Blynk IoT App (Android / iOS)

---

## 🔗 Circuit Connections

The four LEDs are connected to the ESP32-CAM through current-limiting resistors.

| Load (Indicator) | ESP32-CAM GPIO Pin |
| :---: | :---: |
| LED 1 | GPIO 13 |
| LED 2 | GPIO 12 |
| LED 3 | GPIO 14 |
| LED 4 | GPIO 15 |

---

## ⚙️ Working of this Micro-Project

1.  **Programming & Initialization:** The ESP32-CAM is programmed, connects to Wi-Fi (using triple failover logic), and initializes communication with the Blynk Cloud.
2.  **Control Loop:** The code constantly runs the Blynk handler (`Blynk.run()`), waiting for commands from the mobile app.
3.  **Command Execution:** When a user toggles an ON/OFF button or moves a brightness slider on the Blynk app, a corresponding virtual pin command is sent to the ESP32-CAM.
4.  **Output:** The microcontroller processes the command and updates the respective GPIO pin. For ON/OFF, the pin is set HIGH/LOW. For brightness control, the **PWM duty cycle** (using `ledcWrite()`) is adjusted, visually dimming or brightening the connected LED.

---

## 📖 Literature Review

Wireless home automation is a popular and practical field in IoT. The **ESP32-CAM** provides a compact, cost-effective platform for implementing smart systems due to its integrated Wi-Fi. This project demonstrates foundational skills in IoT communication, circuit interfacing (using LEDs as safe loads), and the use of the **Blynk** platform for real-time remote control, serving as a prototype for advanced automated systems.

---

## 📱 Applications of the Micro-Project

The core principles of this project are applicable to:

* Smart home lighting control.
* Remote control and automation of various home appliances.
* Prototyping and development of commercial smart switches.
* Educational tool for IoT, electronics, and network integration.

