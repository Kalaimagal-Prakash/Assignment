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
#include <malloc.h>
#include <ctype.h> 
#include <conio.h> // For getch()
#include "Header.h"

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
   system ("cls");
#endif
}

void FilterChar (const char* inputString, char* outputBuffer) {
   int j = 0;
   for (int i = 0; inputString[i] != '\0'; i++)
      if (isalnum (inputString[i])) outputBuffer[j++] = tolower (inputString[i]); // Convert to lowercase and add to output buffer
   outputBuffer[j] = '\0';                                                       // Null-terminate the output string
}

/// <summary>Test cases for Palindrome function.</summary>
static void TestPalindrome () {
   struct {
      const char* Input;
      const char* Expected;
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
      input[i] = tests[i].Input;
      char* temp = malloc (strlen (tests[i].Input) + 1);
      if (temp == NULL) {
         printf ("Memory allocation failed for temp\n");
         return;
      }
      FilterChar (tests[i].Input, temp);
      const char* actualResult = IsPalindrome (temp) ? "Palindrome" : "Not Palindrome";
      printf ("| %-9d | %-31s | %-17s | %s |\n", i + 1, tests[i].Input, actualResult,
         strcmp (actualResult, tests[i].Expected) == 0 ? GREEN "PASS" RESET : RED "FAIL" RESET);
      free (temp);
   }
}

/// <summary>Test cases for Reverse Number function.</summary>
static void TestReverseNumber () {
   struct {
      int Input, Expected;
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
      int actualResult = ReverseNumber (tests[i].Input);
      printf ("| %-9d | %-31d | %-17d | %s |\n", i + 1, tests[i].Input, actualResult,
         actualResult == tests[i].Expected ? GREEN "PASS" RESET : RED "FAIL" RESET);
   }
}

void main () {
   // Run test cases
   printf (YELLOW "------------------- Test Results for Palindrome Check ---------------------\n" RESET);
   TestPalindrome ();
   printf (YELLOW "\n------------------- Test Results for Reverse Number -----------------------\n" RESET);
   TestReverseNumber ();
   char choice;
   while (1) {
      printf (MAGENTA "Enter the input: " RESET);
      size_t bufsize = 0;
      char* buffer = NULL;
      while (1) {
         char* temp = realloc (buffer, bufsize + 1);
         if (temp == NULL) {
            fprintf (stderr, "Memory allocation failed\n");
            free (buffer);
            return;
         }
         buffer = temp;
         int ch = getchar ();
         if (ch == '\n' || ch == EOF) break;
         buffer[bufsize++] = (char)ch;
      }
      if (bufsize > 4000) printf (RED "The input exceeds the maximum length.\n" RESET);
      else if (bufsize > 0) {
         buffer[bufsize] = '\0';
         // Check for empty string or whitespace
         if (strlen (buffer) == 0 || strspn (buffer, " \t\r\n") == strlen (buffer)) printf ("Empty string is not a palindrome.\n");
         else {
            char* endptr;
            int num = (int)strtol (buffer, &endptr, 10);
            if (*endptr == '\0' || *endptr == '\n') {
               int reversedNum = ReverseNumber (num);
               printf ((num < 0) ? "Negative numbers are not palindromes.\nReversed Number: %d\n" :
                  reversedNum == -1 ? "Overflow\n" : "Reversed Number: %d \n%s\n",
                  reversedNum, reversedNum == num ? "Palindrome" : "Not a Palindrome");
            }
            else {
               char* temp = malloc (bufsize + 1);
               if (temp == NULL) {
                  fprintf (stderr, "Memory allocation failed for temp\n");
                  free (buffer);
                  return;
               }
               FilterChar (buffer, temp);
               printf ("%s\n", IsPalindrome (temp) ? "Palindrome" : "Not a Palindrome");
               free (temp);
            }
         }
      }
      free (buffer);
      buffer = NULL;
      while (1) {
         printf ("\nDo you want to enter another input? (y/n): ");
         choice = _getch (); // Get single character input without pressing Enter
         ClearScreen ();
         choice = tolower (choice);
         if (choice == 'y') break;
         if (choice == 'n') {
            printf (SKYBLUE "Exit the Program" RESET);
            return;
         }
      }
   }
}