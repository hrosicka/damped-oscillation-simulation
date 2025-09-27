# Damped Harmonic Oscillator Simulation ⚙️

This repository contains C programs that simulate a damped harmonic oscillator, a fundamental concept in physics and engineering. 
The simulations model the motion of a mass-spring-damper system using 3 different numerical integration methods to solve the second-order ordinary differential equation (ODE) of motion.

- **Explicit Euler Method**
- **Euler-Cromer Method**
- **Runge-Kutta RK4 Method**

Each method computes the position of the mass over time and outputs the results to a separate data file for analysis and visualization.

---

## 🧠 Methods Overview

### 1. Explicit Euler Method
A simple first-order integration technique. It updates the position using the velocity from the previous time step. Suitable for basic simulations but may become unstable for stiff or oscillatory systems.

- **Source file:** `Euler.c`
- **Output:** `damped_oscillation_Euler.txt`

### 2. Euler-Cromer Method
A modification of the Euler method that uses the updated velocity to compute the new position, offering improved stability for oscillatory systems.

- **Source file:** `Euler-Cromer.c`
- **Output:** `damped_oscillation_Euler_Cromer.txt`

### 3. Runge-Kutta RK4 Method
A fourth-order integration method that evaluates the system at multiple intermediate points within each time step, providing much higher accuracy.

- **Source file:** `Runge-Kutta-RK4.c`
- **Output:** `damped_oscillation_RK4.txt

---

## 🚀 Getting Started

To run these simulations, you will need a C compiler (like GCC) installed on your system.

**Compiling and Running**

1. Clone the repository
   
2. Compile the ```Euler.c``` program:
   ```bash
   gcc Euler.c -o euler
   ```
   
3. Compile the ```Euler-Cromer.c``` program:
   ```bash
   gcc Euler-Cromer.c -o euler-cromer
   ```

4. Run the Euler simulation
   This will generate a file named ```damped_oscillation_Euler.txt``` with the simulation data.
   
5. Run the Euler-Cromer simulation
   This will generate a file named ```damped_oscillation_Euler_Cromer.txt``` with its data.

---

## 📂 Files

- `Euler.c` — Explicit Euler method implementation
- `Euler-Cromer.c` — Euler-Cromer method implementation
- `Runge-Kutta-RK4.c` — Runge-Kutta RK4 method implementation
- `plot.py` — Python script for result visualization
- `damped_oscillation_Euler.txt`, `damped_oscillation_Euler_Cromer.txt`, `damped_oscillation_RK4.txt` — Simulation outputs
- `comparison_plot.png` — Comparison plot of all methods

---

## 📈 Visualization

The results from all three methods can be compared using the provided Python script:

- **Plot script:** `plot.py`
- **Output plot:** `comparison_plot.png`

```bash
python plot.py
```

---

## 📜 License
This project is licensed under the MIT License. For more details, see the ```LICENSE``` file.

Feel free to experiment with different physical parameters or time step values to observe how each method behaves!

