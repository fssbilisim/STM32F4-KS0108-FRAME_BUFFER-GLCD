#include "stm32f4xx_hal.h"


uint8_t fss_bitSet8_return(uint8_t data, uint8_t n)
{
	data |= 1 << n;
	return data;
}

uint8_t fss_bitClear8_return(uint8_t data, uint8_t n)
{
	data &= ~(1 << n);
	return data;
}

//********************************************
// fss_bitSet8(&var, 7);

void fss_bitSet8(uint8_t *data, uint8_t n)
{		
	*data |= 1 << n;	
}

void fss_bitSet16(uint16_t *data, uint8_t n)
{		
	*data |= 1 << n;	
}

void fss_bitSet32(uint32_t *data, uint8_t n)
{		
	*data |= 1 << n;	
}

//********************************************
// fss_bitClear8(&var, 7);

void fss_bitClear8(uint8_t *data, uint8_t n)
{
	*data &= ~(1 << n);
}

void fss_bitClear16(uint16_t *data, uint8_t n)
{
	*data &= ~(1 << n);
}

void fss_bitClear32(uint32_t *data, uint8_t n)
{
	*data &= ~(1 << n);
}

//************************************************
// fss_bitToggle8(&var, 7);

void fss_bitToggle8(uint8_t *data, uint8_t n)
{
	*data ^= 1 << n;
}

void fss_bitToggle16(uint16_t *data, uint8_t n)
{
	*data ^= 1 << n;
}

void fss_bitToggle32(uint32_t *data, uint8_t n)
{
	*data ^= 1 << n;
}

//************************************************
int  bit_test_8 (unsigned int  word, int  n)
{
    if ( n < 0  || n > 8 )
       return  0;

    if ( (word >> (31 - n)) & 0x1 )
       return 1;
    else
       return 0;
}
//************************************************

uint8_t bit_set_8 (uint8_t *data, int  n)
{
    if ( n < 0  || n > 8 )
       return  0;

    return  *data | (1 << n );
}

uint8_t  bit_clear_8 (uint8_t *data, int  n)
{
    if ( n < 0  || n > 8 )
       return  0;

    return  *data & ~(1 << n );
}



