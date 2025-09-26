#include <stdio.h>
#include <math.h>

// Given constant
#define Earth_radius 6378.388

// Prototype Helper functions
double calculateDegree(double deg, double min, double sec);
double sinDeg(double deg);
double cosDeg(double deg);
double resultCalc();

int main() {

    // User Input
    printf("Please enter latitude in ° ’ ” and longitude in ° ’ ” for departure and arrival: \n");

    double result = resultCalc();

    // Output the distance
    printf("Flight Distance in km is %.2f\n", result);

    return 0;
}

// Help formulas
double calculateDegree(double deg, double min, double sec) {
    return deg + min / 60.0 + sec / 3600.0;
}

double sinDeg(double deg) {
    return sin(deg * M_PI / 180.0);
}

double cosDeg(double deg) {
    return cos(deg * M_PI / 180.0);
}

double resultCalc() {
    double deplat_deg, deplat_min, deplat_sec;
    double deplon_deg, deplon_min, deplon_sec;
    double arrlat_deg, arrlat_min, arrlat_sec;
    double arrlon_deg, arrlon_min, arrlon_sec;

    // Use separate variables for the results instead of 'result'
    scanf("%lf%*s %lf%*s %lf%*s %lf%*s %lf%*s %lf%*s %lf%*s %lf%*s %lf%*s %lf%*s %lf%*s %lf%*s",
        &deplat_deg, &deplat_min, &deplat_sec,
        &deplon_deg, &deplon_min, &deplon_sec,
        &arrlat_deg, &arrlat_min, &arrlat_sec,
        &arrlon_deg, &arrlon_min, &arrlon_sec);

    // Coordinates reformat 
    double deplat = calculateDegree(deplat_deg, deplat_min, deplat_sec);
    double deplon = calculateDegree(deplon_deg, deplon_min, deplon_sec);
    double arrlat = calculateDegree(arrlat_deg, arrlat_min, arrlat_sec);
    double arrlon = calculateDegree(arrlon_deg, arrlon_min, arrlon_sec);

    // Calculate the distance with the given formula
    double distance = Earth_radius * acos(sinDeg(arrlat) * sinDeg(deplat) + cosDeg(arrlat) * cosDeg(deplat) * cosDeg(arrlon - deplon));

    return distance;
}
