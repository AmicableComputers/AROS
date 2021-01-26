#define ARROWUP0_WIDTH    18
#define ARROWUP0_HEIGHT   11

UBYTE ArrowUp0Data[] =
{
    0x00, 0x00, 0x40, 0x00,
    0x00, 0x00, 0x40, 0x00,
    0x00, 0x00, 0x40, 0x00,
    0x00, 0xC0, 0x40, 0x00,
    0x01, 0xE0, 0x40, 0x00,
    0x03, 0xF0, 0x40, 0x00,
    0x07, 0x38, 0x40, 0x00,
    0x0C, 0x0C, 0x40, 0x00,
    0x00, 0x00, 0x40, 0x00,
    0x00, 0x00, 0x40, 0x00,
    0x7F, 0xFF, 0xC0, 0x00,

    0xFF, 0xFF, 0x80, 0x00,
    0x80, 0x00, 0x00, 0x00,
    0x80, 0x00, 0x00, 0x00,
    0x80, 0x00, 0x00, 0x00,
    0x80, 0x00, 0x00, 0x00,
    0x80, 0x00, 0x00, 0x00,
    0x80, 0x00, 0x00, 0x00,
    0x80, 0x00, 0x00, 0x00,
    0x80, 0x00, 0x00, 0x00,
    0x80, 0x00, 0x00, 0x00,
    0x80, 0x00, 0x00, 0x00,
};

struct Image ArrowUp0Image =
{
    0, 0, /* Left, Top */
    ARROWUP0_WIDTH, ARROWUP0_HEIGHT, /* Width, Height */
    2, /* Depth */
    (UWORD *)ArrowUp0Data, /* ImageData */
    0x03, /* PlanePick */
    0x00, /* PlaneOnOff */
    NULL /* NextImage */
};
