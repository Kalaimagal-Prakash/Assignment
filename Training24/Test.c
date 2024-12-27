// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// Test.c
// Program on A6 branch.
// ------------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <corecrt.h>
#include <io.h>
#include <fcntl.h>
#include <conio.h>
#include <ctype.h>
#include <malloc.h>

// ANSI escape codes for colors
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"

// External declarations for functions
extern void PrintChessboard (FILE* output);

///<summary>Compares two files at once and returns the result of the comparison.</summary>
static int FileCompare (FILE* ref, FILE* output) {
   fseek (ref, 0, SEEK_END);
   long refSize = ftell (ref), outSize;
   fseek (output, 0, SEEK_END);
   outSize = ftell (output);
   fseek (ref, 0, SEEK_SET);
   fseek (output, 0, SEEK_SET);
   wchar_t* refBuffer = malloc (refSize);
   wchar_t* outBuffer = malloc (outSize);
   if (!refBuffer || !outBuffer) return -1;
   fread (refBuffer, 1, refSize, ref);
   fread (outBuffer, 1, outSize, output);
   long minSize = (refSize < outSize) ? refSize : outSize;
   for (long i = 0; i < minSize / sizeof (wchar_t); i++) {
      if (refBuffer[i] != outBuffer[i]) {
         free (refBuffer);
         free (outBuffer);
         return -3;  // Mismatch
      }
   }
   free (refBuffer);
   free (outBuffer);
   return (refSize == outSize) ? 0 : -2;  // Size mismatch
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
      int result = FileCompare (ref, output);
      (result == 0) ? wprintf (GREEN L"Files match! TEST PASSED\n" RESET) : wprintf (RED L"TEST FAILED\n" RESET);
      fclose (output);
      fclose (ref);
   }
   return 0;
}