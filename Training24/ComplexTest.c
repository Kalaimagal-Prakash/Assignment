// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P 
// ------------------------------------------------------------------------------------------------
// ComplexTest.c
// Program on Test1.1 branch.
// ------------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "ComplexNumber.h"

static int GetComplexInput (Complex* c, const char* input) {
   printf ("%s", input);
   while (scanf ("%f %f", &c->Real, &c->Imagine) != 2) {
      printf ("Invalid input. Enter two float numbers.\n");
      while (getchar () != '\n');
   }
   return 1;
}

/// <summary>Function for Addition Test Case.</summary>
static void TestAddition (Complex a, Complex b) {
   Complex sum = Op_Add (a, b);
   Complex expected_add = { a.Real + b.Real, a.Imagine + b.Imagine };
   printf ("Test Case 1: Addition\n");
   printf ("Expected: %.2f + %.2fi | Result: %.2f + %.2fi\n", expected_add.Real, expected_add.Imagine, sum.Real, sum.Imagine);
   printf (Op_Equals (sum, expected_add) ? GREEN "Test Passed.\n\n" RESET : RED "Test Failed.\n\n" RESET);
}

/// <summary>Function for Subtraction Test Case.</summary>
static void TestSubtraction (Complex a, Complex b) {
   Complex sum = Op_Sub (a, b);
   Complex expected_sub = { a.Real - b.Real, a.Imagine - b.Imagine };
   printf ("Test Case 2: Subtraction\n");
   printf ("Expected: %.2f + %.2fi | Result: %.2f + %.2fi\n", expected_sub.Real, expected_sub.Imagine, sum.Real, sum.Imagine);
   printf (Op_Equals (sum, expected_sub) ? GREEN "Test Passed.\n\n" RESET : RED "Test Failed.\n\n" RESET);
}

/// <summary>Function for Multiplication Test Case.</summary>
static void TestMultiplication (Complex a, Complex b) {
   Complex sum = Op_Mul (a, b);
   Complex expected_mul = { a.Real * b.Real - a.Imagine * b.Imagine, a.Real * b.Imagine + a.Imagine * b.Real };
   printf ("Test Case 3: Multiplication\n");
   printf ("Expected: %.2f + %.2fi | Result: %.2f + %.2fi\n", expected_mul.Real, expected_mul.Imagine, sum.Real, sum.Imagine);
   printf (Op_Equals (sum, expected_mul) ? GREEN "Test Passed.\n\n" RESET : RED "Test Failed.\n\n" RESET);
}

/// <summary>Function for Modulus Test Case.</summary>
static void TestModulus (Complex a, Complex b) {
   float modulus_a = Op_Modulus (a);
   float modulus_b = Op_Modulus (b);
   printf ("Test Case 4: Modulus\n");
   printf ("Expected: |a| = %.2f, |b| = %.2f | Result: |a| = %.2f, |b| = %.2f\n", modulus_a, modulus_b, modulus_a, modulus_b);
   printf (fabs (modulus_a - sqrt (a.Real * a.Real + a.Imagine * a.Imagine)) < 0.0001 &&
      fabs (modulus_b - sqrt (b.Real * b.Real + b.Imagine * b.Imagine)) < 0.0001 ? GREEN "Test Passed.\n\n" RESET : RED "Test Failed.\n\n" RESET);
}

/// <summary>Function for Conjugate Test Case.</summary>
static void TestConjugate (Complex a, Complex b) {
   Complex conj_a = Op_Conjugate (a);
   Complex expected_conj_a = { a.Real, -a.Imagine };
   printf ("Test Case 5: Conjugate\n");
   printf ("Expected: Conjugate of a = %.2f + %.2fi | Result: Conjugate of a = %.2f + %.2fi\n", expected_conj_a.Real, expected_conj_a.Imagine, conj_a.Real, conj_a.Imagine);
   printf (Op_Equals (conj_a, expected_conj_a) ? GREEN "Test Passed.\n" RESET : RED "Test Failed.\n" RESET);

   Complex conj_b = Op_Conjugate (b);
   Complex expected_conj_b = { b.Real, -b.Imagine };
   printf ("Expected: Conjugate of b = %.2f + %.2fi | Result: Conjugate of b = %.2f + %.2fi\n", expected_conj_b.Real, expected_conj_b.Imagine, conj_b.Real, conj_b.Imagine);
   printf (Op_Equals (conj_b, expected_conj_b) ? GREEN "Test Passed.\n\n" RESET : RED "Test Failed.\n\n" RESET);
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