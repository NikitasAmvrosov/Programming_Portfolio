#include <stdio.h>
#include <math.h>
#include "fms.h"

// Prototype functions
void printTime(Time time);
int durationCalculation(Time departure, Time arrival);
void printDuration(int duration);

void Generate_Time_Table(FMS *pFMS);
void Generate_Distance_Table(FMS *pFMS);
void Generate_Duration_Table(FMS *pFMS);


// Time Table Section
void printTime(Time time){
    printf("%02u:%02u", time.hour, time.minute);
}

void Generate_Time_Table(FMS *pFMS){
    printf("   Airline|Flight No.|from|  to|Departure| Arrival|Airplane\n");
    printf("----------|----------|----|----|---------|--------|--------\n");

    for (unsigned int i = 0; i < pFMS -> cntAirline; i++){
        Airline *airline = &pFMS -> pAirline[i];

        for (unsigned int j = 0; j < airline -> cntAirplane; j++){
            Airplane *airplane = &airline -> pAirplane[j];

            for (unsigned int k = 0; k < airplane -> cntFlightPath; k++){
                FlightPath *flightPath = &airplane -> pFlightpath[k];

                // Flight details
                printf("%10s|%10s|%4s|%4s|    ",
                
                    airline -> airlineName,
                    flightPath -> flightPathName,
                    flightPath -> pDepartureAirport -> iata,
                    flightPath -> pArrivalAirport -> iata);

                // Departure
                printTime(flightPath->departure);
                printf("|   ");

                // Arrival
                printTime(flightPath->arrival);
                printf("|");

                // Airplane
                printf("  %6s\n", airplane->airVehicleRegistration);

            }

            printf("\n");
        }
    }
}

// Distance section
// Conversion for the distance formula
double calculateDegree(double deg, double min, double sec);
double sinDeg(double deg);
double cosDeg(double deg);

double calculateDegree(double deg, double min, double sec){
    return deg + min / 60.0 + sec / 3600.0;
}

double sinDeg(double deg){
    return sin(deg * M_PI / 180.0);
}

double cosDeg(double deg){
    return cos(deg * M_PI / 180.0);
}


void Generate_Distance_Table(FMS *pFMS){

    for (unsigned int i = 0; i < pFMS -> cntAirline; i++){

        printf("   Airline|Flight No.|from|  to|Distance\n");
        printf("----------|----------|----|----|--------\n");

        Airline *airline = &pFMS->pAirline[i];

        double totalDistance = 0;

        for (unsigned int j = 0; j < airline -> cntAirplane; j++){
            Airplane *airplane = &airline -> pAirplane[j];

            for (unsigned int k = 0; k < airplane -> cntFlightPath; k++){
                FlightPath *flightPath = &airplane -> pFlightpath[k];

                // Accesses departure and arrival airports through the FlightPath
                Airport *departure = flightPath->pDepartureAirport;
                Airport *arrival = flightPath->pArrivalAirport;

                // Extracts latitude and longitude components for departure and arrival airports
                double deplat = calculateDegree(departure->latitude.degree, departure->latitude.minute, departure->latitude.second);
                double deplon = calculateDegree(departure->longitude.degree, departure->longitude.minute, departure->longitude.second);
                double arrlat = calculateDegree(arrival->latitude.degree, arrival->latitude.minute, arrival->latitude.second);
                double arrlon = calculateDegree(arrival->longitude.degree, arrival->longitude.minute, arrival->longitude.second);

                // Calculates distance using the extracted components
                double distance = r * acos(sinDeg(deplat) * sinDeg(arrlat) + cosDeg(deplat) * cosDeg(arrlat) * cosDeg(arrlon - deplon));
                totalDistance += distance;

                printf("%10s|%10s|%4s|%4s| %.2f\n",
                       airline -> airlineName,
                       flightPath -> flightPathName,
                       departure->iata,
                       arrival->iata,
                       distance);

            }

            printf("\n");
            printf("Total flight distance for %s %s is %.2f\n", airline->airlineName, airplane -> airplaneName, totalDistance);
            printf("\n");

        }

    }
}

// Time Duration Section
int durationCalculation(Time departure, Time arrival) {
    int minutesDeparture = departure.hour * 60 + departure.minute;
    int minutesArrival = arrival.hour * 60 + arrival.minute;

    int duration = minutesArrival - minutesDeparture;

    // Overnight flights
    if (duration < 0) {
        duration += 24 * 60;
    }

    return duration;
}

void printDuration(int duration) {
    int hours = duration / 60;
    int minutes = duration % 60;
    printf("%02d:%02d", hours, minutes);
}

void Generate_Duration_Table(FMS *pFMS){

    for (unsigned int i = 0; i < pFMS -> cntAirline; i++) {
        
        printf("   Airline|Flight No.|from|  to|Duration\n");
        printf("----------|----------|----|----|--------\n");

        Airline *airline = &pFMS->pAirline[i];

        int totalDuration = 0;

        for (unsigned int j = 0; j < airline->cntAirplane; j++){
            
            Airplane *airplane = &airline->pAirplane[j];

            for (unsigned int k = 0; k < airplane->cntFlightPath; k++){
                FlightPath *flightPath = &airplane->pFlightpath[k];

                int duration = durationCalculation(flightPath->departure, flightPath->arrival);
                totalDuration += duration;

                printf("%10s|%10s|%4s|%4s|  ",
                       airline -> airlineName,
                       flightPath -> flightPathName,
                       flightPath -> pDepartureAirport -> iata,
                       flightPath -> pArrivalAirport -> iata);

                printDuration(duration);
                printf("\n");
            }

            printf("\n");

            printf("Total flight Time for %s %s is ", airline -> airlineName, airplane -> airplaneName);
            printDuration(totalDuration);
            printf("\n");
            printf("\n");

        }  
    }
}




