// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P 
// ------------------------------------------------------------------------------------------------
// ComplexTest.c
// Program on Test1.1 branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <math.h>
#include "ComplexNumber.h"

/// <summary>Function to compare two complex numbers.</summary>
int CompareComplex (Complex sum, Complex expected) {
   float epsilon = 0.0001;
   return (fabs (sum.Real - expected.Real) < epsilon) && (fabs (sum.Imagine - expected.Imagine) < epsilon);
}

int GetComplexInput (Complex* c, const char* input) {
   printf ("%s", input);
   int valid = 0;
   while (!valid) {
      if (scanf_s ("%f %f", &c->Real, &c->Imagine) != 2) {
         printf ("Invalid input. Enter two float numbers.\n");
         while (getchar () != '\n');
      }
      else valid = 1;
   }
   return 1;
}

/// <summary>Function for Addition Test Case.</summary>
void TestAddition (Complex a, Complex b) {
   Complex sum = Op_Add (a, b);
   Complex expected_add = { a.Real + b.Real, a.Imagine + b.Imagine };
   printf ("Test Case 1: Addition\n");
   printf ("Expected: %.2f + %.2fi\n", expected_add.Real, expected_add.Imagine);
   printf ("Result  : %.2f + %.2fi\n", sum.Real, sum.Imagine);
   printf (CompareComplex (sum, expected_add) ? "Test Passed.\n\n" : "Test Failed.\n\n");
}

/// <summary>Function for Subtraction Test Case.</summary>
void TestSubtraction (Complex a, Complex b) {
   Complex sum = Op_Sub (a, b);
   Complex expected_sub = { a.Real - b.Real, a.Imagine - b.Imagine };
   printf ("Test Case 2: Subtraction\n");
   printf ("Expected: %.2f + %.2fi\n", expected_sub.Real, expected_sub.Imagine);
   printf ("Result  : %.2f + %.2fi\n", sum.Real, sum.Imagine);
   printf (CompareComplex (sum, expected_sub) ? "Test Passed.\n\n" : "Test Failed.\n\n");
}

/// <summary>Function for Multiplication Test Case.</summary>
void TestMultiplication (Complex a, Complex b) {
   Complex sum = Op_Mul (a, b);
   Complex expected_mul = { a.Real * b.Real - a.Imagine * b.Imagine, a.Real * b.Imagine + a.Imagine * b.Real };
   printf ("Test Case 3: Multiplication\n");
   printf ("Expected: %.2f + %.2fi\n", expected_mul.Real, expected_mul.Imagine);
   printf ("Result  : %.2f + %.2fi\n", sum.Real, sum.Imagine);
   printf (CompareComplex (sum, expected_mul) ? "Test Passed.\n\n" : "Test Failed.\n\n");
}

/// <summary>Function for Modulus Test Case.</summary>
void TestModulus (Complex a, Complex b) {
   float modulus_a = Op_Modulus (a);
   float modulus_b = Op_Modulus (b);
   printf ("Test Case 4: Modulus\n");
   printf ("Expected: |a| = %.2f, |b| = %.2f\n", modulus_a, modulus_b);
   printf ("Result  : |a| = %.2f, |b| = %.2f\n", modulus_a, modulus_b);
   printf (fabs (modulus_a - sqrt (a.Real * a.Real + a.Imagine * a.Imagine)) < 0.0001 &&
      fabs (modulus_b - sqrt (b.Real * b.Real + b.Imagine * b.Imagine)) < 0.0001 ? "Test Passed.\n\n" : "Test Failed.\n\n");
}

/// <summary>Function for Conjugate Test Case.</summary>
void TestConjugate (Complex a, Complex b) {
   Complex conj_a = Op_Conjugate (a);
   Complex expected_conj_a = { a.Real, -a.Imagine };
   printf ("Test Case 5: Conjugate\n");
   printf ("Expected: Conjugate of a = %.2f + %.2fi\n", expected_conj_a.Real, expected_conj_a.Imagine);
   printf ("Result  : Conjugate of a = %.2f + %.2fi\n", conj_a.Real, conj_a.Imagine);
   printf (CompareComplex (conj_a, expected_conj_a) ? "Test Passed.\n" : "Test Failed.\n");

   Complex conj_b = Op_Conjugate (b);
   Complex expected_conj_b = { b.Real, -b.Imagine };
   printf ("Expected: Conjugate of b = %.2f + %.2fi\n", expected_conj_b.Real, expected_conj_b.Imagine);
   printf ("Result  : Conjugate of b = %.2f + %.2fi\n", conj_b.Real, conj_b.Imagine);
   printf (CompareComplex (conj_b, expected_conj_b) ? "Test Passed.\n\n" : "Test Failed.\n\n");
}

int main () {
   Complex a, b;
   printf ("Enter the first complex number: \n");
   GetComplexInput (&a, "Real and imaginary parts: ");
   printf ("Enter the second complex number:\n");
   GetComplexInput (&b, "Real and imaginary parts: ");
   printf ("\nComplex Number 1: %.2f + %.2fi\n", a.Real, a.Imagine);
   printf ("Complex Number 2: %.2f + %.2fi\n\n", b.Real, b.Imagine);
   TestAddition (a, b);
   TestSubtraction (a, b);
   TestMultiplication (a, b);
   TestModulus (a, b);
   TestConjugate (a, b);
   return 0;
}