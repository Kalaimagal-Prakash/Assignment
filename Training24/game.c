// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// game.c
// Program on A3 branch.
// Convert the given decimal number to different forms (Decimal, Hexadecimal, Binary) 
// ------------------------------------------------------------------------------------------------

#include <malloc.h>
#include "game.h"

/// <summary>Convert a decimal number to its binary representation.</summary>
char* DecimalToBinary (int n) {
   char* binaryStr = (char*)malloc (BITS + (BITS / 8) + 1);                 // Allocate memory for binary string with extra space for formatting
   if (binaryStr == NULL) return NULL;
   int binaryNum[BITS],index=0;                                            // Array to store binary digits and index for the string     
   for (int i = 0; i < BITS; i++) binaryNum[BITS - 1 - i] = (n >> i) & 1;           
   for (int i = 0; i < BITS; i++) {
      binaryStr[index++] = binaryNum[i] + '0';                            // Convert binary digit to character
      if ((i + 1) % 8 == 0 && i != BITS - 1) binaryStr[index++] = ' ';    // Add space every 8 bits except at the end
   }
   binaryStr[index] = '\0';                                               // Null-terminate the string
   return binaryStr;
}

/// <summary>Convert a decimal number to its hexadecimal representation.</summary>
char* DecimalToHex (int h) {
   int index = 0;
   char* hexStr = (char*)malloc (HEX_DIGIT + 3 + 1);                    // Allocate memory for hex string
   if (hexStr == NULL) return NULL;
   for (int i = 0; i < HEX_DIGIT; i++) {                    
      int digit = (h >> ((HEX_DIGIT - 1 - i) * 4)) & 0xF;              // Extract hex digit
      hexStr[index++] = digit < 10 ? digit + '0' : digit - 10 + 'A';   // Convert digit to character
   }
   hexStr[index] = '\0';                                               // Null-terminate the string
   return hexStr;
}