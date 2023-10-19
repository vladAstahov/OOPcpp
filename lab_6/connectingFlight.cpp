#include "connectingFlight.h"

ostream &operator<<(ostream &stream, const connectingFlight &aconnectingFlight)
{
    stream << static_cast<flight>(aconnectingFlight);
    stream << "Connecting point: " << aconnectingFlight.connectingPoint << endl;
    stream << "Connecting duration" << aconnectingFlight.connectingDuration << endl;

    return stream;
}

istream &operator>>(istream &stream, connectingFlight &aconnectingFlight)
{
    cout << "input number: ";
    stream >> aconnectingFlight.number;
    cout << "input airline: ";
    stream >> aconnectingFlight.airline;
    cout << "input from: ";
    stream >> aconnectingFlight.from;
    cout << "input to: ";
    stream >> aconnectingFlight.to;
    cout << "input distance: ";
    stream >> aconnectingFlight.distance;
    cout << "input duration: ";
    stream >> aconnectingFlight.duration;
    cout << "input aircraft: ";
    stream >> aconnectingFlight.aircraft;
    cout << "input passangers: ";
    stream >> aconnectingFlight.passangers;
    cout << "input connecting point: ";
    stream >> aconnectingFlight.connectingPoint;
    cout << "input connecting duration: ";
    stream >> aconnectingFlight.connectingDuration;

    return stream;
}

ofstream &operator<<(ofstream &stream, const connectingFlight &aconnectingFlight)
{
    stream << static_cast<flight>(aconnectingFlight);
    stream << aconnectingFlight.connectingPoint << endl;
    stream << aconnectingFlight.connectingDuration << endl;

    return stream;
}

ifstream &operator>>(ifstream &stream, connectingFlight &aconnectingFlight)
{
    stream >> aconnectingFlight.number;
    stream >> aconnectingFlight.airline;
    stream >> aconnectingFlight.from;
    stream >> aconnectingFlight.to;
    stream >> aconnectingFlight.distance;
    stream >> aconnectingFlight.duration;
    stream >> aconnectingFlight.aircraft;
    stream >> aconnectingFlight.passangers;
    stream >> aconnectingFlight.connectingPoint;
    stream >> aconnectingFlight.connectingDuration;

    return stream;
}

bool connectingFlight::operator==(connectingFlight anotherFlight)
{
    if (this->number != anotherFlight.number)
        return false;
    if (this->duration != anotherFlight.duration)
        return false;
    if (this->airline != anotherFlight.airline)
        return false;
    if (this->from != anotherFlight.from)
        return false;
    if (this->to != anotherFlight.to)
        return false;
    if (this->distance != anotherFlight.distance)
        return false;
    if (this->aircraft != anotherFlight.aircraft)
        return false;
    if (this->passangers != anotherFlight.passangers)
        return false;
    if (this->connectingDuration != anotherFlight.connectingDuration)
        return false;
    if (this->connectingPoint != anotherFlight.connectingPoint)
        return false;

    return true;
}