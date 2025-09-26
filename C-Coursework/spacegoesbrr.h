#ifndef SPACEGOESBRR_H
#define SPACEGOESBRR_H

typedef struct Shuttle {
    int missionNumber;
    char startDate[21];  
    char missionName[21];
    char orbiter[21];
    char launchPad[21];
} Shuttle;

typedef struct Node {
    Shuttle data;
    struct Node* prev;
    struct Node* next;
} Node;

#endif // SPACEGOESBRR_H
