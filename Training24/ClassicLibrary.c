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
#include <ctype.h>
#include <limits.h>
#define MAXLENGTH 100

bool Palindrome (const char* str) {
   char filtered[MAXLENGTH];
   int j = 0, left = 0;
   for (int i = 0; str[i]; i++) if (isalnum (str[i])) filtered[j++] = tolower (str[i]);      // Filter out non-alphanumeric characters and convert to lowercase
   filtered[j] = '\0';                                                                       // Null-terminate the filtered string
   int right = j - 1;                                                                        // Ensure the right index is set correctly
   while (left < right) {
      if (filtered[left] != filtered[right]) return false;
      left++;
      right--;
   }
   return true;
}

int ReverseNumber (int num) {
   int reversed = 0;
   int isNegative = (num < 0);
   if (isNegative) num = -num;
   while (num > 0) {                                                                       // Reverse the digits of the number
      if (reversed > (INT_MAX - num % 10) / 10) return 0;
      reversed = reversed * 10 + (num % 10);
      num /= 10;
   }
   return isNegative ? -reversed : reversed;
}