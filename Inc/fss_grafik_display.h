
#include "main.h"
#include "fss_util.h"

#define GLCD_LEFT    0
#define GLCD_RIGHT   1

#define ON           1
#define OFF          0


/////////////////////////////////////////////////////////////////////////
// Function Prototypes
/////////////////////////////////////////////////////////////////////////
void glcd_init(int8_t mode);
void glcd_pixel(int8_t x, int8_t y, int8_t color);
void glcd_fillScreen(int8_t color);
void glcd_writeByte(int8_t side, uint8_t data);
void glcd_update();
/////////////////////////////////////////////////////////////////////////
