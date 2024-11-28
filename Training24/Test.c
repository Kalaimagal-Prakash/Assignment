// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// Test.c - The program sorts integers and searches for numbers.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include "header.h"

// ANSI escape codes for colors
#define RESET   "\033[0m"
#define SKYBLUE "\033[36m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"

/// <summary>Function to clear the console screen.</summary>
static void ClearScreen () {
#ifdef _WIN32
   system ("cls");
#endif
}

/// <summary>Function to display the elements of an array.</summary>
static void DisplayArray (int arr[], int size) {
   printf ("| ");
   for (int i = 0; i < size; i++) printf ("%d  ", arr[i]);
   printf ("|\n");
}

/// <summary>Function to check if the array is sorted.</summary>
static bool IsSorted (int arr[], int size) {
   for (int i = 1; i < size; i++) if (arr[i - 1] > arr[i]) return false; // Not sorted
   return true; // Sorted
}

/// <summary>Checks if the input string is a valid integer (digits only).</summary>
static int IsValidInteger (const char* str) {
   if (str == NULL || *str == '\n' || *str == '\0') return 0;
   while (isspace (*str)) str++;
   if (*str == '+' || *str == '-') str++;
   for (; *str != '\0' && *str != '\n'; str++) if (!isdigit (*str)) return 0;
   return 1;
}

/// <summary>Function to format and print test results.</summary>
static void PrintTestCase (int numTests, int inputs[], int sortedArray[], int size, int searchElement) {
   printf (YELLOW "------------------ Test Case %d -------------------\n" RESET, numTests);
   printf ("| Input Array:            ");
   DisplayArray (inputs, size);
   printf ("| Output Array:           ");
   DisplayArray (sortedArray, size);
   printf ("| Insertion sort : %s\n", IsSorted (sortedArray, size) ? GREEN "PASS" RESET : RED "FAIL" RESET);
   // Find the element in the sorted array
   int index = BinarySearch (sortedArray, size, searchElement);
   if (index >= 0) printf ("Element %d found at sorted index %d.\n", searchElement, index);
   else printf (RED "Element %d not found.\n" RESET, searchElement);
   printf ("--------------------------------------------------\n\n");
}

/// <summary>Tests sorting and searching algorithms with predefined cases.</summary>
static void TestSort () {
   struct {
      int input[50], searchElement, size;
   } tests[] = {
       {{34, 7, 23, 32, 10}, 2, 5},          // Search for an element not in the array
       {{5, 3, 8, 1, 2, 6}, 8, 6},
       {{11, 2}, 11, 2},
       {{12, 11, 13, 5}, 5, 4},
       {{-1, -2, -3, -4, -5, -6, -7}, -3, 7},
       {{99, 3, 14}, 14, 3},
       {{-10, 0, 5, 2}, 0, 4},
       {{1, 2, 3, 4, 5}, 6, 5}               // Search for an element not in the array
   };
   int numTests = sizeof (tests) / sizeof (tests[0]);
   for (int i = 0; i < numTests; i++) {
      int sortedArray[50];
      for (int j = 0; j < tests[i].size; j++) sortedArray[j] = tests[i].input[j];
      InsertionSort (sortedArray, tests[i].size);
      PrintTestCase (i + 1, tests[i].input, sortedArray, tests[i].size, tests[i].searchElement);
   }
}

/// <summary>User input for array creation, sorting, and element searching.</summary>
static void ManualArrayInput () {
   char continueInput = 'y';
   do {
      int arr[50], num;
      char buffer[100];
      printf ("\nEnter the number of elements (maximum length of the array is 50): ");
      fgets (buffer, sizeof (buffer), stdin);
      num = atoi (buffer);
      if (num > 50 || num < 1) {
         printf ("Invalid number of elements. Please enter a number between 1 and 50.\n");
         continue;
      }
      printf ("Enter %d integer numbers:\n", num);
      for (int i = 0; i < num; i++) {
         fgets (buffer, sizeof (buffer), stdin);
         arr[i] = atoi (buffer);
         if (!IsValidInteger (buffer)) {
            printf ("Invalid input. Please enter a valid integer.\n");
            i--; // Decrement i to repeat this iteration for the same index
            continue;
         }
      }
      InsertionSort (arr, num);
      printf (GREEN "Sorted array: " RESET);
      DisplayArray (arr, num);
      char choice = 'y';
      do {
         printf ("\nEnter a number to search: ");
         fgets (buffer, sizeof (buffer), stdin);
         buffer[strcspn (buffer, "\n")] = '\0';
         if (IsValidInteger (buffer)) {
            int find = atoi (buffer);
            int index = BinarySearch (arr, num, find);
            if (index >= 0) printf ("Element %d found at sorted index %d.\n", find, index);
            else printf (RED "Element not found.\n" RESET);
         }
         else printf ("Invalid input. Enter a valid integer.\n");
         printf (YELLOW "\nDo you want to search for another number? (y/n): " RESET);
         choice = tolower (_getch ());
      } while (choice == 'y');
      ClearScreen ();
      printf (YELLOW "\nDo you want to input another array? (y/n): " RESET);
      continueInput = tolower (_getch ());
   } while (tolower (continueInput) == 'y');
}

// Main function
int main () {
   TestSort ();
   ManualArrayInput ();
   printf (SKYBLUE "\nExit the Program" RESET);
   return 0;
}