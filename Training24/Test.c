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
#define MAGENTA "\033[35m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"

/// <summary>Function to clear the console screen.</summary>
void ClearScreen () {
#ifdef _WIN32
   system ("cls");           // Windows-specific command to clear the screen
#endif
}

int main () {
   int arr[50], num;
   printf ("Enter number of elements (maximum 50) in array: ");
   scanf_s ("%d", &num);
   if (num > 50 || num < 1) {
      printf ("Invalid number of elements. Please enter a number between 1 and 50.");
      return 1;
   }
   printf ("Enter %d integer numbers:\n", num);
   for (int c = 0; c < num; c++) scanf_s ("%d", &arr[c]);
   InsertionSort (arr, num);
   printf (GREEN "Sorted array: " RESET);
   for (int c = 0; c < num; c++) printf ("%d ", arr[c]);
   printf ("\n");
   char choice = 'y';
   do {
      printf ("\nEnter a number to search: ");
      int target;
      if (scanf_s ("%d", &target) != 1) {
         fprintf (stderr, "Invalid input. Please enter an integer.\n");
         while (getchar () != '\n');
         continue;
      }
      int index = BinarySearch (arr, num, target);
      if (index != -1) printf ("Element found at index %d.\n", index);
      else printf (RED "Element not found.\n" RESET);
      printf (YELLOW "\nDo you want to search for another number? (y/n): " RESET);
      choice = _getch ();
      choice = tolower (choice);
   } while (choice == 'y');
   printf (SKYBLUE "\nExit the Program" RESET);
   return 0;
 }