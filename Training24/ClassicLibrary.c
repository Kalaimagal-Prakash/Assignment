// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// ClassicLibrary.c
// Program on A5 branch.
// ClassicLibrary.c - The program sorts numbers and searches for a specific number in the sorted list.
// ------------------------------------------------------------------------------------------------
#include "header.h"

void InsertionSort (IndexedElement arr[], int size) {
   for (int i = 1; i < size; i++) {
      IndexedElement key = arr[i];                             // Current element to be inserted
      int j = i - 1;
      while (j >= 0 && arr[j].value > key.value) arr[j + 1] = arr[j--];
      arr[j + 1] = key;                                       // Insert the key at its correct position
   }
}

int BinarySearch (IndexedElement arr[], int size, int searchElement) {
   int left = 0, right = size - 1;
   while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid].value == searchElement) return mid;       // Element found
      if (arr[mid].value < searchElement) left = mid + 1;
      else right = mid - 1;
   }
   return -1;                                               // Element not found
}