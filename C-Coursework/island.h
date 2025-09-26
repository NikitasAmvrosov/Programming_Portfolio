#ifndef ISLAND_H_
#define ISLAND_H_

typedef struct Time{

    unsigned int hour;
    unsigned int minute;

}Time;

typedef struct Island{   

    char islandName[50];
    Time begin;
    Time end;
    
}Island;                 

// External declarations for data arrays
extern Island Information[];
extern Island Tour[4][5];
extern int tourSizes[4];

#endif /* ISLAND_H_ */
