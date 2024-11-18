// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Kalaimagal V P
// ------------------------------------------------------------------------------------------------
// // ClassicLibrary.c - The program sorts numbers and searches for a specific number in the sorted list.
// ------------------------------------------------------------------------------------------------
void InsertionSort (int arr[], int size) {
   for (int i = 1; i < size; i++) {
      int key = arr[i], j = i - 1;                     // Current element to be inserted
      while (j >= 0 && arr[j] > key) arr[j + 1] = arr[j--];
      arr[j + 1] = key;                               // Insert the key at its correct position
   }
}

int BinarySearch (int arr[], int size, int searchElement) {
   int left = 0, right = size - 1;
   while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == searchElement) return mid;     // Element found
      if (arr[mid] < searchElement) left = mid + 1;
      else right = mid - 1;
   }
   return -1;                                        // Element not found
}