// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// Cash.c
// Program on Test2.2 branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include "Cash.h"

void CalculateChange (int cashPaid, int actualAmount, int countCoin[]) {
   int change = cashPaid - actualAmount;
   int denominations[] = { 10, 5, 2, 1 };
   for (int i = 0; i < 4; i++) {
      countCoin[i] = change / denominations[i];
      change = change % denominations[i];
   }
   printf ("Change to be returned: Rs. %d\n", cashPaid - actualAmount);
   printf ("No. of Rs.10 coins: %d\nNo. of Rs.5 coins: %d\nNo. of Rs.2 coins: %d\nNo. of Rs.1 coins: %d\n",
      countCoin[0], countCoin[1], countCoin[2], countCoin[3]);
}