# MIPS Pipeline Simulator

A C++ project that simulates the execution of instructions in a classic **5-stage MIPS pipeline**. The project demonstrates how pipeline hazards are handled using:

- **Stalling with Forwarding**
- **Instruction Reordering with Forwarding**

The project also generates output files and visualizations to help understand instruction flow and pipeline performance.

---

# Features

- Simulates a MIPS pipelined processor
- Detects instruction dependencies
- Handles data hazards
- Supports forwarding and stalling techniques
- Applies instruction reordering optimization
- Generates execution results in text files
- Includes Python visualization support

---

# Pipeline Stages

The simulator follows the standard 5-stage MIPS pipeline:

1. **IF** — Instruction Fetch
2. **ID** — Instruction Decode
3. **EX** — Execute
4. **MEM** — Memory Access
5. **WB** — Write Back

---

# Project Structure

```bash
.
├── solve.cpp
├── input.hpp
├── stallForwarding.hpp
├── reorderingForwarding.hpp
├── Dep.hpp
├── visuals.py
├── Dep.txt
├── StallForwarding.txt
├── reorderingForwarding.txt
├── order.txt
├── speedUp1.txt
├── speedUp2.txt
└── README.md
```

---

# Technologies Used

- C++
- Python
- STL (Standard Template Library)

---

# How It Works

## 1. Input Processing
The simulator reads MIPS instructions and extracts:

- Instruction type
- Source registers
- Destination registers
- Dependency distances

---

## 2. Dependency Detection
Dependencies between instructions are analyzed and stored.

Examples:

- RAW (Read After Write)
- Data hazards

---

## 3. Stall + Forwarding Simulation
The simulator inserts stalls when required and applies forwarding whenever possible.

Generated file:

```bash
StallForwarding.txt
```

---

## 4. Instruction Reordering
Instructions are reordered to reduce stalls and improve performance.

Generated files:

```bash
reorderingForwarding.txt
order.txt
```

---

## 5. Performance Calculation
The simulator calculates pipeline speedup.

Generated files:

```bash
speedUp1.txt
speedUp2.txt
```

---

# Build and Run

## Compile

Using g++:

```bash
g++ solve.cpp -o solve
```

---

## Run

### Windows

```bash
solve.exe
```

### Linux / macOS

```bash
./solve
```

---

# Visualization

The project automatically runs the Python visualization script:

```bash
visuals.py
```

Make sure Python is installed before running the project.

---

# Example Output

Example speedup result:

```bash
Speed Up = 1.67
```

---

# Learning Objectives

This project helps understand:

- Computer Architecture concepts
- Pipeline execution
- Hazard detection
- Forwarding techniques
- Instruction scheduling
- Performance optimization

---

# Future Improvements

Possible future enhancements:

- Branch prediction support
- Cache simulation
- More MIPS instructions
- GUI visualization
- Cycle-by-cycle animation

---

# Authors

Developed as a Computer Architecture / MIPS Pipeline project.

---

# License

This project is for educational purposes.

