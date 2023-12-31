#ifndef Flight
#define Flight

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class flight
{
private:
    double distance;
    string number;
    string airline;
    string from;
    string to;
    double duration;
    string aircraft;
    long int passangers;

public:
    flight();
    flight(ofstream &outfile);
    flight(ifstream &file);
    void display();
    double getSpeed();
    string getAircraft();
    string getFrom();
    double getDistance();
};

#endif