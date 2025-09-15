# Damped Harmonic Oscillator Simulation ⚙️

This repository contains C programs that simulate a damped harmonic oscillator, a fundamental concept in physics and engineering. 
The simulations model the motion of a mass-spring-damper system using two different numerical integration methods to solve the second-order ordinary differential equation (ODE) of motion.

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

## 📂 Project Files

- ```Euler.c```: Implements the simulation using the Explicit Euler method.

- ```Euler-Cromer.c```: Implements the simulation using the Euler-Cromer method. This method is a more stable and energy-conserving alternative, especially for oscillatory systems.

- ```LICENSE```: The project's license (MIT)

