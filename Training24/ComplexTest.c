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
#include <conio.h> 
#include <stdlib.h>
#include "ComplexNumber.h"

/// <summary>Function to clear the console screen.</summary>
void ClearScreen () {
#ifdef _WIN32
   system ("cls");
#endif
}
// Prompts the user to input the real and imaginary parts of a complex number and ensures valid float input.
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
   Complex sum = OpAdd (a, b);
   Complex expectedAdd = { a.Real + b.Real, a.Imagine + b.Imagine };
   printf ("Test Case 1: Addition\n");
   printf ("Expected: %.2f + %.2fi | Result: %.2f + %.2fi\n", expectedAdd.Real, expectedAdd.Imagine, sum.Real, sum.Imagine);
   printf (OpEquals (sum, expectedAdd) ? GREEN "Test Passed.\n\n" RESET : RED "Test Failed.\n\n" RESET);
}

/// <summary>Function for Subtraction Test Case.</summary>
static void TestSubtraction (Complex a, Complex b) {
   Complex sum = OpSub (a, b);
   Complex expectedSub = { a.Real - b.Real, a.Imagine - b.Imagine };
   printf ("Test Case 2: Subtraction\n");
   printf ("Expected: %.2f + %.2fi | Result: %.2f + %.2fi\n", expectedSub.Real, expectedSub.Imagine, sum.Real, sum.Imagine);
   printf (OpEquals (sum, expectedSub) ? GREEN "Test Passed.\n\n" RESET : RED "Test Failed.\n\n" RESET);
}

/// <summary>Function for Multiplication Test Case.</summary>
static void TestMultiplication (Complex a, Complex b) {
   Complex sum = OpMul (a, b);
   Complex expectedMul = { a.Real * b.Real - a.Imagine * b.Imagine, a.Real * b.Imagine + a.Imagine * b.Real };
   printf ("Test Case 3: Multiplication\n");
   printf ("Expected: %.2f + %.2fi | Result: %.2f + %.2fi\n", expectedMul.Real, expectedMul.Imagine, sum.Real, sum.Imagine);
   printf (OpEquals (sum, expectedMul) ? GREEN "Test Passed.\n\n" RESET : RED "Test Failed.\n\n" RESET);
}

/// <summary>Function for Modulus Test Case.</summary>
static void TestModulus (Complex a, Complex b) {
   float modulusA = OpModulus (a);
   float modulusB = OpModulus (b);
#define TOLERANCE 0.0001
   double expectedModulusA = sqrt (a.Real * a.Real + a.Imagine * a.Imagine);
   double expectedModulusB = sqrt (b.Real * b.Real + b.Imagine * b.Imagine);
   printf ("Test Case 4: Modulus\n");
   printf ("Expected: |a| = %.2f, |b| = %.2f | Result: |a| = %.2f, |b| = %.2f\n",expectedModulusA, expectedModulusB, modulusA, modulusB);
   printf (fabs (modulusA - expectedModulusA) < TOLERANCE || fabs (modulusB - expectedModulusB) < TOLERANCE ? GREEN "Test Passed.\n\n" RESET
      : RED "Test Failed.\n\n" RESET);
}

/// <summary>Function for Conjugate Test Case.</summary>
static void TestConjugate (Complex a, Complex b) {
   Complex conjA = OpConjugate (a);
   Complex expectedConjA = { a.Real, -a.Imagine };
   printf ("Test Case 5: Conjugate\n");
   printf ("Expected: Conjugate of a = %.2f + %.2fi | Result: Conjugate of a = %.2f + %.2fi\n", expectedConjA.Real, expectedConjA.Imagine, conjA.Real, conjA.Imagine);
   printf (OpEquals (conjA, expectedConjA) ? GREEN "Test Passed.\n" RESET : RED "Test Failed.\n" RESET);

   Complex conjB = OpConjugate (b);
   Complex expectedConjB = { b.Real, -b.Imagine };
   printf ("Expected: Conjugate of b = %.2f + %.2fi | Result: Conjugate of b = %.2f + %.2fi\n", expectedConjB.Real, expectedConjB.Imagine, conjB.Real, conjB.Imagine);
   printf (OpEquals (conjB, expectedConjB) ? GREEN "Test Passed.\n\n" RESET : RED "Test Failed.\n\n" RESET);
}

static void DisplayMenu () {
   printf ("\nSelect the operation to perform:\n");
   printf ("1. Addition\n");
   printf ("2. Subtraction\n");
   printf ("3. Multiplication\n");
   printf ("4. Modulus\n");
   printf ("5. Conjugate\n");
   printf ("6. Exit\n");
}

int main () {
   Complex a, b;
   char choice;
   int continueTesting = 1;
   printf ("Enter the first complex number: \n");
   GetComplexInput (&a, "Real and imaginary parts: ");
   printf ("Enter the second complex number:\n");
   GetComplexInput (&b, "Real and imaginary parts: ");
   printf ("\nComplex Number 1: %.2f + %.2fi\n", a.Real, a.Imagine);
   printf ("Complex Number 2: %.2f + %.2fi\n\n", b.Real, b.Imagine);
   while (continueTesting) {
      DisplayMenu ();
      printf ("Enter your choice: ");
      choice = _getch ();
      ClearScreen ();
      switch (choice) {
      case '1': TestAddition (a, b); break;
      case '2': TestSubtraction (a, b); break;
      case '3': TestMultiplication (a, b); break;
      case '4': TestModulus (a, b); break;
      case '5': TestConjugate (a, b); break;
      case '6': continueTesting = 0; break;
      default:
         printf ("Invalid choice. Please select a valid option.\n");
         break;
      }
      if (continueTesting) {
         printf ("\nDo you want to perform another operation? (y/n): ");
         choice = _getch ();
         if (choice == 'n' || choice == 'N') continueTesting = 0;
      }
   }
   printf ("Exiting the program.\n");
   return 0;
}