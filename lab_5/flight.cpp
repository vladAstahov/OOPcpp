#include "flight.h"

flight::flight()
{
    this->number = "";
    this->aircraft = "";
    this->from = "";
    this->to = "";
    this->distance = 0;
    this->duration = 0;
    this->aircraft = "";
    this->passangers = 0;
}

ostream &operator<<(ostream &stream, const flight &aflight)
{
    stream << "====================" << endl;
    stream << "Number: " << aflight.number << endl;
    stream << "Airline: " << aflight.airline << endl;
    stream << "From: " << aflight.from << endl;
    stream << "To: " << aflight.to << endl;
    stream << "Distance: " << aflight.distance << endl;
    stream << "Duration: " << aflight.duration << endl;
    stream << "Aircraft: " << aflight.aircraft << endl;
    stream << "Passangers count: " << aflight.passangers << endl;

    return stream;
}

istream &operator>>(istream &stream, flight &aflight)
{
    cout << "input number: ";
    stream >> aflight.number;
    cout << "input airline: ";
    stream >> aflight.airline;
    cout << "input from: ";
    stream >> aflight.from;
    cout << "input to: ";
    stream >> aflight.to;
    cout << "input distance: ";
    stream >> aflight.distance;
    cout << "input duration: ";
    stream >> aflight.duration;
    cout << "input aircraft: ";
    stream >> aflight.aircraft;
    cout << "input passangers: ";
    stream >> aflight.passangers;

    return stream;
}

ofstream &operator<<(ofstream &stream, const flight &aflight)
{
    stream << aflight.number << endl;
    stream << aflight.airline << endl;
    stream << aflight.from << endl;
    stream << aflight.to << endl;
    stream << aflight.distance << endl;
    stream << aflight.duration << endl;
    stream << aflight.aircraft << endl;
    stream << aflight.passangers << endl;

    return stream;
}

ifstream &operator>>(ifstream &stream, flight &aflight)
{
    stream >> aflight.number;
    stream >> aflight.airline;
    stream >> aflight.from;
    stream >> aflight.to;
    stream >> aflight.distance;
    stream >> aflight.duration;
    stream >> aflight.aircraft;
    stream >> aflight.passangers;

    return stream;
}

bool flight::operator==(flight anotherFlight)
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

    return true;
}

double flight::getSpeed()
{
    return this->distance / this->duration;
}

string flight::getAircraft()
{
    return this->aircraft;
}

string flight::getFrom()
{
    return this->from;
}

double flight::getDistance()
{
    return this->distance;
}