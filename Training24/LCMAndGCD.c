// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// LCMAndGCD.c
// Program on B2 branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
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

/// <summary>Function to calculate GCD.</summary>
static int GCD (int a, int b) {
   while (b != 0) {
      int temp = b;
      b = a % b;
      a = temp;
   }
   return a;
}

/// <summary>Function to calculate LCM.</summary>
static int LCM (int a, int b) {
   if (a == 0 || b == 0) return 0;
   return (a * b) / GCD (a, b);
}

static void TestCase () {
   int inputs[][2] = { {12, 18}, {7, 5}, {0, 10}, {15, 25} };
   int expectedResults[][2] = { {6, 36}, {1, 35}, {10, 0}, {5, 75} };
   for (int i = 0; i < sizeof (inputs) / sizeof (inputs[0]); i++) {
      int n1 = inputs[i][0];
      int n2 = inputs[i][1];
      int expectedGcd = expectedResults[i][0];
      int expectedLcm = expectedResults[i][1];
      int gcdResult = GCD (n1, n2);
      int lcmResult = LCM (n1, n2);
      printf (YELLOW "\nTest Case %d\n" RESET, i + 1);
      printf ("Input       : %d, %d\n", n1, n2);
      printf ("Expected GCD: %d, Expected LCM: %d\n", expectedGcd, expectedLcm);
      printf ("Actual   GCD: %d, Actual   LCM: %d\n", gcdResult, lcmResult);
      gcdResult == expectedGcd && lcmResult == expectedLcm ? printf (GREEN "PASS\n\n" RESET) : printf (RED "FAIL\n\n" RESET);
   }
}

static void UserInput () {
   int n1, n2;
   char buffer[100];
   printf ("\nEnter the first number: ");
   fgets (buffer, sizeof (buffer), stdin);
   n1 = strtol (buffer, NULL, 10);
   printf ("Enter the second number: ");
   fgets (buffer, sizeof (buffer), stdin);
   n2 = strtol (buffer, NULL, 10);
   printf ("The GCD of %d and %d is: %d\n", n1, n2, GCD (n1, n2));
   printf ("The LCM of %d and %d is: %d\n", n1, n2, LCM (n1, n2));
}

int main () {
   int choice;
   char continueChoice;
   do {
      printf ("\nChoose an option:\n1. Run Testcases \n2. Get User Input\nEnter the choice (1 or 2): ");
      choice = _getche () - '0';
      ClearScreen ();
      switch (choice) {
      case 1: TestCase (); break;
      case 2: UserInput (); break;
      default: printf ("Invalid choice. Please try again.\n");
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