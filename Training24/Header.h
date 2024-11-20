// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// Header.h - Program to print chess board.
// Program on A6 branch.
// ------------------------------------------------------------------------------------------------
#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <cstdio>

///<summary>Function to determine which piece should be at a given position (row, col).</summary>
wchar_t GetPiece (int row, int col);

///<summary>Returns the chess piece at the specified row and column on the chessboard.</summary>
void PrintChessboard (FILE* fp);

#endif // CHESSBOARD_H