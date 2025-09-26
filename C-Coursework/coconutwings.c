#include <stdio.h>
#include "island.h"

// Prototype functions
void initializeTourData();
void print_island_info(Island island);
void printTour(int tourNumber, Island Tour[][5], int tourSizes[]);
void outputFormatting(Island Tour[][5], int tourSizes[]);

// Function to print the island information
void print_island_info(Island island){

    printf("Island : %s\n", island.islandName);
    printf("Opening hours: %02d:%02d - %02d:%02d\n", island.begin.hour, island.begin.minute, island.end.hour, island.end.minute);
}

// Function to handle user input and display the corresponding tour
void printTour(int tourNumber, Island Tour[][5], int tourSizes[]){

    printf("---------------------------------------------------\n");
    printf("---------------- Tour %d ---------------------------\n", tourNumber);
    printf("---------------------------------------------------\n");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < tourSizes[tourNumber - 1]; i++){

        print_island_info(Tour[tourNumber - 1][i]);
        printf("---------------------------------------------------\n");
    }

    printf("%26s", "End\n");
}

// Function to handle user input and display the corresponding tour
void outputFormatting(Island Tour[][5], int tourSizes[]){

    int tourNumber;

    do {

        printf("Please enter a tour number (1-4) or enter the number 0 to exit the program: \n");
        scanf("%d", &tourNumber);

        if (tourNumber == 0){

            printf("Exiting the program...\n");
            return;

        } else if (tourNumber >= 1 && tourNumber <= 4){

            printTour(tourNumber, Tour, tourSizes);

        } else{

            printf("Invalid tour number, please enter a number between 1 and 4.\n");
        }

    } while (tourNumber != 0);
}

int main(){

    // Initializes the tour array
    initializeTourData();
    outputFormatting(Tour, tourSizes);

    return 0;
}
