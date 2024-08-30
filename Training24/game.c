// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// game.c
// Program on A3 branch.
// Convert the given decimal number to different forms (Decimal, Hexadecimal, Binary) 
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "game.h"

// Convert a decimal number to its binary representation
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

// Convert a decimal number to its hexadecimal representation
char* DecimalToHex (int h) {
   int index = 0;
   char* hexStr = (char*)malloc (HEX_DIGIT + 3 + 1);                    // Allocate memory for hex string
   if (hexStr == NULL) return NULL;
   hexStr[index++] = '0';
   hexStr[index++] = 'x';                                              // Prefix for hexadecimal
   for (int i = 0; i < HEX_DIGIT; i++) {                    
      int digit = (h >> ((HEX_DIGIT - 1 - i) * 4)) & 0xF;              // Extract hex digit
      hexStr[index++] = digit < 10 ? digit + '0' : digit - 10 + 'A';   // Convert digit to character
   }
   hexStr[index] = '\0';                                              // Null-terminate the string
   return hexStr;
}
// Test cases for DecimalToBinary function
void TestDecToBinAndNegBin () {
   unsigned int positive_inputs[] = { 5, 45, 10, 214, 255 };
   const char* expected_bin_result[] = {
       "00000000 00000000 00000000 00000101",                         // Expected binary results for positive numbers
       "00000000 00000000 00000000 00101101",
       "00000000 00000000 00000000 00001010",
       "00000000 00000000 00000000 11010110",
       "00000000 00000000 00000000 11111110"
   };
   const char* expected_neg_bin_result[] = {                          // Expected binary results for negative numbers (two's complement representation)
       "11111111 11111111 11111111 11111011",
       "11111111 11111111 11111111 11010011",
       "11111111 11111111 11111111 11110110",
       "11111111 11111111 11111111 00101010",
       "11111111 11111111 11111111 00000000"  
   };
   int noOfTests = sizeof (positive_inputs) / sizeof (positive_inputs[0]);
   // Test positive cases
   for (int i = 0; i < noOfTests; i++) {
      char* result = DecimalToBinary ((int)positive_inputs[i]);
      if (result != NULL) {
         if (strcmp (result, expected_bin_result[i]) == 0) printf ("Positive Test Case %d: Input --> %u PASS\n", i + 1, positive_inputs[i]);
         else {
            printf ("Positive Test Case %d:  FAIL\n", i + 1);
            printf ("EXPECTED: %s\n", result);
            printf ("GOT: %s\n", expected_bin_result[i]);
         }
         free (result);
      }
      else {
         printf ("Positive Test Case %d: FAIL\n", i + 1);
         printf ("EXPECTED: %s\n", expected_bin_result[i]);
         printf ("GOT: NULL (Memory allocation failed)\n");
      }
      printf ("\n");
   }
   // Test negative cases
   for (int i = 0; i < noOfTests; i++) {
      char* result = DecimalToBinary (-(int)positive_inputs[i]);
      if (result != NULL) {
         if (strcmp (result, expected_neg_bin_result[i]) == 0) printf ("Negative Test Case %d: Input --> -%u PASS\n", i + 1, positive_inputs[i]);
         else {
            printf ("Negative Test Case %d: FAIL\n", i + 1);
            printf ("EXPECTED: %s\n", result);
            printf ("GOT: %s\n", expected_neg_bin_result[i]);
         }
         free (result);
      }
      else {
         printf ("Negative Test Case %d: FAIL\n", i + 1);
         printf ("EXPECTED: %s\n", expected_neg_bin_result[i]);
         printf ("GOT: NULL (Memory allocation failed)\n");
      }
      printf ("\n");
   }
}

// Test cases for DecimalToHex function
void TestDecToHexAndNegHex () {
   unsigned int inputs[] = { 6, 9, 255, 78, 34 };
   const char* expected_result_pos[] = {
       "0x00000006",                                 // Expected hexadecimal results for positive numbers
       "0x00000009",
       "0x000000FF",
       "0x0000004E",
       "0x00000020"
   };
   const char* expected_result_neg[] = {
       "0xFFFFFFFA",                                // Expected hexadecimal results for negative numbers
       "0xFFFFFFF7",
       "0xFFFFFF01",
       "0xFFFFFFB2",
       "0xFFFFFFD0"
   };
   int noOfTests = sizeof (inputs) / sizeof (inputs[0]);
   // Test positive values
   for (int i = 0; i < noOfTests; i++) {
      char* result = DecimalToHex (inputs[i]);
      if (strcmp (result, expected_result_pos[i]) == 0) printf ("Test Case %d (Positive): Input --> %u Pass\n", i + 1, inputs[i]);
      else {
         printf ("Test Case %d (Positive): FAIL\n", i + 1);
         printf ("EXPECTED: %s\n", result);
         printf ("GOT: %s\n", expected_result_pos[i]);
      }
      free (result);
      printf ("\n");
   }
   // Test negative values
   for (int i = 0; i < noOfTests; i++) {
      char* result = DecimalToHex (-((int)inputs[i]));
      if (strcmp (result, expected_result_neg[i]) == 0) printf ("Test Case %d (Negative): Input ---> -%u Pass\n", i + 1, inputs[i]);
      else {
         printf ("Test Case %d (Negative): FAIL\n", i + 1);
         printf ("EXPECTED: %s\n", result);
         printf ("GOT: %s\n", expected_result_neg[i]);
      }
      free (result);
      printf ("\n");
   }
}