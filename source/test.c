#include <string.h>
#include "system.h"
#include "dubya.h"

int main()
{
    REG_DISPLAYCONTROL = VIDEOMODE_3 | BGMODE_2;
    Color c = MakeColor(255,0,0);
    circler(100,100,50,c,8);
    while(1)
    {
        // vsync();
        // offsetX++;
    }
    return 0;
} 