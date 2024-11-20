// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// Test.c
// Program on A6 branch.
// ------------------------------------------------------------------------------------------------
_CRT_SECURE_NO_WARNINGS;
#include <stdio.h>
#include <corecrt.h>
#include <io.h>
#include <fcntl.h>
#include <conio.h>
#include <ctype.h>

// ANSI escape codes for colors
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"

// External declarations for functions
extern void PrintChessboard (FILE* output);

///<summary>Compares two files character by character and returns the result of the comparison.</summary>
static int FileCompare (FILE* ref, FILE* output, int* row, int* col) {
   wchar_t refChar = getwc (ref);
   wchar_t outChar = getwc (output);
   *row = 1;
   *col = 0;
   // Loop through both files character by character
   while (refChar != WEOF && outChar != WEOF) {
      *col += 1;
      if (refChar != outChar) return -3;  // Mismatch found
      // If newline is encountered, move to the next row
      if (refChar == L'\n') {
         *row += 1;
         *col = 0;
      }
      // Get the next character from both files
      refChar = getwc (ref);
      outChar = getwc (output);
   }
   // To check if both files reached EOF at the same time
   if (refChar != outChar) return refChar != WEOF ? -1 : -2;
   return 0;  // Files match
}

int main () {
   int k = _setmode (_fileno (stdout), _O_U8TEXT);
   FILE* output;
   FILE* ref;
   errno_t err = fopen_s (&output, "Chess.txt", "w+,ccs=UTF-8");
   if (err != 0) {
      wprintf (L"Failed to open Chess.txt\n");
      return -1;
   }
   fwprintf (output, L"Running Test Chessboard...\n");
   PrintChessboard (output);
   fclose (output);
   wprintf (L"\nDo you want to run a test case? (y/n): \n");
   char choice = _getch ();
   if (tolower (choice) == 'y') {
      // Open Chess.txt for reading
      err = fopen_s (&output, "Chess.txt", "r+,ccs=UTF-8");
      if (err != 0) {
         wprintf (L"Failed to open Chess.txt for reading\n");
         return -1;
      }
      // Open Chess_Ref.txt for reading
      err = fopen_s (&ref, "Chess_Ref.txt", "r+,ccs=UTF-8");
      if (err != 0) {
         wprintf (L"Failed to open Chess_Ref.txt\n");
         fclose (output);
         return -1;
      }
      // Initialize row and column to track the position in the files
      int row = 1, col = 0;
      int result = FileCompare (ref, output, &row, &col);
      switch (result) {
      case 0: wprintf (GREEN L"Files match! TEST PASSED\n" RESET); break;
      case -1: case -3: wprintf (RED L"Files mismatch! Error at row %d, col %d.\n" RESET, row, col); break;
      case -2: wprintf (YELLOW L"One file ended early! Error at row %d, col %d.\n" RESET, row, col); break;
      default: wprintf (YELLOW L"Unknown error at row %d, col %d.\n" RESET, row, col); break;
      }
      fclose (output);
      fclose (ref);
   }
   return 0;
}