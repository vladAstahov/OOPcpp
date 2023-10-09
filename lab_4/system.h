#ifndef FlightsSystem
#define FlightsSystem

#include "flight.h"

class flightsSystem
{
private:
    flight *list;
    int lenght;
    void reorderList(int N);
    void clearList();

public:
    flightsSystem();
    flightsSystem(ofstream &outfile);
    flightsSystem(ifstream &file);
    ~flightsSystem();

    void display();
    void getAircraftWithMaxSpeed();
    void getTotalDistanceFromMoscow();
};

#endif