#include<stdio.h>
#include<time.h>
#include"main.h"

void park_vehicle(void)
{
    char choice;
    int slot = 0;
    printf("\033[35m============================================\n\033[0m");
    printf("\033[33m        Vehicle Park Menu\033[0m\n");
    printf("\033[35m============================================\n\033[0m");
    while (1)
    {
        printf("\033[33mDo you want to park vehicle? (y/n): \033[0m");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y')
        {
            printf("\033[33mReturning to Main Menu...\033[0m\n");
            break;
        }
        Vehicle v;
        while (1)
        {
            printf("\033[36mEnter Vehicle ID (Plate): \033[0m");
            scanf("%s", v.plate);
            if (validate_vehicle_plate(v.plate) == FAILURE)
            {
                continue;
            }
            else if (isduplicate(v.plate) == SUCCESS)
            {
                printf("\033[31mDuplicate Vehicle Found\033[0m\n");
                continue;
            }
            else
            {
                break;
            }
        }
        while (1)
        {
            printf("\033[36mEnter Owner Name: \033[0m");
            scanf(" %[^\n]", v.owner);
            if (validate_vehicle_owner(v.owner) == FAILURE)
            {
                continue;
            }
            else
            {
                break;
            }
        }
        while (1)
        {
            printf("\033[36mEnter Vehicle Type (Car/Bike/Auto/Minibus): \033[0m");
            scanf("%s", v.vehicle_type);
            if (validate_vehicle_type(v.vehicle_type) == FAILURE)
            {
                continue;
            }
            else
            {
                break;
            }
        }
        slot = allocateSlot(v.plate);
        if (slot == FULL)
        {
            printf("\033[31mParking Full\033[0m\n");
            continue;
        }
        v.slot_id = slot;
        v.entry_time = time(NULL);
        vehicles[vehicle_count] = v;
        vehicle_count++;
        printf("\033[32mVehicle Parked Successfully at Slot %d\033[0m\n", slot);
    }
}
