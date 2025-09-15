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

## 🧠 About the Methods
Programs solve the differential equation for a damped harmonic oscillator, but they use different numerical methods to approximate the solution over time.

### Explicit Euler Method (```Euler.c```)
This is a simple, first-order method. It calculates the new position based on the old velocity and the new velocity based on the old acceleration. While easy to implement, it can introduce numerical errors that cause the simulated energy to increase or decrease over time, making it less stable for long-term oscillatory simulations.

### Euler-Cromer Method (```Euler-Cromer.c```)
The Euler-Cromer method is a slight but crucial modification. It first calculates the new velocity and then uses this updated velocity to calculate the new position. This simple change significantly improves the method's stability and accuracy, especially for systems that conserve energy (like an undamped oscillator), making it a popular choice in physics simulations.

---

## 📈 Visualizing the Results
The output files (```damped_oscillation_Euler.txt``` and ```damped_oscillation_Euler_Cromer.txt```) are simple text files with two columns: Time (s) and Position (m). You can easily plot this data to compare the two methods.

### Using Python and Matplotlib

