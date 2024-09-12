// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// Header.h
// Program on A4 branch.
// 1. Palindrome is a word that reads the same forward or backward. Example: Civic, Madam, Bib, Nun, Level and so on. 
//    Your program must take the word as input and display the result if it is a palindrome or not. 
//    For complexity, you can also use phrases instead of words (E.g., Was it a car or a cat I saw? I did, did I? Don’t nod)
// 2. Write a program that reverses a given integer (as defined in C) as explained below and check if it is a palindrome.
// ------------------------------------------------------------------------------------------------
#ifndef PALINDROME_H
#define PALINDROME_H
#include <stdbool.h>

/// <summary>Function to check the word is palindrome or not.</summary>
bool Palindrome (const char* str);

/// <summary>Function to check the integer to reverse and check if it's a palindrome.</summary>
int ReverseNumber (int num);

#endif PALINDROME_H