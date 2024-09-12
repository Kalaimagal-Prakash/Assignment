// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// Test.c
// Program on A4 branch.
// 1. Palindrome is a word that reads the same forward or backward. Example: Civic, Madam, Bib, Nun, Level and so on. 
//    Your program must take the word as input and display the result if it is a palindrome or not. 
//    For complexity, you can also use phrases instead of words (E.g., Was it a car or a cat I saw? I did, did I? Don’t nod)
// 2. Write a program that reverses a given integer (as defined in C) as explained below and check if it is a palindrome.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h> 
#include "Header.h"
#define MAXLENGTH 100

// ANSI escape codes for colors
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"

/// <summary>Function to clear the console screen.</summary>
void ClearScreen () {
#ifdef _WIN32
   system ("cls");           // Windows-specific command to clear the screen
#else
   system ("clear");        // Unix/Linux/MacOS-specific command to clear the screen
#endif
}

/// <summary>Function to print test results.</summary>
void FormatResult (int numTests, const char* inputs[], const char* expected_results[], const char* actual_results[], int pass[]) {
   // Adjust column widths for alignment
   printf (YELLOW "---------------------------------- Test Results ----------------------------------\n" RESET);
   printf ("| Test Case | Input                           | Expected     | Actual     |Result|\n");
   printf ("|-----------|---------------------------------|--------------|------------|------|\n");
   for (int i = 0; i < numTests; i++)
      printf ("| %-9d | %-31s | %-12s | %-10s | %6s |\n", i + 1, inputs[i], expected_results[i], actual_results[i] ? actual_results[i] : "NULL",
         pass[i] ? GREEN "PASS" RESET : RED "FAIL" RESET);
   printf ("\n");
}

/// <summary>Test cases for Palindrome function.</summary>
void TestPalindrome () {
   struct {
      const char* input;
      bool expected;
   } tests[] = {
       {"civic", true}, {"madam", true}, {"12321", true},
       {"Was it a car or a cat I saw?", true}, {"Hello, World!", false},
       {"A man, a plan, a canal, Panama", true}, {"", true},
       {"A", true}, {"ab", false}, {"Able was I ere I saw Elba", true} };
   int numTests = sizeof (tests) / sizeof (tests[0]);
   char** actualResults = malloc (numTests * sizeof (char*));
   int* pass = malloc (numTests * sizeof (int));
   if (actualResults == NULL || pass == NULL) {
      printf ("Memory allocation failed\n");
      return;
   }
   for (int i = 0; i < numTests; ++i) {
      bool result = Palindrome (tests[i].input);
      const char* resultStr = result ? "True" : "False";
      actualResults[i] = _strdup (resultStr);
      pass[i] = (result == tests[i].expected);
   }
   // Call the function to format and print the results
   FormatResult (numTests,
      (const char* []) {
      "civic", "madam", "12321", "Was it a car or a cat I saw?", "Hello, World!", "A man, a plan, a canal, Panama", "", "A", "ab", "Able was I ere I saw Elba"
   },
      (const char* []) {
      "True", "True", "True", "True", "False", "True", "True", "True", "False", "True"
   },
      (const char**)actualResults, pass);
   for (int i = 0; i < numTests; ++i) free (actualResults[i]);
   free (actualResults);
   free (pass);
}

