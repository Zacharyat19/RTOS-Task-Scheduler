# Simulated-Embedded-Device-Kernel

## Overview

This project simulates a simple Real-Time Operating System (RTOS) in C++ with basic task scheduling, inter-task communication, hardware abstraction, and time-based control.

The RTOS supports:
- Cooperative multitasking
- Round-robin or priority-based scheduling
- Software timers
- Simulated ADC, UART, GPIO, and IPC components
- Sleep-based task delays

## Project Structure
```bash
/embedded-kernel-sim/
├── main.cpp
├── RTOS/
│   ├── Task.h / Task.cpp
│   ├── Scheduler.h / Scheduler.cpp
│   ├── RTOS.h / RTOS.cpp
│   └── Timer.h / Timer.cpp
├── HAL/
│   ├── GPIO.h / GPIO.cpp
│   ├── UART.h / UART.cpp
│   └── ADC.h / ADC.cpp
├── Drivers/
│   ├── SensorDriver.h / SensorDriver.cpp
│   └── Communication.h / Communication.cpp
└── Utils/
    ├── MessageQueue.h / MessageQueue.cpp
```
## Tasks in `main.cpp`

- **Sensor Task**  
  Reads from a simulated ADC and sends the value to a shared message queue.

- **Communication Task**  
  Receives messages from the queue and sends them over UART.

- **GPIO Task**  
  Periodically toggles a simulated GPIO pin (e.g., LED heartbeat or output control).

## How It Works

- `RTOS::start()` runs a scheduler loop indefinitely.
- Each tick:
  - Sleeping tasks are updated via the timer.
  - The scheduler picks the next READY task based on the active policy.
  - The selected task executes its body function.
  - If the task hasn’t changed its own state, it’s returned to READY.
