#include <stdio.h>

int main() {
    // Define physical constants and parameters
    double m = 5;          // Mass [kg]
    double k = 1.2;         // Spring constant [N/m]
    double c = 2;          // Damping coefficient [Ns/m]
    double dt = 0.01;        // Time step [s]
    double total_time = 15.0; // Total simulation time [s]

    // Initial conditions
    double x = 1.0;          // Initial position [m]
    double v = 0.0;          // Initial velocity [m/s]
    double t = 0.0;          // Initial time [s]

    // Create a file for outputting data
    FILE *data_file = fopen("damped_oscillation.txt", "w");
    if (data_file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Print a header for better data readability
    fprintf(data_file, "Time\tPosition\n");

    // Main simulation loop
    while (t <= total_time) {
        // Calculate acceleration
        double a = (-k * x - c * v) / m;

        // Update velocity and position using the Euler method
        v += a * dt;
        x += v * dt;

        // Write data to the file
        fprintf(data_file, "%f\t%f\n", t, x);

        // Advance the time
        t += dt;
    }

    // Close the file
    fclose(data_file);

    printf("Simulation complete. Data has been saved to 'damped_oscillation.txt'.\n");

    return 0;
}