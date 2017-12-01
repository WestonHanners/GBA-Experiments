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

void pset(uint8 x, uint8 y, Color color) 
{
  if (x >= SCREEN_W || y >= SCREEN_H) { return; }
  // if (x <= 0 || y <= 0) { return; }
  SCREENBUFFER[(y * SCREEN_W) + x] = color;
}

void circler(uint8 x, uint8 y, uint8 r, Color color, uint8 i) 
{
  for (double iteration = i; iteration > 0; iteration-=0.5) {
    circle(x,y,r-iteration,color);
  }
}

void circle(uint8 x, uint8 y, uint8 r, Color color) 
{
  for (double angle = 0.0; angle < (2*M_PI); angle = angle + 0.05) {
    uint8 px = round(r * cos(angle) + x);
    uint8 py = round(r * sin(angle) + y);
    pset(px,py,color);
  }
}

uint8 clampx(uint8 x) 
{
  if (x > SCREEN_W-1) { return 0; }
  if (x < 0) { return 0; }
  return x;
}

uint8 clampy(uint8 y) 
{
  if (y > SCREEN_H-1) { return 0; }
  if (y < 0) { return 0; }
  return y;
}
