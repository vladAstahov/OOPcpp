#include <stdio.h>
#include <stdlib.h>

struct Flight
{
    char number[20];
    char airline[20];
    char from[20];
    char to[20];
    double distance;
    double duration;
    char aircraft[20];
    long int passangers;
};

typedef struct Flight Flight;

#define COUNT 3

void fabricFlight(Flight *);
void printFlights(Flight[COUNT]);
void printFlight(Flight);
void printWithMaxSpeed(Flight flights[COUNT]);
int isMoscow(Flight flight);
void getDistanceFromMoscow(Flight flights[COUNT]);

int main()
{
    Flight flights[COUNT];

    for (int i = 0; i < COUNT; i++)
    {
        Flight *addres = &flights[i];
        fabricFlight(addres);
    }

    printf("All flighs \n");
    printFlights(flights);
    printf("Aircrafts with max speed \n");
    printWithMaxSpeed(flights);
    printf("-----");
    getDistanceFromMoscow(flights);

    return 0;
}

void fabricFlight(Flight *flight)
{
    printf("Input number \n");
    scanf("%19s", &flight->number);
    printf("Input airline \n");
    scanf("%19s", &flight->airline);
    printf("Input from \n");
    scanf("%19s", &flight->from);
    printf("Input to \n");
    scanf("%19s", &flight->to);
    printf("Input distance of flight \n");
    scanf("%lf", &flight->distance);
    printf("Input duration of flight \n");
    scanf("%lf", &flight->duration);
    printf("Input aircraft \n");
    scanf("%19s", &flight->aircraft);
    printf("Input passangers count \n");
    scanf("%ld", &flight->passangers);
}

void printFlights(Flight flights[COUNT])
{
    for (int i = 0; i < COUNT; i++)
    {
        printf("---- \n");
        printFlight(flights[i]);
    }
}

void printFlight(Flight flight)
{
    printf("Number %s \n", &flight.number);
    printf("Airline %s \n", &flight.airline);
    printf("From %s \n", &flight.from);
    printf("To %s \n", &flight.to);
    printf("Distance %lf \n", flight.distance);
    printf("Duration %lf \n", flight.duration);
    printf("Aircraft %s \n", &flight.aircraft);
    printf("Passengers count %ld \n", flight.passangers);
}

void printWithMaxSpeed(Flight flights[COUNT])
{
    double maxSpeed = 0;

    for (int i = 0; i < COUNT; i++)
    {
        double currentSpeed = flights[i].distance / flights[i].duration;

        if (currentSpeed >= maxSpeed)
        {
            maxSpeed = currentSpeed;
        }
    }

    for (int i = 0; i < COUNT; i++)
    {
        double currentSpeed = flights[i].distance / flights[i].duration;

        if (currentSpeed >= maxSpeed)
        {
            printf("%s \n", &flights[i].aircraft);
        }
    }
}

void getDistanceFromMoscow(Flight flights[COUNT])
{
    double distance = 0;

    for (int i = 0; i < COUNT; i++)
    {
        if (isMoscow(flights[i]) == 1)
        {
            distance += flights[i].distance;
        }
    }

    printf("Total distance from Moscow %lf \n", distance);
}

int isMoscow(Flight flight)
{
    if ((flight.from[0] == 'M' || flight.from[0] == 'm') && flight.from[1] == 'o' && flight.from[2] == 's' && flight.from[3] == 'c' && flight.from[4] == 'o' && flight.from[5] == 'w')
    {
        return 1;
    }

    return 0;
}