#include <stdio.h>
#include <stdlib.h>

double acceleration(double position, double velocity, double mass, double spring_const, double damping_coeff) {
    // F = -k*x - b*v
    return (-spring_const * position - damping_coeff * velocity) / mass;
}

int main() {
    // Parametry systému
    double mass = 5.0;
    double spring_const = 1.2;
    double damping_coeff = 2.0;
    double delta_t = 0.01;
    double total_time = 15.0;

    // Počáteční podmínky
    double position = 1.0;
    double velocity = 0.0;
    double current_time = 0.0;

    FILE *data_file = fopen("damped_oscillation_RK4.txt", "w");
    if (!data_file) {
        fprintf(stderr, "Chyba při otevírání souboru!\n");
        return EXIT_FAILURE;
    }
    fprintf(data_file, "Time (s)\tPosition (m)\n");

    while (current_time <= total_time) {
        // Záznam dat
        fprintf(data_file, "%f\t%f\n", current_time, position);

        // RK4 integrace
        double k1x = velocity;
        double k1v = acceleration(position, velocity, mass, spring_const, damping_coeff);

        double k2x = velocity + 0.5 * delta_t * k1v;
        double k2v = acceleration(position + 0.5 * delta_t * k1x, velocity + 0.5 * delta_t * k1v, mass, spring_const, damping_coeff);

        double k3x = velocity + 0.5 * delta_t * k2v;
        double k3v = acceleration(position + 0.5 * delta_t * k2x, velocity + 0.5 * delta_t * k2v, mass, spring_const, damping_coeff);

        double k4x = velocity + delta_t * k3v;
        double k4v = acceleration(position + delta_t * k3x, velocity + delta_t * k3v, mass, spring_const, damping_coeff);

        position += (delta_t / 6.0) * (k1x + 2*k2x + 2*k3x + k4x);
        velocity += (delta_t / 6.0) * (k1v + 2*k2v + 2*k3v + k4v);
        current_time += delta_t;
    }

    fclose(data_file);
    printf("Simulace dokončena. Data uložena v 'damped_oscillation_RK4.txt'.\n");
    return EXIT_SUCCESS;
}