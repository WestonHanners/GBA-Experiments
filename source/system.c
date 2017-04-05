#include "system.h"

Color MakeColor(uint8 red, uint8 green, uint8 blue) {
    return (red & 0x1F) | (green & 0x1F) << 5 | (blue & 0x1F) << 10; 
}
 
void vsync()
{
  while (REG_VCOUNT >= 160);
  while (REG_VCOUNT < 160);
}