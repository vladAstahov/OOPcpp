#ifndef FlightsSystem
#define FlightsSystem

#include "connectingFlight.h"

class flightsSystem
{
private:
    flight *list;
    connectingFlight *connectingList;
    int lenght;
    int connectingLenght;
    void reorderList(int N, int type); // type === 1 - list : connectingList
    void expandList(int N, int type);

public:
    flightsSystem();
    ~flightsSystem();
    void clearList();

    int operator+=(flight newFlight);
    int operator+=(connectingFlight newFlight);

    void readConnectionFromFile(ifstream file);
    void readFlightsFromFile(ifstream file);
    void writeConnectionToFile(ofstream file);
    void writeFlightsToFile(ofstream file);

    friend ostream &operator<<(ostream &stream, const flightsSystem &asystem);
    friend istream &operator>>(istream &stream, flightsSystem &asystem);
    friend ofstream &operator<<(ofstream &stream, const flightsSystem &asystem);
    friend ifstream &operator>>(ifstream &stream, flightsSystem &asystem);

    void getAircraftWithMaxSpeed();
    void getTotalDistanceFromMoscow();
    void compareFromKeyboard();
};

#endif