# MatLED

> **High School Graduation Project 2026** <br>
> **Specialization:** Mathematics & Computer Science <br>
> **Student:** Tundrea Cristina-Ioana <br>
> **High School:** Saint Sava National College <br>

---

## 📌 Overview
Graduation project 2026 featuring a LED matrix controlled with an Android mobile app.

<p align="center">
  <img width="400" alt="ComponentsUsed" src="https://github.com/user-attachments/assets/ed7c46fe-d305-4a42-9290-be00e2368a0f" />
  <br>
  <i>Figure 1: Overview of used components</i>
</p>

---

<p align="center">
  <img width="400" alt="Overview" src="https://github.com/user-attachments/assets/c0c826f2-9e31-4e90-a42f-d84f6d39c680" />
  <br>
  <i>Figure 2: Complete hardware setup with Arduino Uno, LED Matrix and HC-05 Bluetooth Module</i>
</p>

---

## 🛠️ Hardware Components & Technologies
### Hardware:
* Development Board: Arduino Uno R3 using the 8 bit ATmega328P microcontroller
* HC-05 Bluetooth Module
* LED Matrix (32 x 8) display using the MAX7219 driver
* Duracell 9 V alkaline battery
* Toshiba Heavy Duty 9 V battery
* Mini Breadboard
* Jumper Wires male to male
* Jumper Wires male to female
* Battery Cable
* USB Cable from AM to BM

### Software:
* **Arduino IDE 2.3.10** (C/C++)
* **Libraries:** `<MD_Parola.h>`, `<MD_MAX72xx.h>`, `<SPI.h>`, `<SoftwareSerial.h>`

---

## 📄 Technical Documentation (RO)
Complete project documentation written for the graduation exam (in Romanian): <br>
👉 ** [Read Full Documentation (PDF)](...) **

### Table of contents:
1. Introduction & Justification
2. Hardware Components Overview
3. Circuit Schematic & System Architecture
4. Source Code Structure
5. User Guide & Mobile App Interface
6. Challenging issues
7. Internet of Things
8. Conclusion
9. Bibliography

---

## 🔌 Circuit Pinout
Brief overview of hardware connections:

|       **Component**      | **Module Pin** | **Arduino Pin** |             **Importance**            |
|:------------------------:|:--------------:|:---------------:|:-------------------------------------:|
|   _LED Matrix MAX7219_   |       VCC      |       5 V       |         Positive Alimentation         |
|                          |       GND      |       GND       |                 Ground                |
|                          |       DIN      |      Pin 11     |           Data Transmission           |
|                          |       CS       |      Pin 10     |              Chip Select              |
|                          |       CLK      |      Pin 6      |     Hardware Sincronisation Clock     |
| _Bluetooth HC-05 Module_ |       VCC      |       5 V       |         Positive Alimentation         |
|                          |       GND      |       GND       |                 Ground                |
|                          |       TXD      |      Pin 2      | Serial Data Transmission (to Arduino) |
|                          |       RXD      |      Pin 3      |         Serial Data Reception         |

---

<p align="center">
  <img width="400" alt="InitialElectricalScheme" src="https://github.com/user-attachments/assets/03231339-c88a-4dc9-a824-e5d0bb6337b3" />
  <br>
  <i>Figure 3: Initial Electrical Scheme</i>
</p>

---

<p align="center">
  <img width="400" alt="FinalElectricalScheme" src="https://github.com/user-attachments/assets/623fd985-8a1d-460d-900c-1658d812f81b" />
  <br>
  <i>Figure 4: Final Electrical Scheme</i>
</p>

---

## 🚀 User's Guide
1. Download or clone the source code (`.ino` file).
2. Open the file in **Arduino IDE**.
3. Install the required libraries via the *Library Manager*.
4. Select the correct Board and COM Port under **Tools**.
5. Click **Upload** to upload the source code on the Arduino Board.
6. Test the code!

---

<p align="center">
  <img width="400"  alt="App3 2 (1)" src="https://github.com/user-attachments/assets/b9236d67-acc7-4a52-b594-72af830ed245" />
  <br>
  <i>Figure 5: User interface in the Android Mobile App</i>
</p>

## Final Overview

<p align="center">
  <img width="450" alt="FinalOverview" src="https://github.com/user-attachments/assets/3d11dfb9-8ea5-4ba6-8cb9-eb928d3abadc" />
  <br>
  <i>Figure 6: Final Project Overview</i>
</p>
