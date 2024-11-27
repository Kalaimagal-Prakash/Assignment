// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// Cash.c
// Program on Test1.3 branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include "Cash.h"

void CalculateChange (int cashPaid, int actualAmount) {
   int change = cashPaid - actualAmount;
   int denominations[] = {10, 5, 2, 1};
   int countCoin[4] = {0, 0, 0, 0};

   for (int i = 0; i < 4; i++) {
      countCoin[i] = change / denominations[i];
      change = change % denominations[i];
   }
   printf ("10 rupee coins to be returned as: %d coins\n", countCoin[0]);
   printf ("5  rupee coins to be returned as: %d coins\n", countCoin[1]);
   printf ("2  rupee coins to be returned as: %d coins\n", countCoin[2]);
   printf ("1  rupee coins to be returned as: %d coins\n", countCoin[3]);
}