#include<stdio.h>
#include<string.h>
#include"main.h"

int getHourlyRate(char* type)
{
    if (strcmp(type, "Bike") == 0)
    {
       return 10;
    }
    if (strcmp(type, "Car") == 0)
    {
       return 40;
    }    
    if (strcmp(type, "Auto") == 0)
    {
        return 25;
    }
    if (strcmp(type, "Minibus") == 0)
    {
        return 70;
    }
}
int calculateFare(Vehicle* vehicle)
{
    long duration = vehicle->exit_time - vehicle->entry_time;
    int hours = duration / 3600;
    if (hours < 1)
    {
        hours = 1;
    }
    return hours * getHourlyRate(vehicle->vehicle_type);
}