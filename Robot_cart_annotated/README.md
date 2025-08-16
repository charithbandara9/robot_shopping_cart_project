# 🤖🛒 Shopping Robot Cart — Arduino Mega 2560

An **autonomous line‑following cart** powered by **Arduino Mega 2560**, **dual BTS7960B motor drivers**, **JGA25‑370 encoder motors**, **8‑analog IR sensor array**, and an **L3G4200D gyro**. It listens for commands over **ESP‑01 Wi‑Fi** and moves along a black path inside a shopping complex.

- Beginner‑friendly code: each file is small and focused.
- PID control for smooth line following.
- Clear tuning guide with example values.
- Practical tips for sensor thresholding and acceleration.

---

## 📁 Repo layout

```
/firmware/robot_cart/
  Robot_cart.ino
  pin_setup.ino
  sensor_array.ino
  gyro_lib.ino
  all_functions.ino
  definations___variable.h
robot_cart_wiring_v2.svg   # wiring diagram (ESP-01 included)
```
---

## 🔌 Wiring diagram

![Robot Cart Wiring]([robot_cart_wiring_v2.svg](https://github.com/kalanakanchana/robot_shopping_cart_project/blob/main/Robot_cart_annotated/robot_cart_wiring_v2.svg))

- **Left driver:** LFPWM=D6, LBPWM=D4, LF_EN=D49, LB_EN=D47  
- **Right driver:** RFPWM=D9, RBPWM=D7, RF_EN=D53, RB_EN=D51  
- **Encoders:** Left A=D2, Right A=D3  
- **IR Array:** A7..A0 (left→right)  
- **Gyro (I²C):** SDA=20, SCL=21 (3.3 V)  
- **Buttons:** Start=D23, ESP reset=D25 (INPUT_PULLUP)  
- **Buzzer:** D13  
- **ESP‑01 (via AMS1117‑3.3):** TX→D10, RX←D11 (with level shift)

---

## ⚙️ Control parameters (defaults)

These live in `definations___variable.h`:

```cpp
// Speed & limits
const int   BASE_SPEED = 120;  // 0..255, "cruise" PWM
const int   MAX_PWM    = 255;  // motor command clamp

// PID for line error -> steering (err in ~ -3500..+3500)
const float KP = 18.0;
const float KD = 6.0;
const float KI = 0.0;

// Behavior
const bool  ENABLE_AUTO_START = true; // start after calibration
```

### What they do
- **BASE_SPEED**: your cart’s “cruise” speed on a straight line.  
- **MAX_PWM**: hard limit so spikes don’t overdrive motors.  
- **KP**: how hard the robot corrects toward the line.  
- **KD**: damping to reduce oscillation.  
- **KI**: removes slow bias drift (use small values).  

> **Start point:** `BASE_SPEED=100–140, KP≈15–22, KD≈4–8, KI=0`.

---

## 🏁 Acceleration (smoother starts)

Jumps in PWM can cause brownouts and wheel slip. Add a simple ramp (if you want extra smoothness):

```cpp
// all_functions.ino
int prevL = 0, prevR = 0;
const int ACCEL_STEP = 8;        // PWM step per loop
const int ACCEL_DT_MS = 10;      // loop dt (approx)

void setMotorSmooth(int left, int right){
  left  = constrain(left,  -MAX_PWM, MAX_PWM);
  right = constrain(right, -MAX_PWM, MAX_PWM);

  // ramp toward targets
  if(left > prevL)  prevL = min(prevL + ACCEL_STEP, left);
  else              prevL = max(prevL - ACCEL_STEP, left);

  if(right > prevR) prevR = min(prevR + ACCEL_STEP, right);
  else              prevR = max(prevR - ACCEL_STEP, right);

  setMotor(prevL, prevR);
}
```

Then in `Robot_cart.ino` change the final drive line:
```cpp
// setMotor(left, right);
setMotorSmooth(left, right);
```

---

## 🎯 PID tuning (try‑and‑error that works)

Do this on a simple oval track:

1) **Zero KI:** set `KI=0.0`.  
2) **Raise KP** until you see fast corrections but **slight oscillation** on straights.  
3) **Add KD** (start at 4, go up) until oscillation calms and turns are clean.  
4) **Optionally add small KI** (0.2–0.6) only if the robot **biases to one side on long straights**.  
5) Increase **BASE_SPEED** once stable; re‑touch KD a little if oscillation returns.

