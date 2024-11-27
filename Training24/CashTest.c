// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// CashTest.c
// Program on Test1.3 branch.
// ------------------------------------------------------------------------------------------------
_CRT_SECURE_NO_WARNINGS;
#include <stdio.h>
#include "Cash.h"

int main () {
   int cashPaid, actualAmount;
   printf ("Enter cash paid by the customer: ");
   scanf_s ("%d", &cashPaid);
   printf ("Enter the actual amount: ");
   scanf_s ("%d", &actualAmount);
   if (cashPaid < actualAmount) {
      printf ("Cash paid is less than the actual amount!\n");
      return 1;
   }
   CalculateChange (cashPaid, actualAmount);
   return 0;
}

