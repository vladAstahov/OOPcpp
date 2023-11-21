#ifndef OutCountryFlight
#define OutCountryFlight

#include "flight.h"

class outCountryFlight : public flight
{
private:
    string from;
    string to;
    string country;

public:
    virtual bool isSame(outCountryFlight *anotherFlight);

    virtual string getFrom();
    virtual void display();
    virtual void cin();
    virtual void readFromFile(ifstream &file);
    virtual void writeToFile(ofstream &file);
};

#endif