# 📟 Handheld Remote Controller (ESP32) — Beginner-Friendly Guide

This folder contains the **handheld remote** firmware for the autonomous shopping cart system.  
It runs on an **ESP32**, shows menus on a **128×64 ST7920** display (via **U8g2**), reads **3 buttons** + a **refresh button**, plays a **buzzer**, measures **battery voltage**, and connects to your **Python server over Wi-Fi**.

> All source files are **heavily commented** so beginners can follow every step.

---

## 📁 Files in This Folder

```
hand_device_beginner/
  hand_device.ino   # Full sketch with UI, Wi-Fi, battery, and server comms
  README.md                  # This guide
```

---

## 🔹 Hardware Used

| Component | Purpose |
|-----------|---------|
| **ESP32 Dev Module** | Main microcontroller |
| **128×64 ST7920 LCD** | Displays menus, status, and battery level |
| **3× Push Buttons** | Menu navigation & selection |
| **Refresh Button** | Forces display & data refresh |
| **Buzzer** | Audio feedback |
| **Li-ion Battery + Voltage Divider** | Portable power source with battery monitoring |
| **LM2596 / AMS1117-3.3** | Power regulation to ESP32 |
| **Misc. Wires & Connectors** | For all connections |

---

## 🔌 Pin Mapping (From Code)

| Function | ESP32 GPIO | Notes |
|---|---:|---|
| **Buzzer** | **13** | Active HIGH |
| **Camera flag** | **21** | `cam_on_off` (always HIGH in this version) |
| **Button 1** | **25** | Menu Up |
| **Button 2** | **19** | Menu Down |
| **Button 3** | **22** | Select / Confirm |
| **Refresh Button** | **33** | Refresh display/data |
| **Battery ADC** | **27** | Reads Li-ion voltage via divider |
| **LCD CLK** | **18** | ST7920 software SPI clock |
| **LCD DAT** | **23** | ST7920 software SPI data |
| **LCD CS** | **5**  | ST7920 chip select |
| **LCD RST** | **4**  | ST7920 reset |

---

## 🔋 Battery Voltage Reading

The voltage divider is ≈ **(10k + 4.7k) / 4.7k** → ratio **3.13**.

**Formula in code:**
```cpp
int raw = analogRead(27);
float v_adc = raw * 3.3 / 4095.0;
float v_bat = v_adc * 3.13;
```

Map `v_bat` to battery % for display.

---

## 🖥️ Display Setup

The ST7920 display is driven by U8g2 in **software SPI** mode:
```cpp
U8G2_ST7920_128X64_1_SW_SPI u8g2(U8G2_R0, 18, 23, 5, 4);
```

**Basic draw cycle:**
```cpp
u8g2.firstPage();
do {
  u8g2.setFont(u8g2_font_6x12_tf);
  u8g2.drawStr(0, 14, "Shopping Remote");
} while (u8g2.nextPage());
```

---

## 📶 Wi-Fi & Server Communication

**Connection:**
```cpp
WiFi.setHostname("remote");
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
```

**Protocol (example):**

Remote → Server:
```
HELLO,REMOTE
GOTO:VEGETABLES
REFRESH
```

Server → Remote:
```
ACK
STATUS:ARRIVED
STATUS:SCANNING
DONE
```

---

## ⏱️ Typical Timing

| Step | Time |
|------|------|
| Remote → Server message | 5–30 ms |
| Server route calculation | 5–30 ms |
| Robot activation | 100–300 ms |
| LCD refresh | 10–25 ms |
| **Total (press → robot moves)** | **~120–350 ms** |

---

## 🔊 Buzzer Feedback

Short beep = menu move  
Double beep = confirm  
Long beep = error/disconnect

```cpp
void beep_buzzer(int count, int ms){
  for(int i=0;i<count;i++){
    digitalWrite(13, HIGH);
    delay(ms);
    digitalWrite(13, LOW);
    delay(ms);
  }
}
```

---

## 🧪 First-Time Bring-Up

1. Upload sketch with **U8g2** installed.  
2. Power ESP32 and LCD.  
3. Check menu appears.  
4. Test buttons.  
5. Verify battery reading (4.2 V full, 3.5 V low).  
6. Connect to Wi-Fi.  
7. Send command; server replies **ACK**.  
8. Watch cart move in ~0.3s.

---

## 📜 License

Open source for learning. Attribution appreciated.

---

## 📷 Wiring Diagram

![Remote Schematic](Schematic_remote_unit_circuit_2025-08-14.jpeg)
