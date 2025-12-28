# Project 1: Microcontroller Programming - GPIO, Timers & Interrupts

## 🎯 Objective

This project serves as a foundational exercise in embedded systems programming, focusing on direct hardware manipulation using **register-level C programming**. The goal is to gain a deep understanding of how to control a microcontroller's core peripherals—General Purpose Input/Output (GPIO), Timers, and Interrupts—without relying on high-level abstraction libraries.

The target platform for this implementation is the **ATmega328P** microcontroller (commonly found in the Arduino Uno).

## 🛠️ Technology Stack

*   **Microcontroller:** ATmega328P
*   **Programming Language:** Embedded C
*   **Development Environment:** Register-level programming (no Arduino framework)

## 📂 Project Structure

The repository is organized according to the submission requirements:

```
Project1_Basics/
├── Circuits/
│   ├── button_circuit.mmd
│   ├── button_circuit.png
│   ├── led_circuit.mmd
│   └── led_circuit.png
├── Screenshots/
├── Report.pdf
├── Report.md
├── GitHub Link.txt
├── README.md
├── led_blink_delay.c
├── led_blink_timer.c
├── button_input_read.c
├── square_wave_timer.c
├── timer_delay.c
├── exti_button_toggle.c
└── timer_interrupt_blink.c
```

## 📝 Task Implementation Details

The project is divided into three main sections, each demonstrating a core microcontroller concept.

### A. GPIO Programming

| File | Task Description | Concept Demonstrated |
| :--- | :--- | :--- |
| `led_blink_delay.c` | LED blink using a software delay (`_delay_ms`). | Basic GPIO output and blocking software timing. |
| `led_blink_timer.c` | LED blink using a hardware timer (polling method). | Precise timing using Timer/Counter registers in a polling loop. |
| `button_input_read.c` | Read button input and display state on an LED. | GPIO input configuration, internal pull-up resistor usage, and state reading. |

### B. Timer Programming

| File | Task Description | Concept Demonstrated |
| :--- | :--- | :--- |
| `square_wave_timer.c` | Generate 1Hz/2Hz/5Hz square waves. | Using Timer/Counter in **CTC (Clear Timer on Compare Match)** mode to generate a precise PWM signal. |
| `timer_delay.c` | Build a custom `delay_ms()` function using timer registers. | Implementing a non-blocking-friendly delay function by manually configuring a timer. |

### C. Interrupts

| File | Task Description | Concept Demonstrated |
| :--- | :--- | :--- |
| `exti_button_toggle.c` | External interrupt toggles LED. | Configuring **External Interrupts (INT0)** to respond to a button press (falling edge) and executing an **ISR (Interrupt Service Routine)**. |
| `timer_interrupt_blink.c` | Timer interrupt causes LED blink. | Configuring a Timer/Counter to trigger an interrupt at a fixed interval, demonstrating non-blocking, precise timing. |

## 📄 Documentation

A comprehensive **Report.pdf** (and its source **Report.md**) is included, detailing the methodology, register configurations, and technical explanations for each task.

## 🔌 Circuit Diagrams

The `Circuits/` folder contains diagrams for the basic LED and button connections, illustrating the required hardware setup for testing the code.

## 🔗 GitHub Link

The `GitHub Link.txt` file is a placeholder. Please update it with the URL of your final repository.
