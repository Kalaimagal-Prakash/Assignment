// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// Cash.h
// Program on Test2.2 branch.
// ------------------------------------------------------------------------------------------------
#ifndef CASH_H
#define CASH_H

// ANSI escape codes for colors
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

/// <summary>Function to calculate the change to be returned and the number of coins of different denominations.</summary>
int* CalculateChange (int cashPaid, int actualAmount);

#endif CASH_H