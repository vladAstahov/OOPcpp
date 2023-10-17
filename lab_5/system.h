#ifndef FlightsSystem
#define FlightsSystem

#include "flight.h"

class flightsSystem
{
private:
    flight *list;
    int lenght;
    void reorderList(int N);
    void expandList(int N);

public:
    flightsSystem();
    ~flightsSystem();
    void clearList();

    int operator+=(flight newFlight);

    friend ostream &operator<<(ostream &stream, const flightsSystem &asystem);
    friend istream &operator>>(istream &stream, flightsSystem &asystem);
    friend ofstream &operator<<(ofstream &stream, const flightsSystem &asystem);
    friend ifstream &operator>>(ifstream &stream, flightsSystem &asystem);

    void getAircraftWithMaxSpeed();
    void getTotalDistanceFromMoscow();
    void compareFromKeyboard();
};

#endif