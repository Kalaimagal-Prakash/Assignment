// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// game.c
// Program on A3 branch.
// Convert the given decimal number to different forms (Decimal, Hexadecimal, Binary) 
// ------------------------------------------------------------------------------------------------

#include <stdio.h>

/// <summary>Function to convert decimal to binary.</summary>
void DecimalToBinary (int n) {
   int binaryNum[32], i = 0, isNegative = n < 0;
   if (isNegative) n = -n;                       // Work with positive equivalent
   while (n > 0) {                               // Convert decimal to binary
      binaryNum[i] = n % 2;
      n /= 2;
      i++;
   }
   while (i < 8) {                              // Assuming 8-bit representation
      binaryNum[i] = 0;
      i++;
   }
   if (isNegative) {
      for (int j = 0; j < 8; j++) binaryNum[j] = binaryNum[j] == 0 ? 1 : 0; // Invert bits
      int carry = 1;
      for (int j = 0; j < 8; j++) {
         int sum = binaryNum[j] + carry;
         binaryNum[j] = sum % 2;
         carry = sum / 2;
      }
   }
   printf ("\nBinary value is: ");              // Print binary in reverse order
   for (int j = 7; j >= 0; j--) printf ("%d", binaryNum[j]);
   printf ("\n");
}

/// <summary>Function to convert decimal to hexadecimal.</summary>
void DecimalToHex (int h) {
   char hex_Number[9]; 
   unsigned int number = (unsigned int)h;          // Cast to unsigned to handle negative values correctly
   int i = 0;
   while (number != 0) {                           // Convert number to hexadecimal 
      int temp = number % 16;
      if (temp < 10) hex_Number[i++] = temp + '0'; // Convert to character '0'-'9'
      else hex_Number[i++] = temp + 'A' - 10;      // Convert to character 'A'-'F'
      number /= 16;
   }
   while (i < 8) hex_Number[i++] = '0';
   printf ("Hexadecimal value is: ");             // Print the hexadecimal in reverse order
   for (int j = i - 1; j >= 0; j--) printf ("%c", hex_Number[j]);
}

int main () {
   int number;
   printf ("Enter the Input: ");                         // Get user input
   if (scanf_s ("%d", &number) != 1) {
      printf ("Invalid Input\n");
      return 1;
   }
   printf ("Decimal: %d\n", number);                   // Print decimal value
   DecimalToHex (number);                              // Print hexadecimal value
   DecimalToBinary (number);                           // Print binary value
   return 0;
}