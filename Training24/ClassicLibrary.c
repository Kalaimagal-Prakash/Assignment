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
   wchar_t pieces[2][8] = {
       {L'\u265C', L'\u265E', L'\u265D', L'\u265B', L'\u265A', L'\u265D', L'\u265E', L'\u265C'},  // Black pieces
       {L'\u2656', L'\u2658', L'\u2657', L'\u2655', L'\u2654', L'\u2657', L'\u2658', L'\u2656'}   // White pieces
   };
   wchar_t pawns[2] = { L'\u265F', L'\u2659' };  // Black pawn, White pawn
   if (row == 0) return pieces[0][col];          // Black back rank pieces
   if (row == 1) return pawns[0];                // Black pawns
   if (row == 6) return pawns[1];                // White pawns
   if (row == 7) return pieces[1][col];          // White back rank pieces
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