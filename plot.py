import matplotlib.pyplot as plt
import numpy as np

# Load data from the simulation files for all three methods
data_euler = np.loadtxt('damped_oscillation_Euler.txt', skiprows=1)
data_euler_cromer = np.loadtxt('damped_oscillation_Euler_Cromer.txt', skiprows=1)
data_rk4 = np.loadtxt('damped_oscillation_RK4.txt', skiprows=1)

# Extract time and position for each method
time_euler, pos_euler = data_euler[:, 0], data_euler[:, 1]
time_euler_cromer, pos_euler_cromer = data_euler_cromer[:, 0], data_euler_cromer[:, 1]
time_rk4, pos_rk4 = data_rk4[:, 0], data_rk4[:, 1]

# Create the plot
plt.figure(figsize=(10, 6))
plt.plot(time_euler, pos_euler, label='Explicit Euler Method', linestyle='--', color='red')
plt.plot(time_euler_cromer, pos_euler_cromer, label='Euler-Cromer Method', linestyle='-.', color='blue')
plt.plot(time_rk4, pos_rk4, label='Runge-Kutta RK4 Method', linestyle='-', color='green')

# Add labels and title
plt.title('Comparison of Damped Oscillator Simulation Methods')
plt.xlabel('Time [s]')
plt.ylabel('Position [m]')
plt.legend()
plt.grid(True)
plt.savefig('comparison_plot.png')
plt.show()

print("Plot saved as 'comparison_plot.png'.")