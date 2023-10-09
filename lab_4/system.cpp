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

flightsSystem::flightsSystem()
{
    this->reorderList(0);
}

flightsSystem::flightsSystem(ofstream &outfile)
{
    int N;
    cout << "input elements count \n";
    cin >> N;

    outfile << N << endl;
    this->reorderList(N);

    for (int i = 0; i < N; i++)
    {
        flight newFlight(outfile);
        this->list[i] = newFlight;
    }
}

flightsSystem::flightsSystem(ifstream &file)
{
    int N;
    file >> N;
    this->reorderList(N);

    for (int i = 0; i < N; i++)
    {
        flight newFlight(file);
        this->list[i] = newFlight;
    }
}

flightsSystem::~flightsSystem()
{
    this->clearList();
}

void flightsSystem::display()
{
    for (int i = 0; i < this->lenght; i++)
    {
        this->list[i].display();
    }
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