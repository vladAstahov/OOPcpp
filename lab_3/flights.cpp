#include "flights.h";

using namespace std;

/* private */
void flights::clearList()
{
    delete this->list;
}

void flights::reorderList(int size)
{
    this->clearList();
    this->list = new Flight[size];
    this->length = size;
}

void flights::setListElement(int index, Flight element)
{
    this->list[index] = element;
}

/* file methods */
void flights::readFromFile(ifstream &file)
{
    int N;
    file >> N;
    this->reorderList(N);

    for (int i = 0; i < N; i++)
    {
        Flight newFlight = ifFlight(file);
        this->setListElement(i, newFlight);
    }
}

void flights::writeToFile(ofstream &file)
{
    int N;
    cout << "input elements count \n";
    cin >> N;

    file << N << endl;
    this->reorderList(N);

    for (int i = 0; i < N; i++)
    {
        Flight newFlight = cinFlight();
        ofFlight(file, newFlight);
        this->setListElement(i, newFlight);
    }
}

/* display methods */
void flights::display()
{
    int listLength = this->length;

    for (int i = 0; i < listLength; i++)
    {
        coutFlight(this->list[i]);
    }
}

void flights::getAircraftWithMaxSpeed()
{
    int listLength = this->length;

    double maxSpeed = 0;

    for (int i = 0; i < listLength; i++)
    {
        maxSpeed = max(getAircraftSpeed(this->list[i]), maxSpeed);
    }

    cout << "\n Flights with max speed \n"
         << endl;
    for (int i = 0; i < listLength; i++)
    {
        double currSpeed = getAircraftSpeed(this->list[i]);

        if (currSpeed >= maxSpeed)
        {
            cout << this->list[i].aircraft << endl;
        }
    }
}

void flights::getTotalDistanceFromMoscow()
{
    int listLength = this->length;
    double distance = 0;

    for (int i = 0; i < listLength; i++)
    {
        if (this->list[i].from == "Moscow")
        {
            distance += this->list[i].distance;
        }
    }

    cout << "\n Total distance from Moscow: ";
    cout << distance << endl;
}