// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// Header.h
// Program on A5 branch.
// Header.h - The header file declares functions for sorting integers with insertion sort and 
// searching for a target value using binary search.
// ------------------------------------------------------------------------------------------------
#ifndef HEADER_H
#define HEADER_H

///  <summary>Define the structure for pairing elements with their original indices.</summary>
typedef struct {
   int value, originalIndex;
} IndexedElement;

/// <summary>Sorts an array of integers in ascending order using Insertion Sort.</summary>
void InsertionSort (IndexedElement arr[], int size);

/// <summary>Performs a binary search for a target value in a sorted array.</summary>
int BinarySearch (IndexedElement arr[], int size, int searchElement);

#endif HEADER_H