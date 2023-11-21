#include "system.h"

ostream &operator<<(ostream &stream, const flightsSystem &asystem)
{
    stream << "ALL FLIGHTS" << endl;
    for (int i = 0; i < asystem.length; i++)
    {
        asystem.list[i]->display();
    }

    return stream;
}

istream &operator>>(istream &stream, flightsSystem &asystem)
{
    int inCountryCount;
    int outCountryCount;

    cout << "input all flights count: ";
    stream >> asystem.length;
    asystem.list = new flight *[asystem.length];
    cout << "input in country flights count";
    stream >> inCountryCount;
    for (int i = 0; i < inCountryCount; i++)
    {
        asystem.list[i] = new inCoutryFlight();
        asystem.list[i]->cin();
    }
    cout << "input out country flights count: ";
    stream >> outCountryCount;
    for (int i = 0; i < outCountryCount; i++)
    {
        asystem.list[inCountryCount + i] = new outCountryFlight();
        asystem.list[inCountryCount + i]->cin();
    }
    asystem.inCountryCount = inCountryCount;

    return stream;
}

void flightsSystem::writeToFile(ofstream &file)
{
    file << this->length << endl;
    file << this->inCountryCount << endl;
    for (int i = 0; i < this->length; i++)
    {
        this->list[i]->writeToFile(file);
    }
}

void flightsSystem::readFromFile(ifstream &file)
{
    file >> this->length;
    file >> this->inCountryCount;
    this->list = new flight *[this->length];

    for (int i = 0; i < this->inCountryCount; i++)
    {
        this->list[i] = new inCoutryFlight();
        this->list[i]->readFromFile(file);
    }
    for (int i = 0; i < this->length - this->inCountryCount; i++)
    {
        this->list[i + this->inCountryCount] = new outCountryFlight();
        this->list[i + this->inCountryCount]->readFromFile(file);
    }
}

void flightsSystem::getAircraftWithMaxSpeed()
{
    double maxSpeed = 0;

    for (int i = 0; i < this->length; i++)
    {
        maxSpeed = max(this->list[i]->getSpeed(), maxSpeed);
    }

    cout << "\n Flights with max speed \n"
         << endl;
    for (int i = 0; i < this->length; i++)
    {
        double currSpeed = this->list[i]->getSpeed();

        if (currSpeed >= maxSpeed)
        {
            cout << this->list[i]->getAircraft() << endl;
        }
    }
}

void flightsSystem::getTotalDistanceFromMoscow()
{
    int listLength = this->length;
    double distance = 0;

    for (int i = 0; i < listLength; i++)
    {
        if (this->list[i]->getFrom() == "Moscow")
        {
            distance += this->list[i]->getDistance();
        }
    }

    cout << "\n Total distance from Moscow: ";
    cout << distance << endl;
}

void flightsSystem::compareFromKeyboard()
{
    int type;
    cout << "input 1 to input in country, 2 to input out country";
    cin >> type;

    flight *comparing;
    if (type == 1)
    {
        comparing = new inCoutryFlight();
    }
    else
    {
        comparing = new outCountryFlight();
    }
    comparing->cin();

    bool isFounded = false;
    for (int i = 0; i < this->length; i++)
    {
        if (this->list[i]->isSame(comparing))
        {
            cout << "the same founed on " << i + 1 << "position" << endl;
            isFounded = true;
        }
    }

    if (!isFounded)
    {
        cout << "not found" << endl;
    }
}