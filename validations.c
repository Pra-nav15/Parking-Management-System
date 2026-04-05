#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"main.h"

int validate_vehicle_plate(char* plate)
{
    int plate_len = strlen(plate);
    if (plate_len != 9)
    {
        printf("\033[31mInvalid Number Plate (must be 9 characters)\033[0m\n");
        return FAILURE;
    }
    for (int i = 0;i < plate_len;i++)
    {
        if (!isalnum(plate[i]))
        {
            printf("\033[31mInvalid Plate: Only alphanumeric allowed\033[0m\n");
            return FAILURE;
        }
    }
    return SUCCESS;
}

int validate_vehicle_type(char* type)
{
    if (strcmp(type, "Car") && strcmp(type, "Bike") && strcmp(type, "Auto") && strcmp(type, "Minibus"))
    {
        printf("\033[31mInvalid Vehicle Type (Car/Bike/Auto/Minibus only)\033[0m\n");
        return FAILURE;
    }
    return SUCCESS;
}

int validate_vehicle_owner(char* name)
{
    int name_len = strlen(name);
    for (int i = 0;i < name_len;i++)
    {
        if (!isalpha(name[i]))
        {
            printf("\033[31mInvalid Name: Only alphabets allowed\033[0m\n");
            return FAILURE;
        }
    }
    return SUCCESS;
}

int findByPlate(char* plate)
{
    for (int i = 0; i < vehicle_count; i++)
    {
        if (strcmp(vehicles[i].plate, plate) == 0)
        {
            return i;
        }
    }
    return FAILURE;
}

int isduplicate(char* plate)
{
    for (int i = 0; i < vehicle_count; i++)
    {
        if (strcmp(vehicles[i].plate, plate) == 0)
        {
            return SUCCESS;
        }
    }
    return FAILURE;
}