// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------------------------------------
// Header.h
// Program on main branch.
// ------------------------------------------------------------------------------------------------
#ifndef HEADER_H
#define HEADER_H

char board[3][3];
char player1 = 'X', player2 = 'O';
int currentPlayer = 1;

void InitializeBoard ();
int GetWinner ();
int MakeMove (int cell, int player);
int AvailableMove ();
void PlayerMove ();
int ValidMove (int cell);

#endif HEADER_H