#include <stdio.h>
#include "fms.h"


Airport airports[] = {
    {"EDDH", "HAM", {53, 37, 49}, {9, 59, 18}, 16.0},   // Hamburg
    {"EDDB", "BER", {52, 21, 44}, {13, 30, 2}, 48.0},   // Berlin-Brandenburg
    {"EDDL", "DUS", {51, 16, 51}, {6, 45, 26}, 44.0},   // Düsseldorf
    {"EDDK", "CGN", {50, 51, 57}, {7, 8, 34}, 92.0},    // Cologne/Bonn
    {"EDDF", "FRA", {50, 1, 59}, {8, 34, 14}, 111.0},   // Frankfurt
    {"EDDS", "STR", {48, 41, 24}, {9, 13, 19}, 389.0},  // Stuttgart
    {"EDDM", "MUC", {48, 21, 14}, {11, 47, 10}, 453.0}, // Munich
};

FlightPath flightPathsLufthansa[] = {
    {"LH 2147", &airports[6], &airports[0], {11, 30}, {14, 30}}, // MUC to HAM
    {"LH 2147", &airports[0], &airports[4], {15, 30}, {16, 30}}, // HAM to FRA
    {"LH 2147", &airports[4], &airports[6], {18, 30}, {20, 30}}, // FRA to MUC
    {"LH 2147", &airports[6], &airports[0], {20, 45}, {22, 0}},  // MUC to HAM
    {"LH 2147", &airports[0], &airports[6], {22, 30}, {23, 30}}  // HAM to MUC
};

FlightPath flightPathsEuroWings[] = {
    {"EW 5953", &airports[6], &airports[2], {3, 0}, {4, 15}},    // MUC to DUS
    {"EW 5953", &airports[2], &airports[1], {8, 0}, {10, 0}},    // DUS to BER
    {"EW 5953", &airports[1], &airports[3], {10, 12}, {13, 15}}, // BER to CGN
    {"EW 5953", &airports[3], &airports[6], {18, 0}, {20, 30}},  // CGN to MUC
    {"EW 5953", &airports[6], &airports[2], {21, 45}, {23, 30}}  // MUC to DUS
};

FlightPath flightPathsTUIfly[] = {
    {"X3 2174", &airports[0], &airports[5], {8, 0}, {10, 0}},   // HAM to STR
    {"X3 2174", &airports[5], &airports[1], {10, 15}, {13, 0}}, // STR to BER
    {"X3 2174", &airports[1], &airports[4], {13, 10}, {15, 0}}, // BER to FRA
    {"X3 2174", &airports[4], &airports[0], {15, 12}, {17, 0}}, // FRA to HAM
    {"X3 2174", &airports[0], &airports[4], {22, 0}, {24, 0}}   // HAM to FRA
};

Airplane airplanesLufthansa[] = {
    {"A380", "D-AIMA", flightPathsLufthansa, 5}
};

Airplane airplanesEuroWings[] = {
    {"A320", "D-AIAB", flightPathsEuroWings, 5}
};

Airplane airplanesTUIfly[] = {
    {"B747", "D-ABCD", flightPathsTUIfly, 5}
};

Airline airlines[] = {
    {"Lufthansa", airplanesLufthansa, 1},
    {"EuroWings", airplanesEuroWings, 1},
    {"TUIFly", airplanesTUIfly, 1}
};

FMS fms = {
    airlines,
    3
};

