// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// Swap.c
// Program on B5 branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <conio.h>

// ANSI escape codes for colors
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"

static void ClearScreen () {
#ifdef _WIN32
   system ("cls");
#endif
}

/// <summary>Function to swap the given 2 numbers.</summary>
static void Swap (int* a, int* b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}

/// <summary>Function to run test cases for swap numbers.</summary>
static void TestCase () {
   int Inputs[5][2] = { {5, 8}, {-3, 4},{0, 7},{100, 200}, {1, 1} };
   int Expected[5][2] = { {8, 5}, {4, -3}, {7, 0}, {200, 100}, {1, 1} };
   for (int i = 0; i < 5; i++) {
      int a = Inputs[i][0], b = Inputs[i][1];
      int expectedA = Expected[i][0], expectedB = Expected[i][1];
      printf ("\nTest case %d: a = %d, b = %d\n", i + 1, a, b);
      printf ("Before swapping: a = %d, b = %d\n", a, b);
      Swap (&a, &b);
      printf ("After swapping: a = %d, b = %d\n", a, b);
      a == expectedA && b == expectedB ? printf (GREEN "Test Passed\n\n" RESET) : printf (RED "Test Failed\n" RESET);
   }
}

int main () {
   int choice;
   char continueChoice;
   do {
      printf ("Choose an option:\n1. Run Test Cases\n2. User Input\nEnter your choice: ");
      choice = _getche () - '0';
      ClearScreen ();
      switch (choice) {
      case 1:
         TestCase ();
         break;
      case 2: {
         int a, b;
         printf ("Enter the first number: ");
         scanf_s ("%d", &a);
         printf ("Enter the second number: ");
         scanf_s ("%d", &b);
         printf ("Before swapping: a = %d, b = %d\n", a, b);
         Swap (&a, &b);
         printf ("After swapping: a = %d, b = %d\n", a, b);
         break;
      }
      default:
         printf ("Invalid choice.\n");
         break;
      }
      printf ("\n\nDo you want to continue? (y/n): ");
      continueChoice = _getche ();
      ClearScreen ();
      if (continueChoice == 'n' || continueChoice == 'N') {
         printf (YELLOW "\nExit the Program\n" RESET);
         break;
      }
   } while (continueChoice == 'y' || continueChoice == 'Y');
   return 0;
}