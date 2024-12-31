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
       L'\u265F'  // Black pawn
   };
   wchar_t whitePieces[] = {
       L'\u2656', // White rook
       L'\u2658', // White knight
       L'\u2657', // White bishop
       L'\u2655', // White queen
       L'\u2654', // White king
       L'\u2659'  // White pawn
   };
   return (row == 0) ? (col == 0 || col == 7) ? blackPieces[0] : (col == 1 || col == 6) ? blackPieces[1] :
      (col == 2 || col == 5) ? blackPieces[2] : (col == 3) ? blackPieces[3] : (col == 4) ? blackPieces[4] : L' ' :
      (row == 1) ? blackPieces[5] : (row == 6) ? whitePieces[5] :
      (row == 7) ? (col == 0 || col == 7) ? whitePieces[0] : (col == 1 || col == 6) ? whitePieces[1] :
      (col == 2 || col == 5) ? whitePieces[2] : (col == 3) ? whitePieces[3] : (col == 4) ? whitePieces[4] : L' ' :
      L' ';
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