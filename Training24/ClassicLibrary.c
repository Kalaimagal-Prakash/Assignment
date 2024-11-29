// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------------------------------------
// Classiclibrary.c
// Program on main branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

char board[3][3];
char player1 = 'X', player2 = 'O';
int currentPlayer = 1;


void InitializeBoard () {
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         board[i][j] = '1' + (i * 3 + j);
      }
   }
}

void PrintBoard () {
   printf ("Tic-Tac-Toe Game\n");
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         printf (" %c ", board[i][j]);
         if (j < 2) printf ("|");
      }
      printf ("\n");
      if (i < 2) {
         printf ("---|---|---\n");
      }
   }
   printf ("\n");
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

int getAvailableMove () {
   int availableMove[9];
   int count = 0;
   for (int i = 0; i < 9; i++) {
      int row = i / 3;
      int col = i % 3;
      if (board[row][col] != 'X' && board[row][col] != 'X') {
         availableMove[count++] = i + 1;
      }
   }
   return availableMove[rand () % count];
}



void PlayerMove () {
   int Pmove;
   printf ("Player %d's turn. Enter the number (1-9):", currentPlayer);
   scanf_s ("%d", &Pmove);
   if (validMove (Pmove)) {
      MakeMove (Pmove, (currentPlayer == 1) ? 'X' : 'O');
   }
   else {
      printf ("Invalid move try again");
      PlayerMove ();
   }
}

void ComputerMove () {
   int Cmove = getAvaliableMove ();
   printf ("Computer (O) chooses cell %d\n", Cmove);
   MakeMove (Cmove, 'O');
}

int validMove (int cell) {
   if (cell < 1 || cell > 9) {
      return 0;  // Invalid move if outside 1-9 range
   }

   int row = (cell - 1) / 3;
   int col = (cell - 1) % 3;
   return (board[row][col] != 'X' && board[row][col] != 'O');  // Check if the cell is empty
}


int main () {
   srand (time (NULL));
   InitializeBoard ();
   PrintBoard ();
   int winner = 0;

   while (1) {
      //PrintBoard ();
      if (currentPlayer == 1) {
         PlayerMove ();

      }
      else if (currentPlayer == 2) {
         if (player1 == 'X') {
            ComputerMove ();
         }
         else PlayerMove ();
      }
   }
}