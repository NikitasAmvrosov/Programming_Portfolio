#ifndef FMS_H
#define FMS_H

#define r 6378.388


typedef struct Coordinate{

    double degree;
    double minute;
    double second;

}Coordinate;

typedef struct Time{

    unsigned char hour;
    unsigned char minute;

}Time;

typedef struct Airport{

    char icao[5];
    char iata[4];


    Coordinate latitude;
    Coordinate longitude;

    //Height above mean sea level
    float heightAMSL;

}Airport;

typedef struct Flightpath{

    char flightPathName[256];

    Airport *pDepartureAirport;
    Airport *pArrivalAirport;

    Time departure;
    Time arrival;

}FlightPath;

typedef struct Airplane{

    char airplaneName[256];
    char airVehicleRegistration[256];

    FlightPath *pFlightpath;

    unsigned int cntFlightPath;
}Airplane;

typedef struct Airline{

    char airlineName[256];

    Airplane *pAirplane;

    unsigned int cntAirplane;
}Airline;

typedef struct FMS{

    Airline *pAirline;
    unsigned int cntAirline;

}FMS;




#endif // FMS_H