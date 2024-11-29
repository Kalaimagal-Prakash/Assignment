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
   Complex add;
   add.Real = a.Real + b.Real;
   add.Imagine = a.Imagine + b.Imagine;
   return add;
}

Complex Op_Sub (Complex a, Complex b) {
   Complex sub;
   sub.Real = a.Real - b.Real;
   sub.Imagine = a.Imagine - b.Imagine;
   return sub;
}

Complex Op_Mul (Complex a, Complex b) {
   Complex mul;
   mul.Real = a.Real * b.Real - a.Imagine * b.Imagine;
   mul.Imagine = a.Real * b.Imagine + a.Imagine * b.Real;
   return mul;
}

float Op_Modulus (Complex x) {
   return sqrt (x.Real * x.Real + x.Imagine * x.Imagine);
}

Complex Op_Conjugate (Complex a) {
   Complex Conj;
   Conj.Real = a.Real;
   Conj.Imagine = -a.Imagine;
   return Conj;
}