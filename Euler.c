#include <stdio.h>

int main() {
    // Definice fyzikálních konstant a parametrů
    double m = 5.0;            // Hmotnost [kg]
    double k = 1.2;            // Konstanta pružiny [N/m]
    double c = 2.0;            // Koeficient tlumení [Ns/m]
    double dt = 0.01;          // Časový krok [s]
    double total_time = 15.0;  // Celková doba simulace [s]

    // Počáteční podmínky
    double x = 1.0;            // Počáteční poloha [m]
    double v = 0.0;            // Počáteční rychlost [m/s]
    double t = 0.0;            // Počáteční čas [s]

    // Vytvoření souboru pro výstup dat
    FILE *data_file = fopen("damped_oscillation_Euler.txt", "w");
    if (data_file == NULL) {
        printf("Chyba při otevírání souboru!\n");
        return 1;
    }

    // Tisk hlavičky pro lepší čitelnost dat
    fprintf(data_file, "Time\tPosition\n");

    // Hlavní simulační smyčka
    while (t <= total_time) {
        // Výpočet zrychlení
        double a = (-k * x - c * v) / m;

        // Explicitní Eulerova metody
        // Uložení staré rychlosti před aktualizací
        double v_old = v;

        // Aktualizace rychlosti
        v += a * dt;
        
        // Aktualizace polohy pomocí staré rychlosti
        x += v_old * dt;

        // Zápis dat do souboru
        fprintf(data_file, "%f\t%f\n", t, x);

        // Posun času
        t += dt;
    }

    // Uzavření souboru
    fclose(data_file);

    printf("Simulace dokončena. Data byla uložena do souboru 'damped_oscillation_Euler.txt'.\n");

    return 0;
}