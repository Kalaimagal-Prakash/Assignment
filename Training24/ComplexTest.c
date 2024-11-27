// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P 
// ------------------------------------------------------------------------------------------------
// ComplexTest.c
// Program on T1 branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <math.h>
#include "ComplexNumber.h"

void RunTests (float real1, float real2, float img1, float img2) {
   Complex a = { real1, img1 };
   Complex b = { real2, img2 };
   Complex sum;
   float modulus_a, modulus_b;
   printf ("a   = %.2f + %.2fi\n", a.real, a.imagine);
   printf ("b   = %.2f + %.2fi\n\n", b.real, b.imagine);

   sum = Op_Add (a, b);
   printf ("Addition = %.2f + %.2fi\n", sum.real, sum.imagine);
   printf (sum.real == 3.0 && sum.imagine == 7.0 ? "Test Passed.\n\n" : "Test Failed.\n\n");

   sum = Op_Sub (a, b);
   printf ("Subtraction = %.2f + %.2fi\n", sum.real, sum.imagine);
   printf (sum.real == 1.0 && sum.imagine == -1.0 ? "Test Passed.\n\n" : "Test Failed.\n\n");

   sum = Op_Mul (a, b);
   printf ("Muliplication = %.2f + %.2fi\n", sum.real, sum.imagine);
   printf (sum.real == -10.0 && sum.imagine == 11.0 ? "Test Passed.\n\n" : "Test Failed.\n\n");

   modulus_a = Op_Modulus (a);
   modulus_b = Op_Modulus (b);
   printf ("Modulus function\na   = %.2f + %.2fi, |a| = %.2f\n", a.real, a.imagine, modulus_a);
   printf ("b   = %.2f + %.2fi, |b| = %.2f\n", b.real, b.imagine, modulus_b);
   printf (fabs (modulus_a - 3.605551) < 0.0001 && fabs (modulus_b - 4.123105) < 0.0001 ? "Test Passed.\n\n" : "Test Failed.\n\n");

   sum = Op_Conjugate (a);
   printf ("Conjugate = %.2f + %.2fi\n", sum.real, sum.imagine);
   printf (sum.real == 2.0 && sum.imagine == -3.0 ? "Test Passed.\n\n" : "Test Failed.\n\n");
}

int main () {
   float real1, real2, img1, img2;
   printf ("Enter numbers for the first complex number:\n");
   printf ("Enter the real part: ");
   scanf_s ("%f", &real1);
   printf ("Enter the imaginary part: ");
   scanf_s ("%f", &img1);

   printf ("Enter numbers for the second complex number:\n");
   printf ("Enter the real part: ");
   scanf_s ("%f", &real2);
   printf ("Enter the imaginary part: ");
   scanf_s ("%f", &img2);

   RunTests (real1, real2, img1, img2);
   return 0;
}