#include "stm32f4xx_hal.h"
#include <string.h>
#include <stdio.h> /* for printf */
#include "fss_util.h"

const uint8_t TEXT35[95][5]={
   bin8(00000000),   bin8(00000000),   bin8(00000000),   bin8(00000000),   bin8(00000000), //SPACE
   bin8(01000100),   bin8(01000100),   bin8(01000100),   bin8(00000000),   bin8(01000100), //!
   bin8(10101010),   bin8(10101010),   bin8(00000000),   bin8(00000000),   bin8(00000000), //"
   bin8(10101010),   bin8(11101110),   bin8(10101010),   bin8(11101110),   bin8(10101010), //#
   bin8(01100110),   bin8(11001100),   bin8(11001100),   bin8(01100110),   bin8(11101110), //$
   bin8(10101010),   bin8(00100010),   bin8(01000100),   bin8(10001000),   bin8(10101010), //%
   bin8(01000100),   bin8(10101010),   bin8(01000100),   bin8(10101010),   bin8(01100110), //&
   bin8(01000100),   bin8(01000100),   bin8(00000000),   bin8(00000000),   bin8(00000000), //'
   bin8(01000100),   bin8(10001000),   bin8(10001000),   bin8(10001000),   bin8(01000100), //(
   bin8(01000100),   bin8(00100010),   bin8(00100010),   bin8(00100010),   bin8(01000100), //)
   bin8(00000000),   bin8(10101010),   bin8(01000100),   bin8(10101010),   bin8(00000000), //*
   bin8(00000000),   bin8(01000100),   bin8(11101110),   bin8(01000100),   bin8(00000000), //+
   bin8(00000000),   bin8(00000000),   bin8(00000000),   bin8(01000100),   bin8(10001000), //,
   bin8(00000000),   bin8(00000000),   bin8(11101110),   bin8(00000000),   bin8(00000000), //-
   bin8(00000000),   bin8(00000000),   bin8(00000000),   bin8(00000000),   bin8(01000100), //.
   bin8(00100010),   bin8(00100010),   bin8(01000100),   bin8(10001000),   bin8(10001000), ///
   bin8(11101110),   bin8(10101010),   bin8(10101010),   bin8(10101010),   bin8(11101110), //0
   bin8(01000100),   bin8(11001100),   bin8(01000100),   bin8(01000100),   bin8(11101110), //1
   bin8(11101110),   bin8(00100010),   bin8(11101110),   bin8(10001000),   bin8(11101110), //2
   bin8(11101110),   bin8(00100010),   bin8(11101110),   bin8(00100010),   bin8(11101110), //3
   bin8(10101010),   bin8(10101010),   bin8(11101110),   bin8(00100010),   bin8(00100010), //4
   bin8(11101110),   bin8(10001000),   bin8(11101110),   bin8(00100010),   bin8(11101110), //5
   bin8(11001100),   bin8(10001000),   bin8(11101110),   bin8(10101010),   bin8(11101110), //6
   bin8(11101110),   bin8(00100010),   bin8(01000100),   bin8(10001000),   bin8(10001000), //7
   bin8(11101110),   bin8(10101010),   bin8(11101110),   bin8(10101010),   bin8(11101110), //8
   bin8(11101110),   bin8(10101010),   bin8(11101110),   bin8(00100010),   bin8(01100110), //9
   bin8(00000000),   bin8(01000100),   bin8(00000000),   bin8(01000100),   bin8(00000000), //:
   bin8(00000000),   bin8(01000100),   bin8(00000000),   bin8(01000100),   bin8(10001000), //;
   bin8(00100010),   bin8(01000100),   bin8(10001000),   bin8(01000100),   bin8(00100010), //<
   bin8(00000000),   bin8(11101110),   bin8(00000000),   bin8(11101110),   bin8(00000000), //=
   bin8(10001000),   bin8(01000100),   bin8(00100010),   bin8(01000100),   bin8(10001000), //>
   bin8(11001100),   bin8(00100010),   bin8(01100110),   bin8(00000000),   bin8(01000100), //?
   bin8(01000100),   bin8(10101010),   bin8(11101110),   bin8(10001000),   bin8(01100110), //@
   bin8(11101110),   bin8(10101010),   bin8(11101110),   bin8(10101010),   bin8(10101010), //A
   bin8(11001100),   bin8(10101010),   bin8(11101110),   bin8(10101010),   bin8(11001100), //B
   bin8(11101110),   bin8(10001000),   bin8(10001000),   bin8(10001000),   bin8(11101110), //C
   bin8(11001100),   bin8(10101010),   bin8(10101010),   bin8(10101010),   bin8(11001100), //D
   bin8(11101110),   bin8(10001000),   bin8(11101110),   bin8(10001000),   bin8(11101110), //E
   bin8(11101110),   bin8(10001000),   bin8(11101110),   bin8(10001000),   bin8(10001000), //F
   bin8(11101110),   bin8(10001000),   bin8(10001000),   bin8(10101010),   bin8(11101110), //G
   bin8(10101010),   bin8(10101010),   bin8(11101110),   bin8(10101010),   bin8(10101010), //H
   bin8(11101110),   bin8(01000100),   bin8(01000100),   bin8(01000100),   bin8(11101110), //I
   bin8(00100010),   bin8(00100010),   bin8(00100010),   bin8(10101010),   bin8(11101110), //J
   bin8(10001000),   bin8(10101010),   bin8(11001100),   bin8(11001100),   bin8(10101010), //K
   bin8(10001000),   bin8(10001000),   bin8(10001000),   bin8(10001000),   bin8(11101110), //L
   bin8(10101010),   bin8(11101110),   bin8(11101110),   bin8(10101010),   bin8(10101010), //M
   bin8(00000000),   bin8(11001100),   bin8(10101010),   bin8(10101010),   bin8(10101010), //N
   bin8(01000100),   bin8(10101010),   bin8(10101010),   bin8(10101010),   bin8(01000100), //O
   bin8(11101110),   bin8(10101010),   bin8(11101110),   bin8(10001000),   bin8(10001000), //P
   bin8(01000100),   bin8(10101010),   bin8(10101010),   bin8(11101110),   bin8(01100110), //Q
   bin8(11101110),   bin8(10101010),   bin8(11001100),   bin8(11101110),   bin8(10101010), //R
   bin8(11101110),   bin8(10001000),   bin8(11101110),   bin8(00100010),   bin8(11101110), //S
   bin8(11101110),   bin8(01000100),   bin8(01000100),   bin8(01000100),   bin8(01000100), //T
   bin8(10101010),   bin8(10101010),   bin8(10101010),   bin8(10101010),   bin8(11101110), //U
   bin8(10101010),   bin8(10101010),   bin8(10101010),   bin8(10101010),   bin8(01000100), //V
   bin8(10101010),   bin8(10101010),   bin8(11101110),   bin8(11101110),   bin8(10101010), //W
   bin8(00000000),   bin8(10101010),   bin8(01000100),   bin8(01000100),   bin8(10101010), //X
   bin8(10101010),   bin8(10101010),   bin8(01000100),   bin8(01000100),   bin8(01000100), //Y
   bin8(11101110),   bin8(00100010),   bin8(01000100),   bin8(10001000),   bin8(11101110), //Z
   bin8(11101110),   bin8(10001000),   bin8(10001000),   bin8(10001000),   bin8(11101110), //[
   bin8(10001000),   bin8(10001000),   bin8(01000100),   bin8(00100010),   bin8(00100010), // 
   bin8(11101110),   bin8(00100010),   bin8(00100010),   bin8(00100010),   bin8(11101110), //]
   bin8(01000100),   bin8(10101010),   bin8(00000000),   bin8(00000000),   bin8(00000000), //^
   bin8(00000000),   bin8(00000000),   bin8(00000000),   bin8(00000000),   bin8(11101110), //_
   bin8(10001000),   bin8(01000100),   bin8(00000000),   bin8(00000000),   bin8(00000000), //`
   bin8(00000000),   bin8(01000100),   bin8(10101010),   bin8(10101010),   bin8(01100110), //a
   bin8(10001000),   bin8(11001100),   bin8(10101010),   bin8(10101010),   bin8(11001100), //b
   bin8(00000000),   bin8(01100110),   bin8(10001000),   bin8(10001000),   bin8(01100110), //c
   bin8(00100010),   bin8(01100110),   bin8(10101010),   bin8(10101010),   bin8(01100110), //d
   bin8(00000000),   bin8(01000100),   bin8(10101010),   bin8(11001100),   bin8(01100110), //e
   bin8(01100110),   bin8(01000100),   bin8(11101110),   bin8(01000100),   bin8(01000100), //f
   bin8(00000000),   bin8(01000100),   bin8(10101010),   bin8(01100110),   bin8(11001100), //g
   bin8(10001000),   bin8(11001100),   bin8(10101010),   bin8(10101010),   bin8(10101010), //h
   bin8(01000100),   bin8(00000000),   bin8(01000100),   bin8(01000100),   bin8(01000100), //i
   bin8(01000100),   bin8(00000000),   bin8(01000100),   bin8(01000100),   bin8(10001000), //j
   bin8(10001000),   bin8(10001000),   bin8(10101010),   bin8(11001100),   bin8(10101010), //k
   bin8(01000100),   bin8(01000100),   bin8(01000100),   bin8(01000100),   bin8(01000100), //l
   bin8(00000000),   bin8(11101110),   bin8(11101110),   bin8(10101010),   bin8(10101010), //m
   bin8(00000000),   bin8(11001100),   bin8(10101010),   bin8(10101010),   bin8(10101010), //n
   bin8(00000000),   bin8(01000100),   bin8(10101010),   bin8(10101010),   bin8(01000100), //o
   bin8(00000000),   bin8(11001100),   bin8(10101010),   bin8(11001100),   bin8(10001000), //p
   bin8(00000000),   bin8(01100110),   bin8(10101010),   bin8(01100110),   bin8(00100010), //q
   bin8(00000000),   bin8(10001000),   bin8(11101110),   bin8(10001000),   bin8(10001000), //r
   bin8(00000000),   bin8(01100110),   bin8(11001100),   bin8(00100010),   bin8(11001100), //s
   bin8(01000100),   bin8(11101110),   bin8(01000100),   bin8(01000100),   bin8(01000100), //t
   bin8(00000000),   bin8(10101010),   bin8(10101010),   bin8(10101010),   bin8(01000100), //u
   bin8(00000000),   bin8(10101010),   bin8(10101010),   bin8(01000100),   bin8(01000100), //v
   bin8(00000000),   bin8(10101010),   bin8(10101010),   bin8(11101110),   bin8(10101010), //w
   bin8(00000000),   bin8(10101010),   bin8(01000100),   bin8(01000100),   bin8(10101010), //x
   bin8(00000000),   bin8(10101010),   bin8(10101010),   bin8(01100110),   bin8(11001100), //y
   bin8(00000000),   bin8(11101110),   bin8(01100110),   bin8(11001100),   bin8(11101110), //z
   bin8(00100010),   bin8(01000100),   bin8(11001100),   bin8(01000100),   bin8(00100010), //{
   bin8(01000100),   bin8(01000100),   bin8(01000100),   bin8(01000100),   bin8(01000100), //|
   bin8(10001000),   bin8(01000100),   bin8(01100110),   bin8(01000100),   bin8(10001000), //}
   bin8(00000000),   bin8(11001100),   bin8(10101010),   bin8(00000000),   bin8(00000000)  //~
   };

