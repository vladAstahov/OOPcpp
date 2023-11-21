#include "flight.h"

double flight::getSpeed()
{
    return this->distance / this->duration;
};

string flight::getAircraft()
{
    return this->aircraft;
}

double flight::getDistance()
{
    return this->distance;
}

string flight::getFrom()
{
    return "";
}

bool flight::isSame(flight *anotherFlight)
{
    if (anotherFlight->duration != this->duration)
        return false;
    if (anotherFlight->number != this->number)
        return false;
    if (anotherFlight->airline != this->airline)
        return false;
    if (anotherFlight->distance != this->distance)
        return false;
    if (anotherFlight->aircraft != this->aircraft)
        return false;
    if (anotherFlight->passangers != this->passangers)
        return false;

    return true;
}

void flight::display()
{
    cout << "====================" << endl;
    cout << "Number: " << this->number << endl;
    cout << "Airline: " << this->airline << endl;
    cout << "Distance: " << this->distance << endl;
    cout << "Duration: " << this->duration << endl;
    cout << "Aircraft: " << this->aircraft << endl;
    cout << "Passangers count: " << this->passangers << endl;
}

void flight::cin()
{
    cout << "input number: ";
    std::cin >> this->number;
    cout << "input airline: ";
    std::cin >> this->airline;
    cout << "input distance: ";
    std::cin >> this->distance;
    cout << "input duration: ";
    std::cin >> this->duration;
    cout << "input aircraft: ";
    std::cin >> this->aircraft;
    cout << "input passangers: ";
    std::cin >> this->passangers;
}

void flight::readFromFile(ifstream &file)
{
    file >> this->number;
    file >> this->airline;
    file >> this->distance;
    file >> this->duration;
    file >> this->aircraft;
    file >> this->passangers;
}

void flight::writeToFile(ofstream &file)
{
    file << this->number << endl;
    file << this->airline << endl;
    file << this->distance << endl;
    file << this->duration << endl;
    file << this->aircraft << endl;
    file << this->passangers << endl;
}