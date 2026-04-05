#include<stdio.h>
#include"main.h"

void print_bill(Vehicle* vehicle, int amount)
{
    printf("\n\033[35m==========================================================\033[0m\n");
    printf("\033[33m              Parking Bill              \033[0m\n");
    printf("\033[35m============================================================\033[0m\n");
    printf("\033[33m%-22s : \033[0m%d\n", "Vehicle Slot ID", vehicle->slot_id);
    printf("\033[33m%-22s : \033[0m%s\n", "Plate Number", vehicle->plate);
    printf("\033[33m%-22s : \033[0m%s\n", "Owner Name", vehicle->owner);
    printf("\033[33m%-22s : \033[0m%s\n", "Vehicle Type", vehicle->vehicle_type);

    printf("\033[33m%-22s : \033[0m%s", "Entry Time", ctime(&vehicle->entry_time));
    printf("\033[33m%-22s : \033[0m%s", "Exit Time", ctime(&vehicle->exit_time));

    long duration = vehicle->exit_time - vehicle->entry_time;
    int hours = duration / 3600;
    int minutes = (duration % 3600) / 60;

    printf("\033[33m%-22s : \033[0m%02d HH : %02d MM\n", "Duration", hours, minutes);
    printf("\033[33m%-22s : \033[32m%d\033[0m\n", "Total Amount", amount);
    printf("\033[35m============================================================\033[0m\n");
}