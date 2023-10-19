#ifndef ConnectingFlight
#define ConnectingFlight

#include "flight.h"

class connectingFlight : public flight
{
private:
    string connectingPoint;
    double connectingDuration;

public:
    connectingFlight() : flight(), connectingPoint(""), connectingDuration(0){};

    bool operator==(connectingFlight anotherFlight);

    friend ostream &operator<<(ostream &stream, const connectingFlight &aconnectingFlight);
    friend istream &operator>>(istream &stream, connectingFlight &aconnectingFlight);
    friend ofstream &operator<<(ofstream &stream, const connectingFlight &aconnectingFlight);
    friend ifstream &operator>>(ifstream &stream, connectingFlight &aconnectingFlight);
};

#endif