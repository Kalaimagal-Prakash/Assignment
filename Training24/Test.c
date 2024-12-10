// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------------------------------------
// Test.c
// Program on main branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include "Header.h"
#include <time.h>

void PrintBoard () {
   printf ("Tic-Tac-Toe Game\n");
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         printf (" %c ", board[i][j]);
         if (j < 2) printf ("|");
      }
      printf ("\n");
      if (i < 2) printf ("---|---|---\n");
   }
   printf ("\n");
}


int main () {
   srand (time (NULL));
   InitializeBoard ();
   PrintBoard ();
   int winner = 0;
   int moves = 0;
   while (1) {
      PlayerMove ();
      PrintBoard ();
      moves++;
      if (GetWinner ()) {
         printf ("Player %d wins!\n", currentPlayer);
         break;
      }
      if (moves == 9) {
         printf ("It's a tie!\n");
         break;
      }
      currentPlayer = (currentPlayer == 1) ? 2 : 1;  // Switch player
   }
   return 0;
}