**Symptoms → What to change**
- Wobbles left/right on straights → **Increase KD** (or reduce KP slightly)  
- Misses inside of turns → **Increase KP** or **BASE_SPEED** slightly  
- Drifts slowly off‑center → add small **KI** (≤0.6)  
- Sluggish to correct → **Increase KP** (and maybe BASE_SPEED)

---

## 🧵 Line sensor basics (black/white & threshold)

Your array feeds **A7..A0**. First, see raw values:

```cpp
// Quick debug: read raw analogs
for (int i = 0; i < 8; i++) {
  int v = analogRead(SENSOR_PINS[i]); // 0..1023
  Serial.print(v); Serial.print(i==7?'\n':'\t');
}
delay(50);
```

Typical readings (will vary by sensor height & floor):  
- **White floor:** ~150–400  
- **Black line:** ~600–950  

### Calibrating (already in code)
`calibrateSensors()` runs for ~2 seconds (hold Start while booting) and learns **min/max** per sensor as you move the cart over **white** and **black**.  
We then normalize to **0..1000** in `readLineSensors()` and compute a weighted position **0..7000**. Center is **3500**.

```cpp
// pin_setup.ino (already included)
int readLineSensors(int* out){
  long weighted = 0, sum = 0;
  for(int i=0;i<8;i++){
    int v = analogRead(SENSOR_PINS[i]);
    v = constrain(v, sensorMin[i], sensorMax[i]);
    int norm = map(v, sensorMin[i], sensorMax[i], 0, 1000); // white->0, black->1000
    out[i] = norm;
    weighted += (long)norm * (i * 1000);
    sum += norm;
  }
  if(sum == 0) return -1;           // line lost
  return (int)(weighted / sum);     // position 0..7000
}
```

> If your sensors output **inverted** (white high, black low), just swap the map ends: `map(..., 1000, 0)`.

### Simple threshold approach (alternative)
If you prefer plain thresholding:
```cpp
const int TH = 500; // pick mid of measured white/black
bool isBlack[8];
for (int i=0; i<8; i++) {
  int v = analogRead(SENSOR_PINS[i]);
  isBlack[i] = (v > TH); // invert if needed
}
```

---

## 🧭 Line error → steering

We use **position − 3500** as the error. Negative = line left, positive = line right.

```cpp
// sensor_array.ino
int computeLineError(){
  int pos = readLineSensors(sensorVal); // 0..7000, -1 if lost
  if (pos < 0) return 0;                // lost: go straight (or implement search)
  return pos - 3500;                    // center error
}
```

And in `Robot_cart.ino`:

```cpp
int err = computeLineError();     // ~ -3500..+3500
integral += err;                  // consider clamping integral to avoid windup
float deriv = (err - lastError);
lastError = err;

// PID
float steer = KP*err + KD*deriv + KI*integral;
steer /= 100.0f;                  // scale because error is large

int left  = BASE_SPEED - (int)steer;
int right = BASE_SPEED + (int)steer;
setMotorSmooth(left, right);      // or setMotor(...)
```

**Anti‑windup (optional):**
```cpp
integral = constrain(integral, -30000, 30000);
```

**Line lost strategy (simple):**
```cpp
if (pos < 0) {
  // lastError tells which way we were offset
  int spin = (lastError >= 0) ? +80 : -80;
  setMotor(BASE_SPEED - spin, BASE_SPEED + spin); // gentle scan
  return;
}
```

---

## 🚦 Safe power & noise tips
- Power **BTS7960** directly from the **11.1 V battery**, not from 5 V rail.  
- Tie **all grounds** together (battery −, LM2596 GND, Mega GND, drivers, sensors).  
- Add bulk capacitors **470–1000 µF** near each motor driver + **100 µF + 0.1 µF** at LM2596 OUT.  
- Keep motor wires **twisted** and **away** from I²C lines and the IR array ribbon.

---

## 🧪 Quick test checklist
1. **Sensors**: raw values change clearly over black vs white.  
2. **Calibration**: hold Start during boot; you should see different min/max per sensor.  
3. **Encoders**: spin wheels by hand—counts on D2/D3 increment.  
4. **Motors**: both sides spin in correct directions; swap **M+ / M−** if reversed.  
5. **Gyro**: heading changes when rotating robot (optional; used for stability).  

---

## ▶️ Getting started
1. Open `robot_cart/Robot_cart.ino` in Arduino IDE.  
2. Select **Board: Arduino Mega 2560**.  
3. Upload.  
4. Place robot on track → **Hold Start** during power‑up to calibrate → release → robot follows the line.

---

## 📜 License
Open‑source for education and personal projects. Attribution appreciated.
