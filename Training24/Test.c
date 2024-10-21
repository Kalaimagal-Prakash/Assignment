// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// Test.c
// Program on A5 branch.
// Test.c - The program sorts integers with insertion sort and searches for numbers using binary search, 
// with options for test cases and user input.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <ctype.h>    // For tolower
#include <stdlib.h>   // For strtol and realloc
#include <conio.h>    // For getch()
#include <stdbool.h>
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
void DisplayArray (IndexedElement arr[], int size) {
   printf ("| ");
   for (int i = 0; i < size; i++) printf ("%d  ", arr[i].value);
   printf ("|\n");
}

/// <summary>Function to check if the array is sorted.</summary>
bool IsSorted (IndexedElement arr[], int size) {
   for (int i = 1; i < size; i++) if (arr[i - 1].value > arr[i].value) return false; // Not sorted
   return true; // Sorted
}

/// <summary>Function to format and print test results.</summary>
void PrintTestCase (int numTests, IndexedElement inputs[], int size, int searchElement) {
   IndexedElement sortedArray[50];
   // Copy input array for sorting
   for (int i = 0; i < size; i++) sortedArray[i] = inputs[i];
   InsertionSort (sortedArray, size);
   printf (YELLOW "------------------ Test Case %d -------------------\n" RESET, numTests);
   printf ("| Input Array:            ");
   DisplayArray ((int*)inputs, size);
   printf ("| Output Array:           ");
   DisplayArray ((int*)sortedArray, size);
   // Check if sorted correctly
   if (IsSorted ((int*)sortedArray, size)) printf ("Insertion sort: " GREEN "PASS" RESET "\n");
   else printf ("Insertion sort: " RED "FAIL" RESET "\n");
   // Find the element in the sorted array
   int index = BinarySearch ((int*)sortedArray, size, searchElement);
   if (index != -1) {
      int originalIndex = sortedArray[index].originalIndex;
      printf ("Element %d found at sorted index %d (original index %d).\n", searchElement, index, originalIndex);
   }
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
   for (int i = 0; i < numTests; i++) {
      IndexedElement indexedInput[50];
      for (int j = 0; j < tests[i].size; j++) {
         indexedInput[j].value = tests[i].input[j];
         indexedInput[j].originalIndex = j;
      }
      PrintTestCase (i + 1, indexedInput, tests[i].size, tests[i].searchElement);
   }
}

/// <summary>User input for array creation, sorting, and element searching.</summary>
void ManualArrayInput () {
   char continueInput = 'y';
   while (tolower (continueInput) == 'y') {
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
      }
      // Create an array of IndexedElements for sorting
      IndexedElement indexedArray[50];
      for (int i = 0; i < num; i++) {
         indexedArray[i].value = arr[i];
         indexedArray[i].originalIndex = i;
      }
      InsertionSort (indexedArray, num);
      printf (GREEN "Sorted array: " RESET);
      DisplayArray (indexedArray, num); // Use DisplayArray to show the sorted array
      char choice = 'y';
      do {
         printf ("\nEnter a number to search: ");
         int find;
         fgets (buffer, sizeof (buffer), stdin);
         find = atoi (buffer);
         int index = BinarySearch (indexedArray, num, find);
         if (index != -1) printf ("Element found at index %d (original index %d).\n", index, indexedArray[index].originalIndex);
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
   ManualArrayInput ();
   printf (SKYBLUE "\nExit the Program" RESET);
   return 0;
}