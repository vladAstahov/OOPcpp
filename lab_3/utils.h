#ifndef flights_utils
#define flights_utils

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct Flight
{
    string number;
    string airline;
    string from;
    string to;
    double distance;
    double duration;
    string aircraft;
    long int passangers;
};

Flight cinFlight();
Flight ifFlight(ifstream &file);
void coutFlight(Flight flight);
void ofFlight(ofstream &file, Flight newFlight);
double getAircraftSpeed(Flight flight);

#endif