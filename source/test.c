#include "system.c"
#include "skate.h"

int main()
{
    REG_DISPLAYCONTROL = 0;

    while(1)
    {
        vsync();
    }
    return 0;
} 
