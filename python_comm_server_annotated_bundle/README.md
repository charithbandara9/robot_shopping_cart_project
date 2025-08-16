# 🖥️ Python Communication Server — Beginner-Friendly Guide

This folder contains the **Python TCP server** used by your shopping robot system
to receive messages (like destinations or scan results) from devices
such as the **ESP32‑CAM** and the **handheld ESP32 remote**.

## ✅ What's in here
- Original `.py` files (unchanged)
- **`.annotated.py`** versions with **line‑by‑line explanations** above every line
- This README with setup and run instructions

## ▶️ How to run
```bash
# 1) (Optional) Create a virtual environment
python -m venv .venv && source .venv/bin/activate  # Windows: .venv\Scripts\activate

# 2) Install requirements (if there's a requirements.txt here)
pip install -r requirements.txt  # or just 'pip install pyzbar opencv-python' if needed

# 3) Start the server
python server.py     # or whichever main file your project uses
```

> If your main file has a **different name**, run that instead.
> The **annotated** versions end with `.annotated.py`; they are meant for learning,
> but you should run the **original** `.py` file for production.

## 🔌 What the server does (typical flow)
1. Open a TCP socket and **listen** on a port (e.g., `0.0.0.0:5050`).
2. **Accept** a client (ESP32, robot, or camera).
3. **Read** text messages or binary frames.
4. **Parse** commands (e.g., `HELLO`, `GOTO:VEGETABLES`, `STATUS:...`).
5. **Respond** with `ACK`, status, or results.
6. Loop for the next message or client.

## 🧱 Example message exchange
**Client → Server**
```
HELLO,REMOTE
GOTO:VEGETABLES
HEARTBEAT:-58,3.98
```
**Server → Client**
```
ACK
STATUS:ROUTING
STATUS:ARRIVED
```

## 🛠️ Common options in code
- `HOST = "0.0.0.0"` — accept connections from any network interface
- `PORT = 5050` — choose a free port; open it in your firewall/router if needed
- `TIMEOUT = 3.0` — socket timeout to avoid hanging reads
- `BUFF_SIZE = 4096` — how much to read per `recv()` call

## 🧪 Test locally
Open two terminals:
1. **Server:** `python server.py`
2. **Client:** `nc 127.0.0.1 5050` (or `telnet 127.0.0.1 5050`) and type `HELLO`

## 🔐 Safety
- Never expose your server directly to the Internet without authentication.
- Keep your network private (local router), or add a simple token check in messages.

## 🧯 Troubleshooting
- **Address already in use** → change `PORT`, or stop the old server.
- **Nothing received** → verify client IP/port and firewall settings.
- **UnicodeDecodeError** → handle bytes carefully; decode with `errors="ignore"` for quick tests.
- **BrokenPipeError** → client disconnected; catch the exception and keep the server running.

Happy building!
