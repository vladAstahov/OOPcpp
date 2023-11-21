#include "out-country-flight.h"

bool outCountryFlight::isSame(outCountryFlight *anotherFlight)
{
    if (this->from != anotherFlight->from)
        return false;
    if (this->to != anotherFlight->to)
        return false;
    if (this->country != anotherFlight->country)
        return false;
    return flight::isSame(anotherFlight);
}

void outCountryFlight::display()
{
    flight::display();
    cout << "From: " << this->from << endl;
    cout << "To: " << this->to << endl;
    cout << "Country: " << this->country << endl;
}

void outCountryFlight::cin()
{
    flight::cin();
    cout << "input from: ";
    std::cin >> this->from;
    cout << "input to: ";
    std::cin >> this->to;
    cout << "input country: ";
    std::cin >> this->country;
}

void outCountryFlight::readFromFile(ifstream &file)
{
    flight::readFromFile(file);
    file >> this->from;
    file >> this->to;
    file >> this->country;
}

void outCountryFlight::writeToFile(ofstream &file)
{
    flight::writeToFile(file);
    file << this->from << endl;
    file << this->to << endl;
    file << this->country << endl;
}

string outCountryFlight::getFrom()
{
    return this->from;
}