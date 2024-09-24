// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// Test.c
// Program on A4 branch.
// 1. Palindrome is a word that reads the same forward or backward. Example: Civic, Madam, Bib, Nun, Level and so on. 
//    Your program must take the word as input and display the result if it is a palindrome or not. 
//    For complexity, you can also use phrases instead of words (E.g., Was it a car or a cat I saw? I did, did I? Don�t nod)
// 2. Write a program that reverses a given integer (as defined in C) as explained below and check if it is a palindrome.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h> 
#include <conio.h> // For getch()
#include "Header.h"
#define MAXLENGTH 100

// ANSI escape codes for colors
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"
#define SKYBLUE "\033[36m"

/// <summary>Function to clear the console screen.</summary>
void ClearScreen () {
#ifdef _WIN32
   system ("cls");           // Windows-specific command to clear the screen
#endif
}

void FilterChar (char* buffer, const char* temp) {
   int j = 0;
   for (int i = 0; temp[i] != '\0'; i++)
      if (temp[i] != ' ' && temp[i] != ',' && temp[i] != '?' && temp[i] != '/' && temp[i] != '.') buffer[j++] = tolower (temp[i]);         // Skip spaces, commas, question marks, dot and slash
   buffer[j] = '\0';
}

/// <summary>Function to print test results for string.</summary>
void FormatResult (int numTests, const char** inputs, const char** actualResults, const int* pass) {
   printf (YELLOW "------------------- Test Results for Palindrome Check --------------------\n" RESET);
   printf ("| Test Case | Input                           | Output            |Result|\n");
   printf ("|-----------|---------------------------------|-------------------|------|\n");
   for (int i = 0; i < numTests; i++)
      printf ("| %-9d | %-31s | %-17s | %6s |\n", i + 1, inputs[i], actualResults[i] ? actualResults[i] : "NULL", pass[i] ? GREEN "PASS" RESET : RED "FAIL" RESET);
   printf ("\n");
}

/// <summary>Function to print test results for reverse number.</summary>
void FormatResult2 (int numTests, int* inputs, int* actualResults, int* pass) {
   printf (YELLOW "--------------------- Test Results for Reverse Number --------------------\n" RESET);
   printf ("| Test Case | Input                           | Output            |Result|\n");
   printf ("|-----------|---------------------------------|-------------------|------|\n");
   for (int i = 0; i < numTests; i++) printf ("| %-9d | %-31d | %-17d | %8s |\n", i + 1, inputs[i], actualResults[i], pass[i] ? GREEN "PASS" RESET : RED "FAIL" RESET);
   printf ("\n");
}

/// <summary>Test cases for Palindrome function.</summary>
void TestPalindrome () {
   struct {
      const char* input;
      const char* expected;
   } tests[] = {
       {"civic", "Palindrome"},
       {"madam", "Palindrome"},
       {"12321", "Palindrome"},
       {"Was it a car or a cat I saw", "Palindrome"},
       {"Hello, World!", "Not Palindrome"},
       {"A man, a plan, a canal, Panama", "Palindrome"},
       {"A", "Palindrome"},
       {"ab", "Not Palindrome"},
       {"Able was I ere I saw Elba", "Palindrome"},
       {"a@a", "Palindrome"},
       {"@!$2", "Not Palindrome"},
       {"I did, did I?", "Palindrome"}
   };
   int numTests = sizeof (tests) / sizeof (tests[0]);
   const char** input = malloc (numTests * sizeof (const char*));
   char** actualResults = malloc (numTests * sizeof (char*));
   int* pass = malloc (numTests * sizeof (int));
   if (input == NULL || actualResults == NULL || pass == NULL) {
      printf ("Memory allocation failed\n");
      return;
   }
   for (int i = 0; i < numTests; ++i) {
      input[i] = tests[i].input;
      char temp[MAXLENGTH];
      FilterChar (temp, tests[i].input);
      actualResults[i] = IsPalindrome (temp) ? "Palindrome" : "Not Palindrome";
      pass[i] = (strcmp (actualResults[i], tests[i].expected) == 0);
   }
   // Call the function to format and print the results
   FormatResult (numTests, input, actualResults, pass);
   free (input);
   free (actualResults);
   free (pass);
}

/// <summary>Test cases for ReverseNumber function.</summary>
void TestReverseNumber () {
   struct {
      int input, expected;
   } tests[] = {
       {1234, 4321}, {0, 0}, {1000, 1},
       {10, 1}, {9, 9}, {-11234, -43211}, {-42145142, -24154124}
   };
   int numTests = sizeof (tests) / sizeof (tests[0]);
   int* input = malloc (numTests * sizeof (int));
   int* actualResults = malloc (numTests * sizeof (int));
   int* pass = malloc (numTests * sizeof (int));
   if (input == NULL || actualResults == NULL || pass == NULL) {
      printf ("Memory allocation failed\n");
      return;
   }
   for (int i = 0; i < numTests; ++i) {
      input[i] = tests[i].input;
      actualResults[i] = ReverseNumber (tests[i].input);
      pass[i] = (actualResults[i] == tests[i].expected);
   }
   // Call the function to format and print the results
   FormatResult2 (numTests, input, actualResults, pass);
   free (input);
   free (actualResults);
   free (pass);
}

void main () {
   // Run test cases
   TestPalindrome ();
   TestReverseNumber ();
   char buffer[MAXLENGTH], choice, temp[MAXLENGTH];
   while (1) {
      printf (MAGENTA "Enter the input: " RESET);
      if (!fgets (buffer, sizeof (buffer), stdin)) {
         printf ("Error reading input.\n");
         continue;
      }
      buffer[strcspn (buffer, "\n")] = '\0';                                     // Remove newline character
      if (strlen (buffer) == 0 || strspn (buffer, " \\t\\r\\n") == strlen (buffer)) printf ("Empty string is not a palindrome.\n");             // Check for empty string
      else {
         char* endptr;
         int num = (int)strtol (buffer, &endptr, 10);                            // Convert input to integer
         if (*endptr == '\0' || *endptr == '\n') {
            int reversedNum = ReverseNumber (num);
            (num < 0) ? printf ("Negative numbers are not palindromes.\nReversed Number: %d-\n", abs (reversedNum)) :
            (reversedNum == -1) ? printf ("Overflow\n") :
            printf ("Reversed Number: %d \n%s\n", reversedNum, reversedNum == num ? "Palindrome\n" : "Not a Palindrome\n");
         }
         else {
            FilterChar (temp, buffer);
            printf (IsPalindrome (temp) ? "Palindrome\n" : "Not a Palindrome\n");
         }
      }
      while (1) {
         printf ("\nDo you want to enter another input? (y/n): ");
         choice = _getch ();                                                   // Get single character input without pressing Enter
         ClearScreen ();
         if (choice == 'n' || choice == 'N') {
            printf (SKYBLUE "Exit the Program" RESET);
            return;
         }
         else if (choice == 'y' || choice == 'Y') break;
         else printf ("Invalid input. Please enter 'y' or 'n'.\n");
      }
   }
}