# MatLED

> **High School Graduation Project 2026** <br>
> **Specialization:** Mathematics & Computer Science <br>
> **Student:** Tundrea Cristina-Ioana <br>
> **High School:** Saint Sava National College <br>

---

## 📌 Overview
Graduation project 2026 featuring a LED matrix controlled with an Android mobile app.

---

## 🛠️ Hardware Components & Technologies
### Hardware:
* Development Board: Arduino Uno R3 using the 8 bytes ATmega328P microcontroller
* Bluetooth Module HC-05
* LED Matrix (32 x 8) display using the MAX7219 driver
* Duracell 9 V alkaline battery
* Toshiba Heavy Duty 9 V battery
* Mini Breadboard
* Jumper Wires male to male
* Jumper Wires male to female
* Battery Cable
* USB Cable from AM to BM

## Software:
* **Arduino IDE 2.3.10** (C/C++)
* **Libraries:** `<MD_Parola.h>`, `<MD_MAX72xx.h>`, `<SPI.h>`, `<SoftwareSerial.h>`

---

## 📄 Technical Documentation (RO)
Complete project documentation written for the graduation exam (in Romanian):
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

## 🚀 User's Guide
1. Download or clone the source code (`.ino` file).
2. Open the file in **Arduino IDE**.
3. Install the required libraries via the *Library Manager*.
4. Select the correct Board and COM Port under **Tools**.
5. Click **Upload** to upload the source code on the Arduino Board.
6. Test the code!


