#ifndef Flights
#define Flights

#include "utils.h"

class flights
{
private:
    Flight *list;
    int length;
    void reorderList(int size);
    void clearList();
    void setListElement(int index, Flight element);

public:
    void writeToFile(ofstream &file);
    void readFromFile(ifstream &file);
    void display();
    void getAircraftWithMaxSpeed();
    void getTotalDistanceFromMoscow();
};

#endif