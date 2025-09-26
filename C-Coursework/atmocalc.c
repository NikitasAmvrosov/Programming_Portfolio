#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 9.81           // Gravitational constant
#define R 287            // Gas constant for air
#define N 1.235          // Polytropic exponent
#define T_ZERO 288.15    // Temperature of standard atmosphere
#define RHO_ZERO 1.225   // Density of standard atmosphere
#define N_RATIO ((N - 1) / N)

// Structure to hold airport data
typedef struct {
    int latidude,
            longitude,
            temperature,
            pressure,
            altitude;

} AirportData;

// Prototype Helper functions
void userInput(AirportData* pAirportData);
void calculations(AirportData* data);

// Main function
int main() {
    AirportData Data;

    // Get user input for airport data
    userInput(&Data);

    // Perform calculations and print results
    calculations(&Data);

    return 0;
}

// Function to get user input for airport data
void userInput(AirportData* pAirportData) {
    printf("Please enter latitude, longitude, temperature and pressure for the airport: \n");

    // Read input values, check for correctness, and assign altitude based on coordinates
    if (scanf("%d %d %d %d", &(pAirportData->latidude), &(pAirportData->longitude), &(pAirportData->temperature), &(pAirportData->pressure)) != 4) {
        printf("Wrong coordinates entered!\n");
        exit(1);
    }

    // Check for specific coordinates and assign corresponding height
    if (pAirportData->latidude == 48 && pAirportData->longitude == 9) {
        pAirportData->altitude = 388;  // Assign the height for Stuttgart
    } else if (pAirportData->latidude == 52 && pAirportData->longitude == 13) {
        pAirportData->altitude = 37;   // Assign the height for Berlin
    } else if (pAirportData->latidude == 48 && pAirportData->longitude == 11) {
        pAirportData->altitude = 453;  // Assign the height for München
    } else if (pAirportData->latidude == 50 && pAirportData->longitude == 8) {
        pAirportData->altitude = 110;  // Assign the height for Frankfurt
    } else {
        // If coordinates do not match, print an error message and exit
        printf("Wrong coordinates entered!\n");
        exit(1);
    }
}

// Function to perform calculations and print results
void calculations(AirportData* data) {
    // Convert temperature to Kelvin and pressure to Pa
    double T = data->temperature + 273.15;   // Correct
    double p = data->pressure * 100;         // Correct

    // Calculate temperature at sea level, standard air density, actual air density, and pressure altitude
    double T_0 = T + N_RATIO * (G / R) * data->altitude;
    double rho_0 = p / (R * T_0);
    double rho = rho_0 * pow((1 - N_RATIO * (G / (R * T_0)) * data->altitude), (1 / (N - 1)));
    double H_rho = (pow((rho / RHO_ZERO), (N - 1)) - 1) * (-N / (N - 1)) * ((R * T_ZERO) / G);

    // Print the calculated values
    printf("T_0 = %.3fK, rho_0 = %.3fkg/m³, rho = %.3fkg/m³, H = %.3fm \n", T_0, rho_0, rho, H_rho);
}