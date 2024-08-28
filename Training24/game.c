// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// game.c
// Program on A3 branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>

/// <summary>Function to convert decimal to binary.</summary>
void decimalToBinary (int n) {
   int binaryNum[32];
   int i = 0;
   int isNegative = n < 0;
   if (n == 0) {                                 // Handle zero case
      printf ("Binary: 0\n");
      return;
   }
   if (isNegative) n = -n;
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
   printf ("\nBinary value is: %s", isNegative ? "-" : "");   // Print binary in reverse order
   for (int j = 7; j >= 0; j--) printf ("%d", binaryNum[j]);
   printf ("\n");
}

/// <summary>Function to convert decimal to hexadecimal.</summary>
void decimalToHex (int h) {
   char hex_Number[100];
   int i = 0;
   int isNegative = h < 0;
   if (isNegative) h = -h;  // Work with positive equivalent
   if (h == 0) {                         // Handle zero case
      printf ("Hexadecimal value is: 0\n");
      return;
   }
   while (h != 0) {
      int temp = h % 16;
      if (temp < 10) {
         hex_Number[i++] = temp + '0';             // Convert to character
      }
      else {
         hex_Number[i++] = temp + 'A' - 10;        // Convert to character
      }
      h /= 16;
   }
   if (isNegative) printf ("Hexadecimal value is: -");     // Print the result
   else printf ("Hexadecimal value is: ");
   for (int j = i - 1; j >= 0; j--) printf ("%c", hex_Number[j]);
}

int main () {
   int number;
   printf ("Input: ");                                  // Get user input
   if (scanf_s ("%d", &number) != 1) {
      printf ("Invalid input\n");
      return 1;
   }
   printf ("Decimal: %d\n", number);                   // Print decimal value
   decimalToHex (number);                              // Print hexadecimal value
   decimalToBinary (number);                           // Print binary value
   return 0;
}