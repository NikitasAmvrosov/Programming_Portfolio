#include "island.h"

// Initialize the Information array
Island Information[] = {
    {"Amity Island", {9, 0}, {17, 0}},
    {"Craggy Island", {9, 0}, {16, 0}},
    {"Isla Numbar", {7, 0}, {12, 0}},
    {"Shutter Island", {8, 0}, {20, 0}},
    {"Skull Island", {8, 0}, {17, 30}}
};

// Declare the Tour array and tourSizes array
Island Tour[4][5];
int tourSizes[4] = {4, 4, 3, 5};

// Function to initialize the Tour array
void initializeTourData() {
    Tour[0][0] = Information[0];
    Tour[0][1] = Information[1];
    Tour[0][2] = Information[2];
    Tour[0][3] = Information[0];

    Tour[1][0] = Information[4];
    Tour[1][1] = Information[1];
    Tour[1][2] = Information[2];
    Tour[1][3] = Information[4];

    Tour[2][0] = Information[3];
    Tour[2][1] = Information[4];
    Tour[2][2] = Information[3];

    Tour[3][0] = Information[2];
    Tour[3][1] = Information[4];
    Tour[3][2] = Information[3];
    Tour[3][3] = Information[0];
    Tour[3][4] = Information[2];
}
