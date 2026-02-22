# Smart Overloading Prevention System 🚛
**Active Engine Control Mechanism**
## 📌 Overview
This project introduces an in-vehicle automated self-regulation system designed to prevent Heavy Commercial Vehicles (HCVs) from overloading. Developed as a solution for the Smart India Hackathon, it shifts the enforcement paradigm from easily bypassed manual weighbridges to a proactive, hardware-based intervention system.

## ⚠️ The Problem
* **Severe Road Damage:** Frequent overloading causes premature potholes, cracks, and catastrophic bridge collapses.
* **Fatal Accidents:** Excess weight significantly increases braking distances, leading to severe highway collisions.
* **Enforcement Gap:** Traditional static weighbridges and standard on-board scales are easily manipulated, bypassed, or ignored by drivers.

## 🚀 Core Mechanisms
The system utilizes a "Dynamic Tare" algorithm to differentiate between actual payload overloading and temporary road bumps. It enforces compliance through two distinct active mechanisms:

1. **Stationary Prevention (Ignition Cut-off):** If the vehicle is parked and the Load Cell detects an overload exceeding RTO limits, the 12V Ignition Relay opens. This completely prevents the engine from starting.
2. **Moving Prevention (Limp Mode):** If an overload is detected mid-journey, the system prioritizes safety to avoid an abrupt highway stop. Instead of cutting power, it triggers "Limp Mode," restricting the vehicle's maximum speed to 20 km/h until safely parked.

## 🛠️ Technology Stack
* **Microcontroller:** Arduino UNO
* **Sensors:** Load Cells
* **Actuators:** Relay Module (Ignition control) & Motor-control Transistors
* **Language:** C++ (Arduino Framework)

## 📂 Repository Structure
* `/src`: C++ source code for the Arduino microcontroller.
* `/docs`: System architecture presentations and patent literature surveys (CN102019873A, US8855871B2).
* `/hardware`: Circuit diagrams and pinout configurations.
* `/media`: Prototype demonstration videos and component images.

## 🎥 Project Vision & Concept
*Note: This is an AI-generated cinematic pitch created to illustrate the real-world impact and conceptual design of the Smart Overloading Prevention System.*

📺 [Watch the Concept Video Here]()