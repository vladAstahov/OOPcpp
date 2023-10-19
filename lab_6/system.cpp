#include "system.h"

void flightsSystem::clearList()
{
    delete[] this->list;
    delete[] this->connectingList;
}

void flightsSystem::reorderList(int N, int type)
{
    if (type == 0)
    {
        this->list = new flight[N];
        this->lenght = N;
    }
    else
    {
        this->connectingList = new connectingFlight[N];
        this->connectingLenght = N;
    }
}

void flightsSystem::expandList(int N, int type)
{
    if (type == 0)
    {
        flight *old = new flight[this->lenght];
        int oldLenght = this->lenght;

        for (int i = 0; i < this->lenght; i++)
        {
            old[i] = this->list[i];
        }
        this->reorderList(N, type);

        for (int i = 0; i < oldLenght; i++)
        {
            this->list[i] = old[i];
        }
    }
    else
    {
        connectingFlight *old = new connectingFlight[this->lenght];
        int oldLenght = this->connectingLenght;

        for (int i = 0; i < this->connectingLenght; i++)
        {
            old[i] = this->connectingList[i];
        }
        this->reorderList(N, type);

        for (int i = 0; i < oldLenght; i++)
        {
            this->connectingList[i] = old[i];
        }
    }
}

flightsSystem::flightsSystem()
{
    this->reorderList(0, 0);
    this->reorderList(0, 1);
}

flightsSystem::~flightsSystem()
{
    this->clearList();
}

ostream &operator<<(ostream &stream, const flightsSystem &asystem)
{
    stream << "flights:" << endl;
    for (int i = 0; i < asystem.lenght; i++)
    {
        stream << asystem.list[i];
    }

    stream << "connecting flights:" << endl;
    for (int i = 0; i < asystem.connectingLenght; i++)
    {
        stream << asystem.connectingList[i];
    }

    return stream;
}
istream &operator>>(istream &stream, flightsSystem &asystem)
{
    int N;
    cout << "input flighs count \n";
    stream >> N;

    asystem.reorderList(N, 0);

    for (int i = 0; i < N; i++)
    {
        flight newFlight;
        stream >> newFlight;
        asystem.list[i] = newFlight;
    }

    cout << "input connection flights count" << endl;
    stream >> N;

    asystem.reorderList(N, 1);

    for (int i = 0; i < N; i++)
    {
        connectingFlight newFlight;
        stream >> newFlight;
        asystem.connectingList[i] = newFlight;
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

    stream << asystem.connectingLenght << endl;

    for (int i = 0; i < asystem.connectingLenght; i++)
    {
        stream << asystem.connectingList[i];
    }

    return stream;
}
ifstream &operator>>(ifstream &stream, flightsSystem &asystem)
{
    int N;
    stream >> N;
    asystem.lenght = N;

    asystem.reorderList(N, 0);

    for (int i = 0; i < N; i++)
    {
        flight newFlight;
        stream >> newFlight;
        asystem.list[i] = newFlight;
    }

    stream >> N;
    asystem.connectingLenght = N;

    asystem.reorderList(N, 1);

    for (int i = 0; i < N; i++)
    {
        connectingFlight newFlight;
        stream >> newFlight;
        asystem.connectingList[i] = newFlight;
    }

    return stream;
}

int flightsSystem::operator+=(flight newFlight)
{
    this->expandList(this->lenght + 1, 0);
    this->list[this->lenght - 1] = newFlight;
    return this->lenght;
}

int flightsSystem::operator+=(connectingFlight newFlight)
{
    this->expandList(this->connectingLenght + 1, 1);
    this->connectingList[this->connectingLenght - 1] = newFlight;
    return this->connectingLenght;
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