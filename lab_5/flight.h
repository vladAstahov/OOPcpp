#ifndef Flight
#define Flight

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class flight
{
private:
    double duration;
    string number;
    string airline;
    string from;
    string to;
    double distance;
    string aircraft;
    long int passangers;

public:
    flight();
    double getSpeed();
    string getAircraft();
    string getFrom();
    double getDistance();

    bool operator==(flight anotherFlight);

    friend ostream &operator<<(ostream &stream, const flight &aflight);
    friend istream &operator>>(istream &stream, flight &aflight);
    friend ofstream &operator<<(ofstream &stream, const flight &aflight);
    friend ifstream &operator>>(ifstream &stream, flight &aflight);
};

#endif