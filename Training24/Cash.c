// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// Cash.c
// Program on Test2.2 branch.
// ------------------------------------------------------------------------------------------------
#include "Cash.h"

int* CalculateChange (int cashPaid, int actualAmount, int denominations[], int numDenominations) {
   int change = cashPaid - actualAmount;
   static int countCoin[10];                       // Assuming a maximum of 10 denominations
   for (int i = 0; i < numDenominations; i++) {
      countCoin[i] = change / denominations[i];
      change = change % denominations[i];
   }
   return countCoin;
}