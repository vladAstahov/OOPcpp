#ifndef InCountryFlight
#define InCountryFlight

#include "flight.h"

class inCoutryFlight : public flight
{
private:
    string from;
    string to;

public:
    virtual bool isSame(inCoutryFlight *anotherFlight);

    virtual string getFrom();
    virtual void display();
    virtual void cin();
    virtual void readFromFile(ifstream &file);
    virtual void writeToFile(ofstream &file);
};

#endif