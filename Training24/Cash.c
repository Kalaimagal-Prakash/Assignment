// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// Cash.c
// Program on Test2.2 branch.
// ------------------------------------------------------------------------------------------------
#include "Cash.h"

void CalculateChange (int cashPaid, int actualAmount, int countCoin[]) {
   int change = cashPaid - actualAmount;
   int denominations[] = { 10, 5, 2, 1 };
   for (int i = 0; i < 4; i++) {
      countCoin[i] = change / denominations[i];
      change = change % denominations[i];
   }
}