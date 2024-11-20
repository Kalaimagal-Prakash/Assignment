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
   if (row == 0) {  // Black pieces (first row)
      switch (col) {
      case 0: case 7: return L'\u265C';  // Black Rook
      case 1: case 6: return L'\u265E';  // Black Knight
      case 2: case 5: return L'\u265D';  // Black Bishop
      case 3: return L'\u265B';          // Black Queen
      case 4: return L'\u265A';          // Black King
      default: return L' ';              // Empty (shouldn't happen)
      }
   }
   else if (row == 1) return L'\u265F';  // Black Pawn
   else if (row == 6) return L'\u2659';  // White Pawn
   else if (row == 7) {                  // White pieces (last row)
      switch (col) {
      case 0: case 7: return L'\u2656';  // White Rook
      case 1: case 6: return L'\u2658';  // White Knight
      case 2: case 5: return L'\u2657';  // White Bishop
      case 3: return L'\u2655';          // White Queen
      case 4: return L'\u2654';          // White King
      default: return L' ';              // Empty (shouldn't happen)
      }
   }
   return L' '; // Empty square for all other rows
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