// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// AssignmentB.c
// Program on B1 branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// ANSI escape codes for colors
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

static void ClearScreen () {
#ifdef _WIN32
   system ("cls");
#endif
}

static void Fibonacci (int n) {
   int a = 0, b = 1, next;
   printf ("%d %d ", a, b);
   for (int i = 2; i < n; i++) {
      next = a + b;
      printf ("%d ", next);
      a = b;
      b = next;
   }
   printf ("\n");
}

static int IsPrime (int n) {
   if (n <= 1) return 0;
   for (int i = 2; i * i <= n; i++) if (n % i == 0) return 0;
   return 1;
}

int main () {
   int n, choice;
   char buffer[100];
   char continueChoice;
   do {
      printf ("\nChoose an option:\n");
      printf ("1. Display Fibonacci series up to n terms\n");
      printf ("2. Check if a number is prime\n");
      printf ("Enter your choice (1 or 2): ");
      fgets (buffer, sizeof (buffer), stdin);
      choice = atoi (buffer);
      ClearScreen ();
      printf ("Enter the value of n: ");
      fgets (buffer, sizeof (buffer), stdin);
      n = atoi (buffer);
      ClearScreen ();
      switch (choice) {
      case 1:
         printf (GREEN "Fibonacci series up to %d terms: " RESET, n);
         Fibonacci (n);
         break;
      case 2:
         IsPrime (n) ? printf (GREEN "%d is a prime number.\n" RESET, n) : printf (RED "%d is not a prime number.\n" RESET, n);
         break;
      default:
         printf ("Invalid choice. Please select 1 or 2.\n");
         break;
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
