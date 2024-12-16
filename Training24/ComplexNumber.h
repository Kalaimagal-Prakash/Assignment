// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P 
// ------------------------------------------------------------------------------------------------
// ComplexNumber.h
// Program on Test1.1 branch.
// ------------------------------------------------------------------------------------------------
#ifndef COMPLEX_H
#define COMPLEX_H

// ANSI escape codes for colors
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

typedef struct {
   float Real, Imagine;
}Complex;

/// <summary>Adds two complex numbers</summary>
Complex Op_Add (Complex a, Complex b);

/// <summary>Subtract the one number to another complex numbers</summary>
Complex Op_Sub (Complex a, Complex b);

/// <summary>Multiply the two complex numbers</summary>
Complex Op_Mul (Complex a, Complex b);

/// <summary>Find the Modulus of a complex numbers</summary>
float Op_Modulus (Complex x);

/// <summary>Find the conjugate of a complex numbers</summary>
Complex Op_Conjugate (Complex a);

/// <summary>Function to compare two complex numbers.</summary>
int Op_Equals (Complex a, Complex b);

#endif COMPLEX_H