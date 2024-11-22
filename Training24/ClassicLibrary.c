// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------------------------------------
// Classiclibrary.c
// Program on main branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>

typedef struct ComplexNumber {
   float real;
   float imagine;
}complex;

complex add (complex a, complex b) {
   complex add;
   add.real = a.real + b.real;
   add.imagine = a.imagine + b.imagine;
   return add;
}

complex sub (complex a, complex b) {
   complex sub;
   sub.real = a.real - b.real;
   sub.imagine = a.imagine - b.imagine;
   return sub;
}

complex mul (complex a, complex b) {
   complex mul;
   mul.real = a.real * b.real;
   mul.imagine = a.imagine * b.imagine;
   return mul;
}

static void modulus (int x, int y) {
   x = 25, y = 36;
   int mod = sqrt (x ^ 2) + sqrt (y ^ 2);
   printf ("modulus is :%d", mod);
   return 0;
}

int main () {
   int mod;
   complex a, b, sum;
   a.real = 2.3;
   a.imagine = 5.6;
   b.real = 3.3;
   b.imagine = 4.5;
   printf ("Adding funtion.\na   = % 3f + % 3fi\n", a.real, a.imagine);
   printf ("b   = % 3f + % 3fi\n", b.real, b.imagine);
   sum = add (a, b);
   printf ("sum = % f + % fi\n", sum.real, sum.imagine);

   printf ("Subtraction funtion\na   = % f + % fi\n", a.real, a.imagine);
   printf ("b   = % f + % fi\n", b.real, b.imagine);
   sum = sub (a, b);
   printf ("sum = % f + % fi\n", sum.real, sum.imagine);

   printf ("Muliplication funtion\na   = % f + % fi\n", a.real, a.imagine);
   printf ("b   = % f + % fi\n", b.real, b.imagine);
   sum = mul (a, b);
   printf ("sum = % f + % fi\n", sum.real, sum.imagine);

   static void modulus (int x, int y);
   return 0;
}































