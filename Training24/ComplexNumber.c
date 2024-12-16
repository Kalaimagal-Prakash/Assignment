// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P 
// ------------------------------------------------------------------------------------------------
// ComplexNumber.c
// Program on Test1.1 branch.
// ------------------------------------------------------------------------------------------------
#include <math.h>
#include "ComplexNumber.h"

Complex Op_Add (Complex a, Complex b) {
   return (Complex) { a.Real + b.Real, a.Imagine + b.Imagine };
}

Complex Op_Sub (Complex a, Complex b) {
   return(Complex) { a.Real - b.Real, a.Imagine - b.Imagine };
}

Complex Op_Mul (Complex a, Complex b) {
   return(Complex) { a.Real* b.Real - a.Imagine * b.Imagine, a.Real* b.Imagine + a.Imagine * b.Real };
}

float Op_Modulus (Complex x) {
   return sqrt (x.Real * x.Real + x.Imagine * x.Imagine);
}

Complex Op_Conjugate (Complex a) {
   return(Complex) { a.Real, -a.Imagine };
}

int Op_Equals (Complex a, Complex b) {
   return a.Real == b.Real && a.Imagine == b.Imagine;
}