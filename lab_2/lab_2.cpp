#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Flight
{
    string number;
    string airline;
    string from;
    string to;
    double distance;
    double duration;
    string aircraft;
    long int passangers;
};

Flight readFlight(ifstream &file);
void printFlight(Flight flight);
void printWithMaxSpeed(Flight *flights);
void printFlights(Flight *flights);
void getDistanceFromMoscow(Flight *flights);
void printWithMaxSpeed(Flight *flights);

int N;
Flight *flights;

int main()
{
    ifstream infile;
    infile.open("text.txt");

    infile >> N;
    infile.get();

    flights = new Flight[N];

    for (int i = 0; i < N; i++)
    {
        flights[i] = readFlight(infile);
    }

    infile.close();

    printFlights(flights);
    printWithMaxSpeed(flights);
    getDistanceFromMoscow(flights);

    return 0;
}

Flight readFlight(ifstream &file)
{
    Flight flight;

    getline(file, flight.number);
    getline(file, flight.airline);
    getline(file, flight.from);
    getline(file, flight.to);
    file >> flight.distance;
    file >> flight.duration;
    file.get();
    getline(file, flight.aircraft);
    file >> flight.passangers;
    file.get();

    return flight;
}

void printFlights(Flight *flights)
{
    cout << "\n All flights";
    for (int i = 0; i < N; i++)
    {
        printFlight(flights[i]);
    }
}

void printFlight(Flight flight)
{
    cout << "\n --------";
    cout << "\n Number: ";
    cout << flight.number << endl;
    cout << "\n Airline: ";
    cout << flight.airline << endl;
    cout << "\n From: ";
    cout << flight.from << endl;
    cout << "\n To: ";
    cout << flight.to << endl;
    cout << "\n Distance: ";
    cout << flight.distance << endl;
    cout << "\n Duration: ";
    cout << flight.duration << endl;
    cout << "\n Aircraft: ";
    cout << flight.aircraft << endl;
    cout << "\n Passangers count: ";
    cout << flight.passangers << endl;
}

void printWithMaxSpeed(Flight *flights)
{
    double maxSpeed = 0;

    for (int i = 0; i < N; i++)
    {
        double currentSpeed = flights[i].distance / flights[i].duration;

        if (currentSpeed >= maxSpeed)
        {
            maxSpeed = currentSpeed;
        }
    }

    cout << "\n Flights with max speed \n"
         << endl;
    for (int i = 0; i < N; i++)
    {
        double currentSpeed = flights[i].distance / flights[i].duration;

        if (currentSpeed >= maxSpeed)
        {
            cout << flights[i].aircraft << endl;
        }
    }
}

void getDistanceFromMoscow(Flight *flights)
{
    double distance = 0;

    for (int i = 0; i < N; i++)
    {
        if (flights[i].from == "Moscow")
        {
            distance += flights[i].distance;
        }
    }

    cout << "\n Total distance from Moscow:";
    cout << distance << endl;
}