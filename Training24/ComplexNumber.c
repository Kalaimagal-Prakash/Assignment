// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P 
// ------------------------------------------------------------------------------------------------
// ComplexNumber.c
// Program on T1 branch.
// ------------------------------------------------------------------------------------------------
#include <math.h>
#include "ComplexNumber.h"

Complex Op_Add (Complex a, Complex b) {
   Complex add;
   add.real = a.real + b.real;
   add.imagine = a.imagine + b.imagine;
   return add;
}

Complex Op_Sub (Complex a, Complex b) {
   Complex sub;
   sub.real = a.real - b.real;
   sub.imagine = a.imagine - b.imagine;
   return sub;
}

Complex Op_Mul (Complex a, Complex b) {
   Complex mul;
   mul.real = a.real * b.real - a.imagine * b.imagine;
   mul.imagine = a.real * b.imagine + a.imagine * b.real;
   return mul;
}

float Op_Modulus (Complex x) {
   return sqrt (x.real * x.real + x.imagine * x.imagine);
}
Complex Op_Conjugate (Complex a) {
   Complex Conj;
   Conj.real = a.real;
   Conj.imagine = -a.imagine;
   return Conj;
}