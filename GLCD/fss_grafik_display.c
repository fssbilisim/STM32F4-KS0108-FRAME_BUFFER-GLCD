
#include "main.h"
#include "fss_util.h"

#define GLCD_LEFT    0
#define GLCD_RIGHT   1

#define ON           1
#define OFF          0

#define Bit_RESET 0
#define Bit_SET   1

#define LCD_SET_RESET_LINE()      HAL_GPIO_WritePin(RST_GPIO_Port, RST_Pin, GPIO_PIN_RESET)
#define LCD_RESET_RESET_LINE()    HAL_GPIO_WritePin(RST_GPIO_Port, RST_Pin, GPIO_PIN_SET)

#define LCD_READ_DATA()           HAL_GPIO_WritePin(RW_GPIO_Port, RW_Pin, GPIO_PIN_SET)
#define LCD_WRITE_DATA()          HAL_GPIO_WritePin(RW_GPIO_Port, RW_Pin, GPIO_PIN_RESET)

#define LCD_SEND_DATA()           HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_SET)
#define LCD_SEND_COMMAND()        HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_RESET)

#define LCD_SET_STROBE_LINE()     HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_SET)
#define LCD_RESET_STROBE_LINE()   HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_RESET)

#define LCD_CHOOSE_CRYSTAL_1()	  HAL_GPIO_WritePin(CS1_GPIO_Port, CS1_Pin, GPIO_PIN_SET);   HAL_GPIO_WritePin(CS2_GPIO_Port, CS2_Pin, GPIO_PIN_RESET)
#define LCD_CHOOSE_CRYSTAL_0()	  HAL_GPIO_WritePin(CS1_GPIO_Port, CS1_Pin, GPIO_PIN_RESET); HAL_GPIO_WritePin(CS2_GPIO_Port, CS2_Pin, GPIO_PIN_SET)

/////////////////////////////////////////////////////////////////////////
// Function Prototypes
/////////////////////////////////////////////////////////////////////////
void glcd_init();
void glcd_pixel(uint8_t x, uint8_t y, uint8_t color);
void glcd_fillScreen(uint8_t color);
void glcd_writeByte(uint8_t side, uint8_t data);
void glcd_update();

/////////////////////////////////////////////////////////////////////////

struct
{
	uint8_t left[512];
	uint8_t right[512];
} displayData;

//////////////////////////////////////////////////////////////////////////////////////////////

GPIO_InitTypeDef GPIO_InitStructure;

