#ifndef FlightsSystem
#define FlightsSystem

#include "in-country-flight.h"
#include "out-country-flight.h"

class flightsSystem
{
private:
    flight **list;
    int length;
    int inCountryCount;
    void reorderList(int N);

public:
    void clearList();

    friend ostream &operator<<(ostream &stream, const flightsSystem &asystem);
    friend istream &operator>>(istream &stream, flightsSystem &asystem);

    void readFromFile(ifstream &file);
    void writeToFile(ofstream &file);
    void getAircraftWithMaxSpeed();
    void getTotalDistanceFromMoscow();
    void compareFromKeyboard();
};

#endif