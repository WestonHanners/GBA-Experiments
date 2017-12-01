#include "system.h"
#include "math.h"

Color MakeColor(uint8 red, uint8 green, uint8 blue) 
{
  return (red & 0x1F) | (green & 0x1F) << 5 | (blue & 0x1F) << 10; 
}
 
void vsync()
{
  while (REG_VCOUNT >= 160);
  while (REG_VCOUNT < 160);
}

void pset(uint16 x, uint16 y, Color color) 
{
  if (x >= SCREEN_W || y >= SCREEN_H) 
  { 
    return;
  }
  if (x <= 0 || y <= 0) 
  { 
    return; 
  }
  SCREENBUFFER[(y * SCREEN_W) + x] = color;
}

void circler(uint16 x, uint16 y, uint16 r, Color color, uint8 i) 
{
  for (double iteration = i; iteration > 0; iteration-=0.5) {
    circle(x,y,r-iteration,color);
  }
}

void circle(uint16 x, uint16 y, uint16 r, Color color) 
{
  for (double angle = 0.0; angle < (2*M_PI); angle = angle + 0.05) {
    uint16 px = round(r * cos(angle) + x);
    uint16 py = round(r * sin(angle) + y);
    pset(px,py,color);
  }
}

uint16 clampx(uint16 x) 
{
  if (x > SCREEN_W-1) { return 0; }
  if (x < 0) { return 0; }
  return x;
}

uint16 clampy(uint16 y) 
{
  if (y > SCREEN_H-1) { return 0; }
  if (y < 0) { return 0; }
  return y;
}
