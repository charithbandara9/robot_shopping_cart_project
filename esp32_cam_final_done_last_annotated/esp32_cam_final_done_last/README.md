# 📷 ESP32-CAM Final Scanner with Python Server — Beginner Guide

This project lets your **ESP32-CAM** act as a barcode/QR code scanner, sending results to a **Python server** over Wi‑Fi.  
It is part of the **autonomous shopping cart system**, where scanned data triggers robot actions.

---

## 📂 Project Structure

```
esp32_cam_final_sanner_python_annotated/
│
├── esp32_cam_final_sanner_python/   # Arduino ESP32-CAM firmware
│   ├── esp32_cam_final_sanner_python.ino  # Main sketch (setup + loop)
│   ├── camera_pins.h                       # Camera pin definitions
│   ├── functions.ino                       # Helper functions
│   └── variables.h                         # Config + global vars
│
└── server/                         # Python TCP server
    └── server.py                   # Receives barcode text & prints
```

---

## 🛠️ Hardware Needed
- **ESP32-CAM** module (AI-Thinker recommended)
- FTDI programmer (for flashing)
- Power supply (5V 2A recommended)
- Wi‑Fi network
- (Optional) tripod or enclosure for camera

---

## 🔌 Wiring (Flashing mode)
| FTDI Programmer | ESP32‑CAM |
|---|---|
| 5V | 5V |
| GND | GND |
| TX | U0R |
| RX | U0T |
| GPIO0 → GND (for flashing) | — |

After flashing, disconnect GPIO0 from GND and reset to run.

---

## 📜 How It Works
1. ESP32‑CAM starts and connects to your Wi‑Fi.
2. Camera stream is active and barcode scanning runs in the loop.
3. When a valid barcode/QR is detected, its text is sent to the Python server via TCP.
4. Python server logs the text and can forward it to the robot cart system.

---

## 📦 Arduino Code Overview

**Main sketch (`esp32_cam_final_sanner_python.ino`)**
- `setup()` → initializes camera, connects Wi‑Fi, starts TCP client.
- `loop()` → captures frame, scans for barcode, sends data if found.

**`functions.ino`**
- Contains **barcode decoding logic**.
- Handles TCP send function.

**`variables.h`**
- Stores **SSID**, **password**, and server IP/port.

**`camera_pins.h`**
- AI Thinker ESP32‑CAM GPIO mapping.

---

## 🐍 Python Server Overview (`server.py`)
- Listens on a TCP port for incoming barcode text.
- Prints the scanned value to console.
- Can be expanded to send commands to the robot cart.

Example minimal server run:
```bash
python server.py
```

---

## 🚀 Quick Start

**1️⃣ Flash ESP32-CAM**
- Open Arduino IDE
- Select `AI Thinker ESP32-CAM`
- Install `esp32` board package
- Install `esp32-camera` and barcode decoding library
- Upload code with GPIO0 → GND

**2️⃣ Start Python Server**
```bash
cd server
python server.py
```

**3️⃣ Test Scan**
- Point ESP32-CAM at a barcode
- See decoded text in server terminal

---

## 💡 Beginner Tips
- Good lighting = better scan speed.
- Keep camera still for a clear read.
- Adjust resolution for performance (e.g., `FRAMESIZE_QVGA`).
- If Wi‑Fi fails, check SSID/password in `variables.h`.
- Server and ESP32‑CAM must be on the **same network**.

---

## 📜 License
Open source for educational purposes.
