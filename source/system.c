typedef unsigned char      uint8;
typedef unsigned short     uint16;
typedef unsigned int       uint32;
typedef unsigned short     Color;

#define REG_DISPLAYCONTROL *((volatile uint32*)(0x04000000))
#define VIDEOMODE_3         0x0003
#define BGMODE_2            0x0400

#define SCREENBUFFER        ((volatile uint16*)0x06000000)
#define SCREEN_W            240
#define SCREEN_H            160

#define REG_VCOUNT      (* (volatile uint16*) 0x04000006)
#define MEM_PALETTE     ((uint16*)(0x05000200))

inline Color MakeColor(uint8 red, uint8 green, uint8 blue) {
    return (red & 0x1F) | (green & 0x1F) << 5 | (blue & 0x1F) << 10; 
}

inline void vsync()
{
  while (REG_VCOUNT >= 160);
  while (REG_VCOUNT < 160);
}