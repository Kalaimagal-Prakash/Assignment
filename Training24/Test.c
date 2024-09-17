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
#include <ctype.h> 
#include "Header.h"
#define MAXLENGTH 100

// ANSI escape codes for colors
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"

/// <summary>Function to clear the console screen.</summary>
void ClearScreen () {
#ifdef _WIN32
   system ("cls");           // Windows-specific command to clear the screen
#else
   system ("clear");        // Unix/Linux/MacOS-specific command to clear the screen
#endif
}

void Filter (char* buffer, const char* temp) {
   int j = 0;
   for (int i = 0; temp[i] != '\0'; i++) {
      if (temp[i] != ' ' && temp[i] != ',' && temp[i] != '?' && temp[i] != '/' && temp[i] != '.') {           // Skip spaces, commas, question marks, dot and slash
         buffer[j] = tolower (temp[i]);
         j++;
      }
   }
   buffer[j] = '\0';
}

/// <summary>Function to print test results.</summary>
void FormatResult (int numTests, const char* inputs[], const char* expected_results[], const char* actual_results[], int pass[]) {
   // Adjust column widths for alignment
   printf (YELLOW "---------------------------------------- Test Results ----------------------------------------\n" RESET);
   printf ("| Test Case | Input                           | Expected          | Actual            |Result|\n");
   printf ("|-----------|---------------------------------|-------------------|-------------------|------|\n");
   for (int i = 0; i < numTests; i++)
      printf ("| %-9d | %-31s | %-17s | %-17s | %6s |\n", i + 1, inputs[i], expected_results[i], actual_results[i] ? actual_results[i] : "NULL",
         pass[i] ? GREEN "PASS" RESET : RED "FAIL" RESET);
   printf ("\n");
}

/// <summary>Test cases for Palindrome function.</summary>
void TestPalindrome () {
   struct {                                                          // Array of test cases for palindrome checking
      const char* input;
      const char* expected;
   } tests[] = {
       {"civic", "Palindrome" }, { "madam", "Palindrome" }, { "12321", "Palindrome" },
       {"Was it a car or a cat I saw", "Palindrome" }, { "Hello, World!", "Not Palindrome" },
       {"A man, a plan, a canal, Panama", "Palindrome" },
       {"A", "Palindrome" }, { "ab", "Not Palindrome" }, { "Able was I ere I saw Elba", "Palindrome" },{ "a@a", "Palindrome" } ,{ "@!$2", "Not Palindrome" } };
   int numTests = sizeof (tests) / sizeof (tests[0]);
   char** actualResults = malloc (numTests * sizeof (char*));
   int* pass = malloc (numTests * sizeof (int));
   if (actualResults == NULL || pass == NULL) {
      printf ("Memory allocation failed\n");
      return;
   }
   for (int i = 0; i < numTests; ++i) {
      char temp[MAXLENGTH];
      Filter (temp, tests[i].input);                                 // Filter out non-alphanumeric characters and convert to lowercase
      bool result = Palindrome (temp);
      const char* resultStr = result ? "Palindrome" : "Not Palindrome";
      actualResults[i] = _strdup (resultStr);
      pass[i] = (result == (strcmp (tests[i].expected, "Palindrome") == 0));
   }
   // Call the function to format and print the results
   FormatResult (numTests,
      (const char* []) {
      "civic", "madam", "12321", "Was it a car or a cat I saw", "Hello, World!", "A man, a plan, a canal, Panama", "A", "ab", "Able was I ere I saw Elba", "a@a", "@!$2"
   },
      (const char* []) {
      "Palindrome", "Palindrome", "Palindrome", "Palindrome", "Not Palindrome", "Palindrome", "Palindrome", "Not Palindrome", "Palindrome", "Palindrome", "Not Palindrome"
   },
      (const char**)actualResults, pass);
   for (int i = 0; i < numTests; ++i) free (actualResults[i]);
   free (actualResults);
   free (pass);
}

/// <summary>Test cases for Reverse_Number function.</summary>
void TestReverseNumber () {
   struct {                                                        // Array of test cases for reversing numbers
      int input;
      int expected;
   } tests[] = {
       {1234, 4321}, {0, 0}, {1000, 1 },
       {10, 1}, {9, 9}, {3456, 6543}
   };
   int numTests = sizeof (tests) / sizeof (tests[0]);
   int* actualResults = malloc (numTests * sizeof (int));
   int* pass = malloc (numTests * sizeof (int));
   if (actualResults == NULL || pass == NULL) {
      printf ("Memory allocation failed\n");
      return;
   }
   for (int i = 0; i < numTests; ++i) {
      int result = ReverseNumber (tests[i].input);              // Reverse the number
      actualResults[i] = result;
      pass[i] = (result == tests[i].expected);
   }
   FormatResult (numTests,
      (const char* []) {
      "1234", "0", "1000", "10", "9", "3456"
   },
      (const char* []) {
      "4321", "0", "1", "1", "9", "6543"
   },
      (const char* []) {
      "4321", "0", "1", "1", "9", "6543"
   },
      pass);
   free (actualResults);
   free (pass);
}

int main () {
   // Run test case
   TestPalindrome ();
   TestReverseNumber ();
   char buffer[MAXLENGTH], choice[MAXLENGTH], temp[MAXLENGTH];
   int num = 0;
   while (1) {
      printf ("\nEnter a string or integer: ");
      if (fgets (buffer, sizeof (buffer), stdin)) {
         buffer[strcspn (buffer, "\n")] = '\0';                                               // Remove newline character
         char* endptr;
         num = (int)strtol (buffer, &endptr, 10);                                             // Convert input to integer
         if (*endptr == '\0' || *endptr == '\n') {
            int reversedNum = ReverseNumber (num);
            if (reversedNum == -1) printf ("Overflow\n");
            else if (reversedNum == -2) printf ("Not a Palindrome (Negative Number)\n");
            else {
               printf ("Reversed Number: %d\n", reversedNum);
               if (reversedNum == num) printf ("Palindrome\n");
               else printf ("Not a Palindrome\n");
            }
         }
         else {
            Filter (temp, buffer);
            if (Palindrome (temp)) printf ("Palindrome\n");
            else printf ("Not a Palindrome\n");
         }
      }
      else printf ("Error reading input.\n");
      printf ("Do you want to enter another string or integer? (y/n): ");
      if (fgets (choice, sizeof (choice), stdin)) {
         ClearScreen ();
         choice[strcspn (choice, "\n")] = '\0';
         if (choice[0] == 'n' || choice[0] == 'N') {
            ClearScreen ();
            printf ("Exiting...\n");
            break;
         }
         else if (choice[0] != 'y' && choice[0] != 'Y') printf ("Invalid choice. Please enter 'y' to continue or 'n' to exit.\n");
      }
   }
   return 0;
}