# ==============================================
# BEGINNER-FRIENDLY ANNOTATED VERSION
# Every line below has a quick explanation.
# ==============================================
# Import statement: brings modules/functions into this file
import socket
# Import statement: brings modules/functions into this file
import threading

# Variable assignment: stores a value for later use
esp01_conn = None
# Variable assignment: stores a value for later use
esp32_conn = None

# Function definition: creates a reusable block of code
def handle_client(conn, addr, device_name):
# Code: executes an instruction
    global esp01_conn, esp32_conn
# Print: show a message in the console
    print(f"[{device_name}] Connected from {addr[0]}")

# Conditional: runs code only if the condition is True
    if device_name == "ESP-01":
# Variable assignment: stores a value for later use
        esp01_conn = conn
# Else-if: another branch of the conditional
    elif device_name == "ESP32":
# Variable assignment: stores a value for later use
        esp32_conn = conn

# Try block: attempt to run code that might fail
    try:
# While loop: repeat while a condition stays True
        while True:
# Variable assignment: stores a value for later use
            data = conn.recv(1024)
# Conditional: runs code only if the condition is True
            if not data:
# Break: exit the current loop early
                break

# Variable assignment: stores a value for later use
            message = data.decode('utf-8').strip()
# Print: show a message in the console
            print(f"[{device_name}] says: {message}")

# (Comment) Forward data to the other client
            # Forward data to the other client
# Conditional: runs code only if the condition is True
            if device_name == "ESP-01" and esp32_conn:
# Code: executes an instruction
                esp32_conn.sendall((f"[From ESP-01] {message}\n").encode())
# Else-if: another branch of the conditional
            elif device_name == "ESP32" and esp01_conn:
# Code: executes an instruction
                esp01_conn.sendall((f"[From ESP32] {message}\n").encode())

# (Comment) Optional: reply automatically
            # Optional: reply automatically
# Code: executes an instruction
            conn.sendall(f"[Server ACK] Received: {message}\n".encode())

# Except block: handle an error so the app keeps running
    except Exception as e:
# Print: show a message in the console
        print(f"[{device_name}] Error: {e}")

# Code: executes an instruction
    conn.close()
# Print: show a message in the console
    print(f"[{device_name}] Disconnected")

# Function definition: creates a reusable block of code
def start_server(port, device_name):
# Variable assignment: stores a value for later use
    server_socket = socket.socket()
# Code: executes an instruction
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
# Code: executes an instruction
    server_socket.bind(('0.0.0.0', port))
# Code: executes an instruction
    server_socket.listen(1)
# Print: show a message in the console
    print(f"Listening for {device_name} on port {port}...")

# While loop: repeat while a condition stays True
    while True:
# Code: executes an instruction
        conn, addr = server_socket.accept()
# Code: executes an instruction
        threading.Thread(target=handle_client, args=(conn, addr, device_name), daemon=True).start()

# (Comment) Start threads for ESP-01 and ESP32 servers
# Start threads for ESP-01 and ESP32 servers
# Code: executes an instruction
threading.Thread(target=start_server, args=(8888, "ESP-01"), daemon=True).start()
# Code: executes an instruction
threading.Thread(target=start_server, args=(9999, "ESP32"), daemon=True).start()

# (Comment) Keep the main thread alive
# Keep the main thread alive
# Print: show a message in the console
print("Python TCP server is running. Waiting for connections...")
# While loop: repeat while a condition stays True
while True:
# Pass: placeholder that does nothing
    pass
