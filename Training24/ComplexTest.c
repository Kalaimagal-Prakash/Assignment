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
   printf ("Addition            : %.2f + %.2fi  -> ", expectedAdd.Real, expectedAdd.Imagine);
   printf (OpEquals (sum, expectedAdd) ? GREEN "Passed\n" RESET : RED "Failed\n" RESET);
}

/// <summary>Function for Subtraction Test Case.</summary>
static void TestSubtraction (Complex a, Complex b, Complex expectedSub) {
   Complex sum = OpSub (a, b);
   printf ("Subtraction         : %.2f + %.2fi  -> ", expectedSub.Real, expectedSub.Imagine);
   printf (OpEquals (sum, expectedSub) ? GREEN "Passed\n" RESET : RED "Failed\n" RESET);
}

/// <summary>Function for Multiplication Test Case.</summary>
static void TestMultiplication (Complex a, Complex b, Complex expectedMul) {
   Complex sum = OpMul (a, b);
   printf ("Multiplication      : %.2f + %.2fi  -> ", expectedMul.Real, expectedMul.Imagine);
   printf (OpEquals (sum, expectedMul) ? GREEN "Passed\n" RESET : RED "Failed\n" RESET);
}

/// <summary>Function for Conjugate Test Case.</summary>
static void TestConjugate (Complex a, Complex expectedConjA) {
   Complex conjA = OpConjugate (a);
   printf ("Conjugate           : %.2f + %.2fi  -> ", expectedConjA.Real, expectedConjA.Imagine);
   printf (OpEquals (conjA, expectedConjA) ? GREEN "Passed\n" RESET : RED "Failed\n" RESET);
}

/// <summary>Function for Modulus Test Case.</summary>
static void TestModulus (Complex a, float expectedModA) {
   float modulusA = OpModulus (a);
   printf ("Modulus             : %.2f  -> ", expectedModA);
   printf (fabs (modulusA - expectedModA) < EPSILON ? GREEN "Passed\n" RESET : RED "Failed\n" RESET);
}

/// <summary>Function to execute the test cases automatically.</summary>
static void TestCases () {
   Complex testCases[3] = { {1, 2}, {-3, 4}, {5, -6} };
   Complex expectedSum[3] = { {-2, 6}, {2, -2}, {6, -4} }, expectedSub[3] = { {4, -2}, {-8, 10}, {4, -8} },
      expectedMul[3] = { {-11, -2}, {9, 38}, {17, 4} }, expectedConj[3] = { {1, -2}, {-3, -4}, {5, 6} };
   float expectedMod[3] = { 2.2361f, 5.0f, 7.8102f };
   for (int i = 0; i < 3; i++) {
      printf (YELLOW "\nTest %d:\n" RESET, i + 1);
      TestAddition (testCases[i], testCases[(i + 1) % 3], expectedSum[i]);
      TestSubtraction (testCases[i], testCases[(i + 1) % 3], expectedSub[i]);
      TestMultiplication (testCases[i], testCases[(i + 1) % 3], expectedMul[i]);
      TestConjugate (testCases[i], expectedConj[i]);
      TestModulus (testCases[i], expectedMod[i]);
   }
}

/// <summary> Function for user-defined operations.</summary>
static void UserInput () {
   Complex a, b;
   printf ("Enter the first complex number (real and imaginary part):\n");
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
   TestAddition (a, b, OpAdd (a, b), 1);
   TestSubtraction (a, b, OpSub (a, b), 2);
   TestMultiplication (a, b, OpMul (a, b), 3);
   TestConjugate (a, OpConjugate (a), 5);
   TestModulus (a, OpModulus (a), 4);
}

int main () {
   int choice, continueTesting = 1;
   do {
      printf ("\n1. Run Test Cases\n");
      printf ("2. Enter User Input\n");
      printf ("3. Exit\n");
      printf ("Enter your choice: ");
      choice = _getch ();
      ClearScreen ();
      switch (choice) {
      case '1': TestCases (); break;
      case '2': UserInput (); break;
      case '3': printf (YELLOW "Exiting the program.\n" RESET); exit (0); break;
      default: printf ("Invalid choice. Please try again.\n"); break;
      }
      if (continueTesting) {
         printf ("\nDo you want to run the program? (y/n): ");
         choice = _getch ();
         if (choice == 'n' || choice == 'N') continueTesting = 0;
      }
   } while (continueTesting);
   printf (YELLOW "Exiting the program.\n" RESET);
   return 0;
}