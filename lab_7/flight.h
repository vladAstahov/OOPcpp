#ifndef Flight
#define Flight

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class flight
{
protected:
    double duration;
    string number;
    string airline;
    double distance;
    string aircraft;
    long int passangers;

public:
    double getSpeed();
    string getAircraft();
    double getDistance();

    virtual string getFrom();
    virtual bool isSame(flight *anotherFlight);

    virtual void display();
    virtual void cin();
    virtual void readFromFile(ifstream &file);
    virtual void writeToFile(ofstream &file);
};

#endif