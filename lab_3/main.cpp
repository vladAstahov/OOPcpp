#include "flights.h"

flights flightsSystem;

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

        flightsSystem.readFromFile(infile);

        infile.close();
        break;
    case 2:
        outfile.open("flights.txt");

        flightsSystem.writeToFile(outfile);

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
             << "enter 4 to quit"
             << endl;
        cin >> command;

        switch (command)
        {
        case 1:
            flightsSystem.display();
            break;
        case 2:
            flightsSystem.getAircraftWithMaxSpeed();
            break;
        case 3:
            flightsSystem.getTotalDistanceFromMoscow();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "incorrect command";
        }
    }
}