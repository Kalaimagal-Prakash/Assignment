// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// ClassicLibrary.c
// Program on A5 branch.
// Write a program that sorts integer arrays in ascending order using any of the sorting algorithms discussed
// in the Sorting workshop. Also, implement binary search algorithm to search for an element in the sorted array.
// You may take the arrays as input from the user.
// ------------------------------------------------------------------------------------------------
void InsertionSort (int arr[], int n) {
   for (int i = 1; i < n; i++) {
      int key = arr[i], j = i - 1;
      while (j >= 0 && arr[j] > key) {
         arr[j + 1] = arr[j];
         j--;
      }
      arr[j + 1] = key;
   }
}

int BinarySearch (int arr[], int n, int find) {
   int left = 0, right = n - 1, result = -1; // To store the index of the first occurrence
   while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == find) {
         result = mid;
         right = mid - 1;
      }
      else if (arr[mid] < find) left = mid + 1;
      else right = mid - 1;
   }
   return result; // Return the index of the first occurrence or -1 if not found
}