//================================
// Paste above "glcd_fillScreen(int1 color)"
//================================
// Purpose:       Write small text on a graphic LCD
// Inputs:        (x,y) - The upper left coordinate of the first letter
//                textptr - A pointer to an array of text to display
//                color - ON or OFF

//char characterSet[] = " !#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
void glcd_text35(uint8_t x, uint8_t y, char* textptr, uint8_t color)
{
   uint8_t i, j, k;                           // Loop counters
   uint8_t pixelData[5];                     // Stores character data

   for(i=0; textptr[i] != '\0'; ++i, ++x) // Loop through the passed string
   {
      if((textptr[i] >= ' ') && (textptr[i] <= '~'))  memcpy(pixelData, TEXT35[textptr[i]-' '], 5);        
      else                                            memcpy(pixelData, TEXT35[0], 5); // Default to space        

      if(x+3 >= 128)          // Performs character wrapping
      {
         x = 0;                           // Set x at far left position
         y += 5 + 1;                      // Set y at next position down
      }
      for(j=3; j>0; j--, x++)             // Loop through character byte data
//!      {
         for(k=0; k<5; k++)               // Loop through the vertical pixels
         {
            if((pixelData[k]>>j) & 1) // Check if the pixel should be set					  
            {
               glcd_pixel(x, y+k, color); // Draws the pixel
            }
         }
      }
   }
