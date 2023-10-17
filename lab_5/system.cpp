#include "system.h"

void flightsSystem::clearList()
{
    delete[] this->list;
}

void flightsSystem::reorderList(int N)
{
    this->list = new flight[N];
    this->lenght = N;
}

void flightsSystem::expandList(int N)
{
    flight *old = new flight[this->lenght];
    int oldLenght = this->lenght;

    for (int i = 0; i < this->lenght; i++)
    {
        old[i] = this->list[i];
    }
    this->reorderList(N);

    for (int i = 0; i < oldLenght; i++)
    {
        this->list[i] = old[i];
    }
}

flightsSystem::flightsSystem()
{
    this->reorderList(0);
}

flightsSystem::~flightsSystem()
{
    this->clearList();
}

ostream &operator<<(ostream &stream, const flightsSystem &asystem)
{
    for (int i = 0; i < asystem.lenght; i++)
    {
        stream << asystem.list[i];
    }

    return stream;
}
istream &operator>>(istream &stream, flightsSystem &asystem)
{
    int N;
    cout << "input elements count \n";
    stream >> N;

    asystem.reorderList(N);

    for (int i = 0; i < N; i++)
    {
        flight newFlight;
        stream >> newFlight;
        asystem.list[i] = newFlight;
    }

    return stream;
}

ofstream &operator<<(ofstream &stream, const flightsSystem &asystem)
{
    stream << asystem.lenght << endl;

    for (int i = 0; i < asystem.lenght; i++)
    {
        stream << asystem.list[i];
    }

    return stream;
}
ifstream &operator>>(ifstream &stream, flightsSystem &asystem)
{
    int N;
    stream >> N;
    asystem.reorderList(N);

    for (int i = 0; i < N; i++)
    {
        stream >> asystem.list[i];
    }

    return stream;
}

int flightsSystem::operator+=(flight newFlight)
{
    this->expandList(this->lenght + 1);
    this->list[this->lenght - 1] = newFlight;
    return this->lenght;
}

void flightsSystem::getAircraftWithMaxSpeed()
{
    double maxSpeed = 0;

    for (int i = 0; i < this->lenght; i++)
    {
        maxSpeed = max(this->list[i].getSpeed(), maxSpeed);
    }

    cout << "\n Flights with max speed \n"
         << endl;
    for (int i = 0; i < this->lenght; i++)
    {
        double currSpeed = this->list[i].getSpeed();

        if (currSpeed >= maxSpeed)
        {
            cout << this->list[i].getAircraft() << endl;
        }
    }
}

void flightsSystem::getTotalDistanceFromMoscow()
{
    int listLength = this->lenght;
    double distance = 0;

    for (int i = 0; i < listLength; i++)
    {
        if (this->list[i].getFrom() == "Moscow")
        {
            distance += this->list[i].getDistance();
        }
    }

    cout << "\n Total distance from Moscow: ";
    cout << distance << endl;
}

void flightsSystem::compareFromKeyboard()
{
    flight comparingFlight;
    cin >> comparingFlight;
    bool isFined = false;

    for (int i = 0; i < this->lenght; i++)
    {
        if (this->list[i] == comparingFlight)
        {
            cout << i + 1 << " flight is similar";
            isFined = true;
        }
    }

    if (!isFined)
    {
        cout << "no similar flights";
    }
}