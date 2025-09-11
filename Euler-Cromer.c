#include <stdio.h>
#include <stdlib.h>

/**
 * @file main.c
 * @brief Simulates a damped harmonic oscillator using the Euler-Cromer method.
 *
 * This program models the motion of a mass-spring-damper system. It calculates the position
 * and velocity of the mass over time and writes the results to a file. The Euler-Cromer
 * method is a numerical integration technique that improves upon the basic explicit Euler
 * method by using the *updated* velocity to calculate the new position, which helps
 * conserve energy better and is more stable for oscillatory systems.
 */
int main(void) {
    // --- 1. PHYSICAL CONSTANTS AND SIMULATION PARAMETERS ---
    // These values define the properties of the physical system and the simulation's resolution.
    double mass = 5.0;            // [kg] Mass of the object.
    double spring_const = 1.2;    // [N/m] The spring constant (Hooke's Law).
    double damping_coeff = 2.0;   // [Ns/m] Coefficient of damping (viscous friction).
    double delta_t = 0.01;        // [s] The time step for numerical integration. Smaller values
                                  // lead to higher accuracy but longer simulation times.
    double total_time = 15.0;     // [s] The total duration of the simulation.

    // --- 2. INITIAL CONDITIONS ---
    // The state of the system at the beginning of the simulation (time t=0).
    double position = 1.0;        // [m] Initial displacement from the equilibrium position.
    double velocity = 0.0;        // [m/s] Initial velocity of the mass.
    double current_time = 0.0;    // [s] The current simulation time.

    // --- 3. FILE HANDLING ---
    // Opens a file to save the simulation data for later analysis (e.g., plotting).
    FILE *data_file = fopen("damped_oscillation_Euler_Cromer.txt", "w");
    if (data_file == NULL) {
        // Error handling for file opening failure.
        fprintf(stderr, "Error opening the output file!\n");
        return EXIT_FAILURE; // A more standard way to indicate an error.
    }

    // Write a header to the file for easy data interpretation.
    fprintf(data_file, "Time (s)\tPosition (m)\n");

    // --- 4. MAIN SIMULATION LOOP ---
    // This loop iteratively calculates the state of the system at each time step.
    while (current_time <= total_time) {
        // --- 4a. CALCULATION OF ACCELERATION ---
        // Based on Newton's second law (F=ma), where F = F_spring + F_damping.
        // F_spring = -spring_const * position (Hooke's Law)
        // F_damping = -damping_coeff * velocity
        double acceleration = (-spring_const * position - damping_coeff * velocity) / mass;

        // --- 4b. NUMERICAL INTEGRATION (EULER-CROMER METHOD) ---
        // Update velocity using the calculated acceleration.
        velocity += acceleration * delta_t;
        
        // Update position using the *newly calculated* velocity.
        // This is the key difference from the basic Euler method and improves stability.
        position += velocity * delta_t;

        // --- 4c. DATA LOGGING ---
        // Store the current time and position in the output file.
        fprintf(data_file, "%f\t%f\n", current_time, position);

        // --- 4d. TIME ADVANCEMENT ---
        // Move to the next time step.
        current_time += delta_t;
    }

    // --- 5. CLEANUP ---
    // Close the file to ensure all data is written and resources are freed.
    fclose(data_file);

    printf("Simulation complete. Data has been saved to 'damped_oscillation_Euler_Cromer.txt'.\n");

    return EXIT_SUCCESS; // A standard way to indicate successful program execution.
}