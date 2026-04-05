#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdint.h>
#include <time.h>

#define MAX_SLOTS 10
#define MAX_VEHICLES 10

#define SUCCESS  1
#define FAILURE -1
#define EXIT     0
#define FULL    -2

typedef struct
{
    int slot_id; // Assigned parking slot
    char plate[15]; // License plate (alphanumeric, 4-14 chars)
    char owner[50]; // Owner full name
    char vehicle_type[10]; // "car", "bike", or "truck"
    time_t entry_time; // UNIX timestamp — recorded via time(NULL)
    time_t exit_time; // UNIX timestamp — set on vehicle exit
}Vehicle;

typedef struct
{
    int slot_id; // Unique slot number (1 to MAX_SLOTS)
    int is_occupied; // 0 = free, 1 = occupied
    char plate[15]; // Plate of current occupant (empty if free)
}ParkingSlot;

extern Vehicle vehicles[MAX_VEHICLES];
extern ParkingSlot slots[MAX_SLOTS];
extern int vehicle_count;
extern int slot;

void park_vehicle(void);
void exit_vehicle(void);
void print_bill(Vehicle* vehicle, int amount);
int getHourlyRate(char* type);
int allocateSlot(char* plate);
void releaseSlot(int slot_id);
void check_slot(void);
int calculateFare(Vehicle* v);
int validate_vehicle_plate(char* plate);
int validate_vehicle_type(char* type);
int validate_vehicle_owner(char* name);
int findByPlate(char* plate);
int isduplicate(char* plate);

#endif