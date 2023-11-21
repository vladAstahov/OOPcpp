#include "in-country-flight.h"

bool inCoutryFlight::isSame(inCoutryFlight *anotherFlight)
{
    cout << "inCoutryFlight::operator==" << endl;
    if (this->from != anotherFlight->from)
        return false;
    cout << "after first comparing" << endl;
    if (this->to != anotherFlight->to)
        return false;
    return flight::isSame(anotherFlight);
}

void inCoutryFlight::display()
{
    flight::display();
    cout << "From: " << this->from << endl;
    cout << "To: " << this->to << endl;
}

void inCoutryFlight::cin()
{
    flight::cin();
    cout << "input from: ";
    std::cin >> this->from;
    cout << "input to: ";
    std::cin >> this->to;
}

void inCoutryFlight::readFromFile(ifstream &file)
{
    flight::readFromFile(file);
    file >> this->from;
    file >> this->to;
}

void inCoutryFlight::writeToFile(ofstream &file)
{
    flight::writeToFile(file);
    file << this->from << endl;
    file << this->to << endl;
}

string inCoutryFlight::getFrom()
{
    return this->from;
}