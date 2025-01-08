// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// Tables.c
// Program on B3 branch.
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

/// <summary>Prints a diamond pattern of stars with height based on the input.</summary>
static void PrintDiamond (int n) {
   for (int i = 1; i <= n; i++) {
      for (int j = i; j < n; j++) printf (" ");
      for (int j = 1; j <= (2 * i - 1); j++) printf ("*");
      printf ("\n");
   }
   for (int i = n - 1; i >= 1; i--) {
      for (int j = n; j > i; j--)  printf (" ");
      for (int j = 1; j <= (2 * i - 1); j++) printf ("*");
      printf ("\n");
   }
}

/// <summary>Prints multiplication tables from 1 to 10.</summary>
static int Tables () {
   for (int i = 1; i <= 10; i++) {
      printf ("Multiplication Table for %d:\n", i);
      for (int j = 1; j <= 10; j++) printf ("%2d * %2d = %2d\n", i, j, i * j);
      printf ("\n");
   }
   return 0;
}

int main () {
   int choice, n;
   char continueChoice;
   do {
      printf ("\nChoose an option:\n1. Print Diamond\n2. Print Multiplication Tables\nEnter your choice (1 or 2): ");
      choice = _getche () - '0';
      ClearScreen ();
      switch (choice) {
      case 1:
         printf ("Enter the number of rows (half the height of the diamond): ");
         scanf_s ("%d", &n);
         PrintDiamond (n);
         break;
      case 2: Tables (); break;
      default: printf ("Invalid choice! Please try again.\n"); break;
      }
      printf ("\n\nDo you want to continue? (y/n): ");
      continueChoice = _getche ();
      if (continueChoice == 'n' || continueChoice == 'N') {
         printf (YELLOW "\nExit the Program\n" RESET);
         break;
      }
   } while (continueChoice == 'y' || continueChoice == 'Y');
   return 0;
}