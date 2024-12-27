// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// Classiclibrary.c
// Program on A6 branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>

wchar_t GetPiece (int row, int col) {
   wchar_t black[2][8] = {
       {L'\u265C', L'\u265E', L'\u265D', L'\u265B', L'\u265A', L'\u265D', L'\u265E', L'\u265C'},  // Black pieces
       {L'\u265F'}  // Black pawns
   };
   wchar_t white[2][8] = {
       {L'\u2656', L'\u2658', L'\u2657', L'\u2655', L'\u2654', L'\u2657', L'\u2658', L'\u2656'},  // White pieces
       {L'\u2659'}  // White pawns
   };
   if (row == 0) return black[0][col];
   if (row == 1) return black[1][0];
   if (row == 6) return white[1][0];
   if (row == 7) return white[0][col];
   return L' ';
}

void PrintChessboard (FILE* fp) {
   // Print the top border
   wprintf (L"┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓\n");
   fwprintf (fp, L"┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓\n");
   // Loop through rows and columns to print the chessboard
   for (int row = 0; row < 8; row++) {
      // Print each row's
      for (int col = 0; col < 8; col++) {
         wchar_t piece = GetPiece (row, col);
         wprintf (L"┃ %lc ", piece);          // Print to console
         fwprintf (fp, L"┃ %lc ", piece);     // Print to file
      }
      wprintf (L"┃ \n");
      fwprintf (fp, L"┃ \n");
      // Print row separators
      if (row != 7) {
         wprintf (L"┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫\n");
         fwprintf (fp, L"┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫\n");
      }
   }
   // Print the bottom border
   wprintf (L"┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛\n");
   fwprintf (fp, L"┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛\n");
}