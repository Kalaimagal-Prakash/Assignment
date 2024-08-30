// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// game.h
// Program on A3 branch.
// Convert the given decimal number to different forms (Decimal, Hexadecimal, Binary) 
// ------------------------------------------------------------------------------------------------

#ifndef GAME_H
#define GAME_H
#define BITS 32
#define HEX_DIGIT BITS/4

/// <summary>Function to convert Decimal to Binary.</summary>
char* DecimalToBinary (int n);

/// <summary>Function to convert Decimal to Hexadecimal.</summary>
char* DecimalToHex (int h);

/// <summary>Test cases for Decimal to Binary.</summary>
void TestDecToBinAndNegBin ();

/// <summary>Test cases for Decimal to Hexadecimal.</summary>
void TestDecToHexAndNegHex ();

#endif GAME_H
