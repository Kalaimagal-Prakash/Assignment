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
   wchar_t blackPieces[] = {
       L'\u265C', // Black rook
       L'\u265E', // Black knight
       L'\u265D', // Black bishop
       L'\u265B', // Black queen
       L'\u265A', // Black king
       L'\u265D', // Black bishop
       L'\u265E', // Black knight
       L'\u265C'  // Black rook
   };
   wchar_t whitePieces[] = {
       L'\u2656', // White rook
       L'\u2658', // White knight
       L'\u2657', // White bishop
       L'\u2655', // White queen
       L'\u2654', // White king
       L'\u2657', // White bishop
       L'\u2658', // White knight
       L'\u2656'  // White rook
   };
   if (row == 0) return blackPieces[col];
   if (row == 1) return L'\u265F';
   if (row == 6) return L'\u2659';
   if (row == 7) return whitePieces[col];
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