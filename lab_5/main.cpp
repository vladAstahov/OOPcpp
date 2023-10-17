#include "system.h"

flightsSystem flights;

void startMenu();
void methodsMenu();

int main()
{
    startMenu();
    methodsMenu();

    return 0;
}

void startMenu()
{
    int startCommand;
    cout << "input 1 if you want read flights from file \n"
         << "input 2 if you want write flights manually \n"
         << endl;

    cin >> startCommand;

    ifstream infile;
    ofstream outfile;

    switch (startCommand)
    {
    case 1:
        infile.open("flights.txt");

        infile >> flights;

        infile.close();
        break;
    case 2:
        outfile.open("flights.txt");

        cin >> flights;
        outfile << flights;

        outfile.close();
        break;
    default:
        cout << "incorrect command, try again \n"
             << endl;
        startMenu();
        break;
    }
}

void methodsMenu()
{
    while (1 == 1)
    {
        int command;
        cout << "enter 1 to print all flights \n"
             << "enter 2 to print aircraft with max speed \n"
             << "enter 3 to get total distance from Moscow \n"
             << "enter 4 to add new flight \n"
             << "enter 5 to find similar flight \n"
             << "enter 6 to quit"
             << endl;
        cin >> command;

        flight newFlight;

        ofstream outfile;

        switch (command)
        {
        case 1:
            cout << flights;
            break;
        case 2:
            flights.getAircraftWithMaxSpeed();
            break;
        case 3:
            flights.getTotalDistanceFromMoscow();
            break;
        case 4:
            cin >> newFlight;
            flights += newFlight;

            outfile << flights;

            outfile.close();
            break;
        case 5:
            flights.compareFromKeyboard();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "incorrect command";
        }
    }
}