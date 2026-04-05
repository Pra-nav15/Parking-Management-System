#include<stdio.h>
#include<unistd.h>
#include"main.h"

void exit_vehicle(void)
{
    printf("\033[35m============================================\n\033[0m");
    printf("\033[33m        Vehicle Exit Menu\033[0m\n");
    printf("\033[35m============================================\n\033[0m");
    char plate[15];
    printf("\033[34mEnter Vehicle Plate Number: \033[0m");
    scanf("%s",plate);
    int index = findByPlate(plate);
    if (index == FAILURE)
    {
        printf("\033[31mVehicle Not Found\033[0m\n");
        return;
    }
    vehicles[index].exit_time = time(NULL);
    int amount = calculateFare(&vehicles[index]);
    releaseSlot(vehicles[index].slot_id);
    printf("\033[32mVehicle Found. Processing Bill...\033[0m\n");
    sleep(2);
    print_bill(&vehicles[index], amount);
}
