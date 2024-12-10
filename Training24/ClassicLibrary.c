// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// Tic-Tac-Toe Game
// Program on main branch.
// ------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

char board[3][3];
char player1 = 'X', player2 = 'O';
int currentPlayer = 1;

/// <summary>Function to initialize the Tic - Tac - Toe game board.</summary>
void InitializeBoard () {
   for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) board[i][j] = '1' + (i * 3 + j);
}

/// <summary>Function to print the Tic-Tac-Toe board.</summary>
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

/// <summary>Function to make a move in the game by updating the board.</summary>
int MakeMove (int cell, int player) {
   int row = (cell - 1) / 3;
   int col = (cell - 1) % 3;
   if (board[row][col] != 'X' && board[row][col] != 'O') {
      board[row][col] = player;
      return 1;
   }
   return 0;
}

/// <summary>Function to find an available move by returning a random unused cell.</summary>
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

/// <summary>function checks if the chosen cell is within the valid range.</summary>
int ValidMove (int cell) {
   if (cell < 1 || cell > 9) return 0;
   int row = (cell - 1) / 3;
   int col = (cell - 1) % 3;
   return (board[row][col] != 'X' && board[row][col] != 'O');
}

/// <summary>Function to check for a winner.</summary>
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

/// <summary>Function to handle a player's move and updating the board.</summary>
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

int main () {
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