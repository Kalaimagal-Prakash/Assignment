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
#include <string.h>
#include <malloc.h>
#include "game.h"

// ANSI escape codes for colors
#define COLOR_RESET   "\033[0m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_RED     "\033[31m"
#define COLOR_YELLOW  "\033[33m"

/// <summary>Function to clear the console screen.</summary>
void ClearScreen () {
#ifdef _WIN32
   system ("cls");              // Windows-specific command to clear the screen
#else
   system ("clear");           // Unix/Linux/MacOS-specific command to clear the screen
#endif
}

/// <summary>Function to print test results for binary conversion.</summary>
void FormatBin (int numTests, int inputs[], const char* expected_results[], const char* actual_results[], int pass[]) {
   // Adjust column widths for alignment
   printf (COLOR_YELLOW "-------------------------------------------- Test Results for Binary ------------------------------------------\n" COLOR_RESET);
   printf ("| Test Case | Input       | Expected                            | Actual                               |Result|\n");
   printf ("|-----------|-------------|-------------------------------------|--------------------------------------|------|\n");
   for (int i = 0; i < numTests; i++) {
      // Adjust column widths to match header alignment
      printf ("| %-9d | %-11d | %-35s |" COLOR_GREEN " % -36s "COLOR_RESET"| % -6s | \n", i + 1, inputs[i], expected_results[i], actual_results[i] ? actual_results[i] : "NULL",
         pass[i] ? COLOR_GREEN "PASS" COLOR_RESET : COLOR_RED "FAIL" COLOR_RESET);
   }
   printf ("\n");
}

/// <summary>Function to print test results for Hexadecimal conversion.</summary>
void FormatHex (int numTests, int inputs[], const char* expected_results[], const char* actual_results[], int pass[]) {
   // Adjust column widths for alignment
   printf (COLOR_YELLOW "------------------- Test Results Hexadecimal -------------------\n" COLOR_RESET);
   printf ("| Test Case | Input       | Expected     | Actual       |Result|\n");
   printf ("|-----------|-------------|--------------|--------------|------|\n");
   for (int i = 0; i < numTests; i++) {
   // Adjust column widths to match header alignment
      printf ("| %-9d | %-11d | %-12s |" COLOR_GREEN " %-12s "COLOR_RESET"| %-6s |\n", i + 1, inputs[i], expected_results[i], actual_results[i] ? actual_results[i] : "NULL",
         pass[i] ? COLOR_GREEN "PASS" COLOR_RESET : COLOR_RED "FAIL" COLOR_RESET);
   }
   printf ("\n");
}

/// <summary>Test cases for DecimalToBinary function.</summary>
void TestDec2Bin () {
   // Define input test values and expected binary results
   int inputs[] = { 5, 45, 214, 2147483647, 255, -5, -255, -2147483647 };
   const char* expected_bin_result[] = {
       "00000000 00000000 00000000 00000101",  // 5
       "00000000 00000000 00000000 00101101",  // 45
       "00000000 00000000 00000000 11010110",  // 214
       "01111111 11111111 11111111 11111111",  // 2147483647
       "00000000 00000000 00000000 11111111",  // 255
       "11111111 11111111 11111111 11111011",  // -5
       "11111111 11111111 11111111 00000001",  // -255
       "10000000 00000000 00000000 00000001"   // -2147483647
   };
   int numTests = sizeof (inputs) / sizeof (inputs[0]);
   char** actual_bin_result = malloc (numTests * sizeof (char*));
   int* pass = malloc (numTests * sizeof (int));
   if (actual_bin_result == NULL || pass == NULL) {
      printf ("Memory allocation failed\n");
      return;
   }
   for (int i = 0; i < numTests; i++) {
      char* result = Dec2Bin (inputs[i]);
      pass[i] = (result && strcmp (result, expected_bin_result[i]) == 0) ? 1 : 0;
      actual_bin_result[i] = result;
   }
   // Call the function to format and print the results
   FormatBin (numTests, inputs, expected_bin_result, actual_bin_result, pass);
   for (int i = 0; i < numTests; i++) free (actual_bin_result[i]);
   free (actual_bin_result);
   free (pass);
}

/// <summary>Test cases for DecimalToHex function.</summary>
void TestDec2Hex () {
   // Define input test values and expected hexadecimal results
   int inputs[] = { 1, 255, 4095, 65536, 2147483647, -2147483647, -255, -1 };
   const char* expected_hex_result[] = {
       "00000001",  // 1
       "000000FF",  // 255
       "00000FFF",  // 4095
       "00010000",  // 65536
       "7FFFFFFF",  // 2147483647
       "80000001",  // -2147483647
       "FFFFFF01",  // -255
       "FFFFFFFF"   // -1
   };
   int numTests = sizeof (inputs) / sizeof (inputs[0]);
   char** actual_hex_result = malloc (numTests * sizeof (char*));
   int* pass = malloc (numTests * sizeof (int));
   if (actual_hex_result == NULL || pass == NULL) {
      printf ("Memory allocation failed\n");
      return;
   }
   for (int i = 0; i < numTests; i++) {
      char* result = Dec2Hex (inputs[i]);
      pass[i] = (result && strcmp (result, expected_hex_result[i]) == 0) ? 1 : 0;
      actual_hex_result[i] = result;
   }
   // Call the function to format and print the results
   FormatHex (numTests, inputs, expected_hex_result, actual_hex_result, pass);
   for (int i = 0; i < numTests; i++) free (actual_hex_result[i]);
   free (actual_hex_result);
   free (pass);
}

int main () {
   // Run test cases
   TestDec2Bin ();                                                          // Call test function for decimal to binary conversion      
   TestDec2Hex ();                                                          // Call test function for decimal to hexadecimal conversion
   char choice;
   do {
      int num = 0, validInput = 0;                                         // Variable to store the user input
      char buffer[100];
      while (!validInput) {                                                // Prompt the user for input
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
            if (choice != 'y' && choice != 'Y') {
               printf ("Exiting the program.\n");
               return 0;
            }
         }
      }
      char* binaryStr = Dec2Bin (num);                           // Convert the decimal number to binary
      if (binaryStr != NULL) {
         printf ("Binary: %s\n", binaryStr);
         free (binaryStr);
      }
      else printf ("Memory allocation failed.\n");
      char* hexStr = Dec2Hex (num);                                // Convert the decimal number to hexadecimal
      if (hexStr != NULL) {
         printf ("Hexadecimal: %s\n", hexStr);
         free (hexStr);
      }
      else printf ("Memory allocation failed.\n");
      printf ("Decimal: %d\n", num);                                   // Print the decimal number
      printf ("\nDo you want to enter another number? (y/n): ");       // Ask if user wants to continue
      choice = getchar ();
      while (getchar () != '\n');
   } while (choice == 'y' || choice == 'Y');                           // Repeat if 'y' or 'Y'
   printf ("Exiting the program.\n");
   return 0;
}