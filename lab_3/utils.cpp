#include "utils.h"

Flight cinFlight()
{
    Flight newFlight;

    cout << "input number: ";
    cin >> newFlight.number;
    cout << "input airline: ";
    cin >> newFlight.airline;
    cout << "input from: ";
    cin >> newFlight.from;
    cout << "input to: ";
    cin >> newFlight.to;
    cout << "input distance: ";
    cin >> newFlight.distance;
    cout << "input duration: ";
    cin >> newFlight.duration;
    cout << "input aircraft: ";
    cin >> newFlight.aircraft;
    cout << "input passangers: ";
    cin >> newFlight.passangers;

    return newFlight;
}

Flight ifFlight(ifstream &file)
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

void coutFlight(Flight flight)
{
    cout << "\n ====================";
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

void ofFlight(ofstream &outfile, Flight newFlight)
{
    outfile << newFlight.number << endl;
    outfile << newFlight.airline << endl;
    outfile << newFlight.from << endl;
    outfile << newFlight.to << endl;
    outfile << newFlight.distance << endl;
    outfile << newFlight.duration << endl;
    outfile << newFlight.aircraft << endl;
    outfile << newFlight.passangers << endl;
}

double getAircraftSpeed(Flight flight)
{
    return flight.distance / flight.duration;
}