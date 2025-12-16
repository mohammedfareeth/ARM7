🚗 ARM7 (LPC2129) Based Multi‑Sensor Car Dashboard Using CAN

Real‑Time Monitoring of Temperature, Ultrasonic Distance & Automatic Headlight (LDR)

📌 Project Overview
This project presents a CAN‑based automotive car dashboard built on the ARM7 LPC2129 microcontroller. It integrates Temperature, Ultrasonic distance, and LDR‑based automatic headlight control sensors. Sensor data is transmitted over the CAN bus and displayed on a central dashboard in real time, simulating an automotive ECU network.

🎯 Objectives
• Implement CAN communication using LPC2129 (ARM7TDMI‑S)
• Monitor temperature, obstacle distance, and ambient light
• Enable automatic headlight control using LDR
• Design a real‑time, reliable automotive dashboard system
• Gain hands‑on experience with automotive embedded networking

🧠 Sensors Used
• Temperature Sensor (e.g., LM35): Monitors engine/cabin temperature
• Ultrasonic Sensor (e.g., HC‑SR04): Measures obstacle distance for safety
• LDR (Light Dependent Resistor): Controls headlight ON/OFF based on ambient light

🛠️ Hardware Requirements
• Microcontroller: LPC2129 (ARM7TDMI‑S)
• CAN Transceiver: MCP2551 / SN65HVD230
• Sensors: LM35, Ultrasonic sensor, LDR
• Display: 16x4 LCD
• Headlight Load: LED / Relay module
• Power Supply
• CAN Bus (Twisted pair + termination resistors)

💻 Software Tools
• Programming Language: Embedded C
• IDE: Keil µVision
• Toolchain: ARM GCC
• Debugging: Simulator / JTAG
• Communication Protocol: CAN (Controller Area Network)

⚙️ Key Features
• Multi‑sensor data acquisition using LPC2129 ADC & GPIO
• CAN initialization, transmission, and reception
• Unique CAN IDs for each sensor parameter
• Real‑time dashboard display on LCD
• Automatic headlight control using LDR
• Scalable ECU‑based automotive architecture

📂 Project Structure
CAR_DASHBOARD_CAN_LPC2129/
│
├── main.c        // Dashboard control logic
├── can.c         // CAN driver implementation
├── can.h         // CAN definitions
├── sensor.c      // Temperature, Ultrasonic & LDR code
├── sensor.h      // Sensor headers
├── lcd.c         // LCD interface
├── lcd.h         // LCD headers
└── README.md     // Project documentation

🔄 Working Principle
1.Temperature, ultrasonic, and LDR sensors collect real‑time data.
2.LPC2129 processes sensor values using ADC and timers.
3.Each parameter is transmitted as a CAN frame with a unique ID.
4.Dashboard ECU receives CAN messages.
5.LCD displays temperature and distance values.
6.Headlight turns ON automatically in low light and OFF in daylight.

🚀 How to Run the Project
1.Clone the repository:
    git clone https://github.com/mohammedfareeth/ARM7.git
2.Open the project in Keil µVision
3.Select LPC2129 device
4.Build and flash the code
5.Connect CAN transceiver, sensors, and LCD
6.Power ON and observe real‑time dashboard operation

🚘 Applications
• Automotive car dashboards
• Obstacle detection systems
• Automatic vehicle lighting systems
• ECU communication using CAN
• Embedded automotive projects

✅ Learning Outcomes
• Practical CAN protocol implementation
• ARM7 LPC2129 peripheral programming
• Real‑time multi‑sensor integration
• Automotive embedded system design

👤 Author
Mohammed Fareeth
Embedded Systems | Automotive CAN Projects

📜 License
Developed for educational purposes. Free to use and modify.
