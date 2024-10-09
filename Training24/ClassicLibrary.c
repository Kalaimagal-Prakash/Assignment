// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// ClassicLibrary.c
// Program on A4 branch.
// 1. Palindrome is a word that reads the same forward or backward. Example: Civic, Madam, Bib, Nun, Level and so on. 
//    Your program must take the word as input and display the result if it is a palindrome or not. 
//    For complexity, you can also use phrases instead of words (E.g., Was it a car or a cat I saw? I did, did I? Don’t nod)
// 2. Write a program that reverses a given integer (as defined in C) as explained below and check if it is a palindrome.
// ------------------------------------------------------------------------------------------------
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

bool IsPalindrome (const char* str) {
   size_t left = 0, right = strlen (str) - 1;
   while (left < right) return (str[left++] != str[right--]) ? false : true;    // Return false if characters at 'left' and 'right' differ.
   return true;
}

int ReverseNumber (int num) {
   int reversed = 0,negative = (num < 0) ? 1 : 0;
   num = abs(num);
   while (num != 0) {
      int digit = num % 10;                                               // Extract the last digit
      if (reversed > (INT_MAX - digit) / 10) return -1;                   // Handle overflow
      reversed = reversed * 10 + digit;
      num /= 10;                                                          // Remove the last digit from the original number
   }
   return negative ? -reversed : reversed;
}