#define REG_DISPLAYCONTROL       *((volatile uint32*)(0x04000000))

#define VIDEOMODE_0              0x0000
#define VIDEOMODE_3              0x0003

#define BGMODE_2                 0x0400

#define ENABLE_OBJECTS           0x1000

#define MAPPINGMODE_1D           0x0040

#define SCREENBUFFER             ((volatile uint16*)0x06000000)
#define SCREEN_W                 240
#define SCREEN_H                 160

#define REG_VCOUNT               (* (volatile uint16*) 0x04000006)
#define MEM_PALETTE              ((uint16*)(0x05000200))

#define MEM_VRAM                 ((volatile uint32*)0x06000000)
#define MEM_TILE                 ((TileBlock*)MEM_VRAM )
#define MEM_OAM                  ((volatile ObjectAttributes *)0x07000000)
#define CART_RAM                 *((volatile uint16*)(0x0e00ffff))

typedef unsigned char            uint8;
typedef unsigned short           uint16;
typedef unsigned int             uint32;
typedef unsigned short           Color;
typedef uint32                   Tile[16];
typedef Tile                     TileBlock[256];

typedef struct ObjectAttributes {
    uint16 attr0;
    uint16 attr1;
    uint16 attr2;
    uint16 pad;
} __attribute__((packed, aligned(4))) ObjectAttributes;

void vsync();
void pset(uint8 x, uint8 y, Color color);
void circler(uint8 x, uint8 y, uint8 r, Color color, uint8 i);
void circle(uint8 x, uint8 y, uint8 r, Color color);
uint8 clampx(uint8 x);
uint8 clampy(uint8 y);
Color MakeColor(uint8 red, uint8 green, uint8 blue);