#include<stdio.h>
#include "main.h"

Vehicle vehicles[MAX_VEHICLES];
ParkingSlot slots[MAX_SLOTS] = {0};
int vehicle_count = 0;

int main()
{
    int choice;
    printf("\033[35m============================================\n\033[0m");
    printf("\033[36m| %-40s |\n\033[0m", "       Parking Management System");
    while (1)
    {
        printf("\033[35m============================================\n\033[0m");
        printf("\033[32m| %-40s |\n\033[0m", "              Services");
        printf("\033[35m============================================\n\033[0m");
        printf("\033[33m| %-40s |\n", "1. Park a Vehicle");
        printf("\033[33m| %-40s |\n", "2. Exit a Vehicle");
        printf("\033[33m| %-40s |\n", "3. Check Slot Availability");
        printf("\033[33m| %-40s |\n", "4. Exit");
        printf("\033[35m============================================\n\033[0m");
        printf("\033[33mEnter your choice: \033[0m");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            park_vehicle();
            break;
        case 2:
            exit_vehicle();
            break;
        case 3:
            check_slot();
            break;
        case 4:
            printf("\033[33mThank You for Choosing our Service\033[0m\n");
            printf("\033[31mExiting........\033[0m\n");
            return EXIT;
        default:
            printf("\033[31mInvalid Choice, Try Again\033[0m\n");
        }
    }
}
