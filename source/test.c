#include <string.h>
#include "system.h"
#include "dubya.h"

int main()
{
    memcpy(MEM_PALETTE, dubyaPal,  dubyaPalLen );
    memcpy(&MEM_TILE[4][1], dubyaTiles, dubyaTilesLen);

    volatile ObjectAttributes *spriteAttribs = &MEM_OAM[0];

    spriteAttribs->attr0 = 0x3032; // 8bpp tiles, SQUARE shape, at y coord 50
    spriteAttribs->attr1 = 0x4064; // 16x16 size when using the SQUARE shape
    spriteAttribs->attr2 = 2;      // Start at the first tile in tile

    REG_DISPLAYCONTROL = VIDEOMODE_0 | ENABLE_OBJECTS | MAPPINGMODE_1D;

    int x = 0;

    while(1)
    {
        vsync();
        x = (x+1) % (SCREEN_W);
        spriteAttribs->attr1 = 0x4000 | (0x1FF & x);
    }
    return 0;
} 