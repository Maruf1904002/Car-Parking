# Automatic Car Parking System 

This Arduino-based project is designed to manage a small-scale automatic car parking system using IR sensors, a servo motor, and an LCD display. The system detects car presence in four parking slots, monitors entry and exit points, and automatically opens/closes the gate based on availability.

---

## 📌 Features

- 🔍 Detects car presence in 4 individual parking slots
- 🚦 IR-based entry and exit detection
- 🔄 Automatic gate control using a servo motor
- 📟 Real-time status display on 16x2 LCD:
  - Available slots
  - Slot-wise status (E = Empty, F = Full)
- 📡 Serial monitoring via Arduino Serial Monitor

---

## ⚙️ Hardware Requirements

| Component              | Quantity |
|------------------------|----------|
| Arduino UNO/Nano       | 1        |
| Servo Motor (e.g. SG90)| 1        |
| IR Sensors             | 6        |
| 16x2 LCD (I2C or parallel) | 1    |
| Jumper Wires           | As needed |
| Breadboard / PCB       | 1        |

---

## 🧠 Working Principle

- **IR Sensors** placed at:
  - **Entry** and **Exit** gates to detect cars
  - Each of the **4 parking slots** to check availability
- **Servo Motor** acts as the entry/exit gate
- System checks:
  - If a car is at the gate and slot is available → gate opens
  - If all slots are full → displays "Parking Full"
  - After entry/exit → gate auto-closes
- **LCD** shows available slots and real-time status of each slot.

---

## 📋 Pin Configuration

| Component         | Arduino Pin |
|------------------|-------------|
| IR Entry Sensor   | D2          |
| IR Exit Sensor    | D4          |
| IR Slot 1         | D5          |
| IR Slot 2         | D6          |
| IR Slot 3         | D7          |
| IR Slot 4         | D8          |
| Servo Motor       | D3          |
| LCD (I2C Address) | 0x27        |

---

## 🚀 Getting Started

1. Connect all components as per the pin configuration.
2. Upload the code using Arduino IDE.
3. Open Serial Monitor (9600 baud) for live debug info.
4. Observe LCD for slot availability and gate actions.

---

## 🧑‍💻 Author

**Maruf Ahmed**  
Department of Electronics & Telecommunication Engineering  
Rajshahi University of Engineering & Technology (RUET)

---



## 📝 License

This project is open-source and free to use under the [MIT License](https://opensource.org/licenses/MIT).
