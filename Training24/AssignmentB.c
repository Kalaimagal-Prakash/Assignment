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
#include <time.h>

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

/// <summary>Function to generate Fibonacci series up to n terms.</summary>
static void Fibonacci (int n, int a, int b, int output[]) {
   if (n == 0) return;
   output[0] = a;
   for (int i = 1; i < n; i++) {
      output[i] = b;
      int temp = a + b;
      a = b;
      b = temp;
   }
}

/// <summary>Function to check if a number is prime.</summary>
static int IsPrime (int n) {
   if (n == 2) return 1;
   if (n <= 1 || n % 2 == 0) return 0;
   for (int i = 3; i * i <= n; i += 2) if (n % i == 0) return 0;
   return 1;
}

/// <summary>Function to test Fibonacci series.</summary>
static void TestFibonacci () {
   int testCases[] = { 5, 10, 0, 1 };
   int expectedOutput[][10] = { { 0, 1, 1, 2, 3},
      { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 }, { 0 }, { 0, 1 }
   };
   printf (YELLOW "\nTest Case: Fibonacci Series\n" RESET);
   for (int i = 0; i < 4; i++) {
      int n = testCases[i];
      int output[10] = { 0 };
      Fibonacci (n, 0, 1, output);
      printf ("\nFibonacci upto (%d) terms: ", n);
      printf ("\nExpected: ");
      for (int j = 0; j < n; j++) printf ("%d ", expectedOutput[i][j]);
      printf ("\nOutput  : ");
      for (int j = 0; j < n; j++) printf ("%d ", output[j]);
      int pass = 1;
      for (int j = 0; j < n; j++) {
         if (output[j] != expectedOutput[i][j]) {
            pass = 0;
            break;
         }
      }
      pass ? printf (GREEN "\nTEST PASS\n" RESET) : printf (RED "\nTEST FAIL" RESET);
   }
}

/// <summary>Function to test prime number.</summary>
static void TestIsPrime () {
   srand (time (0));
   int numTests = 6;
   printf (YELLOW "\nTest Case: Prime Check\n" RESET);
   for (int i = 0; i < numTests; i++) {
      int num = rand () % 100 + 1;                                // Generate random numbers between 1 and 100
      int result = IsPrime (num);
      printf ("Is %d prime? ", num);
      result == 1 ? printf (GREEN "%d is a prime number. TEST PASS \n" RESET, num) : printf (RED "%d is not a prime number. TEST FAIL\n" RESET, num);
   }
}

int main () {
   int n, choice;
   char buffer[100];
   char continueChoice;
   TestFibonacci ();
   TestIsPrime ();
   do {
      printf ("\nChoose an option:\n1. Display Fibonacci series up to n terms\n2. Check if a number is prime\nEnter your choice (1 or 2): ");
      choice = _getche () - '0';
      ClearScreen ();
      printf ("Enter the value of n: ");
      fgets (buffer, sizeof (buffer), stdin);
      n = atoi (buffer);
      ClearScreen ();
      switch (choice) {
      case 1:
         printf (GREEN "Fibonacci series up to %d terms: " RESET, n);
         int output[10] = { 0 };
         Fibonacci (n, 0, 1, output);
         for (int i = 0; i < n; i++) printf ("%d ", output[i]);
         printf ("\n");
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