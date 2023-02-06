#include "stm32f4xx_hal.h"

void fss_bitSet8(uint8_t *data, uint8_t n);
void fss_bitSet16(uint16_t *data, uint8_t n);
void fss_bitSet32(uint32_t *data, uint8_t n);
void fss_bitClear8(uint8_t *data, uint8_t n);
void fss_bitClear16(uint16_t *data, uint8_t n);
void fss_bitClear32(uint32_t *data, uint8_t n);
void fss_bitToggle8(uint8_t *data, uint8_t n);
void fss_bitToggle16(uint16_t *data, uint8_t n);
void fss_bitToggle32(uint32_t *data, uint8_t n);
uint8_t fss_bitSet8_return(uint8_t data, uint8_t n);
uint8_t fss_bitClear8_return(uint8_t data, uint8_t n);


// 8 bit binary gosterim
// bin8(10110011);
#define bin8(a)	((((a/10000000*128) + \
								(((a/1000000)&1)*64) + \
								(((a/100000)&1)*32) + \
								(((a/10000)&1)*16) + \
								(((a/1000)&1)*8) + \
								(((a/100)&1)*4) + \
								(((a/10)&1)*2) + \
								(a&1)) * (a/10000000)) + \
								(( ((a/262144)*64) + \
								(((a/32768)&1)*32) + \
								(((a/4096)&1)*16) + \
								(((a/512)&1)*8) + \
								(((a/64)&1)*4) + \
								(((a/8)&1)*2) + \
								(a&1)) * (1-(a/10000000))))
