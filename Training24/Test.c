// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// Test.c
// Program on A5 branch.
// Write a program that sorts integer arrays in ascending order using any of the sorting algorithms discussed
// in the Sorting workshop. Also, implement binary search algorithm to search for an element in the sorted array.
// You may take the arrays as input from the user.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <ctype.h>    // For tolower
#include <stdlib.h>   // For strtol and realloc
#include <conio.h>    // For getch()
#include "header.h"

// ANSI escape codes for colors
#define RESET   "\033[0m"
#define SKYBLUE "\033[36m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"

// Function to clear the console screen
void ClearScreen () {
#ifdef _WIN32
   system ("cls");           // Windows-specific command to clear the screen
#endif
}

// Function to format and print test results
void PrintTestCase (int numTests, int inputs[], int actualResults) {
   int sortedArray[50];
   // Copy input array for sorting
   for (int i = 0; i < actualResults; i++) sortedArray[i] = inputs[i];
   InsertionSort (sortedArray, actualResults);
   printf (YELLOW "------------------ Test Case %d -------------------\n" RESET, numTests);
   printf ("| Input Array:            | ");
   for (int i = 0; i < actualResults; i++) printf ("%d  ", inputs[i]);
   printf ("|\n| Output Array:           | ");
   for (int i = 0; i < actualResults; i++) printf ("%d  ", sortedArray[i]);
   printf ("|\n  Status: %s\n", GREEN "PASS THE SORTED ARRAY" RESET);
   printf ("--------------------------------------------------\n\n");
}

// Test sorting
void TestSort () {
   struct {
      int input[50], expected;
   } tests[] = {
       {{34, 7, 23, 32, 10}, 5},
       {{5, 3, 8, 1, 2, 6}, 6},
       {{11, 2,}, 2},
       {{12, 11, 13, 5}, 4},
       {{-1, -2, -3, -4, -5, -6, -7}, 7},
       {{99, 3, 14}, 3},
       {{-10, 0, 5, 2}, 4}
   };
   int numTests = sizeof (tests) / sizeof (tests[0]);
   for (int i = 0; i < numTests; i++) PrintTestCase (i + 1, tests[i].input, tests[i].expected);
}

// Main function
int main () {
   TestSort ();
   char continueInput = 'y';
   while (tolower (continueInput) == 'y') {
      int arr[50], num;
      char buffer[100];
      printf ("\nEnter number of elements (maximum 50) in array: ");
      fgets (buffer, sizeof (buffer), stdin);
      num = atoi (buffer);
      if (num > 50 || num < 1) {
         printf ("Invalid number of elements. Please enter a number between 1 and 50.\n");
         continue; // Restart the loop for valid input
      }
      printf ("Enter %d integer numbers:\n", num);
      for (int i = 0; i < num; i++) {
         fgets (buffer, sizeof (buffer), stdin);
         arr[i] = atoi (buffer);
      }
      InsertionSort (arr, num);
      printf (GREEN "Sorted array: " RESET);
      for (int i = 0; i < num; i++) printf ("%d ", arr[i]);
      printf ("\n");
      char choice = 'y';
      do {
         printf ("\nEnter a number to search: ");
         int find;
         fgets (buffer, sizeof (buffer), stdin);
         find = atoi (buffer);
         int index = BinarySearch (arr, num, find);
         if (index != -1) printf ("Element found at index %d.\n", index);
         else printf (RED "Element not found.\n" RESET);
         printf (YELLOW "\nDo you want to search for another number? (y/n): " RESET);
         choice = tolower (_getch ());
      } while (choice == 'y');
      ClearScreen ();
      printf (YELLOW "\nDo you want to input another array? (y/n): " RESET);
      continueInput = tolower (_getch ());
   }
   printf (SKYBLUE "\nExit the Program" RESET);
   return 0;
}