/// <summary>Test cases for Reverse_Number function.</summary>
void TestReverseNumber () {
   struct {
      int input;
      const char* expected;
   } tests[] = {
       {1234, "4321"}, {0, "0"}, {-1234, "-4321"},
       {1000, "1"}, {2147483647, "Overflow"}, {-2147483647, "Overflow"},
       {10, "1"},      // Leading zeros are removed in integer representation
       {-10, "-1"}, {9, "9"} };
   int numTests = sizeof (tests) / sizeof (tests[0]);
   char** actualResults = malloc (numTests * sizeof (char*));
   int* pass = malloc (numTests * sizeof (int));
   if (actualResults == NULL || pass == NULL) {
      printf ("Memory allocation failed\n");
      return;
   }
   for (int i = 0; i < numTests; ++i) {
      int result = ReverseNumber (tests[i].input);
      // Convert result to string
      char resultStr[12];
      if (result == 0 && (tests[i].input > 0 || tests[i].input < 0)) snprintf (resultStr, sizeof (resultStr), "Overflow");
      else snprintf (resultStr, sizeof (resultStr), "%d", result);
      pass[i] = (strcmp (resultStr, tests[i].expected) == 0) ? 1 : 0;
      actualResults[i] = _strdup (resultStr);
   }
   FormatResult (
      numTests,
      (const char* []) {
      "1234", "0", "-1234", "1000", "2147483647", "-2147483647", "10", "-10", "9"
   },
      (const char* []) {
      "4321", "0", "-4321", "1", "Overflow", "Overflow", "1", "-1", "9"
   },
      (const char**)actualResults, pass);
   for (int i = 0; i < numTests; ++i) free (actualResults[i]);
   free (actualResults);
   free (pass);
}

int main () {
   // Run test case
   TestPalindrome ();                                                      // Call test function to check the word is palindrome
   TestReverseNumber ();                                                   // Call test function to check the integer is reversed and 
   char choice[MAXLENGTH];
   int num = 0;
   int validInput;                                                         // Variable to store the user input
   char buffer[MAXLENGTH];
   do {
      printf (YELLOW "Select the Option: \n1. Check if a word or phrase is a palindrome \n2. Reverse an integer and check if it is a palindrome \n3. Exit \nEnter your option (1-3): " RESET);
      validInput = 0;
      while (!validInput) {                                               // Prompt the user for input
         if (fgets (buffer, sizeof (buffer), stdin)) {
            char* endptr;
            int choiceNum = (int)strtol (buffer, &endptr, 10);
            if (*endptr == '\0' || *endptr == '\n') {
               if (choiceNum >= 1 && choiceNum <= 3) {
                  validInput = 1;
                  num = choiceNum;
               }
               else printf ("Invalid choice. Please enter a number between 1 and 3.\n");
            }
            else printf ("Invalid input. Please enter a valid number.\n");
         }
      }
      ClearScreen ();
      switch (num) {
      case 1: {
         printf ("Enter a phrase or word to check if it's a palindrome: ");
         if (fgets (buffer, sizeof (buffer), stdin)) {
            buffer[strcspn (buffer, "\n")] = '\0';
            if (Palindrome (buffer)) printf ("Palindrome\n");
            else printf ("Not a Palindrome\n");
         }
         break;
      }
      case 2: {
         printf ("Enter an integer to reverse and check if it's a palindrome: ");
         validInput = 0;
         while (!validInput) {
            if (fgets (buffer, sizeof (buffer), stdin)) {
               char* endptr;
               num = (int)strtol (buffer, &endptr, 10);
               if (*endptr == '\0' || *endptr == '\n') validInput = 1;
               else {
                  printf ("Invalid input. Please enter a valid integer.\n");
                  continue;
               }
            }
         }
         int reversedNum = ReverseNumber (num);                              // Reverse the number and check if it's a palindrome
         printf ("Reversed Number: %d\n", reversedNum);
         if (reversedNum == num) printf ("Palindrome\n");
         else printf ("Not a Palindrome\n");
         break;
      }
      case 3:
         printf ("Exiting...\n");
         return 0;
      default:
         printf ("Unexpected error occurred.\n");
         return 1;
      }
      do {
         printf ("\nDo you want to enter another option? (y/n): ");
         if (fgets (choice, sizeof (choice), stdin)) {
            choice[strcspn (choice, "\n")] = '\0';
            if (choice[0] == 'y' || choice[0] == 'Y') {
               ClearScreen ();
               break;
            }
            else if (choice[0] == 'n' || choice[0] == 'N') {
               printf ("Exiting the program.\n");
               return 0;
            }
            else printf ("Invalid choice. Please enter 'y' to continue or 'n' to exit.\n");
         }
      } while (1);                                                       // Infinite loop until a valid choice is entered
   } while (1);                                                          // Infinite loop to allow continuous operation
   return 0;
}