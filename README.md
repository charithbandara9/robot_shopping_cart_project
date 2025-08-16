

# 🛒 Autonomous Shopping Robot Cart — Full Project Guide (Beginner‑Friendly)
<img width="1024" height="1024" alt="cover_image" src="https://github.com/user-attachments/assets/4e5f7322-5004-45eb-a06f-31dab8a8f811" />

Welcome! This repository contains **everything** to build a **Wi‑Fi controlled autonomous shopping cart** system:
- **Robot Cart** (Arduino Mega + motor drivers + sensors + gyro)
- **Handheld Remote Controller** (ESP32 + LCD + buttons + battery monitor)
- **ESP32‑CAM Barcode Scanner** (camera streaming + Python decode)
- **Python Communication Server** (bridges Remote ⇄ Robot, logs scans)

The whole project is explained for **beginners** with simple language, example code, and clear steps.

---

## 🧭 System at a Glance

1) **Remote Controller (ESP32)** → sends your chosen destination (e.g., Vegetables, Bakery) to the **Python Server**.  
2) **Python Server** → forwards that command to the **Robot Cart**.  
3) **Robot Cart (Arduino Mega)** → follows the black line path to the location (using IR array + PID + gyro).  
4) **ESP32‑CAM** → scans product barcodes/QRs; **Server** logs and can notify the Remote.  

> Typical button‑press → robot moves latency: **~120–350 ms** on local Wi‑Fi.

---

## 🗂️ Repository Structure (suggested)

```
project/
├─ robot_cart/                  # Arduino Mega firmware (line follow + motors + gyro)
├─ remote_controller/           # ESP32 remote (LCD menu + buttons + Wi‑Fi)
├─ esp32_cam_scanner/           # ESP32‑CAM + Python decode (separate folder)
├─ python_server/               # Python TCP server (messages + logging)
└─ README.md                    # This file
```

---

## 🔧 Hardware Overview

### Robot Cart
- **Arduino Mega 2560** (main MCU)
- **Dual BTS7960B (IBT‑2) 43A motor drivers** (left/right)
- **JGA25‑370 12V 280RPM DC motors with encoders**
- **8‑channel analog IR sensor array** (black line following)
- **L3G4200D gyroscope** (I²C: SDA=20, SCL=21) for turns stability
- **Push buttons**: Reset, ESP reset, Start (calibrate → wait for command), one spare
- **LM2596 buck** (11.1 V LiPo → 5 V), **11.1 V LiPo battery**
- **ESP‑01 (ESP8266)** for Wi‑Fi link to server (via SoftwareSerial 10/11, level‑shifted)

### Handheld Remote (ESP32)
- **ESP32 Dev Module**
- **ST7920 128×64 LCD** (U8g2 SW‑SPI: CLK=18, DAT=23, CS=5, RST=4)
- **Buttons**: BTN1=25 (Up), BTN2=19 (Down), BTN3=22 (Select), REFRESH=33 (IRQ)
- **Buzzer**: GPIO13, **Battery ADC**: GPIO27 (divider ≈ 3.13)
- Sends: `HELLO`, `GOTO:<PLACE>`, `REFRESH`, `HEARTBEAT`

### ESP32‑CAM Scanner
- **ESP32‑CAM + OV2640** (MQTT/TCP stream, Python OpenCV or Pyzbar decode)
- Best scan distance: **~15–40 cm (QVGA)** or **20–60 cm (VGA)**, good lighting

### Python Communication Server
- Listens for TCP clients (Remote, Cart, Camera)
- Forwards commands, logs scans, sends **ACK / STATUS / DONE**

---

## ⚙️ Robot Cart — Control Highlights

**PID steering from line error**
```cpp
// error ~ -3500..+3500 (center = 0)
integral += error;
float deriv = (error - lastError);
lastError = error;

float steer = KP*error + KD*deriv + KI*integral;  // tune gains
steer /= 100.0;                                    // scale
int left  = BASE_SPEED - (int)steer;
int right = BASE_SPEED + (int)steer;
setMotor(left, right); // or setMotorSmooth(...) with ramping
```

**PID tuning (trial & error)**
- Start: `KP≈15–22`, `KD≈4–8`, `KI=0`, `BASE_SPEED=100–140`
- Wobbles on straights → increase **KD** (or lower **KP**)
- Misses inside turns → raise **KP** (or BASE_SPEED slightly)
- Slow drift → add **small KI** (0.2–0.6)

