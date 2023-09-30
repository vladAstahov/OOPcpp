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
void menu(Flight *flights);

int N;
Flight *flights;

int main()
{
    ofstream outfile;
    outfile.open("text.txt");

    cout << "input elements count \n";
    cin >> N;

    outfile << N << endl;

    for (int i = 0; i < N; i++)
    {
        Flight newFlight;

        cout << "input number";
        cin >> newFlight.number;
        cout << "input airline";
        cin >> newFlight.airline;
        cout << "input from";
        cin >> newFlight.from;
        cout << "input to";
        cin >> newFlight.to;
        cout << "input distance";
        cin >> newFlight.distance;
        cout << "input duration";
        cin >> newFlight.duration;
        cout << "input aircraft";
        cin >> newFlight.aircraft;
        cout << "input passangers";
        cin >> newFlight.passangers;

        outfile << newFlight.number << endl;
        outfile << newFlight.airline << endl;
        outfile << newFlight.from << endl;
        outfile << newFlight.to << endl;
        outfile << newFlight.distance << endl;
        outfile << newFlight.duration << endl;
        outfile << newFlight.aircraft << endl;
        outfile << newFlight.passangers << endl;
    }
    outfile.close();

    ifstream infile;
    infile.open("text.txt");

    infile >> N;

    flights = new Flight[N];

    for (int i = 0; i < N; i++)
    {
        flights[i] = readFlight(infile);
    }

    infile.close();

    menu(flights);

    return 0;
}

void enterFilghts()
{
}

void menu(Flight *flights)
{
    while (1 == 1)
    {
        int command;
        cout << "enter 1 to print all flights \n"
             << "enter 2 to print aircraft with max speed \n"
             << "enter 3 to get total distance from Moscow"
             << endl;
        cin >> command;

        if (command == 1)
        {
            printFlights(flights);
        }
        else if (command == 2)
        {
            printWithMaxSpeed(flights);
        }
        else if (command == 3)
        {
            getDistanceFromMoscow(flights);
        }
        else
        {
            cout << "incorrect command";
        }
    }
}

Flight readFlight(ifstream &file)
{
    Flight flight;

    file >> flight.number;
    file >> flight.airline;
    file >> flight.from;
    file >> flight.to;
    file >> flight.distance;
    file >> flight.duration;
    file >> flight.aircraft;
    file >> flight.passangers;

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