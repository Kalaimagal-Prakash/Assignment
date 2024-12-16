// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// CashTest.c
// Program on Test2.2 branch.
// ------------------------------------------------------------------------------------------------
_CRT_SECURE_NO_WARNINGS;
#include <stdio.h>
#include <stdlib.h> 
#include "Cash.h"

void ClearScreen () {
#ifdef _WIN32
   system ("cls");
#endif
}

/// <summary>Function to run test cases and verify the output of CalculateChange.</summary>
void TestCases () {
   int cashPaid[] = { 28, 56, 90, 100, 5, 50, 120, 200 };
   int actualAmount[] = { 30, 37, 40, 83, 5, 33, 50, 200 };
   int expectedCoinCount[8][4] = {
       {0, 1, 0, 1},
       {1, 1, 2, 0},
       {5, 0, 0, 0},
       {1, 1, 1, 0},
       {0, 0, 0, 0},
       {1, 1, 1, 0},
       {7, 0, 0, 0},
       {0, 0, 0, 0}
   };
   int numOfTestCases = sizeof (cashPaid) / sizeof (cashPaid[0]);
   for (int i = 0; i < numOfTestCases; i++) {
      printf (YELLOW "\nTestCase %d" RESET " \n\nCash Paid : %d\nActual Amount : %d\n", i + 1, cashPaid[i], actualAmount[i]);
      if (cashPaid[i] < actualAmount[i]) {
         printf (RED "Cash paid is less than the actual amount!\n" RESET);
         printf ("Test Failed\n");
         continue;
      }
      if (cashPaid[i] == actualAmount[i]) {
         printf (GREEN "No change to be returned. Test Passed.\n" RESET);
         continue;
      }
      int actualCoinCount[4] = { 0, 0, 0, 0 };
      CalculateChange (cashPaid[i], actualAmount[i], actualCoinCount);
      int pass = 1;
      for (int j = 0; j < 4; j++) {
         if (actualCoinCount[j] != expectedCoinCount[i][j]) {
            pass = 0;
            break;
         }
      }
      if (pass) printf (GREEN "Test Passed\n" RESET);
      else printf (RED "Test Failed\n" RESET);
   }
}

/// <summary>Function to get user input for cash paid and actual amount, and process the transaction.</summary>
int UserInput () {
   int cashPaid, actualAmount;
   printf ("\n\nEnter cash paid by the customer: ");
   scanf_s ("%d", &cashPaid);
   printf ("Enter the actual amount: ");
   scanf_s ("%d", &actualAmount);
   if (cashPaid < actualAmount) {
      printf (RED "Cash paid is less than the actual amount!\n" RESET);
      return 1;
   }
   int actualCoinCount[4] = { 0, 0, 0, 0 };
   CalculateChange (cashPaid, actualAmount, actualCoinCount);
   char choice;
   printf ("Would you like to enter another transaction? (y/n): ");
   (void)getchar ();
   scanf_s ("%c", &choice, 1);
   ClearScreen ();
   if (choice == 'n' || choice == 'N') return 1;
   return 0;
}

int main () {
   int choice;
   while (1) {
      printf ("Select an option:\n1. Run Test Cases\n2. Enter Cash and Actual Amount\n3. Exit\nEnter your choice: ");
      scanf_s ("%d", &choice);
      ClearScreen ();
      switch (choice) {
      case 1:
         TestCases ();
         break;
      case 2:
         while (UserInput () == 0);
         break;
      case 3:
         printf ("Exiting the program.\n");
         return 0;
      default:
         printf (RED "Invalid choice! Please select a valid option.\n" RESET);
         break;
      }
   }
   return 0;
}