**Line sensors**
```cpp
// Normalize each sensor 0..1000 (calibrated min/max) and get position (0..7000)
int pos = readLineSensors(sensorVal);
int error = (pos < 0) ? 0 : (pos - 3500);  // center = 3500
```

**Smooth acceleration (optional)**
```cpp
int prevL=0, prevR=0; const int ACCEL_STEP=8;
void setMotorSmooth(int L, int R){
  L = constrain(L,-255,255); R = constrain(R,-255,255);
  prevL += constrain(L-prevL, -ACCEL_STEP, ACCEL_STEP);
  prevR += constrain(R-prevR, -ACCEL_STEP, ACCEL_STEP);
  setMotor(prevL, prevR);
}
```

---

## 📟 Remote Controller — Key Ideas

**U8g2 display (ST7920, SW‑SPI)**
```cpp
U8G2_ST7920_128X64_1_SW_SPI u8g2(U8G2_R0, 18, 23, 5, 4);
u8g2.firstPage(); do {
  u8g2.setFont(u8g2_font_6x12_tf);
  u8g2.drawStr(0, 14, "Shopping Remote");
  // draw menu, battery, status...
} while (u8g2.nextPage());
```

**Buttons with interrupts**
```cpp
pinMode(25, INPUT_PULLUP); attachInterrupt(digitalPinToInterrupt(25), isrBtn1, FALLING);
// repeat for 19, 22, 33
```

**Battery reading**
```cpp
int raw = analogRead(27);
float v = (raw * 3.3f / 4095.0f) * 3.13f;  // divider ≈ 3.13
```

**Protocol (examples)**
```
Remote → Server:  HELLO,REMOTE | GOTO:VEGETABLES | REFRESH | HEARTBEAT:-58,3.98
Server → Remote:  ACK | STATUS:ARRIVED | STATUS:SCANNING | DONE
```

---

## 📷 ESP32‑CAM — Code Focus

**Camera config & frame capture (concept)**
```cpp
camera_fb_t * fb = esp_camera_fb_get();
if (fb) {
  // send fb->buf (JPEG) to server, or decode locally if you compiled decoder
  esp_camera_fb_return(fb);
}
```

**Python decode (server side)**
```python
from pyzbar.pyzbar import decode
import cv2
codes = decode(frame)  # returns list of barcodes/QRs
```

**Scan tips for beginners**
- Use **QVGA (320×240)** for speed; **VGA** only if you need distance
- Good light, steady camera, focus at ~**25–30 cm**

---

## 🖧 Networking & Timing

- All devices on **same Wi‑Fi** (no Internet required)
- Latency budget (typical): Remote→Server **5–30 ms**, Server→Robot **5–30 ms**, Robot loop reaction **10–20 ms** → **~120–350 ms total**
- Heartbeat every **1 s**; consider disconnected if **>3 s** silence

---

## 🚀 Setup Checklist (Quick Start)

1) **Flash firmware**
- Upload Arduino Mega sketch to `robot_cart/`
- Upload ESP32 remote sketch to `remote_controller/`
- Upload ESP32‑CAM sketch to `esp32_cam_scanner/`

2) **Run Python server**
```bash
cd python_server
python3 server.py
```

3) **Connect**
- Put all devices on the same Wi‑Fi
- Watch serial logs; ensure **ACK** for commands

4) **Drive & scan**
- Use the remote to send `GOTO: ...`
- Robot follows line to the location
- ESP32‑CAM scans barcode → server logs → remote shows status

---

## 🧯 Troubleshooting (Fast)

| Symptom | Fix |
|---|---|
| Remote connects but robot doesn’t move | Check server → robot link & command parsing |
| Robot wobbles | Increase **KD** slightly or reduce **KP** |
| Line lost on corners | Raise **BASE_SPEED** a bit or refine sensor height |
| Camera fails to read | Improve lighting, use QVGA, refocus lens |
| Battery % wrong | Re‑measure divider and update ratio |
| Wi‑Fi drops | Keep antennas clear; add capacitors on power rails |

---

## 📜 License
Open‑source for education and personal builds. Attribution is appreciated.

## 🙏 Credits
Thanks to the open‑source community (Arduino, U8g2, ESP32, OpenCV/pyzbar) and all contributors.
