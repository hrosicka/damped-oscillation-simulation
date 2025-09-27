#include <stdio.h>
#include <stdlib.h>

/**
 * @file Runge-Kutta-RK4.c
 * @brief Simulates a damped harmonic oscillator using the classical Runge-Kutta (RK4) method.
 *
 * This program models the motion of a mass-spring-damper system, calculating the position
 * and velocity of the mass over time using the RK4 integration technique. RK4 provides
 * significantly improved accuracy over the Euler and Euler-Cromer methods by evaluating
 * the state of the system at several intermediate points within each time step.
 * The simulation results are written to a file for further analysis or visualization.
 */

/**
 * @brief Calculates the acceleration of the mass at a given position and velocity.
 *
 * The acceleration is derived from Newton's second law (F=ma), where
 * F = F_spring + F_damping.
 * F_spring = -spring_const * position (Hooke's Law)
 * F_damping = -damping_coeff * velocity
 *
 * @param position Current displacement from equilibrium [m].
 * @param velocity Current velocity of the mass [m/s].
 * @param mass Mass of the object [kg].
 * @param spring_const Spring constant [N/m].
 * @param damping_coeff Damping coefficient [Ns/m].
 * @return Calculated acceleration [m/s^2].
 */
double acceleration(double position, double velocity, double mass, double spring_const, double damping_coeff) {
    return (-spring_const * position - damping_coeff * velocity) / mass;
}

int main(void) {
    // --- 1. PHYSICAL CONSTANTS AND SIMULATION PARAMETERS ---
    double mass = 5.0;            // [kg] Mass of the object.
    double spring_const = 1.2;    // [N/m] Spring constant (Hooke's Law).
    double damping_coeff = 2.0;   // [Ns/m] Damping coefficient (viscous friction).
    double delta_t = 0.01;        // [s] Time step for numerical integration.
    double total_time = 15.0;     // [s] Total duration of simulation.

    // --- 2. INITIAL CONDITIONS ---
    double position = 1.0;        // [m] Initial displacement from equilibrium.
    double velocity = 0.0;        // [m/s] Initial velocity.
    double current_time = 0.0;    // [s] Simulation time counter.

    // --- 3. FILE HANDLING ---
    // Open file for saving simulation data.
    FILE *data_file = fopen("damped_oscillation_RK4.txt", "w");
    if (data_file == NULL) {
        fprintf(stderr, "Error opening the output file!\n");
        return EXIT_FAILURE;
    }
    // Write header for data file.
    fprintf(data_file, "Time (s)\tPosition (m)\n");

    // --- 4. MAIN SIMULATION LOOP ---
    // Iteratively compute the system state using RK4 integration.
    while (current_time <= total_time) {
        // --- 4a. DATA LOGGING ---
        fprintf(data_file, "%f\t%f\n", current_time, position);

        // --- 4b. RUNGE-KUTTA RK4 INTEGRATION ---
        // RK4 evaluates four increments (k1, k2, k3, k4) for both position and velocity.
        double k1x = velocity;
        double k1v = acceleration(position, velocity, mass, spring_const, damping_coeff);

        double k2x = velocity + 0.5 * delta_t * k1v;
        double k2v = acceleration(position + 0.5 * delta_t * k1x,
                                  velocity + 0.5 * delta_t * k1v,
                                  mass, spring_const, damping_coeff);

        double k3x = velocity + 0.5 * delta_t * k2v;
        double k3v = acceleration(position + 0.5 * delta_t * k2x,
                                  velocity + 0.5 * delta_t * k2v,
                                  mass, spring_const, damping_coeff);

        double k4x = velocity + delta_t * k3v;
        double k4v = acceleration(position + delta_t * k3x,
                                  velocity + delta_t * k3v,
                                  mass, spring_const, damping_coeff);

        // Update position and velocity using weighted average of increments.
        position += (delta_t / 6.0) * (k1x + 2*k2x + 2*k3x + k4x);
        velocity += (delta_t / 6.0) * (k1v + 2*k2v + 2*k3v + k4v);

        // --- 4c. TIME ADVANCEMENT ---
        current_time += delta_t;
    }

    // --- 5. CLEANUP ---
    fclose(data_file);
    printf("Simulation complete. Data has been saved to 'damped_oscillation_RK4.txt'.\n");
    return EXIT_SUCCESS;
}