// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// test.c
// Program on A3 branch.
// Convert the given decimal number to different forms (Decimal, Hexadecimal, Binary) 
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "game.h"

// Function to clear the console screen
void clearScreen () {
#ifdef _WIN32
   system ("cls");              // Windows-specific command to clear the screen
#else
   system ("clear");           // Unix/Linux/MacOS-specific command to clear the screen
#endif
}

int main () {
   int num;                                          // Variable to store the user input
   char choice,buffer[100];
   do {
      clearScreen ();
      int validInput = 0;                            // Check the input is Valid
      while (!validInput) {                          // Prompt the user for input
         printf ("Enter a decimal number: ");
         if (fgets (buffer, sizeof (buffer), stdin)) {
            char* endptr;
            num = strtol (buffer, &endptr, 10);
            if (*endptr == '\0' || *endptr == '\n') validInput = 1;
            else printf ("Invalid input. Please enter a valid decimal number.\n");
         }
         if (!validInput) {
            printf ("Do you want to try again? (y/n): ");
            choice = getchar ();
            while (getchar () != '\n');
            if (choice != 'y' && choice != 'Y') printf ("Exiting the program.\n");
         }
      }
      char* binaryStr = DecimalToBinary (num);                                  // Convert the decimal number to binary and print the result
      if (binaryStr != NULL) {
         printf ("Binary: %s\n", binaryStr);
         free (binaryStr);
      }
      else printf ("Memory allocation Failed.\n");
      char* hexStr = DecimalToHex (num);                                      // Convert the decimal number to hexadecimal and print the result
      if (hexStr != NULL) {
         printf ("Hexadecimal: %s\n", hexStr);
         free (hexStr);
      }
      printf ("Decimal: %d\n", num);                                         // Print the decimal number
      printf ("\nDo you want to enter another number? (y/n): ");             // Ask the user if they want to enter another number
      choice = getchar ();
      while (getchar () != '\n');
   } while (choice == 'y' || choice == 'Y');                                // Repeat the process if the user chooses 'y' or 'Y'
   // Test conversion functions
   printf ("----------- Decimal To Binary ---------- \n");
   TestDecToBinAndNegBin ();                                               // Call test function for decimal to binary conversion
   printf ("----------- Decimal To Hexadecimal ----------- \n");
   TestDecToHexAndNegHex ();                                               // Call test function for decimal to hexadecimal conversion
   return 0;
}



