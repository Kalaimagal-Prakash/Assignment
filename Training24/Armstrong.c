// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// Armstrong.c
// Program on B4 branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
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

/// <summary>Function to check if a number is an Armstrong number.</summary>
static int IsArmstrong (int num) {
   int originalNum = num, sum = 0, digits = 0;
   while (num != 0) {
      num /= 10;
      digits++;
   }
   num = originalNum;
   while (num != 0) {
      int digit = num % 10;
      sum += pow (digit, digits);
      num /= 10;
   }
   return sum == originalNum;
}

/// <summary>Function to run test cases with random Armstrong numbers.</summary>
static void RunTestCases (int numTests) {
   srand (time (NULL));
   for (int i = 0; i < numTests; i++) {
      int number;
      do {
         number = rand () % 1000;
      } while (!IsArmstrong (number));
      int result = IsArmstrong (number);
      int expectedResult = 1;
      printf ("Test Case: Check if %d is an Armstrong number.\n", number);
      printf ("Expected: %s\n", expectedResult ? "Armstrong number" : "Not an Armstrong number");
      printf ("Actual  : %s\n", result ? "Armstrong number" : "Not an Armstrong number");
      printf ("TEST %s\n\n", result == expectedResult ? GREEN "PASS" RESET : RED "FAIL" RESET);
   }
}

int main () {
   int numTests = 6;
   int choice;
   char continueChoice;
   do {
      printf ("Choose an option:\n1. Run Random Test Cases\n2. User Input\nEnter your choice: ");
      choice = _getche () - '0';
      ClearScreen ();
      switch (choice) {
      case 1:
         RunTestCases (numTests);
         break;
      case 2: {
         int number;
         printf ("Enter a number: ");
         scanf_s ("%d", &number);
         printf ("%d is %s Armstrong number.\n", number, IsArmstrong (number) ? "an" : "not an");
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