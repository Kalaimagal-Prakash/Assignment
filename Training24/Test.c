// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// Test.c
// Program on A6 branch.
// ------------------------------------------------------------------------------------------------
#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include "Header.h"

//static void TestChessboard () {
//   // Open the output file "Chess.txt" in write mode
//   FILE* outputFile = fopen ("Chess.txt", "w");
//   if (outputFile == NULL) {
//      wprintf (L"Failed to open output file.\n");
//      return;
//   }
//
//   // Redirecting the output to the file
//   fwprintf (outputFile, L"Running Test Chessboard...\n");
//
//   // Call the PrintChessboard function to print the board into the file
//   PrintChessboard (outputFile);
//
//   // Close the file after writing the output
//   fclose (outputFile);
//}

int main () {
   // Set the console output to handle wide characters
   int k = _setmode (_fileno (stdout), _O_U16TEXT);
   //FILE* file = fopen ("Chess.txt", "w+,ccs=UTF-8");
   // Call the TestChessboard function to write the chessboard to the file
   //TestChessboard ();
   PrintChessboard ();
   //PrintChessboard (FILE * ChessFile);
   return 0;
}