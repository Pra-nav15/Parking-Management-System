#include<stdio.h>
#include<string.h>
#include"main.h"

int allocateSlot(char* plate)
{
    for (int i = 0; i < MAX_SLOTS; i++)
    {
        if (slots[i].is_occupied == 0)
        {
            strcpy(slots[i].plate, plate);
            slots[i].is_occupied = 1;
            return i + 1;
        }
    }
    return FULL;
}
void releaseSlot(int slot_id)
{
    if (slot_id > 0 && slot_id <= MAX_SLOTS)
    {
        slots[slot_id - 1].is_occupied = 0;
    }
}

void check_slot(void)
{
    printf("\n\033[33mParking Slot Status\033[0m\n");
    printf("\033[35m============================================================\n\033[0m");
    printf("\033[32m[   ]\033[0m = Vacant            \033[31m[ X ]\033[0m = Occupied\n");
    printf("\033[35m============================================================\n\033[0m");
    for (int i = 0; i < MAX_SLOTS; i++)
    {
        if (slots[i].is_occupied)
        {
            printf("(%d) \033[31m[ X ]\033[0m   ", i + 1);
        }
        else
        {
            printf("(%d) \033[32m[   ]\033[0m   ", i + 1);
        }
        if ((i + 1) % 5 == 0)
        {
            printf("\n\n");
        }
    }
}