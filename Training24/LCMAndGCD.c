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
   return (a * b) / GCD (a, b);
}

int main () {
   int n1, n2;
   char buffer[100];
   printf ("Enter the first number: ");
   fgets (buffer, sizeof (buffer), stdin);
   n1 = strtol (buffer, NULL, 10);
   printf ("Enter the second number: ");
   fgets (buffer, sizeof (buffer), stdin);
   n2 = strtol (buffer, NULL, 10);
   printf ("The GCD of %d and %d is: %d\n", n1, n2, GCD (n1, n2));
   printf ("The LCM of %d and %d is: %d\n", n1, n2, LCM (n1, n2));
   return 0;
}