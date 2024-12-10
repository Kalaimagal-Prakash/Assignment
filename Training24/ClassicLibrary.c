// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------------------------------------
// Classiclibrary.c
// Program on main branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

void InitializeBoard () {
   for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) board[i][j] = '1' + (i * 3 + j);
}

int MakeMove (int cell, int player) {
   int row = (cell - 1) / 3;
   int col = (cell - 1) % 3;
   if (board[row][col] != 'X' && board[row][col] != 'O') {
      board[row][col] = player;
      return 1;
   }
   return 0;
}

int AvailableMove () {
   int availableMove[9] = { 0 };
   int count = 0;
   for (int i = 0; i < 9; i++) {
      int row = i / 3;
      int col = i % 3;
      if (board[row][col] != 'X' && board[row][col] != 'O') {
         availableMove[count++] = i + 1;
      }
   }
   return availableMove[rand () % count];
}

int ValidMove (int cell) {
   if (cell < 1 || cell > 9) return 0;
   int row = (cell - 1) / 3;
   int col = (cell - 1) % 3;
   return (board[row][col] != 'X' && board[row][col] != 'O');
}

int GetWinner () {
   // Check rows, columns, and diagonals for a win
   for (int i = 0; i < 3; i++) {
      if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
      if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
   }
   if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
   if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
   return 0;
}

void PlayerMove () {
   int Pmove;
   while (1) {
      printf ("Player %d's turn. Enter the number (1-9):", currentPlayer);
      scanf_s ("%d", &Pmove);
      if (ValidMove (Pmove)) {
         MakeMove (Pmove, (currentPlayer == 1) ? 'X' : 'O');
         break;
      }
      else printf ("Invalid move. Try again.\n");
   }
}