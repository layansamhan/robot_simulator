# 🤖 Virtual Robot Simulator

Hi! I’m **Layan Samhan**, and this is a personal C programming project: a **2D virtual robot simulator**. I built it to explore how to simulate basic robot behavior using command parsing, state tracking, and logic flow in C.

---

## 🧠 What It Does

This program simulates a simple robot that moves around a 2D grid. You can control the robot by typing commands or loading them from a script. The robot can:

* Move forward
* Turn left or right
* Pick up objects
* Drop objects
* Report its current status

It keeps track of its direction, position, and whether it's holding something. It also responds to invalid commands with clear error messages.

---

## 🕹️ How It Works

* The robot starts at a default position facing a default direction.
* It takes input either **interactively** or from a **.txt script file**.
* The input is processed command by command, updating the robot’s state.
* It’s written in **pure C**, using basic concepts like loops, functions, and conditionals.

---

## 🧪 Example Commands

```
MOVE
TURN RIGHT
MOVE
PICK
STATUS
DROP
TURN LEFT
MOVE
STATUS
```

---

## 💻 To Run It

1. Compile the code with a C compiler (e.g. `gcc`):

   ```bash
   gcc -o robot_simulator main.c
   ```
2. Run it interactively:

   ```bash
   ./robot_simulator
   ```
3. Or with a command script:

   ```bash
   ./robot_simulator script.txt
   ```

---

## 🧱 Core Concepts Used

* State machines
* Command parsing
* CLI interaction
* Modular code structure
* Error handling

---

## 🎯 Why I Built This

I wanted to challenge myself with a small simulation project and get better at managing program state and command handling. It gave me practical experience with logic flow and structuring programs cleanly in C.
