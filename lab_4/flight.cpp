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

flight::flight(ofstream &outfile)
{
    cout << "input number: ";
    cin >> this->number;
    cout << "input airline: ";
    cin >> this->airline;
    cout << "input from: ";
    cin >> this->from;
    cout << "input to: ";
    cin >> this->to;
    cout << "input distance: ";
    cin >> this->distance;
    cout << "input duration: ";
    cin >> this->duration;
    cout << "input aircraft: ";
    cin >> this->aircraft;
    cout << "input passangers: ";
    cin >> this->passangers;

    outfile << this->number << endl;
    outfile << this->airline << endl;
    outfile << this->from << endl;
    outfile << this->to << endl;
    outfile << this->distance << endl;
    outfile << this->duration << endl;
    outfile << this->aircraft << endl;
    outfile << this->passangers << endl;
}

flight::flight(ifstream &file)
{
    file >> this->number;
    file >> this->airline;
    file >> this->from;
    file >> this->to;
    file >> this->distance;
    file >> this->duration;
    file >> this->aircraft;
    file >> this->passangers;
}

void flight::display()
{
    cout << "\n ====================";
    cout << "\n Number: ";
    cout << this->number << endl;
    cout << "\n Airline: ";
    cout << this->airline << endl;
    cout << "\n From: ";
    cout << this->from << endl;
    cout << "\n To: ";
    cout << this->to << endl;
    cout << "\n Distance: ";
    cout << this->distance << endl;
    cout << "\n Duration: ";
    cout << this->duration << endl;
    cout << "\n Aircraft: ";
    cout << this->aircraft << endl;
    cout << "\n Passangers count: ";
    cout << this->passangers << endl;
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