void waitForLCDReady(uint8_t crystalId) {

	// okuma yapabilmek için pinler giriş durumuna alınır.
	GPIO_InitStructure.Pin = DB4_Pin;
	GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
	HAL_GPIO_Init(DB4_GPIO_Port, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = DB5_Pin ;
	GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
	HAL_GPIO_Init(DB5_GPIO_Port, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = DB7_Pin ;
	GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
	HAL_GPIO_Init(DB7_GPIO_Port, &GPIO_InitStructure);

	LCD_READ_DATA();
	LCD_SEND_COMMAND();

	if (crystalId == 0) {
		LCD_CHOOSE_CRYSTAL_0();
	}
	else {
		LCD_CHOOSE_CRYSTAL_1();
	}

	for(int i=0;i<100;i++){;}
	LCD_SET_STROBE_LINE();
	for(int i=0;i<100;i++){;}

	// hazır olana kadar bekle
	while (HAL_GPIO_ReadPin(DB7_GPIO_Port, DB7_Pin) == Bit_SET) {;}

	// pinler cıkış durumuna geri getirilir
	GPIO_InitStructure.Pin = DB4_Pin;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(DB4_GPIO_Port, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = DB5_Pin ;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(DB5_GPIO_Port, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = DB7_Pin ;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(DB7_GPIO_Port, &GPIO_InitStructure);

	LCD_RESET_STROBE_LINE();
}

//////////////////////////////////////////////////////////////////////////////////////////////

void writeByteToLCD(uint8_t crystalId, uint8_t byteType, uint8_t byte) {

	static uint8_t mask = 1;
	waitForLCDReady(crystalId);

	LCD_WRITE_DATA();
	if (byteType == 0)
	{
		LCD_SEND_COMMAND();
	} else
	{
		LCD_SEND_DATA();
	}

	HAL_GPIO_WritePin(DB0_GPIO_Port, DB0_Pin, ((byte & (mask << 0)) != 0) ? Bit_SET : Bit_RESET);
	HAL_GPIO_WritePin(DB1_GPIO_Port, DB1_Pin, ((byte & (mask << 1)) != 0) ? Bit_SET : Bit_RESET);
	HAL_GPIO_WritePin(DB2_GPIO_Port, DB2_Pin, ((byte & (mask << 2)) != 0) ? Bit_SET : Bit_RESET);
	HAL_GPIO_WritePin(DB3_GPIO_Port, DB3_Pin, ((byte & (mask << 3)) != 0) ? Bit_SET : Bit_RESET);
	HAL_GPIO_WritePin(DB4_GPIO_Port, DB4_Pin, ((byte & (mask << 4)) != 0) ? Bit_SET : Bit_RESET);
	HAL_GPIO_WritePin(DB5_GPIO_Port, DB5_Pin, ((byte & (mask << 5)) != 0) ? Bit_SET : Bit_RESET);
	HAL_GPIO_WritePin(DB6_GPIO_Port, DB6_Pin, ((byte & (mask << 6)) != 0) ? Bit_SET : Bit_RESET);
	HAL_GPIO_WritePin(DB7_GPIO_Port, DB7_Pin, ((byte & (mask << 7)) != 0) ? Bit_SET : Bit_RESET);

	for(int i=0;i<100;i++){;}
	LCD_SET_STROBE_LINE();
	for(int i=0;i<100;i++){;}
	LCD_RESET_STROBE_LINE();
	for(int i=0;i<100;i++){;}
}

//////////////////////////////////////////////////////////////////////////////////////////////

void glcd_init()
{
	int crystalId = 0;

	// Initialze some pins
	LCD_RESET_STROBE_LINE();

	LCD_SET_RESET_LINE();
	HAL_Delay(1);
	LCD_RESET_RESET_LINE();

	HAL_Delay(1);

	for (crystalId = 0; crystalId < 2; ++crystalId) {
		writeByteToLCD(crystalId, 0, 0xC0);
		writeByteToLCD(crystalId, 0, 0x3F);
	}
}

/////////////////////////////////////////////////////////////////////////

void glcd_update()
{
	uint8_t i, j;
	uint8_t *p1, *p2;

	p1 = displayData.left;
	p2 = displayData.right;

	// Loop through the vertical pages
	for(i = 0; i < 8; ++i)
	{
		writeByteToLCD(GLCD_LEFT, 0, 0x40);
		writeByteToLCD(GLCD_RIGHT, 0, 0x40);
		writeByteToLCD(GLCD_LEFT, 0, i | 0xB8);
		writeByteToLCD(GLCD_RIGHT, 0, i | 0xB8);

		// Loop through the horizontal sections
		for(j = 0; j < 64; ++j)
		{
			writeByteToLCD(GLCD_LEFT,1, *p1++);      // Turn pixels on or off
			writeByteToLCD(GLCD_RIGHT,1, *p2++);     // Turn pixels on or off
		}
	}
}

/////////////////////////////////////////////////////////////////////////

void glcd_pixel(uint8_t x, uint8_t y, uint8_t color)
{
	uint8_t* p;
	uint16_t temp;
	temp =  y/8;
	temp *= 64;
	temp += x;
	uint8_t* r;

	if(x > 63)
	{
		p = displayData.right + temp - 64;
	}
	else
	{
		p = displayData.left + temp;
	}

	if(color)
	{
		*p = fss_bitSet8_return(*p, y%8);
	}
	else
	{
		*p = fss_bitClear8_return(*p, y%8);
	}

}

/////////////////////////////////////////////////////////////////////////

void glcd_fillScreen(uint8_t color)
{
	uint8_t  data;
	uint8_t  *p1, *p2;
	uint16_t i;

	p1 = displayData.left;
	p2 = displayData.right;
	data = 0xFF * color;

	for(i=0; i<512; ++i)
	{
		*p1++ = data;
		*p2++ = data;
	}
}

/////////////////////////////////////////////////////////////////////////

