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

/// <summary>Function to clear the console screen.</summary>
void ClearScreen () {
#ifdef _WIN32
   system ("cls");           // Windows-specific command to clear the screen
#endif
}

/// <summary>Function to display the elements of an array.</summary>
void DisplayArray (int arr[], int size) {
   printf ("| ");
   for (int i = 0; i < size; i++) printf ("%d  ", arr[i]);
   printf ("|\n");
}

/// <summary>Function to format and print test results.</summary>
void PrintTestCase (int numTests, int inputs[], int size, int searchElement) {
   int sortedArray[50];
   // Copy input array for sorting
   for (int i = 0; i < size; i++) sortedArray[i] = inputs[i];
   InsertionSort (sortedArray, size);
   printf (YELLOW "------------------ Test Case %d -------------------\n" RESET, numTests);
   printf ("| Input Array:            ");
   DisplayArray (inputs, size);
   printf ("| Output Array:           ");
   DisplayArray (sortedArray, size);
   printf ("Insertion sort: %s\n", GREEN "PASS" RESET);
   int index = BinarySearch (sortedArray, size, searchElement);
   if (index != -1) printf ("Element %d found at index %d.\n", searchElement, index);
   else printf ("Element %d not found.\n", searchElement);
   printf ("--------------------------------------------------\n\n");
}

/// <summary>Tests sorting and searching algorithms with predefined cases.</summary>
void TestSort () {
   struct {
      int input[50], searchElement, size;
   } tests[] = {
       {{34, 7, 23, 32, 10}, 23, 5},
       {{5, 3, 8, 1, 2, 6}, 8, 6},
       {{11, 2}, 11, 2},
       {{12, 11, 13, 5}, 5, 4},
       {{-1, -2, -3, -4, -5, -6, -7}, -3, 7},
       {{99, 3, 14}, 14, 3},
       {{-10, 0, 5, 2}, 0, 4}
   };
   int numTests = sizeof (tests) / sizeof (tests[0]);
   for (int i = 0; i < numTests; i++) PrintTestCase (i + 1, tests[i].input, tests[i].size, tests[i].searchElement);
}

/// <summary>User input for array creation, sorting, and element searching.</summary>
void UserInput () {
   char continueInput = 'y';
   while (tolower (continueInput) == 'y') {
      int arr[50], num;
      char buffer[100];
      printf ("\nEnter the number of elements (maximum length of the array is 50): ");
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
      DisplayArray (arr, num); // Use DisplayArray to show the sorted array
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
}

// Main function
int main () {
   TestSort ();
   UserInput ();
   printf (SKYBLUE "\nExit the Program" RESET);
   return 0;
}