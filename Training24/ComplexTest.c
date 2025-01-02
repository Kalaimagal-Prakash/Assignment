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
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#define EPSILON 0.0001

static void ClearScreen () {
#ifdef _WIN32
   system ("cls");
#endif
}

/// <summary>Function to check and get a valid complex number from the user.</summary>
bool GetComplex (Complex* c, const char* message) {
   printf ("%s", message);
   while (1) {
      if (scanf_s ("%f %f", &c->Real, &c->Imagine) == 2) return true;
      else {
         printf ("Invalid input. Enter two floating point numbers (real and imaginary part):\n");
         while (getchar () != '\n');
      }
   }
}

/// <summary>Function for Addition Test Case.</summary>
static void TestAddition (Complex a, Complex b, Complex expectedAdd) {
   Complex sum = OpAdd (a, b);
   printf ("Addition        : %.2f + %.2fi  -> ", expectedAdd.Real, expectedAdd.Imagine);
   printf (OpEquals (sum, expectedAdd) ? GREEN "Passed\n" RESET : RED "Failed\n" RESET);
}

/// <summary>Function for Subtraction Test Case.</summary>
static void TestSubtraction (Complex a, Complex b, Complex expectedSub) {
   Complex sum = OpSub (a, b);
   printf ("Subtraction     : %.2f + %.2fi  -> ", expectedSub.Real, expectedSub.Imagine);
   printf (OpEquals (sum, expectedSub) ? GREEN "Passed\n" RESET : RED "Failed\n" RESET);
}

/// <summary>Function for Multiplication Test Case.</summary>
static void TestMultiplication (Complex a, Complex b, Complex expectedMul) {
   Complex sum = OpMul (a, b);
   printf ("Multiplication  : %.2f + %.2fi  -> ", expectedMul.Real, expectedMul.Imagine);
   printf (OpEquals (sum, expectedMul) ? GREEN "Passed\n" RESET : RED "Failed\n" RESET);
}

/// <summary>Function for Conjugate Test Case.</summary>
static void TestConjugate (Complex a, Complex b, Complex expectedConjA, Complex expectedConjB) {
   Complex conjA = OpConjugate (a);
   printf ("Conjugate(a)    : %.2f + %.2fi  -> ", expectedConjA.Real, expectedConjA.Imagine);
   printf (OpEquals (conjA, expectedConjA) ? GREEN "Passed\n" RESET : RED "Failed\n" RESET);
   Complex conjB = OpConjugate (b);
   printf ("Conjugate(b)    : %.2f + %.2fi  -> ", expectedConjB.Real, expectedConjB.Imagine);
   printf (OpEquals (conjB, expectedConjB) ? GREEN "Passed\n" RESET : RED "Failed\n" RESET);
}

/// <summary>Function for Modulus Test Case.</summary>
static void TestModulus (Complex a, Complex b, float expectedModA, float expectedModB) {
   float modulusA = OpModulus (a);
   printf ("Modulus(a)      : %.2f  -> ", expectedModA);
   printf (fabs (modulusA - expectedModA) < EPSILON ? GREEN "Passed\n" RESET : RED "Failed\n" RESET);
   float modulusB = OpModulus (b);
   printf ("Modulus(b)      : %.2f  -> ", expectedModB);
   printf (fabs (modulusB - expectedModB) < EPSILON ? GREEN "Passed\n" RESET : RED "Failed\n" RESET);
}

/// <summary>Function to execute the test cases automatically.</summary>
static void TestCases () {
   Complex testCases[6] = { {1, 2}, {-3, 4}, {5, -6}, {7, 1}, {0, -5}, {-9, 3} },
      expectedSum[6] = { {-2, 6}, {2, -2}, {12, -5}, {7, -4}, {-9, -2}, {-8, 5} },
      expectedSub[6] = { {4, -2}, {-8, 10}, {-2, -7}, {7, 6}, {9, -8}, {-10, 1} },
      expectedMul[6] = { {-11, -2}, {9, 38}, {41, -37}, {5, -35}, {15, 45}, {-15, -15} },
      expectedConj[6] = { {1, -2},{-3, -4}, {5, 6}, {7, -1}, {0, 5}, {-9, -3} };
   float expectedMod[6] = {
       2.2361f, 5.0f, 7.8102f, 7.0711f, 5.0f, 9.4868f
   };
   for (int i = 0; i < 6; i++) {
      printf (YELLOW "\nTest %d:\n" RESET, i + 1);
      TestAddition (testCases[i], testCases[(i + 1) % 6], expectedSum[i]);
      TestSubtraction (testCases[i], testCases[(i + 1) % 6], expectedSub[i]);
      TestMultiplication (testCases[i], testCases[(i + 1) % 6], expectedMul[i]);
      TestConjugate (testCases[i], testCases[(i + 1) % 6], expectedConj[i], expectedConj[(i + 1) % 6]);
      TestModulus (testCases[i], testCases[(i + 1) % 6], expectedMod[i], expectedMod[(i + 1) % 6]);
   }
}

/// <summary> Function for user-defined operations.</summary>
static void UserInput () {
   Complex a, b;
   printf ("\nEnter the first complex number (real and imaginary part):\n");
   if (!GetComplex (&a, "Complex number 1: ")) {
      printf ("Invalid input. Exiting program.\n");
      return;
   }
   printf ("Enter the second complex number (real and imaginary part):\n");
   if (!GetComplex (&b, "Complex number 2: ")) {
      printf ("Invalid input. Exiting program.\n");
      return;
   }
   printf ("\nComplex Number 1: %.2f + %.2fi\n", a.Real, a.Imagine);
   printf ("Complex Number 2: %.2f + %.2fi\n\n", b.Real, b.Imagine);
   TestAddition (a, b, OpAdd (a, b));
   TestSubtraction (a, b, OpSub (a, b));
   TestMultiplication (a, b, OpMul (a, b));
   TestConjugate (a, b, OpConjugate (a), OpConjugate (b));
   TestModulus (a, b, OpModulus (a), OpModulus (b));
}

int main () {
   int choice, continueTesting = 1;
   do {
      printf ("\n1. Run Test Cases\n2. Enter User Input\n3. Exit\nEnter your choice: ");
      choice = _getche ();
      switch (choice) {
      case '1': TestCases (); break;
      case '2': UserInput (); break;
      case '3': printf (YELLOW "\nExiting the program.\n" RESET); exit (0); break;
      default: printf ("Invalid choice. Please try again.\n"); break;
      }
      if (continueTesting) {
         printf ("\nDo you want to run the program? (y/n): ");
         choice = _getche ();
         ClearScreen ();
         if (choice == 'n' || choice == 'N') continueTesting = 0;
      }
   } while (continueTesting);
   printf (YELLOW "\nExiting the program.\n" RESET);
   return 0;
}